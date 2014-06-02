#include <MFORTH.h>


// FFI definitions
MFORTH_EXTERN(delay, delay, 2)
#undef LAST_FFI
#define LAST_FFI GET_LAST_FFI(delay)

MFORTH_EXTERN(digitalWrite, digitalWrite, 2)
#undef LAST_FFI
#define LAST_FFI GET_LAST_FFI(digitalWrite)

MFORTH_EXTERN(pinMode, pinMode, 2)
#undef LAST_FFI
#define LAST_FFI GET_LAST_FFI(pinMode)


bool serialKeyQ()
{
  return Serial.available() > 0;
}

char serialKey()
{
  while (true)
  {
    int b = Serial.read();
    if (b == -1)
    {
      continue;
    }
    else if (b == 0x0d)
    {
      return 0x0a;
    }
    else
    {
      return (char)b;
    }
  }
}

void serialEmit(char ch)
{
  if (ch == 0x0a)
  {
    Serial.write(0x0d);
  }

  Serial.write(ch);
}

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  /* Initial dictionary with a couple of hand-coded definitions. */
  unsigned char mforthDict[512];
  unsigned char * here = mforthDict;

  unsigned char * favnumLFA = here;
  *here++ = 0x00; // LFAlo; bogus LFA offset
  *here++ = 0x00; // LFAhi; bogus LFA offset
  *here++ = 0x00; // DOCOLON
  *here++ = 'F';
  *here++ = 'A';
  *here++ = 'V';
  *here++ = 'N';
  *here++ = 'U';
  *here++ = 0x80 | 'M';
  *here++ = 0x0b; // CHARLIT
  *here++ = 27;
  *here++ = 0x7f; // EXIT

  unsigned char * twoxLFA = here;
  *here++ = ((twoxLFA - favnumLFA)     ) & 0xff; // LFAlo
  *here++ = ((twoxLFA - favnumLFA) >> 8) & 0xff; // LFAhi
  *here++ = 0x00; // DOCOLON
  *here++ = '2';
  *here++ = 0x80 | 'X';
  *here++ = 0x02; // DUP
  *here++ = 0x04; // +
  *here++ = 0x7f; // EXIT

  unsigned char * delayLFA = here;
  *here++ = ((delayLFA - twoxLFA)     ) & 0xff; // LFAlo
  *here++ = ((delayLFA - twoxLFA) >> 8) & 0xff; // LFAhi
  *here++ = 0x08; // DOFFI2
  *here++ = ((uint16_t)&FFIDEF_delay     ) & 0xff; // FFIdef LSB
  *here++ = ((uint16_t)&FFIDEF_delay >> 8) & 0xff; // FFIdef MSB

  unsigned char * digitalWriteLFA = here;
  *here++ = ((digitalWriteLFA - delayLFA)     ) & 0xff; // LFAlo
  *here++ = ((digitalWriteLFA - delayLFA) >> 8) & 0xff; // LFAhi
  *here++ = 0x08; // DOFFI2
  *here++ = ((uint16_t)&FFIDEF_digitalWrite     ) & 0xff; // FFIdef LSB
  *here++ = ((uint16_t)&FFIDEF_digitalWrite >> 8) & 0xff; // FFIdef MSB

  unsigned char * pinModeLFA = here;
  *here++ = ((pinModeLFA - digitalWriteLFA)     ) & 0xff; // LFAlo
  *here++ = ((pinModeLFA - digitalWriteLFA) >> 8) & 0xff; // LFAhi
  *here++ = 0x08; // DOFFI2
  *here++ = ((uint16_t)&FFIDEF_pinMode     ) & 0xff; // FFIdef LSB
  *here++ = ((uint16_t)&FFIDEF_pinMode >> 8) & 0xff; // FFIdef MSB

  /* MFORTH VM */
  MFORTH mforth(mforthDict, sizeof(mforthDict),
          pinModeLFA - mforthDict, here - mforthDict,
          LAST_FFI,
          serialKeyQ, serialKey, serialEmit);

  /* Launch the MFORTH interpreter. */
  mforth.go();
}
