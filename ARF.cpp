/* Copyright (c) 2014, Michael Alyn Miller <malyn@strangeGizmo.com>.
 * All rights reserved.
 * vi:ts=4:sts=4:et:sw=4:sr:et:tw=72:fo=tcrq
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1.  Redistributions of source code must retain the above copyright
 *     notice unmodified, this list of conditions, and the following
 *     disclaimer.
 * 2.  Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in
 *     the documentation and/or other materials provided with the
 *     distribution.
 * 3.  Neither the name of Michael Alyn Miller nor the names of the
 *     contributors to this software may be used to endorse or promote
 *     products derived from this software without specific prior written
 *     permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,
 * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <ctype.h>

#ifdef __AVR__
#include <avr/pgmspace.h>
#else
#define PROGMEM
#include <string.h>
#define pgm_read_byte(p) (*p)
#define pgm_read_word(p) (*p)
#define memcpy_P memcpy
#define strncasecmp_P strncasecmp
#endif

#include "ARF.h"

#define CFASZ (sizeof(void*))
#define FFIPROCSZ (sizeof(void*))
#define CELLSZ (sizeof(arfCell))

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
enum arfOpcode
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
    arfOpLIT,
    arfOpDUP,
    arfOpDROP,
    arfOpPLUS,
    arfOpMINUS,
    arfOpONEPLUS,
    arfOpONEMINUS,
    arfOpSWAP,
    arfOpBRANCH,
    arfOpABORT,
    arfOpCHARLIT,
    arfOpCOMPILECOMMA,
    arfOpCR,
    arfOpEMIT,
    arfOpEXECUTE,
    arfOpFETCH,
    arfOpLITERAL,
    arfOpNUMBERQ,
    arfOpOR,
    arfOpPARSEWORD,
    arfOpFINDWORD,
    arfOpQDUP,
    arfOpSPACE,
    arfOpSTATE,
    arfOpSTORE,
    arfOpTOIN,
    arfOpTWODROP,
    arfOpTYPE,
    arfOpZBRANCH,
    arfOpZERO,
    arfOpZEROEQUALS,
    arfOpQUIT,
    arfOpTIB,
    arfOpTIBSIZE,
    arfOpACCEPT,
    arfOpINTERPRET,
    arfOpPSQUOTE,
    arfOpBL,
    arfOpCFETCH,
    arfOpCOUNT,
    arfOpTONUMBER,
    arfOpDEPTH,
    arfOpDOT,
    //...
    arfOpEXIT = 0x7F,
};

struct arfPrimitiveWord {
    uint8_t opcode;
    uint8_t nameLen;
    const char * name;
};

static const char arfOpNameABORT[] PROGMEM = "ABORT";
static const char arfOpNameACCEPT[] PROGMEM = "ACCEPT";
static const char arfOpNameBL[] PROGMEM = "BL";
static const char arfOpNameCFETCH[] PROGMEM = "C@";
static const char arfOpNameCOMPILECOMMA[] PROGMEM = "COMPILE,";
static const char arfOpNameCOUNT[] PROGMEM = "COUNT";
static const char arfOpNameCR[] PROGMEM = "CR";
static const char arfOpNameDEPTH[] PROGMEM = "DEPTH";
static const char arfOpNameDOT[] PROGMEM = ".";
static const char arfOpNameDROP[] PROGMEM = "DROP";
static const char arfOpNameDUP[] PROGMEM = "DUP";
static const char arfOpNameEMIT[] PROGMEM = "EMIT";
static const char arfOpNameEXECUTE[] PROGMEM = "EXECUTE";
static const char arfOpNameFETCH[] PROGMEM = "@";
static const char arfOpNameLITERAL[] PROGMEM = "LITERAL";
static const char arfOpNameMINUS[] PROGMEM = "-";
static const char arfOpNameNUMBERQ[] PROGMEM = "NUMBER?";
static const char arfOpNameONEMINUS[] PROGMEM = "1-";
static const char arfOpNameONEPLUS[] PROGMEM = "1+";
static const char arfOpNameOR[] PROGMEM = "OR";
static const char arfOpNamePLUS[] PROGMEM = "+";
static const char arfOpNameQDUP[] PROGMEM = "?DUP";
static const char arfOpNameQUIT[] PROGMEM = "QUIT";
static const char arfOpNameSPACE[] PROGMEM = "SPACE";
static const char arfOpNameSTATE[] PROGMEM = "STATE";
static const char arfOpNameSTORE[] PROGMEM = "STORE";
static const char arfOpNameSWAP[] PROGMEM = "SWAP";
static const char arfOpNameTOIN[] PROGMEM = ">IN";
static const char arfOpNameTONUMBER[] PROGMEM = ">NUMBER";
static const char arfOpNameTWODROP[] PROGMEM = "2DROP";
static const char arfOpNameTYPE[] PROGMEM = "TYPE";
static const char arfOpNameZERO[] PROGMEM = "0";
static const char arfOpNameZEROEQUALS[] PROGMEM = "0=";

// TODO The size of this data structure could be reduced by at least 384
// bytes if we pack the entire thing into a single byte array and then
// just inline the strings, using the count to traverse from
// word-to-word, with a separate counter being used in code to decide
// which opcode we are looking at (instead of including the opcode in
// the struct).  128 bytes saved for the opcode, another 256 bytes saved
// for the string pointer, then some number of extra bytes saved for all
// of the NULL (internal) words.
static const arfPrimitiveWord primitives[128] PROGMEM = {
    // $00 - $07
    { arfOpZeroArgFFI,      0,  NULL },
    { arfOpOneArgFFI,       0,  NULL },
    { arfOpTwoArgFFI,       0,  NULL },
    { arfOpThreeArgFFI,     0,  NULL },

    { arfOpFourArgFFI,      0,  NULL },
    { arfOpFiveArgFFI,      0,  NULL },
    { arfOpSixArgFFI,       0,  NULL },
    { arfOpSevenArgFFI,     0,  NULL },

    // $08 - $0F
    { arfOpEightArgFFI,     0,  NULL },
    { arfOpLIT,             0,  NULL },
    { arfOpDUP,             3,  arfOpNameDUP },
    { arfOpDROP,            4,  arfOpNameDROP },

    { arfOpPLUS,            1,  arfOpNamePLUS },
    { arfOpMINUS,           1,  arfOpNameMINUS },
    { arfOpONEPLUS,         2,  arfOpNameONEPLUS },
    { arfOpONEMINUS,        2,  arfOpNameONEMINUS },

    // $10 - $17
    { arfOpSWAP,            4,  arfOpNameSWAP },
    { arfOpBRANCH,          0,  NULL },
    { arfOpABORT,           5,  arfOpNameABORT },
    { arfOpCHARLIT,         0,  NULL },

    { arfOpCOMPILECOMMA,    8,  arfOpNameCOMPILECOMMA },
    { arfOpCR,              2,  arfOpNameCR },
    { arfOpEMIT,            4,  arfOpNameEMIT },
    { arfOpEXECUTE,         7,  arfOpNameEXECUTE },

    // $18 - $1F
    { arfOpFETCH,           1,  arfOpNameFETCH },
    { arfOpLITERAL,         7,  arfOpNameLITERAL },
    { arfOpNUMBERQ,         7,  arfOpNameNUMBERQ },
    { arfOpOR,              2,  arfOpNameOR },

    { arfOpPARSEWORD,       0,  NULL },
    { arfOpFINDWORD,        0,  NULL },
    { arfOpQDUP,            4,  arfOpNameQDUP },
    { arfOpSPACE,           5,  arfOpNameSPACE },

    // $20 - $27
    { arfOpSTATE,           5,  arfOpNameSTATE },
    { arfOpSTORE,           5,  arfOpNameSTORE },
    { arfOpTOIN,            3,  arfOpNameTOIN },
    { arfOpTWODROP,         5,  arfOpNameTWODROP },

    { arfOpTYPE,            4,  arfOpNameTYPE },
    { arfOpZBRANCH,         0,  NULL },
    { arfOpZERO,            1,  arfOpNameZERO },
    { arfOpZEROEQUALS,      2,  arfOpNameZEROEQUALS },

    // $28 - $2F
    { arfOpQUIT,            4,  arfOpNameQUIT },
    { arfOpTIB,             0,  NULL },
    { arfOpTIBSIZE,         0,  NULL },
    { arfOpACCEPT,          6,  arfOpNameACCEPT },

    { arfOpINTERPRET,       0,  NULL },
    { arfOpPSQUOTE,         0,  NULL },
    { arfOpBL,              2,  arfOpNameBL },
    { arfOpCFETCH,          2,  arfOpNameCFETCH },

    // $30 - $37
    { arfOpCOUNT,           5,  arfOpNameCOUNT },
    { arfOpTONUMBER,        7,  arfOpNameTONUMBER },
    { arfOpDEPTH,           5,  arfOpNameDEPTH },
    { arfOpDOT,             1,  arfOpNameDOT },

    { 0,                    0,  NULL },
    { 0,                    0,  NULL },
    { 0,                    0,  NULL },
    { 0,                    0,  NULL },

    // $38 - $3F
    { 0,                    0,  NULL },
    { 0,                    0,  NULL },
    { 0,                    0,  NULL },
    { 0,                    0,  NULL },

    { 0,                    0,  NULL },
    { 0,                    0,  NULL },
    { 0,                    0,  NULL },
    { 0,                    0,  NULL },

    // $40 - $47
    { 0,                    0,  NULL },
    { 0,                    0,  NULL },
    { 0,                    0,  NULL },
    { 0,                    0,  NULL },

    { 0,                    0,  NULL },
    { 0,                    0,  NULL },
    { 0,                    0,  NULL },
    { 0,                    0,  NULL },

    // $48 - $4F
    { 0,                    0,  NULL },
    { 0,                    0,  NULL },
    { 0,                    0,  NULL },
    { 0,                    0,  NULL },

    { 0,                    0,  NULL },
    { 0,                    0,  NULL },
    { 0,                    0,  NULL },
    { 0,                    0,  NULL },

    // $50 - $57
    { 0,                    0,  NULL },
    { 0,                    0,  NULL },
    { 0,                    0,  NULL },
    { 0,                    0,  NULL },

    { 0,                    0,  NULL },
    { 0,                    0,  NULL },
    { 0,                    0,  NULL },
    { 0,                    0,  NULL },

    // $58 - $5F
    { 0,                    0,  NULL },
    { 0,                    0,  NULL },
    { 0,                    0,  NULL },
    { 0,                    0,  NULL },

    { 0,                    0,  NULL },
    { 0,                    0,  NULL },
    { 0,                    0,  NULL },
    { 0,                    0,  NULL },

    // $60 - $67
    { 0,                    0,  NULL },
    { 0,                    0,  NULL },
    { 0,                    0,  NULL },
    { 0,                    0,  NULL },

    { 0,                    0,  NULL },
    { 0,                    0,  NULL },
    { 0,                    0,  NULL },
    { 0,                    0,  NULL },

    // $68 - $6F
    { 0,                    0,  NULL },
    { 0,                    0,  NULL },
    { 0,                    0,  NULL },
    { 0,                    0,  NULL },

    { 0,                    0,  NULL },
    { 0,                    0,  NULL },
    { 0,                    0,  NULL },
    { 0,                    0,  NULL },

    // $70 - $77
    { 0,                    0,  NULL },
    { 0,                    0,  NULL },
    { 0,                    0,  NULL },
    { 0,                    0,  NULL },

    { 0,                    0,  NULL },
    { 0,                    0,  NULL },
    { 0,                    0,  NULL },
    { 0,                    0,  NULL },

    // $78 - $7F
    { 0,                    0,  NULL },
    { 0,                    0,  NULL },
    { 0,                    0,  NULL },
    { 0,                    0,  NULL },

    { 0,                    0,  NULL },
    { 0,                    0,  NULL },
    { 0,                    0,  NULL },
    { arfOpEXIT,            0,  NULL },
};

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

ARF::ARF(const uint8_t * dictionary, int dictionarySize,
        arfKeyQuestion keyQ, arfKey key, arfEmit emit)
 : keyQ(keyQ), key(key), emit(emit),
   dictionary(dictionary), dictionarySize(dictionarySize),
   state(0)
{
    this->here = const_cast<uint8_t *>(this->dictionary);
}

void ARF::compileParenInterpret()
{
    // -----------------------------------------------------------------
    // INTERPRET [ARF] ( i*x -- j*x )
    //
    // Interpret the string stored in the input buffer.
    //
    // : INTERPRET ( i*x -- j*x )
    //   0 >IN !
    //   BEGIN  PARSE-WORD  DUP WHILE
    //       FIND-WORD ( ca u 0=notfound | xt 1=imm | xt -1=interp)
    //       ?DUP IF ( xt 1=imm | xt -1=interp)
    //           1+  STATE @ 0=  OR ( xt 2=imm | xt 0=interp)
    //           IF EXECUTE ELSE COMPILE, THEN
    //       ELSE
    //           NUMBER? IF
    //               STATE @ IF POSTPONE LITERAL THEN
    //               -- Interpreting; leave number on stack.
    //           ELSE
    //               TYPE  SPACE  [CHAR] ? EMIT  CR  ABORT
    //           THEN
    //       THEN
    //   REPEAT ( j*x ca u) 2DROP ;

    ((arfCell*)this->here)->p = this->docolonCFA;
    this->here += CFASZ;

    static const int8_t interpret[] PROGMEM = {
        arfOpZERO, arfOpTOIN, arfOpSTORE,
        arfOpPARSEWORD, arfOpDUP, arfOpZBRANCH, 37,
        arfOpFINDWORD, arfOpQDUP, arfOpZBRANCH, 14,
        arfOpONEPLUS, arfOpSTATE, arfOpFETCH, arfOpZEROEQUALS, arfOpOR,
            arfOpZBRANCH, 4,
        arfOpEXECUTE, arfOpBRANCH, 21,
        arfOpCOMPILECOMMA, arfOpBRANCH, 18,
        arfOpNUMBERQ, arfOpZBRANCH, 8,
        arfOpSTATE, arfOpFETCH, arfOpZBRANCH, 11,
        arfOpLITERAL, arfOpBRANCH, 8,
        arfOpTYPE, arfOpSPACE, arfOpCHARLIT, '?', arfOpEMIT, arfOpCR,
            arfOpABORT,
        arfOpBRANCH, -39,
        arfOpTWODROP,
        arfOpEXIT,
    };

    memcpy_P(this->here, interpret, sizeof(interpret));
    this->here += sizeof(interpret);
}

void ARF::compileParenQuit()
{
    // -----------------------------------------------------------------
    // (QUIT) [ARF] ( -- )
    //
    // Repeat the following:
    //   - Accept a line from the input source into the input buffer,
    //     set >IN to zero, and interpret.
    //   - Display the implementation-defined system prompt if in
    //     interpretation state, all processing has been completed, and
    //     no ambiguous condition exists.
    //
    // ---
    // : (QUIT)  ( --)
    //   BEGIN
    //       TIB  DUP TIBSIZE ACCEPT  SPACE
    //       INTERPRET
    //       CR  STATE @ 0= IF ." ok " THEN
    //   AGAIN ;

    ((arfCell*)this->here)->p = this->docolonCFA;
    this->here += CFASZ;

    static const int8_t quit[] PROGMEM = {
        arfOpTIB, arfOpDUP, arfOpTIBSIZE, arfOpACCEPT, arfOpSPACE,
        arfOpINTERPRET,
        arfOpCR, arfOpSTATE, arfOpFETCH, arfOpZEROEQUALS, arfOpZBRANCH, 7,
        arfOpPSQUOTE, 3, 'o', 'k', ' ', arfOpTYPE,
        arfOpBRANCH, -19
    };

    memcpy_P(this->here, quit, sizeof(quit));
    this->here += sizeof(quit);
}

void ARF::compileParenEvaluate()
{
}

arfUnsigned ARF::parenAccept(uint8_t * caddr, arfUnsigned n1)
{
    uint8_t * p = caddr;
    arfUnsigned n2 = 0;
    uint8_t ch;

    // Read characters until we get a linefeed.
    while ((ch = this->key()) != '\n')
    {
        // Is our buffer full?  If so, ignore this character.
        if (n2 == n1)
        {
            continue;
        }

        // TODO Deal with backspace.

        // Emit the character.
        this->emit(ch);

        // Append the character to our buffer.
        *p++ = ch;
        n2++;
    }

    // Return the number of characters that were read.
    return n2;
}

bool ARF::parenFindWord(uint8_t * caddr, arfUnsigned u, arfUnsigned &xt, bool &isImmediate)
{
    uint8_t searchLen = u;
    char * searchName = (char *)caddr;

    // Search through the opcodes for a match against this search name.
    for (int op = 0; op < 128; op++)
    {
        // Get a reference to this primitive.
        const arfPrimitiveWord &prim = primitives[op];

        // Ignore this opcode if its length is not the same as our
        // search length.
        if (pgm_read_byte(&prim.nameLen) != searchLen)
        {
            continue;
        }

        // Compare the characters.
        if (strncasecmp_P(searchName, (char *)pgm_read_word(&prim.name), searchLen) == 0)
        {
            xt = pgm_read_byte(&prim.opcode);
            isImmediate = false;
            return true;
        }
    }

    // No match.
    return false;
}

// NUMBER? [ARF] "number-question" ( c-addr u -- c-addr u 0 | n -1 )
//
// Attempt to convert a string at c-addr of length u into digits, using
// the radix in BASE.  The number and -1 is returned if the conversion
// was successful, otherwise 0 is returned.
bool ARF::parenNumberQ(uint8_t * caddr, arfUnsigned u, arfInt &n)
{
    // Store the sign as a value to be multipled against the final
    // number.
    arfInt sign = 1;
    if (*caddr == '-')
    {
        sign = -1;
        caddr++;
        u--;
    }

    // Try to convert the (rest of, if we found a sign) number.
    arfUnsigned ud = 0;
    this->parenToNumber(ud, caddr, u);
    if (u == 0)
    {
        n = (arfInt)ud * sign;
        return true;
    }
    else
    {
        return false;
    }
}

// >NUMBER [CORE] 6.1.0567 "to-number" ( ud1 c-addr1 u1 -- ud2 c-addr2 u2 )
//
// ud2 is the unsigned result of converting the characters within the
// string specified by c-addr1 u1 into digits, using the number in BASE,
// and adding each into ud1 after multiplying ud1 by the number in BASE.
// Conversion continues left-to-right until a character that is not
// convertible, including any "+" or "-", is encountered or the string
// is entirely converted.  c-addr2 is the location of the first
// unconverted character or the first character past the end of the
// string if the string was entirely converted.  u2 is the number of
// unconverted characters in the string.  An ambiguous condition exists
// if ud2 overflows during the conversion.
void ARF::parenToNumber(arfUnsigned &ud, uint8_t * &caddr, arfUnsigned &u)
{
    while (u > 0)
    {
        uint8_t ch = *caddr;
        if (ch < '0')
        {
            break;
        }

        arfUnsigned digit = ch - '0';
        if (digit > 9)
        {
            digit = tolower(ch) - 'a' + 10;
        }

        if (digit >= this->base)
        {
            break;
        }

        ud = (ud * this->base) + digit;
        caddr++;
        u--;
    }
}

void ARF::parenParseWord(uint8_t delim, uint8_t * &caddr, arfUnsigned &u)
{
    // Skip over the start of the string until we find a non-delimiter
    // character or we hit the end of the parse area.
    while ((*(this->source + this->toIn) == delim)
            && (this->toIn < this->sourceLen))
    {
        this->toIn++;
    }

    // We're either pointing to a non-delimiter character or we're at
    // the end of the parse area; point caddr at the current location
    // and then scan forwards until we hit another delimiter or we
    // exhaust the parse area.
    uint8_t * pParse = caddr = this->source + this->toIn;
    while ((*pParse != delim) && (this->toIn < this->sourceLen))
    {
        pParse++;
        this->toIn++;
    }

    // Set the string length.
    u = pParse - caddr;
}

void ARF::go()
{
    register uint8_t *ip;
    register arfCell tos;
    register arfCell *restDataStack; // Points at the second item on the stack.
    register arfCell *returnTop;

    uint8_t op;

    // Store the location of the CFAs.
    this->docolonCFA = &&DOCOLON;

    // Compile our RAM definitions.
    uint8_t * parenInterpret = this->here;
    this->compileParenInterpret();

    uint8_t * parenQuit = this->here;
    this->compileParenQuit();

    uint8_t * parenEvaluate = this->here;
    this->compileParenEvaluate();

    // Print the banner.
    if (this->emit != NULL)
    {
        this->emit('H');
        this->emit('i');
        this->emit('\n');
    }

    // Initialize our local variables.
    uint8_t abort = arfOpABORT;
    ip = &abort;
    tos.i = 0;
    restDataStack = (arfCell*)&this->dataStack[32];
    returnTop = (arfCell *)&this->returnStack[32];

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
        &&arfOpLIT,
        &&arfOpDUP,
        &&arfOpDROP,

        &&arfOpPLUS,
        &&arfOpMINUS,
        &&arfOpONEPLUS,
        &&arfOpONEMINUS,

        // $10 - $17
        &&arfOpSWAP,
        &&arfOpBRANCH,
        &&arfOpABORT,
        &&arfOpCHARLIT,

        &&arfOpCOMPILECOMMA,
        &&arfOpCR,
        &&arfOpEMIT,
        &&arfOpEXECUTE,

        // $18 - $1F
        &&arfOpFETCH,
        &&arfOpLITERAL,
        &&arfOpNUMBERQ,
        &&arfOpOR,

        &&arfOpPARSEWORD,
        &&arfOpFINDWORD,
        &&arfOpQDUP,
        &&arfOpSPACE,

        // $20 - $27
        &&arfOpSTATE,
        &&arfOpSTORE,
        &&arfOpTOIN,
        &&arfOpTWODROP,

        &&arfOpTYPE,
        &&arfOpZBRANCH,
        &&arfOpZERO,
        &&arfOpZEROEQUALS,

        // $28 - $2F
        &&arfOpQUIT,
        &&arfOpTIB,
        &&arfOpTIBSIZE,
        &&arfOpACCEPT,

        &&arfOpINTERPRET,
        &&arfOpPSQUOTE,
        &&arfOpBL,
        &&arfOpCFETCH,

        // $30 - $37
        &&arfOpCOUNT,
        &&arfOpTONUMBER,
        &&arfOpDEPTH,
        &&arfOpDOT,

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
DISPATCH_OPCODE:
        goto *(void *)pgm_read_word(&jtb[op]);

        arfOpZeroArgFFI:
        {
            arfZeroArgFFI fn = (arfZeroArgFFI)(((arfCell*)ip)->p);
            ip += FFIPROCSZ;

            *--restDataStack = tos;
            tos = (*fn)();
        }
        continue;

        arfOpOneArgFFI:
        {
            arfOneArgFFI fn = (arfOneArgFFI)(((arfCell*)ip)->p);
            ip += FFIPROCSZ;

            tos = (*fn)(tos);
        }
        continue;

        arfOpTwoArgFFI:
        {
            arfTwoArgFFI fn = (arfTwoArgFFI)(((arfCell*)ip)->p);
            ip += FFIPROCSZ;

            arfCell arg2 = tos;
            arfCell arg1 = *restDataStack++;
            tos = (*fn)(arg1, arg2);
        }
        continue;

        arfOpThreeArgFFI:
        {
            arfThreeArgFFI fn = (arfThreeArgFFI)(((arfCell*)ip)->p);
            ip += FFIPROCSZ;
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

        arfOpLIT:
        {
            *--restDataStack = tos;
            tos = *(arfCell*)ip;
            ip += CELLSZ;
        }
        continue;

        arfOpDUP:
        {
            *--restDataStack = tos;
        }
        continue;

        arfOpDROP:
        {
            tos = *restDataStack++;
        }
        continue;

        arfOpPLUS:
        {
            tos.i += restDataStack++->i;
        }
        continue;

        arfOpMINUS:
        {
            tos.i = restDataStack++->i - tos.i;
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
            arfCell swap = restDataStack[0];
            restDataStack[0] = tos;
            tos = swap;
        }
        continue;

        // TODO Add docs re: Note that (branch) and (0branch) offsets
        // are 8-bit relative offsets.  UNLIKE word addresses, the IP
        // points at the offset in arfOpBRANCH/arfOpZBRANCH.  These
        // offsets can be positive or negative because branches can go
        // both forwards and backwards.
        arfOpBRANCH:
        {
            // Relative, because these are entirely within a single word
            // and so we want it to be relocatable without us having to
            // do anything.  Note that the offset cannot be larger than
            // +/- 127 bytes!
            ip = ip + *(int8_t*)ip;
        }
        continue;

        // -------------------------------------------------------------
        // ABORT [CORE] 6.1.0670 ( i*x -- ) ( R: j*x -- )
        //
        // Empty the data stack and perform the function of QUIT, which
        // includes emptying the return stack, without displaying a
        // message.
        arfOpABORT:
        {
            tos.i = 0;
            restDataStack = (arfCell*)&this->dataStack[32];
            this->base = 10;
            goto arfOpQUIT;
        }
        continue;

        arfOpCHARLIT:
        {
            *--restDataStack = tos;
            tos.i = *ip++;
        }
        continue;

        arfOpCOMPILECOMMA:
        {
            // TODO Needs to differentiate between an opcode on the
            // stack (high bit clear) and an address and compile either
            // a one-byte or two-byte value.
            // Note that this is an MSB-first relative offset to the
            // word's CFA and that the offset is as of the address
            // *after* the offset since that's where the IP will be in
            // the arfWORD handler when we calculate the address.
            // Better to just +2 the value here than have to do a -2 in
            // the inner loop.
            // TODO Implement this
            tos = *restDataStack++;
        }
        continue;

        arfOpCR:
        {
            if (this->emit != NULL)
            {
                this->emit('\n');
            }
        }
        continue;

        arfOpEMIT:
        {
            if (this->emit != NULL)
            {
                this->emit(tos.i);
            }

            tos = *restDataStack++;
        }
        continue;

        // -------------------------------------------------------------
        // EXECUTE [CORE] 6.1.1370 ( i*x xt -- j*x )
        //
        // Remove xt from the stack and perform the semantics identified
        // by it.  Other stack effects are due to the word EXECUTEd.
        arfOpEXECUTE:
        {
            // Is this an opcode?  If so, dispatch the opcode.  If not,
            // set W to the CFA of the address of the CFA and jump to
            // the CFA.
            if (tos.u < 128)
            {
                op = tos.u;
                tos = *restDataStack++;
                goto DISPATCH_OPCODE;
            }
            else
            {
                // TODO Implement this.
                tos = *restDataStack++;
            }
        }
        continue;

        arfOpFETCH:
        {
            tos = *(arfCell*)tos.p;
        }
        continue;

        arfOpLITERAL:
        {
            // TODO Implement this.
        }
        continue;

        // -------------------------------------------------------------
        // NUMBER? [ARF] "number-question" ( c-addr u -- c-addr u 0 | n -1 )
        //
        // Attempt to convert a string at c-addr of length u into
        // digits, using the radix in BASE.  The number and -1 is
        // returned if the conversion was successful, otherwise 0 is
        // returned.
        arfOpNUMBERQ:
        {
            arfUnsigned u = tos.u;
            uint8_t * caddr = (uint8_t*)restDataStack->p;

            arfInt n;
            if (this->parenNumberQ(caddr, u, n))
            {
                // Stack still contains c-addr u; rewrite to n -1.
                restDataStack->i = n;
                tos.i = -1;
            }
            else
            {
                // Stack still contains c-addr u, so just push 0.
                *--restDataStack = tos;
                tos.i = 0;
            }
        }
        continue;

        arfOpOR:
        {
            tos.i |= restDataStack++->i;
        }
        continue;

        // -------------------------------------------------------------
        // PARSE-WORD [ARF] ( "<spaces>name<space>" -- c-addr u )
        //
        // Skip leading spaces and parse name delimited by a space.
        // c-addr is the address within the input buffer and u is the
        // length of the selected string. If the parse area is empty,
        // the resulting string has a zero length.
        arfOpPARSEWORD:
        {
            *--restDataStack = tos;

            uint8_t * caddr;
            arfUnsigned u;
            parenParseWord(' ', caddr, u);
            (--restDataStack)->p = caddr;
            tos.u = u;
        }
        continue;

        // -------------------------------------------------------------
        // FIND-WORD [ARF] "paren-find-paren" ( c-addr u -- c-addr u 0 | xt 1 | xt -1 )
        //
        // Find the definition named in the string at c-addr with length
        // u in the word list whose latest definition is pointed to by
        // nfa.  If the definition is not found, return the string and
        // zero.  If the definition is found, return its execution token
        // xt.  If the definition is immediate, also return one (1),
        // otherwise also return minus-one (-1).  For a given string,
        // the values returned by FIND-WORD while compiling may differ
        // from those returned while not compiling.
        arfOpFINDWORD:
        {
            uint8_t * caddr = (uint8_t *)restDataStack->p;
            arfUnsigned u = tos.u;

            arfUnsigned xt;
            bool isImmediate;
            if (parenFindWord(caddr, u, xt, isImmediate))
            {
                // Stack still contains c-addr u; rewrite to xt 1|-1.
                restDataStack->u = xt;
                tos.i = isImmediate ? 1 : -1;
            }
            else
            {
                // Stack still contains c-addr u, so just push 0.
                *--restDataStack = tos;
                tos.i = 0;
            }
        }
        continue;

        arfOpQDUP:
        {
            if (tos.i != 0)
            {
                *--restDataStack = tos;
            }
        }
        continue;

        arfOpSPACE:
        {
            if (this->emit != NULL)
            {
                this->emit(' ');
            }
        }
        continue;

        arfOpSTATE:
        {
            *--restDataStack = tos;
            tos.p = &this->state;
        }
        continue;

        // -------------------------------------------------------------
        // ! [CORE] 6.1.0010 "store" ( x a-addr -- )
        //
        // Store x at a-addr.
        arfOpSTORE:
        {
            *(arfCell*)tos.p = *restDataStack++;
            tos = *restDataStack++;
        }
        continue;

        // -------------------------------------------------------------
        // >IN [CORE] 6.1.0560 "to-in" ( -- a-addr )
        //
        // a-addr is the address of a cell containing the offset in
        // characters from the start of the input buffer to the start of
        // the parse area.
        arfOpTOIN:
        {
            *--restDataStack = tos;
            tos.p = &this->toIn;
        }
        continue;

        arfOpTWODROP:
        {
            restDataStack++;
            tos = *restDataStack++;
        }
        continue;

        arfOpTYPE:
        {
            if (this->emit != NULL)
            {
                for (int i = 0; i < tos.i; i++)
                {
                    this->emit(*((uint8_t*)restDataStack->p + i));
                }
            }

            restDataStack++;
            tos = *restDataStack++;
        }
        continue;

        arfOpZBRANCH:
        {
            if (tos.i == 0)
            {
                ip = ip + *(int8_t*)ip;
            }
            else
            {
                ip++;
            }

            tos = *restDataStack++;
        }
        continue;

        arfOpZERO:
        {
            *--restDataStack = tos;
            tos.i = 0;
        }
        continue;

        arfOpZEROEQUALS:
        {
            tos.i = tos.i == 0 ? -1 : 0;
        }
        continue;

        // -------------------------------------------------------------
        // QUIT [CORE] 6.1.2050 ( -- ) ( R:  i*x -- )
        //
        // Empty the return stack, store zero in SOURCE-ID if it is
        // present, make the user input device the input source, and
        // enter interpretation state.  Do not display a message.
        // Repeat the following:
        //   - Accept a line from the input source into the input
        //     buffer, set >IN to zero, and interpret.
        //   - Display the implementation-defined system prompt if in
        //     interpretation state, all processing has been completed,
        //     and no ambiguous condition exists.
        arfOpQUIT:
        {
            returnTop = (arfCell *)&this->returnStack[32];
            this->state = 0;
            ip = parenQuit + CFASZ;
        }
        continue;

        arfOpTIB:
        {
            *--restDataStack = tos;
            tos.p = &this->tib;
        }
        continue;

        arfOpTIBSIZE:
        {
            *--restDataStack = tos;
            tos.u = sizeof(this->tib);
        }
        continue;

        // -------------------------------------------------------------
        // ACCEPT [CORE] 6.1.0695 ( c-addr +n1 -- +n2 )
        //
        // Receive a string of at most +n1 characters.  An ambiguous
        // condition exists if +n1 is zero or greater than 32,767.
        // Display graphic characters as they are received.  A program
        // that depends on the presence or absence of non-graphic
        // characters in the string has an environmental dependency.
        // The editing functions, if any, that the system performs in
        // order to construct the string are implementation-defined.
        //
        // Input terminates when an implementation-defined line
        // terminator is received.  When input terminates, nothing is
        // appended to the string, and the display is maintained in an
        // implementation-defined way.
        //
        // +n2 is the length of the string stored at c-addr.
        arfOpACCEPT:
        {
            arfCell n1 = tos;
            arfCell caddr = *restDataStack++;
            tos.u = parenAccept((uint8_t *)caddr.p, n1.u);
        }
        continue;

        arfOpINTERPRET: // ( i*x c-addr u -- j*x)
        {
            this->source = (uint8_t *)restDataStack++->p;
            this->sourceLen = tos.u;
            tos = *restDataStack++;
            (--returnTop)->p = (void *)ip;
            ip = parenInterpret + CFASZ;
        }
        continue;

        // -------------------------------------------------------------
        // (s") [ARF] "paren-s-quote-paren" ( -- c-addr u )
        //
        // Runtime behavior of S": return c-addr and u.
        arfOpPSQUOTE:
        {
            // Push existing TOS onto the stack.
            *--restDataStack = tos;

            // Instruction stream contains the length of the string as a
            // byte and then the string itself.  Start out by pushing
            // the address of the string (ip+1) onto the stack.
            (--restDataStack)->p = ip + 1;

            // Now get the string length into TOS.
            tos.i = *ip++;

            // Advance IP over the string.
            ip = ip + tos.i;
        }
        continue;

        arfOpBL:
        {
            *--restDataStack = tos;
            tos.u = ' ';
        }
        continue;

        arfOpCFETCH:
        {
            tos.u = *(uint8_t*)tos.p;
        }
        continue;

        arfOpCOUNT:
        {
            (--restDataStack)->p = (uint8_t*)tos.p + 1;
            tos.u = *(uint8_t*)tos.p;
        }
        continue;

        // -------------------------------------------------------------
        // >NUMBER [CORE] 6.1.0567 "to-number" ( ud1 c-addr1 u1 -- ud2 c-addr2 u2 )
        //
        // ud2 is the unsigned result of converting the characters
        // within the string specified by c-addr1 u1 into digits, using
        // the number in BASE, and adding each into ud1 after
        // multiplying ud1 by the number in BASE.  Conversion continues
        // left-to-right until a character that is not convertible,
        // including any "+" or "-", is encountered or the string is
        // entirely converted.  c-addr2 is the location of the first
        // unconverted character or the first character past the end of
        // the string if the string was entirely converted.  u2 is the
        // number of unconverted characters in the string.  An ambiguous
        // condition exists if ud2 overflows during the conversion.
        arfOpTONUMBER:
        {
            arfUnsigned u = tos.u;
            uint8_t * caddr = (uint8_t*)restDataStack[0].p;
            arfUnsigned ud = restDataStack[-1].u;

            parenToNumber(ud, caddr, u);

            restDataStack[-1].u = ud;
            restDataStack[0].p = caddr;
            tos.u = u;
        }
        continue;

        // -------------------------------------------------------------
        // DEPTH [CORE] 6.1.1200 ( -- +n )
        //
        // +n is the number of single-cell values contained in the data
        // stack before +n was placed on the stack.
        arfOpDEPTH:
        {
            *--restDataStack = tos;
            tos.i = &this->dataStack[32] - restDataStack - 1;
        }
        continue;

        // -------------------------------------------------------------
        // . [CORE] 6.1.0180 "dot" ( n -- )
        //
        // Display n in free field format.
        arfOpDOT:
        {
            if (this->emit != NULL)
            {
                // FIXME These numbers are printing backwards; we
                // probably need to implement pictured numeric output.
                // FIXME Use BASE.
                do
                {
                    arfInt i = tos.i - ((tos.i / 10) * 10);
                    this->emit('0' + i);
                    tos.i = tos.i / 10;
                } while (tos.i != 0);

                this->emit(' ');
            }

            tos = *restDataStack++;
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
            // Note that offsets are 16-bit values regardless of the
            // platform's word size.
            arfInt relativeOffset = (op << 8) | *ip++;
            arfCell * w = (arfCell*)(ip + relativeOffset);

            // Indirect threading: jump to the CFA.
            goto *(void *)(w->p);

            DOCOLON:
                // IP currently points to the next word in the PFA and that
                // is the location to which we should return once this new
                // word has executed.
                (--returnTop)->p = (void *)ip;

                // Now skip over the CFA and begin executing the thread in
                // the Parameter Field Address.
                ip = (uint8_t *)w + CFASZ;

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
