/* ACCEPT */
0x80|'T', 'P', 'E', 'C', 'C', 'A',
#define ROMDEF_ACCEPT 0xC006
6, 0x00,0x00, DOCOLONROM,
OVER, PLUS, OVER, KEY, DUP, ICHARLIT, 10, NOTEQUALS, IZBRANCH, 44, DUP, ICHARLIT, 8, EQUALS, OVER, ICHARLIT, 127, EQUALS, OR, IZBRANCH, 19, TWOOVER, DROP, NIP, OVER, NOTEQUALS, IZBRANCH, 10, ONEMINUS, ICHARLIT, 8, EMIT, 0xC9,0x91, ICHARLIT, 8, EMIT, IBRANCH, 13, DUP, TWOOVER, NOTEQUALS, IZBRANCH, 7, EMIT, OVER, CSTORE, ONEPLUS, IBRANCH, 2, TWODROP, IBRANCH, -49, DROP, NIP, SWAP, MINUS, EXIT,

/* AGAIN */
0x80|'N', 'I', 'A', 'G', 'A',
#define ROMDEF_AGAIN 0xC049
0x80|5, 0xC0,0x06, DOCOLONROM,
ICHARLIT, BRANCH, 0xC1,0x7B, 0xC5,0x8E, MINUS, 0xC0,0xCD, EXIT,

/* ALIGN */
0x80|'N', 'G', 'I', 'L', 'A',
#define ROMDEF_ALIGN 0xC05C
5, 0xC0,0x49, DOCOLONROM,
EXIT,

/* ALIGNED */
0x80|'D', 'E', 'N', 'G', 'I', 'L', 'A',
#define ROMDEF_ALIGNED 0xC068
7, 0xC0,0x5C, DOCOLONROM,
EXIT,

/* ALLOT */
0x80|'T', 'O', 'L', 'L', 'A',
#define ROMDEF_ALLOT 0xC072
5, 0xC0,0x68, DOCOLONROM,
0xC2,0x8B, PLUSSTORE, EXIT,

/* BACKSLASH */
0x80|'\\',
#define ROMDEF_BACKSLASH 0xC07B
0x80|1, 0xC0,0x72, DOCOLONROM,
0xC9,0x82, NIP, 0xCA,0x80, STORE, EXIT,

/* BASE */
0x80|'E', 'S', 'A', 'B',
#define ROMDEF_BASE 0xC08A
4, 0xC0,0x7B, DOCOLONROM,
VM, ICHARLIT, offsetof(EnforthVM, base), PLUS, EXIT,

/* BEGIN */
0x80|'N', 'I', 'G', 'E', 'B',
#define ROMDEF_BEGIN 0xC098
0x80|5, 0xC0,0x8A, DOCOLONROM,
0xC5,0x8E, EXIT,

/* BL */
0x80|'L', 'B',
#define ROMDEF_BL 0xC0A1
2, 0xC0,0x98, DOCOLONROM,
ICHARLIT, ' ', EXIT,

/* BRACKETCHAR */
0x80|']', 'R', 'A', 'H', 'C', '[',
#define ROMDEF_BRACKETCHAR 0xC0AE
0x80|6, 0xC0,0xA1, DOCOLONROM,
0xC0,0xFA, ICHARLIT, CHARLIT, 0xC1,0x7B, 0xC0,0xCD, EXIT,

/* BRACKETTICK */
0x80|']', '\'', '[',
#define ROMDEF_BRACKETTICK 0xC0BE
0x80|3, 0xC0,0xAE, DOCOLONROM,
0xCA,0x1F, ICHARLIT, LIT, 0xC1,0x7B, 0xC1,0x65, EXIT,

/* CCOMMA */
0x80|',', 'C',
#define ROMDEF_CCOMMA 0xC0CD
2, 0xC0,0xBE, DOCOLONROM,
0xC5,0x8E, CSTORE, ICHARLIT, 1, 0xC1,0x15, 0xC0,0x72, EXIT,

/* CELLPLUS */
0x80|'+', 'L', 'L', 'E', 'C',
#define ROMDEF_CELLPLUS 0xC0E0
5, 0xC0,0xCD, DOCOLONROM,
ICHARLIT, kEnforthCellSize, PLUS, EXIT,

/* CELLS */
0x80|'S', 'L', 'L', 'E', 'C',
#define ROMDEF_CELLS 0xC0ED
5, 0xC0,0xE0, DOCOLONROM,
ICHARLIT, kEnforthCellSize, 0xC9,0xC6, EXIT,

/* CHAR */
0x80|'R', 'A', 'H', 'C',
#define ROMDEF_CHAR 0xC0FA
4, 0xC0,0xED, DOCOLONROM,
0xC0,0xA1, 0xC7,0xD4, DROP, CFETCH, EXIT,

/* CHARPLUS */
0x80|'+', 'R', 'A', 'H', 'C',
#define ROMDEF_CHARPLUS 0xC10A
5, 0xC0,0xFA, DOCOLONROM,
ONEPLUS, EXIT,

/* CHARS */
0x80|'S', 'R', 'A', 'H', 'C',
#define ROMDEF_CHARS 0xC115
5, 0xC1,0x0A, DOCOLONROM,
EXIT,

/* CNOTSIMILAR */
0x80|'}', '{', 'C',
#define ROMDEF_CNOTSIMILAR 0xC11D
3, 0xC1,0x15, DOCOLONROM,
0xC1,0xEF, INVERT, EXIT,

/* COLD */
#define ROMDEF_COLD 0xC125
0, 0xC1,0x1D, DOCOLONROM,
PISQUOTE, 31, 'E', 'n', 'f', 'o', 'r', 't', 'h', ' ', '(', 'C', ')', ' ', 'M', 'i', 'c', 'h', 'a', 'e', 'l', ' ', 'A', 'l', 'y', 'n', ' ', 'M', 'i', 'l', 'l', 'e', 'r', 0xC6,0x64, 0xC1,0xB5, ABORT, EXIT,

/* COLON */
0x80|':',
#define ROMDEF_COLON 0xC151
1, 0xC1,0x25, DOCOLONROM,
0xC1,0xC3, 0xC5,0xBF, ZERO, ONEMINUS, 0xC0,0x72, ICHARLIT, DOCOLON, 0xC0,0xCD, 0xC9,0x0D, EXIT,

/* COMMA */
0x80|',',
#define ROMDEF_COMMA 0xC165
1, 0xC1,0x51, DOCOLONROM,
0xC5,0x8E, STORE, ICHARLIT, 1, 0xC0,0xED, 0xC0,0x72, EXIT,

/* COMPILECOMMA */
0x80|',', 'E', 'L', 'I', 'P', 'M', 'O', 'C',
#define ROMDEF_COMPILECOMMA 0xC17B
8, 0xC1,0x65, DOCOLONROM,
DUP, 0xCA,0x89, IZBRANCH, 5, 0xC0,0xCD, IBRANCH, 3, 0xCC,0x43, EXIT,

