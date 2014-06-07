#include <enforth.h>


// FFI definitions
ENFORTH_EXTERN(delay, delay, 2)
#undef LAST_FFI
#define LAST_FFI GET_LAST_FFI(delay)

ENFORTH_EXTERN(digitalWrite, digitalWrite, 2)
#undef LAST_FFI
#define LAST_FFI GET_LAST_FFI(digitalWrite)

ENFORTH_EXTERN(pinMode, pinMode, 2)
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

unsigned char enforthDict[512];
ENFORTH enforth(
  enforthDict, sizeof(enforthDict),
  LAST_FFI,
  serialKeyQ, serialKey, serialEmit);


void setup()
{
  Serial.begin(9600);

  /* Add a couple of hand-coded definitions. */
  const uint8_t favnumDef[] = {
    0x00, // DOCOLON
    'F',
    'A',
    'V',
    'N',
    'U',
    0x80 | 'M',
    0x0b,   // CHARLIT
    27,
    0x7f }; // EXIT
  enforth.addDefinition(favnumDef, sizeof(favnumDef));

  const uint8_t twoxDef[] = {
    0x00, // DOCOLON
    '2',
    0x80 | 'X',
    0x02,   // DUP
    0x04,   // +
    0x7f }; // EXIT
  enforth.addDefinition(twoxDef, sizeof(twoxDef));

  const uint8_t delayDef[] = {
    0x08, // DOFFI2
    (uint8_t)(((uint16_t)&FFIDEF_delay      ) & 0xff),  // FFIdef LSB
    (uint8_t)(((uint16_t)&FFIDEF_delay >>  8) & 0xff)}; // FFIdef MSB
  enforth.addDefinition(delayDef, sizeof(delayDef));

  const uint8_t digitalWriteDef[] = {
    0x08, // DOFFI2
    (uint8_t)(((uint16_t)&FFIDEF_digitalWrite      ) & 0xff),  // FFIdef LSB
    (uint8_t)(((uint16_t)&FFIDEF_digitalWrite >>  8) & 0xff)}; // FFIdef MSB
  enforth.addDefinition(digitalWriteDef, sizeof(digitalWriteDef));

  const uint8_t pinModeDef[] = {
    0x08, // DOFFI2
    (uint8_t)(((uint16_t)&FFIDEF_pinMode      ) & 0xff),  // FFIdef LSB
    (uint8_t)(((uint16_t)&FFIDEF_pinMode >>  8) & 0xff)}; // FFIdef MSB
  enforth.addDefinition(pinModeDef, sizeof(pinModeDef));
}

void loop()
{
  /* Launch the enforth interpreter. */
  enforth.go();
}
