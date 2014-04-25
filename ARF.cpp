#include <avr/pgmspace.h>

#include "ARF.h"

typedef int arfInt;
typedef int arfUnsigned;

typedef union arfCell
{
	arfInt i;
	arfUnsigned u;
	void *p;
} arfCell;

typedef enum
{
	arfOpZeroArgFFI = 0x00,
	arfOpOneArgFFI,
	arfOpTwoArgFFI,
	arfOpThreeArgFFI,
	arfOpFourArgFFI,
	arfOpFiveArgFFI,
	arfOpSixArgFFI,
	arfOpSevenArgFFI,
	arfOpEightArgFFI,
	arfOpPARENLITERAL,
	arfOpDUP,
	arfOpDROP,
	arfOpPLUS,
	arfOpMINUS,
	arfOpONEPLUS,
	arfOpONEMINUS,
	arfOpSWAP,
	arfOpPARENBRANCH,
	//...
	arfOpEXIT = 0x7F,
} arfOpcode;

typedef enum
{
	arfCFADOCOLON = 0,
	arfCFADOCONSTANT,
	arfCFADOCREATE,
	arfCFADODOES,
} arfCFA;

typedef arfCell (*arfZeroArgFFI)(void);
typedef arfCell (*arfOneArgFFI)(arfCell a);
typedef arfCell (*arfTwoArgFFI)(arfCell a, arfCell b);
typedef arfCell (*arfThreeArgFFI)(arfCell a, arfCell b, arfCell c);
typedef arfCell (*arfFourArgFFI)(arfCell a, arfCell b, arfCell c, arfCell d);
typedef arfCell (*arfFiveArgFFI)(arfCell a, arfCell b, arfCell c, arfCell d,
								 arfCell e);
typedef arfCell (*arfSixArgFFI)(arfCell a, arfCell b, arfCell c, arfCell d,
								arfCell e, arfCell f);
typedef arfCell (*arfSevenArgFFI)(arfCell a, arfCell b, arfCell c, arfCell d,
								  arfCell e, arfCell f, arfCell g);
typedef arfCell (*arfEightArgFFI)(arfCell a, arfCell b, arfCell c, arfCell d,
								  arfCell e, arfCell f, arfCell g, arfCell h);

static int add(int a, int b)
{
	return a + b;
}

static int sum(int a, int b, int c)
{
	return a + b + c;
}

ARF::ARF(const uint8_t * dictionary, int dictionarySize)
 : dictionary(dictionary), dictionarySize(dictionarySize)
{
	this->here = const_cast<uint8_t *>(this->dictionary);
}