/* CONSTANT */
0x80|'T', 'N', 'A', 'T', 'S', 'N', 'O', 'C',
#define ROMDEF_CONSTANT 0xC193
8, 0xC1,0x7B, DOCOLONROM,
0xC1,0xC3, ZERO, ONEMINUS, 0xC0,0x72, ICHARLIT, DOCONSTANT, 0xC0,0xCD, 0xC1,0x65, EXIT,

/* COUNT */
0x80|'T', 'N', 'U', 'O', 'C',
#define ROMDEF_COUNT 0xC1A9
5, 0xC1,0x93, DOCOLONROM,
DUP, CFETCH, SWAP, ONEPLUS, SWAP, EXIT,

/* CR */
0x80|'R', 'C',
#define ROMDEF_CR 0xC1B5
2, 0xC1,0xA9, DOCOLONROM,
ICHARLIT, 10, EMIT, EXIT,

/* CREATE */
0x80|'E', 'T', 'A', 'E', 'R', 'C',
#define ROMDEF_CREATE 0xC1C3
6, 0xC1,0xB5, DOCOLONROM,
0xC0,0xA1, 0xC7,0xD4, DUP, ZEROEQUALS, IZBRANCH, 2, ABORT, 0xC5,0x8E, 0xCB,0x0A, 0xC6,0x8B, FETCH, 0xC6,0xC6, 0xC6,0x8B, STORE, DUP, 0xC0,0xCD, TUCK, 0xC5,0x8E, SWAP, MOVE, 0xC0,0x72, ICHARLIT, DOCREATE, 0xC0,0xCD, 0xC0,0x5C, EXIT,

/* CSIMILAR */
0x80|'~', 'C',
#define ROMDEF_CSIMILAR 0xC1EF
2, 0xC1,0xC3, DOCOLONROM,
0xCA,0xF5, SWAP, 0xCA,0xF5, EQUALS, EXIT,

/* DABS */
0x80|'S', 'B', 'A', 'D',
#define ROMDEF_DABS 0xC1FE
4, 0xC1,0xEF, DOCOLONROM,
DUP, 0xC8,0x65, EXIT,

/* DECIMAL */
0x80|'L', 'A', 'M', 'I', 'C', 'E', 'D',
#define ROMDEF_DECIMAL 0xC20D
7, 0xC1,0xFE, DOCOLONROM,
ICHARLIT, 10, 0xC0,0x8A, STORE, EXIT,

/* DIGITQ */
#define ROMDEF_DIGITQ 0xC217
0, 0xC2,0x0D, DOCOLONROM,
0xCA,0xF5, ICHARLIT, '0', MINUS, DUP, ZEROLESS, IZBRANCH, 4, DROP, ZERO, EXIT, DUP, ICHARLIT, 9, GREATERTHAN, IZBRANCH, 13, DUP, ICHARLIT, 17, LESSTHAN, IZBRANCH, 4, DROP, FALSE, EXIT, ICHARLIT, 7, MINUS, DUP, ONEPLUS, 0xC0,0x8A, FETCH, UGREATERTHAN, IZBRANCH, 4, DROP, FALSE, EXIT, TRUE, EXIT,

/* DNEGATE */
0x80|'E', 'T', 'A', 'G', 'E', 'N', 'D',
#define ROMDEF_DNEGATE 0xC24D
7, 0xC2,0x17, DOCOLONROM,
INVERT, SWAP, INVERT, SWAP, ICHARLIT, 1, MPLUS, EXIT,

/* DO */
0x80|'O', 'D',
#define ROMDEF_DO 0xC25B
0x80|2, 0xC2,0x4D, DOCOLONROM,
ZERO, 0xCA,0x37, STORE, ICHARLIT, PDO, 0xC1,0x7B, 0xC5,0x8E, EXIT,

/* DOT */
0x80|'.',
#define ROMDEF_DOT 0xC26B
1, 0xC2,0x5B, DOCOLONROM,
0xC0,0x8A, FETCH, ICHARLIT, 10, NOTEQUALS, IZBRANCH, 4, 0xCB,0x43, EXIT, DUP, ABS, ZERO, 0xC6,0xB9, 0xC7,0xB2, ROT, 0xC9,0x28, 0xC7,0x9F, 0xCB,0x1C, 0xC9,0x91, EXIT,

/* DP */
#define ROMDEF_DP 0xC28B
0, 0xC2,0x6B, DOCOLONROM,
VM, ICHARLIT, offsetof(EnforthVM, dp), PLUS, EXIT,

/* DUMP */
0x80|'P', 'M', 'U', 'D',
#define ROMDEF_DUMP 0xC298
4, 0xC2,0x8B, DOCOLONROM,
0xC0,0x8A, FETCH, TOR, 0xC5,0xB5, DUP, ZERO, PIQDO, 102, 0xC1,0xB5, OVER, I, PLUS, OVER, I, MINUS, ICHARLIT, 16, MIN, OVER, ZERO, 0xC6,0xB9, 0xC7,0x85, 0xC7,0x85, 0xC7,0x85, 0xC7,0x85, 0xC7,0x85, 0xC7,0x85, 0xC7,0x85, 0xC7,0x85, 0xC7,0x9F, 0xCB,0x1C, ICHARLIT, 2, 0xC9,0x9F, DUP, ZERO, PDO, OVER, I, PLUS, CFETCH, ZERO, 0xC6,0xB9, 0xC7,0x85, 0xC7,0x85, 0xC7,0x9F, 0xCB,0x1C, 0xC9,0x91, PILOOP, -18, ICHARLIT, 16, OVER, MINUS, ICHARLIT, 3, 0xC9,0xC6, 0xC9,0x9F, 0xC9,0x91, ZERO, PDO, DUP, I, PLUS, CFETCH, DUP, ICHARLIT, 32, LESSTHAN, OVER, ICHARLIT, 127, GREATERTHAN, OR, IZBRANCH, 4, DROP, ICHARLIT, '.', EMIT, PILOOP, -20, DROP, ICHARLIT, 16, PIPLUSLOOP, -100, TWODROP, RFROM, 0xC0,0x8A, STORE, EXIT,

/* ELSE */
0x80|'E', 'S', 'L', 'E',
#define ROMDEF_ELSE 0xC315
0x80|4, 0xC2,0x98, DOCOLONROM,
ICHARLIT, BRANCH, 0xC1,0x7B, 0xC5,0x8E, ZERO, 0xC0,0xCD, SWAP, 0xCA,0x03, EXIT,

/* ENDLOOP */
#define ROMDEF_ENDLOOP 0xC326
0, 0xC3,0x15, DOCOLONROM,
0xC1,0x7B, 0xC5,0x8E, MINUS, 0xC0,0xCD, 0xCA,0x37, FETCH, 0xC5,0x96, EXIT,

