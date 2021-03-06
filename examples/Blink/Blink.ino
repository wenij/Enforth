#include <EEPROM.h>

#include <enforth.h>


// FFI definitions
ENFORTH_EXTERN_VOID(digitalWrite, digitalWrite, 2)
#undef LAST_FFI
#define LAST_FFI GET_LAST_FFI(digitalWrite)

ENFORTH_EXTERN_METHOD(millis, { return (unsigned)millis(); }, 0)
#undef LAST_FFI
#define LAST_FFI GET_LAST_FFI(millis)

ENFORTH_EXTERN_VOID(pinMode, pinMode, 2)
#undef LAST_FFI
#define LAST_FFI GET_LAST_FFI(pinMode)


// FFI definitions for tests.
static int twoSeven()
{
    return 27;
}

static int doubleNumber(int num)
{
    return num + num;
}

ENFORTH_EXTERN(twoseven, twoSeven, 0)
#undef LAST_FFI
#define LAST_FFI GET_LAST_FFI(twoseven)

ENFORTH_EXTERN(dubnum, doubleNumber, 1)
#undef LAST_FFI
#define LAST_FFI GET_LAST_FFI(dubnum)


int serialKeyQ()
{
  return Serial.available();
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

int eepromLoad(uint8_t * dictionary, int size)
{
  if (size > 1024)
  {
    return 0;
  }

  for (int i = 0; i < size; i++)
  {
    dictionary[i] = EEPROM.read(i);
  }

  return -1;
}

int eepromSave(uint8_t * dictionary, int size)
{
  if (size > 1024)
  {
    return 0;
  }

  for (int i = 0; i < size; i++)
  {
    EEPROM.write(i, dictionary[i]);
  }

  return -1;
}

EnforthVM enforthVM;
unsigned char enforthDict[1024];


void setup()
{
  Serial.begin(9600);

  /* Initialize Enforth. */
  enforth_init(
    &enforthVM,
    enforthDict, sizeof(enforthDict),
    LAST_FFI,
    serialKeyQ, serialKey, serialEmit,
    eepromLoad, eepromSave);

  /* Add a couple of definitions. */
  enforth_evaluate(&enforthVM, ": favnum 27 ;");
  enforth_evaluate(&enforthVM, ": 2x dup + ;");

  /* Define the FACILITY-EXT word MS in terms of the FFI `millis`. */
  enforth_evaluate(&enforthVM, "USE: millis  : MS 1- millis BEGIN PAUSE 2DUP millis SWAP - < UNTIL 2DROP ;");
}

void loop()
{
  /* Launch the enforth interpreter. */
  enforth_go(&enforthVM);
}