void ARF::go(int (*sketchFn)(void))
{
	// TODO Remove this test code.
	int16_t offset;

	*this->here++ = 'b';
	*this->here++ = 'l';
	*this->here++ = 'i';
	*this->here++ = 'n';
	*this->here++ = 'k';
	*this->here++ = (char)-5;
	*this->here++ = 0x00; // LFAhi
	*this->here++ = 0x00; // LFAlo
	uint8_t * blinkCFA = this->here;
	*this->here++ = 0xe4; // CFAlo: DOCOLON
	*this->here++ = 0x01; // CFAhi
	*this->here++ = arfOpDROP; // TODO Have sketchFn take an argument.
	*this->here++ = arfOpZeroArgFFI;
	*this->here++ = ((unsigned int)sketchFn) & 0xff;
	*this->here++ = (((unsigned int)sketchFn) >> 8) & 0xff;
	*this->here++ = arfOpEXIT;

	*this->here++ = 'g';
	*this->here++ = 'o';
	*this->here++ = (char)-2;
	*this->here++ = 0x00; // LFAhi
	*this->here++ = 0x00; // LFAlo
	uint8_t * goCFA = this->here;
	*this->here++ = 0xe4; // CFAlo: DOCOLON
	*this->here++ = 0x01; // CFAhi
	*this->here++ = arfOpPARENLITERAL;
	*this->here++ = 0x64;
	*this->here++ = 0x00;
	// FIXM3 Need to store this MSB (and right-shifted one with the high
	// bit set) otherwise we could match against an opcode.
	//
	// FIXME Make this an MSB-first relative offset to the word's CFA.
	// Note that the offset is as of the address *after* the offset
	// since that's where the IP will be in the arfWORD handler when we
	// calculate the address.  Better to just +2 the value here than
	// have to do a -2 in the inner loop.
	//
	// TOD0 Do we even need the "W" register and the "jump" and stuff?
	// Seems like we could just compile in the opcode (DOCOLON,
	// DOVARIABLE, etc.) at the call site and then invoke that.  That
	// would save us loading stuff in DOCOLON, having an extra variable,
	// etc.  In that respect, this becomes more like an
	// indirect-threaded Forth.
	//   This won't work, because the caller doesn't know what kind of
	//   word is being called.
	//
	// TODO We've gotten our names a bit wrong here.  These aren't
	// "opcodes" as much as they are "primitive words".  Similarly, the
	// RAM definitions are "user-defined words."  Primitive words are
	// identified by 0x00-0x7F, whereas user-defined words have their
	// high bit set and their PFA must be word-aligned (so that we can
	// shift left the 15-bit value).  Then, in the
	// arfPrimUserDefinedWord handler we can just read the "word type"
	// and then jump to a smaller (RAM-resident, for speed!) table for
	// that type of word.  There is only DOCOLON, DODOES, DOCREATE, etc.
	// so this can be hard-coded and avoids the need to waste "opcodes"
	// (now "primitive word ids"?).
	//
	// Again the key point here is that the PFA contains a list of
	// tokens and addresses, with the high bit telling you what you are
	// looking at.  Either way though, the list is a list of words
	// (primitive or user-defined).  There is no longer a concept of
	// "opcode" since ARF is a Forth machine and not a CPU.
	offset = -((this->here+2) - blinkCFA);
	*this->here++ = (offset >> 8) & 0xff;
	*this->here++ = offset & 0xff;
	*this->here++ = arfOpDROP;
	// Jump back to the start of this word (i.e., the entire word is in
	// a BEGIN ... AGAIN loop).  Note that (branch) offsets are 8-bit
	// relative offsets.  UNLIKE word addresses, the IP points at the
	// offset in arfOpPARENBRANCH.  Note that this is a positive number,
	// which is subtracted from the IP, whereas word addresses are
	// negative numbers that are added to the IP.  They are different
	// because we need to be able to detect word addresses (high bit
	// set) from opcodes (high bit clear), whereas for branch offsets we
	// want to
	// use the full range of the 8-bit value.
	*this->here++ = arfOpPARENBRANCH;
	offset = this->here - (goCFA+2);
	*this->here++ = offset & 0xff;

	this->innerInterpreter(goCFA + 2);
}