/* EVALUATE */
#define ROMDEF_EVALUATE 0xC337
0, 0xC3,0x26, DOCOLONROM,
0xC6,0x20, EXIT,

/* EXECUTE */
0x80|'E', 'T', 'U', 'C', 'E', 'X', 'E',
#define ROMDEF_EXECUTE 0xC345
7, 0xC3,0x37, DOCOLONROM,
DUP, 0xCA,0xD8, SWAP, 0xCA,0x45, PEXECUTE, EXIT,

/* FFIDEFARITY */
#define ROMDEF_FFIDEFARITY 0xC351
0, 0xC3,0x45, DOCOLONROM,
ICHARLIT, offsetof(EnforthFFIDef, arity), PLUS, ICFETCH, EXIT,

/* FFIDEFNAME */
#define ROMDEF_FFIDEFNAME 0xC35A
0, 0xC3,0x51, DOCOLONROM,
ICHARLIT, offsetof(EnforthFFIDef, name), PLUS, IFETCH, EXIT,

/* FFIDEFNAMELEN */
#define ROMDEF_FFIDEFNAMELEN 0xC363
0, 0xC3,0x5A, DOCOLONROM,
0xC3,0x5A, DUP, DUP, ICFETCH, IZBRANCH, 4, ONEPLUS, IBRANCH, -6, SWAP, MINUS, EXIT,

/* FFIQ */
#define ROMDEF_FFIQ 0xC374
0, 0xC3,0x63, DOCOLONROM,
0xCA,0x92, ONEPLUS, ONEPLUS, CFETCH, ICHARLIT, 32, AND, ZERONOTEQUALS, EXIT,

/* FFIS */
0x80|'S', 'I', 'F', 'F',
#define ROMDEF_FFIS 0xC386
4, 0xC3,0x74, DOCOLONROM,
VM, ICHARLIT, offsetof(EnforthVM, last_ffi), PLUS, FETCH, QDUP, IZBRANCH, 14, DUP, 0xC3,0x5A, OVER, 0xC3,0x63, 0xC6,0x64, 0xC9,0x91, IFETCH, IBRANCH, -15, EXIT,

/* FIND */
0x80|'D', 'N', 'I', 'F',
#define ROMDEF_FIND 0xC3A4
4, 0xC3,0x86, DOCOLONROM,
0xC1,0xA9, 0xC4,0x57, EXIT,

/* FINDCODEPRIM */
#define ROMDEF_FINDCODEPRIM 0xC3AD
0, 0xC3,0xA4, DOCOLONROM,
TWOTOR, ZERO, TICKNAMES, DUP, ICFETCH, ICHARLIT, 255, NOTEQUALS, IZBRANCH, 28, DUP, TWORFETCH, ROT, 0xC5,0x1F, IZBRANCH, 14, DROP, ICFETCH, ICHARLIT, 128, AND, ZERONOTEQUALS, ICHARLIT, 2, AND, ONEMINUS, TWORFROM, TWODROP, EXIT, ROT, ONEPLUS, ROT, DROP, SWAP, IBRANCH, -33, TWODROP, TWORFROM, TWODROP, FALSE, EXIT,

/* FINDDEF */
#define ROMDEF_FINDDEF 0xC3DB
0, 0xC3,0xAD, DOCOLONROM,
TWOTOR, 0xC6,0x8B, FETCH, QDUP, IZBRANCH, 31, DUP, TWORFETCH, ROT, 0xC4,0xAE, IZBRANCH, 18, DUP, 0xCA,0x92, ONEPLUS, ONEPLUS, CFETCH, ICHARLIT, 128, AND, ZERONOTEQUALS, ICHARLIT, 2, AND, ONEMINUS, TWORFROM, TWODROP, EXIT, 0xCA,0x92, 0xCC,0x50, IBRANCH, -32, TWORFROM, TWODROP, FALSE, EXIT,

/* FINDFFIDEF */
#define ROMDEF_FINDFFIDEF 0xC408
0, 0xC3,0xDB, DOCOLONROM,
TWOTOR, VM, ICHARLIT, offsetof(EnforthVM, last_ffi), PLUS, FETCH, QDUP, IZBRANCH, 22, RFETCH, OVER, 0xC3,0x63, EQUALS, IZBRANCH, 12, DUP, TWORFETCH, ROT, 0xC4,0xF3, IZBRANCH, 5, TWORFROM, TWODROP, TRUE, EXIT, IFETCH, IBRANCH, -23, TWORFROM, TWODROP, FALSE, EXIT,

/* FINDROMDEF */
#define ROMDEF_FINDROMDEF 0xC42E
0, 0xC4,0x08, DOCOLONROM,
TWOTOR, LASTROMDEF, QDUP, IZBRANCH, 29, DUP, TWORFETCH, ROT, 0xC5,0x53, IZBRANCH, 16, DUP, 0xC9,0x02, ICFETCH, ICHARLIT, 128, AND, ZERONOTEQUALS, ICHARLIT, 2, AND, ONEMINUS, TWORFROM, TWODROP, EXIT, 0xC8,0xFA, 0xC6,0x77, IBRANCH, -30, TWORFROM, TWODROP, FALSE, EXIT,

/* FINDWORD */
#define ROMDEF_FINDWORD 0xC457
0, 0xC4,0x2E, DOCOLONROM,
TWODUP, 0xC3,0xDB, QDUP, IZBRANCH, 4, TWOSWAP, TWODROP, EXIT, TWODUP, 0xC3,0xAD, QDUP, IZBRANCH, 4, TWOSWAP, TWODROP, EXIT, TWODUP, 0xC4,0x2E, DUP, IZBRANCH, 3, TWOSWAP, TWODROP, EXIT,

/* FMSLASHMOD */
0x80|'D', 'O', 'M', '/', 'M', 'F',
#define ROMDEF_FMSLASHMOD 0xC47C
6, 0xC4,0x57, DOCOLONROM,
DUP, TOR, TWODUP, XOR, SWAP, ABS, DUP, TOR, SWAP, TOR, TOR, 0xC1,0xFE, RFROM, UMSLASHMOD, RFROM, ZEROLESS, IZBRANCH, 18, NEGATE, OVER, ZERONOTEQUALS, IZBRANCH, 9, ONEMINUS, SWAP, RFROM, SWAP, MINUS, SWAP, IBRANCH, 7, RFROM, DROP, IBRANCH, 3, RFROM, DROP, RFROM, ZEROLESS, IZBRANCH, 4, SWAP, NEGATE, SWAP, EXIT,

/* FOUNDDEFQ */
#define ROMDEF_FOUNDDEFQ 0xC4AE
0, 0xC4,0x7C, DOCOLONROM,
DUP, 0xCA,0x92, ONEPLUS, ONEPLUS, CFETCH, ICHARLIT, 64, AND, ZERONOTEQUALS, IZBRANCH, 5, DROP, TWODROP, FALSE, EXIT, TWODUP, 0xC7,0x29, NOTEQUALS, IZBRANCH, 5, DROP, TWODROP, FALSE, EXIT, DUP, 0xC3,0x74, IZBRANCH, 4, 0xC5,0x16, EXIT, 0xCA,0xA0, SWAP, QDUP, IZBRANCH, 23, ONEMINUS, TOR, OVER, CFETCH, OVER, CFETCH, 0xC1,0x1D, IZBRANCH, 6, TWODROP, RFROM, DROP, FALSE, EXIT, ONEPLUS, SWAP, ONEPLUS, SWAP, RFROM, IBRANCH, -24, TWODROP, TRUE, EXIT,

/* FOUNDFFIDEFQ */
#define ROMDEF_FOUNDFFIDEFQ 0xC4F3
0, 0xC4,0xAE, DOCOLONROM,
0xC3,0x5A, SWAP, QDUP, IZBRANCH, 23, ONEMINUS, TOR, OVER, CFETCH, OVER, ICFETCH, 0xC1,0x1D, IZBRANCH, 6, TWODROP, RFROM, DROP, FALSE, EXIT, ONEPLUS, SWAP, ONEPLUS, SWAP, RFROM, IBRANCH, -24, TWODROP, TRUE, EXIT,

/* FOUNDFFIQ */
#define ROMDEF_FOUNDFFIQ 0xC516
0, 0xC4,0xF3, DOCOLONROM,
0xCA,0x75, 0xC4,0xF3, EXIT,

/* FOUNDPRIMQ */
#define ROMDEF_FOUNDPRIMQ 0xC51F
0, 0xC5,0x16, DOCOLONROM,
DUP, DUP, ICFETCH, ICHARLIT, 31, AND, PLUS, ONEPLUS, TOR, DUP, ICFETCH, ICHARLIT, 31, AND, ROT, NOTEQUALS, IZBRANCH, 5, TWODROP, RFROM, FALSE, EXIT, ONEPLUS, OVER, CFETCH, OVER, ICFETCH, 0xC1,0x1D, IZBRANCH, 5, TWODROP, RFROM, FALSE, EXIT, ONEPLUS, SWAP, ONEPLUS, SWAP, DUP, RFETCH, EQUALS, IZBRANCH, -20, TWODROP, RFROM, TRUE, EXIT,

/* FOUNDROMDEFQ */
#define ROMDEF_FOUNDROMDEFQ 0xC553
0, 0xC5,0x1F, DOCOLONROM,
TWODUP, 0xC8,0xE6, NOTEQUALS, IZBRANCH, 5, DROP, TWODROP, FALSE, EXIT, 0xC9,0x02, ONEMINUS, SWAP, QDUP, IZBRANCH, 26, ONEMINUS, TOR, OVER, CFETCH, OVER, ICFETCH, ICHARLIT, 127, AND, 0xC1,0x1D, IZBRANCH, 6, TWODROP, RFROM, DROP, FALSE, EXIT, ONEMINUS, SWAP, ONEPLUS, SWAP, RFROM, IBRANCH, -27, TWODROP, TRUE, EXIT,

/* HALT */
#define ROMDEF_HALT 0xC584
0, 0xC5,0x53, DOCOLONROM,
PHALT, EXIT,

/* HERE */
0x80|'E', 'R', 'E', 'H',
#define ROMDEF_HERE 0xC58E
4, 0xC5,0x84, DOCOLONROM,
0xC2,0x8B, FETCH, EXIT,

/* HERETOCHAIN */
#define ROMDEF_HERETOCHAIN 0xC596
0, 0xC5,0x8E, DOCOLONROM,
QDUP, IZBRANCH, 21, DUP, CFETCH, OVER, DUP, 0xC5,0x8E, SWAP, MINUS, SWAP, CSTORE, QDUP, IZBRANCH, 4, MINUS, IBRANCH, 3, DROP, ZERO, IBRANCH, -22, EXIT,

/* HEX */
0x80|'X', 'E', 'H',
#define ROMDEF_HEX 0xC5B5
3, 0xC5,0x96, DOCOLONROM,
ICHARLIT, 16, 0xC0,0x8A, STORE, EXIT,

/* HIDE */
#define ROMDEF_HIDE 0xC5BF
0, 0xC5,0xB5, DOCOLONROM,
0xC6,0x8B, FETCH, 0xCA,0x92, ONEPLUS, ONEPLUS, DUP, CFETCH, ICHARLIT, 64, OR, SWAP, CSTORE, EXIT,

/* HLD */
#define ROMDEF_HLD 0xC5D2
0, 0xC5,0xBF, DOCOLONROM,
VM, ICHARLIT, offsetof(EnforthVM, hld), PLUS, EXIT,

/* HLDEND */
#define ROMDEF_HLDEND 0xC5DB
0, 0xC5,0xD2, DOCOLONROM,
ICHARLIT, kEnforthCellSize * 8 * 3, EXIT,

/* HOLD */
0x80|'D', 'L', 'O', 'H',
#define ROMDEF_HOLD 0xC5E6
4, 0xC5,0xDB, DOCOLONROM,
0xC5,0xD2, FETCH, ONEMINUS, DUP, 0xC5,0xD2, STORE, CSTORE, EXIT,

/* IF */
0x80|'F', 'I',
#define ROMDEF_IF 0xC5F6
0x80|2, 0xC5,0xE6, DOCOLONROM,
ICHARLIT, ZBRANCH, 0xC1,0x7B, 0xC5,0x8E, ZERO, 0xC0,0xCD, EXIT,

/* IMMEDIATE */
0x80|'E', 'T', 'A', 'I', 'D', 'E', 'M', 'M', 'I',
#define ROMDEF_IMMEDIATE 0xC60D
9, 0xC5,0xF6, DOCOLONROM,
0xC6,0x8B, FETCH, 0xCA,0x92, ONEPLUS, ONEPLUS, DUP, CFETCH, ICHARLIT, 128, OR, SWAP, CSTORE, EXIT,

/* INTERPRET */
#define ROMDEF_INTERPRET 0xC620
0, 0xC6,0x0D, DOCOLONROM,
VM, ICHARLIT, offsetof(EnforthVM, source_len), PLUS, TWOSTORE, ZERO, 0xCA,0x80, STORE, 0xC0,0xA1, 0xC7,0xD4, DUP, IZBRANCH, 47, 0xC4,0x57, QDUP, IZBRANCH, 17, ONEPLUS, 0xC9,0xEC, FETCH, ZEROEQUALS, OR, IZBRANCH, 5, 0xC3,0x45, IBRANCH, 28, 0xC1,0x7B, IBRANCH, 24, 0xC7,0x46, IZBRANCH, 10, 0xC9,0xEC, FETCH, IZBRANCH, 15, 0xC6,0xDA, IBRANCH, 11, 0xCB,0x1C, 0xC9,0x91, ICHARLIT, '?', EMIT, 0xC1,0xB5, ABORT, IBRANCH, -52, TWODROP, EXIT,