void ARF::innerInterpreter(uint8_t * xt)
{
	register uint8_t *ip;
	register arfCell tos;
	register arfCell *restDataStack; // Points at the second item on the stack.
	register arfCell *returnTop;

	uint8_t op;

	arfInt i;

	// Initialize our local variables.
	ip = (uint8_t *)xt;
	tos.i = 0;
	restDataStack = (arfCell*)this->dataStack[32];
	returnTop = (arfCell *)this->returnStack[32];

	static const void * const jtb[256] PROGMEM = {
		// $00 - $07
		&&arfOpZeroArgFFI,
		&&arfOpOneArgFFI,
		&&arfOpTwoArgFFI,
		&&arfOpThreeArgFFI,

		&&arfOpFourArgFFI,
		&&arfOpFiveArgFFI,
		&&arfOpSixArgFFI,
		&&arfOpSevenArgFFI,

		// $08 - $0F
		&&arfOpEightArgFFI,
		&&arfOpPARENLITERAL,
		&&arfOpDUP,
		&&arfOpDROP,

		&&arfOpPLUS,
		&&arfOpMINUS,
		&&arfOpONEPLUS,
		&&arfOpONEMINUS,

		// $10 - $17
		&&arfOpSWAP,
		&&arfOpPARENBRANCH,
		0, 0,

		0, 0, 0, 0,

		// $18 - $1F
		0, 0, 0, 0,
		0, 0, 0, 0,

		// $20 - $27
		0, 0, 0, 0,
		0, 0, 0, 0,

		// $28 - $2F
		0, 0, 0, 0,
		0, 0, 0, 0,

		// $30 - $37
		0, 0, 0, 0,
		0, 0, 0, 0,

		// $38 - $3F
		0, 0, 0, 0,
		0, 0, 0, 0,

		// $40 - $47
		0, 0, 0, 0,
		0, 0, 0, 0,

		// $48 - $4F
		0, 0, 0, 0,
		0, 0, 0, 0,

		// $50 - $57
		0, 0, 0, 0,
		0, 0, 0, 0,

		// $58 - $5F
		0, 0, 0, 0,
		0, 0, 0, 0,

		// $60 - $67
		0, 0, 0, 0,
		0, 0, 0, 0,

		// $68 - $6F
		0, 0, 0, 0,
		0, 0, 0, 0,

		// $70 - $77
		0, 0, 0, 0,
		0, 0, 0, 0,

		// $78 - $7F
		0, 0, 0, 0,
		0, 0, 0,
		&&arfOpEXIT,

		// $80 - $8F
		&&arfWORD, &&arfWORD, &&arfWORD, &&arfWORD,
		&&arfWORD, &&arfWORD, &&arfWORD, &&arfWORD,
		&&arfWORD, &&arfWORD, &&arfWORD, &&arfWORD,
		&&arfWORD, &&arfWORD, &&arfWORD, &&arfWORD,

		// $90 - $9F
		&&arfWORD, &&arfWORD, &&arfWORD, &&arfWORD,
		&&arfWORD, &&arfWORD, &&arfWORD, &&arfWORD,
		&&arfWORD, &&arfWORD, &&arfWORD, &&arfWORD,
		&&arfWORD, &&arfWORD, &&arfWORD, &&arfWORD,

		// $A0 - $AF
		&&arfWORD, &&arfWORD, &&arfWORD, &&arfWORD,
		&&arfWORD, &&arfWORD, &&arfWORD, &&arfWORD,
		&&arfWORD, &&arfWORD, &&arfWORD, &&arfWORD,
		&&arfWORD, &&arfWORD, &&arfWORD, &&arfWORD,

		// $B0 - $BF
		&&arfWORD, &&arfWORD, &&arfWORD, &&arfWORD,
		&&arfWORD, &&arfWORD, &&arfWORD, &&arfWORD,
		&&arfWORD, &&arfWORD, &&arfWORD, &&arfWORD,
		&&arfWORD, &&arfWORD, &&arfWORD, &&arfWORD,

		// $C0 - $CF
		&&arfWORD, &&arfWORD, &&arfWORD, &&arfWORD,
		&&arfWORD, &&arfWORD, &&arfWORD, &&arfWORD,
		&&arfWORD, &&arfWORD, &&arfWORD, &&arfWORD,
		&&arfWORD, &&arfWORD, &&arfWORD, &&arfWORD,

		// $D0 - $DF
		&&arfWORD, &&arfWORD, &&arfWORD, &&arfWORD,
		&&arfWORD, &&arfWORD, &&arfWORD, &&arfWORD,
		&&arfWORD, &&arfWORD, &&arfWORD, &&arfWORD,
		&&arfWORD, &&arfWORD, &&arfWORD, &&arfWORD,

		// $E0 - $EF
		&&arfWORD, &&arfWORD, &&arfWORD, &&arfWORD,
		&&arfWORD, &&arfWORD, &&arfWORD, &&arfWORD,
		&&arfWORD, &&arfWORD, &&arfWORD, &&arfWORD,
		&&arfWORD, &&arfWORD, &&arfWORD, &&arfWORD,

		// $F0 - $FF
		&&arfWORD, &&arfWORD, &&arfWORD, &&arfWORD,
		&&arfWORD, &&arfWORD, &&arfWORD, &&arfWORD,
		&&arfWORD, &&arfWORD, &&arfWORD, &&arfWORD,
		&&arfWORD, &&arfWORD, &&arfWORD, &&arfWORD,
	};

	while (true)
	{
		// Get the next opcode and dispatch to the label.
		op = *ip++;
		goto *(void *)pgm_read_word(&jtb[op]);

		arfOpZeroArgFFI:
		{
			arfZeroArgFFI fn = (arfZeroArgFFI)(((arfCell*)ip)->p);
			ip += 2;
			tos = (*fn)();
		}
		continue;

		arfOpOneArgFFI:
		{
			arfOneArgFFI fn = (arfOneArgFFI)(((arfCell*)ip)->p);
			ip += 2;
			tos = (*fn)(tos);
		}
		continue;

		arfOpTwoArgFFI:
		{
			arfTwoArgFFI fn = (arfTwoArgFFI)(((arfCell*)ip)->p);
			ip += 2;
			arfCell arg2 = tos;
			arfCell arg1 = *restDataStack++;
			tos = (*fn)(arg1, arg2);
		}
		continue;

		arfOpThreeArgFFI:
		{
			arfThreeArgFFI fn = (arfThreeArgFFI)(((arfCell*)ip)->p);
			ip += 2;
			arfCell arg3 = tos;
			arfCell arg2 = *restDataStack++;
			arfCell arg1 = *restDataStack++;
			tos = (*fn)(arg1, arg2, arg3);
		}
		continue;

		arfOpFourArgFFI:
		continue;

		arfOpFiveArgFFI:
		continue;

		arfOpSixArgFFI:
		continue;

		arfOpSevenArgFFI:
		continue;

		arfOpEightArgFFI:
		continue;

		arfOpPARENLITERAL:
		{
			*--restDataStack = tos;
			tos = *(arfCell*)ip;
			ip += 2;
		}
		continue;

		arfOpDUP:
		{
			// Move rest pointer to empty location, then copy TOS there.
			*--restDataStack = tos;
		}
		continue;

		arfOpDROP:
		{
			// Make TOS equal to second stack item, then adjust rest pointer.
			tos = *restDataStack++;
		}
		continue;

		arfOpPLUS:
		{
			i = (restDataStack++)->i;
			tos.i += i;
		}
		continue;

		arfOpMINUS:
		{
			i = (restDataStack++)->i;
			tos.i -= i;
		}
		continue;

		arfOpONEPLUS:
		{
			tos.i++;
		}
		continue;

		arfOpONEMINUS:
		{
			tos.i--;
		}
		continue;

		arfOpSWAP:
		{
			arfCell swap = *restDataStack;
			*restDataStack = tos;
			tos = swap;
		}
		continue;

		arfOpPARENBRANCH:
		{
			// Relative, because these are entirely within a single word
			// and so we want it to be relocatable without us having to
			// do anything.  Note that the offset cannot be larger than
			// 255 bytes!
			ip = ip - *ip;
		}
		continue;

		arfOpEXIT:
		{
			ip = (uint8_t *)((returnTop++)->p);
		}
		continue;

		// This is not an opcode, but is instead the code that is run
		// when a non-opcode byte is detected.  We read the next byte,
		// which is the absolute RAM address of the CFA of the word that
		// is being called.  We load the CFA, which will be one of our
		// opcodes, and go back to the top of the loop in order to
		// process that opcode.  Note that we do *not* change IP to
		// point to the CFA, since the called word will either save the
		// IP itself (in the case of DOCOLON) or continue onwards after
		// pushing something onto the stack (in the case of DOVARIABLE).
		// This right here is what makes ARF an indirect-threaded Forth
		// when processing RAM-based definitions: the CFA contains the
		// address (opcode, because we're actually a token-threaded
		// Forth once we're in flash) of the routine that executes the
		// new thread.
		arfWORD:
		{
			// Get the relative offset to the CFA of the target word.
			// Using a relative offset automatically makes this value
			// negative, which differentiates it (high bit set) from
			// opcodes, which are all less than $80 (high bit clear).
			i = (op << 8) | *ip++;
			arfCell * w = (arfCell*)(ip + i);

			// Indirect threading: jump to the CFA.
			goto *(void *)(w->p);

			DOCOLON:
				// IP currently points to the next word in the PFA and that
				// is the location to which we should return once this new
				// word has executed.
				(--returnTop)->p = (void *)ip;

				// Now skip over the CFA and begin executing the thread in
				// the Parameter Field Address.
				ip = (uint8_t *)w + 2;

				// Start processing instructions in this thread.
				continue;

			DOCONSTANT:
				continue;

			DOCREATE:
				continue;

			DODOES:
				continue;
		}
	}
}