/* ITYPE */
#define ROMDEF_ITYPE 0xC664
0, 0xC6,0x20, DOCOLONROM,
OVER, PLUS, SWAP, TWODUP, NOTEQUALS, IZBRANCH, 7, DUP, ICFETCH, EMIT, ONEPLUS, IBRANCH, -9, TWODROP, EXIT,

/* IXTFETCH */
#define ROMDEF_IXTFETCH 0xC677
0, 0xC6,0x64, DOCOLONROM,
DUP, ICFETCH, ICHARLIT, 8, LSHIFT, SWAP, ONEPLUS, ICFETCH, OR, EXIT,

/* LATEST */
0x80|'T', 'S', 'E', 'T', 'A', 'L',
#define ROMDEF_LATEST 0xC68B
6, 0xC6,0x77, DOCOLONROM,
VM, ICHARLIT, offsetof(EnforthVM, latest), PLUS, EXIT,

/* LEAVE */
0x80|'E', 'V', 'A', 'E', 'L',
#define ROMDEF_LEAVE 0xC699
0x80|5, 0xC6,0x8B, DOCOLONROM,
ICHARLIT, UNLOOP, 0xC1,0x7B, ICHARLIT, BRANCH, 0xC1,0x7B, 0xC5,0x8E, 0xCA,0x37, FETCH, DUP, IZBRANCH, 5, 0xC5,0x8E, SWAP, MINUS, 0xC0,0xCD, 0xCA,0x37, STORE, EXIT,

/* LESSNUMSIGN */
0x80|'#', '<',
#define ROMDEF_LESSNUMSIGN 0xC6B9
2, 0xC6,0x99, DOCOLONROM,
0xC5,0x8E, 0xC5,0xDB, PLUS, 0xC5,0xD2, STORE, EXIT,

/* LFACOMMA */
#define ROMDEF_LFACOMMA 0xC6C6
0, 0xC6,0xB9, DOCOLONROM,
DUP, 0xC0,0xCD, ICHARLIT, 8, RSHIFT, 0xC0,0xCD, EXIT,

/* LITERAL */
0x80|'L', 'A', 'R', 'E', 'T', 'I', 'L',
#define ROMDEF_LITERAL 0xC6DA
0x80|7, 0xC6,0xC6, DOCOLONROM,
DUP, ICHARLIT, 255, INVERT, AND, ZEROEQUALS, IZBRANCH, 9, ICHARLIT, CHARLIT, 0xC0,0xCD, 0xC0,0xCD, IBRANCH, 7, ICHARLIT, LIT, 0xC0,0xCD, 0xC1,0x65, EXIT,

/* LOOP */
0x80|'P', 'O', 'O', 'L',
#define ROMDEF_LOOP 0xC6F9
0x80|4, 0xC6,0xDA, DOCOLONROM,
ICHARLIT, PLOOP, 0xC3,0x26, EXIT,

/* LTBRACKET */
0x80|'[',
#define ROMDEF_LTBRACKET 0xC703
0x80|1, 0xC6,0xF9, DOCOLONROM,
FALSE, 0xC9,0xEC, STORE, EXIT,

/* MOD */
0x80|'D', 'O', 'M',
#define ROMDEF_MOD 0xC70F
3, 0xC7,0x03, DOCOLONROM,
0xC9,0x41, DROP, EXIT,

/* MSTAR */
0x80|'*', 'M',
#define ROMDEF_MSTAR 0xC719
2, 0xC7,0x0F, DOCOLONROM,
TWODUP, XOR, ZEROLESS, TOR, ABS, SWAP, ABS, UMSTAR, RFROM, 0xC8,0x65, EXIT,

/* NAMELENGTH */
#define ROMDEF_NAMELENGTH 0xC729
0, 0xC7,0x19, DOCOLONROM,
0xCA,0x92, ONEPLUS, ONEPLUS, CFETCH, ICHARLIT, 31, AND, EXIT,

/* NFALENGTH */
#define ROMDEF_NFALENGTH 0xC736
0, 0xC7,0x29, DOCOLONROM,
DUP, 0xC3,0x74, IZBRANCH, 5, DROP, ZERO, IBRANCH, 3, 0xC7,0x29, EXIT,

/* NUMBERQ */
#define ROMDEF_NUMBERQ 0xC746
0, 0xC7,0x36, DOCOLONROM,
OVER, CFETCH, DUP, ICHARLIT, '-', EQUALS, OVER, ICHARLIT, '+', EQUALS, OR, IZBRANCH, 18, ICHARLIT, '-', EQUALS, IZBRANCH, 4, TRUE, IBRANCH, 2, FALSE, TOR, ICHARLIT, 1, 0xC9,0x53, RFROM, IBRANCH, 3, DROP, ZERO, TOR, TWODUP, ZERO, ZERO, TWOSWAP, 0xCA,0xB1, IZBRANCH, 8, DROP, TWODROP, RFROM, DROP, ZERO, IBRANCH, 10, DROP, TWONIP, DROP, RFROM, ZEROLESS, IZBRANCH, 2, NEGATE, TRUE, EXIT,

/* NUMSIGN */
0x80|'#',
#define ROMDEF_NUMSIGN 0xC785
1, 0xC7,0x46, DOCOLONROM,
0xC0,0x8A, FETCH, 0xCB,0x53, ROT, DUP, ICHARLIT, 9, GREATERTHAN, ICHARLIT, 7, AND, PLUS, ICHARLIT, 48, PLUS, 0xC5,0xE6, EXIT,

/* NUMSIGNGRTR */
0x80|'>', '#',
#define ROMDEF_NUMSIGNGRTR 0xC79F
2, 0xC7,0x85, DOCOLONROM,
DROP, DROP, 0xC5,0xD2, FETCH, 0xC5,0x8E, 0xC5,0xDB, PLUS, OVER, MINUS, EXIT,

/* NUMSIGNS */
0x80|'S', '#',
#define ROMDEF_NUMSIGNS 0xC7B2
2, 0xC7,0x9F, DOCOLONROM,
0xC7,0x85, TWODUP, OR, IZBRANCH, 3, IBRANCH, -7, EXIT,

/* PAREN */
0x80|'(',
#define ROMDEF_PAREN 0xC7C0
0x80|1, 0xC7,0xB2, DOCOLONROM,
ICHARLIT, ')', 0xC7,0xD4, TWODROP, EXIT,

/* PARSEWORD */
0x80|'D', 'R', 'O', 'W', '-', 'E', 'S', 'R', 'A', 'P',
#define ROMDEF_PARSEWORD 0xC7D4
10, 0xC7,0xC0, DOCOLONROM,
TOR, 0xC9,0x82, 0xCA,0x80, FETCH, 0xC9,0x53, RFETCH, TOR, OVER, CFETCH, RFETCH, EQUALS, OVER, AND, IZBRANCH, 7, ICHARLIT, 1, 0xC9,0x53, IBRANCH, -13, RFROM, DROP, OVER, SWAP, RFROM, TOR, DUP, ZEROEQUALS, IZBRANCH, 6, RFROM, TWODROP, FALSE, IBRANCH, 18, OVER, CFETCH, RFETCH, EQUALS, IZBRANCH, 6, RFROM, TWODROP, TRUE, IBRANCH, 7, ICHARLIT, 1, 0xC9,0x53, IBRANCH, -25, OVER, 0xC9,0x82, DROP, MINUS, SWAP, IZBRANCH, 2, ONEPLUS, 0xCA,0x80, STORE, OVER, MINUS, EXIT,

/* PLUSLOOP */
0x80|'P', 'O', 'O', 'L', '+',
#define ROMDEF_PLUSLOOP 0xC824
0x80|5, 0xC7,0xD4, DOCOLONROM,
ICHARLIT, PPLUSLOOP, 0xC3,0x26, EXIT,

/* POSTPONE */
0x80|'E', 'N', 'O', 'P', 'T', 'S', 'O', 'P',
#define ROMDEF_POSTPONE 0xC835
0x80|8, 0xC8,0x24, DOCOLONROM,
0xC0,0xA1, 0xC7,0xD4, 0xC4,0x57, QDUP, ZEROEQUALS, IZBRANCH, 11, 0xCB,0x1C, 0xC9,0x91, ICHARLIT, '?', EMIT, 0xC1,0xB5, ABORT, ZEROLESS, IZBRANCH, 19, ICHARLIT, LIT, 0xC1,0x7B, 0xC1,0x65, ICHARLIT, ((uint8_t)((ROMDEF_COMPILECOMMA >> 8) & 0xff)), ICHARLIT, 8, LSHIFT, ICHARLIT, ((uint8_t)((ROMDEF_COMPILECOMMA     ) & 0xff)), OR, 0xCC,0x43, IBRANCH, 3, 0xC1,0x7B, EXIT,

/* QDNEGATE */
#define ROMDEF_QDNEGATE 0xC865
0, 0xC8,0x35, DOCOLONROM,
ZEROLESS, IZBRANCH, 3, 0xC2,0x4D, EXIT,

/* QDO */
0x80|'O', 'D', '?',
#define ROMDEF_QDO 0xC872
0x80|3, 0xC8,0x65, DOCOLONROM,
ICHARLIT, PQDO, 0xC1,0x7B, 0xC5,0x8E, 0xCA,0x37, STORE, ZERO, 0xC0,0xCD, 0xC5,0x8E, EXIT,

/* QNEGATE */
#define ROMDEF_QNEGATE 0xC885
0, 0xC8,0x72, DOCOLONROM,
ZEROLESS, IZBRANCH, 2, NEGATE, EXIT,

/* QUIT */
0x80|'T', 'I', 'U', 'Q',
#define ROMDEF_QUIT 0xC892
4, 0xC8,0x85, DOCOLONROM,
INITRP, ZERO, 0xC9,0xEC, STORE, 0xCA,0x0E, DUP, 0xCA,0x17, 0xC0,0x06, 0xC9,0x91, 0xC6,0x20, 0xC1,0xB5, 0xC9,0xEC, FETCH, ZEROEQUALS, IZBRANCH, 8, PISQUOTE, 3, 'o', 'k', ' ', 0xC6,0x64, IBRANCH, -27,

/* REPEAT */
0x80|'T', 'A', 'E', 'P', 'E', 'R',
#define ROMDEF_REPEAT 0xC8BD
0x80|6, 0xC8,0x92, DOCOLONROM,
0xC0,0x49, 0xCA,0x03, EXIT,

/* REVEAL */
#define ROMDEF_REVEAL 0xC8C6
0, 0xC8,0xBD, DOCOLONROM,
0xC6,0x8B, FETCH, 0xCA,0x92, ONEPLUS, ONEPLUS, DUP, CFETCH, ICHARLIT, 191, AND, SWAP, CSTORE, EXIT,

/* ROMDEFQ */
#define ROMDEF_ROMDEFQ 0xC8D9
0, 0xC8,0xC6, DOCOLONROM,
ICHARLIT, 8, RSHIFT, ICHARLIT, 192, TUCK, AND, EQUALS, EXIT,

/* ROMNAMELENGTH */
#define ROMDEF_ROMNAMELENGTH 0xC8E6
0, 0xC8,0xD9, DOCOLONROM,
0xC9,0x02, ICFETCH, ICHARLIT, 31, AND, EXIT,

/* ROMXTTOCFA */
#define ROMDEF_ROMXTTOCFA 0xC8F1
0, 0xC8,0xE6, DOCOLONROM,
0xC8,0xFA, ONEPLUS, ONEPLUS, EXIT,

/* ROMXTTOLFA */
#define ROMDEF_ROMXTTOLFA 0xC8FA
0, 0xC8,0xF1, DOCOLONROM,
0xC9,0x02, ONEPLUS, EXIT,

/* ROMXTTONFA */
#define ROMDEF_ROMXTTONFA 0xC902
0, 0xC8,0xFA, DOCOLONROM,
0xCC,0x68, AND, TICKROMDEF, PLUS, EXIT,

/* RTBRACKET */
0x80|']',
#define ROMDEF_RTBRACKET 0xC90D
1, 0xC9,0x02, DOCOLONROM,
TRUE, 0xC9,0xEC, STORE, EXIT,

/* SEMICOLON */
0x80|';',
#define ROMDEF_SEMICOLON 0xC917
0x80|1, 0xC9,0x0D, DOCOLONROM,
ICHARLIT, EXIT, 0xC1,0x7B, 0xC8,0xC6, 0xC7,0x03, EXIT,

/* SIGN */
0x80|'N', 'G', 'I', 'S',
#define ROMDEF_SIGN 0xC928
4, 0xC9,0x17, DOCOLONROM,
ZEROLESS, IZBRANCH, 5, ICHARLIT, '-', 0xC5,0xE6, EXIT,

/* SLASH */
0x80|'/',
#define ROMDEF_SLASH 0xC935
1, 0xC9,0x28, DOCOLONROM,
0xC9,0x41, NIP, EXIT,

/* SLASHMOD */
0x80|'D', 'O', 'M', '/',
#define ROMDEF_SLASHMOD 0xC941
4, 0xC9,0x35, DOCOLONROM,
TOR, 0xC9,0xF8, RFROM, 0xC9,0x64, EXIT,

/* SLASHSTRING */
0x80|'G', 'N', 'I', 'R', 'T', 'S', '/',
#define ROMDEF_SLASHSTRING 0xC953
7, 0xC9,0x41, DOCOLONROM,
ROT, OVER, PLUS, ROT, ROT, MINUS, EXIT,

/* SMSLASHREM */
0x80|'M', 'E', 'R', '/', 'M', 'S',
#define ROMDEF_SMSLASHREM 0xC964
6, 0xC9,0x53, DOCOLONROM,
OVER, TOR, TWODUP, XOR, TOR, ABS, TOR, 0xC1,0xFE, RFROM, UMSLASHMOD, RFROM, 0xC8,0x85, SWAP, RFROM, 0xC8,0x85, SWAP, EXIT,

/* SOURCE */
0x80|'E', 'C', 'R', 'U', 'O', 'S',
#define ROMDEF_SOURCE 0xC982
6, 0xC9,0x64, DOCOLONROM,
VM, ICHARLIT, offsetof(EnforthVM, source_len), PLUS, TWOFETCH, EXIT,

/* SPACE */
0x80|'E', 'C', 'A', 'P', 'S',
#define ROMDEF_SPACE 0xC991
5, 0xC9,0x82, DOCOLONROM,
0xC0,0xA1, EMIT, EXIT,

/* SPACES */
0x80|'S', 'E', 'C', 'A', 'P', 'S',
#define ROMDEF_SPACES 0xC99F
6, 0xC9,0x91, DOCOLONROM,
QDUP, IZBRANCH, 6, 0xC9,0x91, ONEMINUS, IBRANCH, -7, EXIT,

/* SQUOTE */
0x80|'"', 'S',
#define ROMDEF_SQUOTE 0xC9AE
0x80|2, 0xC9,0x9F, DOCOLONROM,
ICHARLIT, '"', 0xC7,0xD4, ICHARLIT, PSQUOTE, 0xC1,0x7B, DUP, 0xC0,0xCD, 0xC5,0x8E, OVER, 0xC0,0x72, SWAP, MOVE, EXIT,

/* STAR */
0x80|'*',
#define ROMDEF_STAR 0xC9C6
1, 0xC9,0xAE, DOCOLONROM,
UMSTAR, DROP, EXIT,

/* STARSLASH */
0x80|'/', '*',
#define ROMDEF_STARSLASH 0xC9CF
2, 0xC9,0xC6, DOCOLONROM,
0xC9,0xDC, NIP, EXIT,

/* STARSLASHMOD */
0x80|'D', 'O', 'M', '/', '*',
#define ROMDEF_STARSLASHMOD 0xC9DC
5, 0xC9,0xCF, DOCOLONROM,
TOR, 0xC7,0x19, RFROM, 0xC9,0x64, EXIT,

/* STATE */
0x80|'E', 'T', 'A', 'T', 'S',
#define ROMDEF_STATE 0xC9EC
5, 0xC9,0xDC, DOCOLONROM,
VM, ICHARLIT, offsetof(EnforthVM, state), PLUS, EXIT,

/* STOD */
0x80|'D', '>', 'S',
#define ROMDEF_STOD 0xC9F8
3, 0xC9,0xEC, DOCOLONROM,
DUP, ZEROLESS, EXIT,

/* THEN */
0x80|'N', 'E', 'H', 'T',
#define ROMDEF_THEN 0xCA03
0x80|4, 0xC9,0xF8, DOCOLONROM,
0xC5,0x8E, OVER, MINUS, SWAP, CSTORE, EXIT,

/* TIB */
#define ROMDEF_TIB 0xCA0E
0, 0xCA,0x03, DOCOLONROM,
VM, ICHARLIT, offsetof(EnforthVM, tib), PLUS, EXIT,

/* TIBSIZE */
#define ROMDEF_TIBSIZE 0xCA17
0, 0xCA,0x0E, DOCOLONROM,
ICHARLIT, 80, EXIT,

/* TICK */
0x80|'\'',
#define ROMDEF_TICK 0xCA1F
1, 0xCA,0x17, DOCOLONROM,
0xC0,0xA1, 0xC7,0xD4, 0xC4,0x57, ZEROEQUALS, IZBRANCH, 11, 0xCB,0x1C, 0xC9,0x91, ICHARLIT, '?', EMIT, 0xC1,0xB5, ABORT, EXIT,

/* TICKPREVLEAVE */
#define ROMDEF_TICKPREVLEAVE 0xCA37
0, 0xCA,0x1F, DOCOLONROM,
VM, ICHARLIT, offsetof(EnforthVM, prev_leave), PLUS, EXIT,

/* TOBODY */
0x80|'Y', 'D', 'O', 'B', '>',
#define ROMDEF_TOBODY 0xCA45
5, 0xCA,0x37, DOCOLONROM,
DUP, 0xCA,0x89, IZBRANCH, 4, DROP, ZERO, EXIT, DUP, 0xC8,0xD9, IZBRANCH, 5, 0xC8,0xF1, ONEPLUS, EXIT, DUP, 0xC7,0x36, SWAP, 0xCA,0x92, ONEPLUS, ONEPLUS, ONEPLUS, PLUS, ONEPLUS, EXIT,

/* TOCFA */
#define ROMDEF_TOCFA 0xCA66
0, 0xCA,0x45, DOCOLONROM,
DUP, 0xC7,0x36, SWAP, 0xCA,0x92, ONEPLUS, ONEPLUS, ONEPLUS, PLUS, EXIT,

/* TOFFIDEF */
#define ROMDEF_TOFFIDEF 0xCA75
0, 0xCA,0x66, DOCOLONROM,
0xCA,0x45, FETCH, EXIT,

/* TOIN */
0x80|'N', 'I', '>',
#define ROMDEF_TOIN 0xCA80
3, 0xCA,0x75, DOCOLONROM,
VM, ICHARLIT, offsetof(EnforthVM, to_in), PLUS, EXIT,

/* TOKENQ */
#define ROMDEF_TOKENQ 0xCA89
0, 0xCA,0x80, DOCOLONROM,
0xCC,0x5E, AND, ZEROEQUALS, EXIT,

/* TOLFA */
#define ROMDEF_TOLFA 0xCA92
0, 0xCA,0x89, DOCOLONROM,
0xCC,0x68, AND, VM, ICHARLIT, offsetof(EnforthVM, dictionary), PLUS, FETCH, PLUS, EXIT,

/* TONFA */
#define ROMDEF_TONFA 0xCAA0
0, 0xCA,0x92, DOCOLONROM,
0xCA,0x92, ONEPLUS, ONEPLUS, ONEPLUS, EXIT,

/* TONUMBER */
0x80|'R', 'E', 'B', 'M', 'U', 'N', '>',
#define ROMDEF_TONUMBER 0xCAB1
7, 0xCA,0xA0, DOCOLONROM,
DUP, IZBRANCH, 32, OVER, CFETCH, 0xC2,0x17, ZEROEQUALS, IZBRANCH, 2, EXIT, TOR, TWOSWAP, 0xC0,0x8A, FETCH, DUP, TOR, UMSTAR, DROP, SWAP, RFROM, UMSTAR, ROT, PLUS, RFROM, MPLUS, TWOSWAP, ICHARLIT, 1, 0xC9,0x53, IBRANCH, -33, EXIT,

/* TOTOKEN */
#define ROMDEF_TOTOKEN 0xCAD8
0, 0xCA,0xB1, DOCOLONROM,
DUP, 0xCA,0x89, IZBRANCH, 2, EXIT, DUP, 0xC8,0xD9, IZBRANCH, 5, 0xC8,0xF1, ICFETCH, EXIT, 0xCA,0x66, CFETCH, EXIT,

/* TOUPPER */
0x80|'R', 'E', 'P', 'P', 'U', '>',
#define ROMDEF_TOUPPER 0xCAF5
6, 0xCA,0xD8, DOCOLONROM,
DUP, ICHARLIT, 'a', ONEMINUS, GREATERTHAN, OVER, ICHARLIT, 'z', ONEPLUS, LESSTHAN, AND, IZBRANCH, 4, ICHARLIT, 32, MINUS, EXIT,

/* TOXT */
#define ROMDEF_TOXT 0xCB0A
0, 0xCA,0xF5, DOCOLONROM,
VM, ICHARLIT, offsetof(EnforthVM, dictionary), PLUS, FETCH, MINUS, 0xCC,0x5E, OR, EXIT,

/* TYPE */
0x80|'E', 'P', 'Y', 'T',
#define ROMDEF_TYPE 0xCB1C
4, 0xCB,0x0A, DOCOLONROM,
OVER, PLUS, SWAP, TWODUP, NOTEQUALS, IZBRANCH, 7, DUP, CFETCH, EMIT, ONEPLUS, IBRANCH, -9, TWODROP, EXIT,

/* UDDOT */
0x80|'.', 'D', 'U',
#define ROMDEF_UDDOT 0xCB32
3, 0xCB,0x1C, DOCOLONROM,
0xC6,0xB9, 0xC7,0xB2, 0xC7,0x9F, 0xCB,0x1C, 0xC9,0x91, EXIT,

/* UDOT */
0x80|'.', 'U',
#define ROMDEF_UDOT 0xCB43
2, 0xCB,0x32, DOCOLONROM,
ZERO, 0xC6,0xB9, 0xC7,0xB2, 0xC7,0x9F, 0xCB,0x1C, 0xC9,0x91, EXIT,

/* UDSLASHMOD */
#define ROMDEF_UDSLASHMOD 0xCB53
0, 0xCB,0x43, DOCOLONROM,
TOR, ZERO, RFETCH, UMSLASHMOD, RFROM, SWAP, TOR, UMSLASHMOD, RFROM, EXIT,

/* UNUSED */
0x80|'D', 'E', 'S', 'U', 'N', 'U',
#define ROMDEF_UNUSED 0xCB67
6, 0xCB,0x53, DOCOLONROM,
VM, ICHARLIT, offsetof(EnforthVM, dictionary), PLUS, FETCH, VM, ICHARLIT, offsetof(EnforthVM, dictionary_size), PLUS, FETCH, PLUS, 0xC5,0x8E, MINUS, EXIT,

/* USE */
0x80|':', 'E', 'S', 'U',
#define ROMDEF_USE 0xCB7E
4, 0xCB,0x67, DOCOLONROM,
0xC0,0xA1, 0xC7,0xD4, DUP, ZEROEQUALS, IZBRANCH, 2, ABORT, TWODUP, 0xC4,0x08, ZEROEQUALS, IZBRANCH, 11, 0xCB,0x1C, 0xC9,0x91, ICHARLIT, '?', EMIT, 0xC1,0xB5, ABORT, 0xC5,0x8E, 0xCB,0x0A, 0xC6,0x8B, FETCH, 0xC6,0xC6, 0xC6,0x8B, STORE, SWAP, ICHARLIT, 32, OR, 0xC0,0xCD, ICHARLIT, DOFFI0, OVER, 0xC3,0x51, PLUS, 0xC0,0xCD, 0xC0,0x5C, 0xC1,0x65, DROP, EXIT,

/* VARIABLE */
0x80|'E', 'L', 'B', 'A', 'I', 'R', 'A', 'V',
#define ROMDEF_VARIABLE 0xCBC3
8, 0xCB,0x7E, DOCOLONROM,
0xC1,0xC3, ZERO, ONEMINUS, 0xC0,0x72, ICHARLIT, DOVARIABLE, 0xC0,0xCD, ZERO, 0xC1,0x65, EXIT,

/* WHILE */
0x80|'E', 'L', 'I', 'H', 'W',
#define ROMDEF_WHILE 0xCBDA
0x80|5, 0xCB,0xC3, DOCOLONROM,
0xC5,0xF6, SWAP, EXIT,

/* WORDS */
0x80|'S', 'D', 'R', 'O', 'W',
#define ROMDEF_WORDS 0xCBE7
5, 0xCB,0xDA, DOCOLONROM,
0xC6,0x8B, FETCH, QDUP, IZBRANCH, 49, DUP, 0xC3,0x74, IZBRANCH, 16, DUP, 0xCA,0x75, DUP, 0xC3,0x5A, SWAP, 0xC3,0x63, 0xC6,0x64, 0xC9,0x91, IBRANCH, 23, DUP, 0xCA,0x92, ONEPLUS, ONEPLUS, CFETCH, ICHARLIT, 64, AND, ZEROEQUALS, IZBRANCH, 11, DUP, 0xCA,0xA0, OVER, 0xC7,0x36, 0xCB,0x1C, 0xC9,0x91, 0xCA,0x92, 0xCC,0x50, IBRANCH, -50, TICKNAMES, DUP, ICFETCH, ICHARLIT, 255, NOTEQUALS, IZBRANCH, 25, DUP, ICFETCH, ICHARLIT, 31, AND, TUCK, OVER, PLUS, ONEPLUS, SWAP, ONEPLUS, ROT, QDUP, IZBRANCH, 7, 0xC6,0x64, 0xC9,0x91, IBRANCH, 2, DROP, IBRANCH, -30, DROP, EXIT,

/* XTCOMMA */
#define ROMDEF_XTCOMMA 0xCC43
0, 0xCB,0xE7, DOCOLONROM,
DUP, ICHARLIT, 8, RSHIFT, 0xC0,0xCD, 0xC0,0xCD, EXIT,

/* XTFETCH */
#define ROMDEF_XTFETCH 0xCC50
0, 0xCC,0x43, DOCOLONROM,
DUP, CFETCH, SWAP, ONEPLUS, CFETCH, ICHARLIT, 8, LSHIFT, OR, EXIT,

/* XTFLAG */
#define ROMDEF_XTFLAG 0xCC5E
0, 0xCC,0x50, DOCOLONROM,
ICHARLIT, 128, ICHARLIT, 8, LSHIFT, EXIT,

/* XTMASK */
#define ROMDEF_XTMASK 0xCC68
0, 0xCC,0x5E, DOCOLONROM,
ICHARLIT, 255, ICHARLIT, 63, ICHARLIT, 8, LSHIFT, OR, EXIT,

#define ROMDEF_LAST 0xCC68
