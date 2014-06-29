/* NUMSIGN */
BASE, FETCH, UDSLASHMOD, ROT, DUP, ICHARLIT, 9, GREATERTHAN, ICHARLIT, 7, AND, PLUS, ICHARLIT, 48, PLUS, HOLD, EXIT, 0, 0, 0, 0, 0, 0, 0,

/* NUMSIGNGRTR */
DROP, DROP, HLD, FETCH, HERE, HLDEND, PLUS, OVER, MINUS, EXIT, 0, 0, 0, 0, 0, 0,

/* NUMSIGNS */
NUMSIGN, TWODUP, OR, IZBRANCH, 3, IBRANCH, -6, EXIT,

/* COMMA */
HERE, STORE, ICHARLIT, 1, CELLS, ALLOT, EXIT, 0,

/* DOT */
BASE, FETCH, ICHARLIT, 10, NOTEQUALS, IZBRANCH, 3, UDOT, EXIT, DUP, ABS, ZERO, LESSNUMSIGN, NUMSIGNS, ROT, SIGN, NUMSIGNGRTR, TYPE, SPACE, EXIT, 0, 0, 0, 0,

/* SLASHSTRING */
ROT, OVER, PLUS, ROT, ROT, MINUS, EXIT, 0,

/* COLON */
CREATE, ICHARLIT, kDefTypeCOLONHIDDEN, CHANGELATESTDEFTYPE, RTBRACKET, EXIT, 0, 0,

/* SEMICOLON */
ICHARLIT, EXIT, COMPILECOMMA, ICHARLIT, kDefTypeCOLON, CHANGELATESTDEFTYPE, LTBRACKET, EXIT,

/* LESSNUMSIGN */
HERE, HLDEND, PLUS, HLD, STORE, EXIT, 0, 0,

/* TOBODY */
DUP, TOKENQ, IZBRANCH, 4, DROP, ZERO, EXIT, DUP, NFALENGTH, SWAP, TOLFA, ONEPLUS, ONEPLUS, ONEPLUS, PLUS, EXIT,

/* TOIN */
VM, ICHARLIT, offsetof(EnforthVM, to_in), PLUS, EXIT, 0, 0, 0,

/* TONUMBER */
DUP, IZBRANCH, 29, OVER, CFETCH, DIGITQ, ZEROEQUALS, IZBRANCH, 2, EXIT, TOR, TWOSWAP, BASE, FETCH, DUP, TOR, UMSTAR, DROP, SWAP, RFROM, UMSTAR, ROT, PLUS, RFROM, MPLUS, TWOSWAP, ICHARLIT, 1, SLASHSTRING, IBRANCH, -30, EXIT,

/* TOUPPER */
DUP, ICHARLIT, 'a', ONEMINUS, GREATERTHAN, OVER, ICHARLIT, 'z', ONEPLUS, LESSTHAN, AND, IZBRANCH, 4, ICHARLIT, 32, MINUS, EXIT, 0, 0, 0, 0, 0, 0, 0,

/* ACCEPT */
OVER, PLUS, OVER, KEY, DUP, ICHARLIT, 10, NOTEQUALS, IZBRANCH, 43, DUP, ICHARLIT, 8, EQUALS, OVER, ICHARLIT, 127, EQUALS, OR, IZBRANCH, 18, TWOOVER, DROP, NIP, OVER, NOTEQUALS, IZBRANCH, 9, ONEMINUS, ICHARLIT, 8, EMIT, SPACE, ICHARLIT, 8, EMIT, IBRANCH, 13, DUP, TWOOVER, NOTEQUALS, IZBRANCH, 7, EMIT, OVER, CSTORE, ONEPLUS, IBRANCH, 2, TWODROP, IBRANCH, -48, DROP, NIP, SWAP, MINUS, EXIT, 0, 0, 0, 0, 0, 0, 0,

/* ALIGN */
EXIT, 0, 0, 0, 0, 0, 0, 0,

/* ALLOT */
DP, PLUSSTORE, EXIT, 0, 0, 0, 0, 0,

/* BASE */
VM, ICHARLIT, offsetof(EnforthVM, base), PLUS, EXIT, 0, 0, 0,

/* BL */
ICHARLIT, ' ', EXIT, 0, 0, 0, 0, 0,

/* CCOMMA */
HERE, CSTORE, ICHARLIT, 1, CHARS, ALLOT, EXIT, 0,

/* CELLS */
ICHARLIT, kEnforthCellSize, UMSTAR, DROP, EXIT, 0, 0, 0,

/* CHARS */
EXIT, 0, 0, 0, 0, 0, 0, 0,

/* COMPILECOMMA */
DUP, TOCOMPILETOKEN, CCOMMA, TOBODY, QDUP, IZBRANCH, 8, VM, ICHARLIT, offsetof(EnforthVM, dictionary), PLUS, FETCH, MINUS, XTCOMMA, EXIT, 0,

/* COUNT */
DUP, CFETCH, SWAP, ONEPLUS, SWAP, EXIT, 0, 0,

/* CR */
ICHARLIT, 10, EMIT, EXIT, 0, 0, 0, 0,

/* CREATE */
BL, PARSEWORD, DUP, ZEROEQUALS, IZBRANCH, 2, ABORT, HERE, TOXT, LATEST, FETCH, XTCOMMA, LATEST, STORE, DUP, ICHARLIT, 3, LSHIFT, ICHARLIT, kDefTypeCREATE, OR, CCOMMA, TUCK, HERE, SWAP, MOVE, ALLOT, ALIGN, EXIT, 0, 0, 0,

/* CNOTSIMILAR */
CSIMILAR, INVERT, EXIT, 0, 0, 0, 0, 0,

/* CSIMILAR */
TOUPPER, SWAP, TOUPPER, EQUALS, EXIT, 0, 0, 0,

/* EVALUATE */
INTERPRET, EXIT, 0, 0, 0, 0, 0, 0,

/* EXECUTE */
DUP, TOTOKEN, SWAP, TOBODY, PEXECUTE, EXIT, 0, 0,

/* FFIS */
VM, ICHARLIT, offsetof(EnforthVM, last_ffi), PLUS, FETCH, QDUP, IZBRANCH, 10, DUP, FFIDEFNAME, OVER, FFIDEFNAMELEN, ITYPE, SPACE, IFETCH, IBRANCH, -11, EXIT, 0, 0, 0, 0, 0, 0,

/* FIND */
COUNT, FINDWORD, EXIT, 0, 0, 0, 0, 0,

/* HERE */
DP, FETCH, EXIT, 0, 0, 0, 0, 0,

/* HEX */
ICHARLIT, 16, BASE, STORE, EXIT, 0, 0, 0,

/* HOLD */
HLD, FETCH, ONEMINUS, DUP, HLD, STORE, CSTORE, EXIT,

/* LATEST */
VM, ICHARLIT, offsetof(EnforthVM, latest), PLUS, EXIT, 0, 0, 0,

/* LITERAL */
DUP, ICHARLIT, 255, INVERT, AND, ZEROEQUALS, IZBRANCH, 7, ICHARLIT, CHARLIT, CCOMMA, CCOMMA, IBRANCH, 5, ICHARLIT, LIT, CCOMMA, COMMA, EXIT, 0, 0, 0, 0, 0,

/* QUIT */
INITRP, ZERO, STATE, STORE, TIB, DUP, TIBSIZE, ACCEPT, SPACE, INTERPRET, CR, STATE, FETCH, ZEROEQUALS, IZBRANCH, 7, PISQUOTE, 3, 'o', 'k', ' ', ITYPE, IBRANCH, -19,

/* SIGN */
ZEROLESS, IZBRANCH, 4, ICHARLIT, '-', HOLD, EXIT, 0,

/* SOURCE */
VM, ICHARLIT, offsetof(EnforthVM, source_len), PLUS, TWOFETCH, EXIT, 0, 0,

/* SPACE */
BL, EMIT, EXIT, 0, 0, 0, 0, 0,

/* STATE */
VM, ICHARLIT, offsetof(EnforthVM, state), PLUS, EXIT, 0, 0, 0,

/* TYPE */
OVER, PLUS, SWAP, TWODUP, NOTEQUALS, IZBRANCH, 7, DUP, CFETCH, EMIT, ONEPLUS, IBRANCH, -9, TWODROP, EXIT, 0,

/* UDOT */
ZERO, LESSNUMSIGN, NUMSIGNS, NUMSIGNGRTR, TYPE, SPACE, EXIT, 0,

/* UNUSED */
VM, ICHARLIT, offsetof(EnforthVM, dictionary), PLUS, FETCH, VM, ICHARLIT, offsetof(EnforthVM, dictionary_size), PLUS, FETCH, PLUS, HERE, MINUS, EXIT, 0, 0,

/* USE */
BL, PARSEWORD, DUP, ZEROEQUALS, IZBRANCH, 2, ABORT, TWODUP, FINDFFIDEF, ZEROEQUALS, IZBRANCH, 8, TYPE, SPACE, ICHARLIT, '?', EMIT, CR, ABORT, HERE, TOXT, LATEST, FETCH, XTCOMMA, LATEST, STORE, SWAP, ICHARLIT, 3, LSHIFT, ICHARLIT, kDefTypeFFI, OR, CCOMMA, ALIGN, COMMA, DROP, EXIT, 0, 0,

/* WORDS */
LATEST, FETCH, QDUP, IZBRANCH, 32, DUP, FFIQ, IZBRANCH, 11, DUP, TOFFIDEF, DUP, FFIDEFNAME, SWAP, FFIDEFNAMELEN, ITYPE, SPACE, IBRANCH, 14, DUP, TODEFTYPE, CHARLIT, kDefTypeCOLONHIDDEN, NOTEQUALS, IZBRANCH, 7, DUP, TONFA, OVER, NFALENGTH, TYPE, SPACE, TOLFA, XTFETCH, IBRANCH, -33, TICKNAMES, DUP, ICFETCH, ICHARLIT, 255, NOTEQUALS, IZBRANCH, 23, DUP, ICFETCH, ICHARLIT, 3, RSHIFT, TUCK, OVER, PLUS, ONEPLUS, SWAP, ONEPLUS, ROT, QDUP, IZBRANCH, 5, ITYPE, SPACE, IBRANCH, 2, DROP, IBRANCH, -28, DROP, EXIT, 0, 0, 0, 0,

/* LTBRACKET */
FALSE, STATE, STORE, EXIT, 0, 0, 0, 0,

/* BACKSLASH */
SOURCE, NIP, TOIN, STORE, EXIT, 0, 0, 0,

/* RTBRACKET */
TRUE, STATE, STORE, EXIT, 0, 0, 0, 0,

/* TODEFTYPE */
TOLFA, ONEPLUS, ONEPLUS, CFETCH, ICHARLIT, 7, AND, EXIT,

/* TOFFIDEF */
TOBODY, FETCH, EXIT, 0, 0, 0, 0, 0,

/* TOLFA */
XTMASK, AND, VM, ICHARLIT, offsetof(EnforthVM, dictionary), PLUS, FETCH, PLUS, EXIT, 0, 0, 0, 0, 0, 0, 0,

/* TONFA */
TOLFA, ONEPLUS, ONEPLUS, ONEPLUS, EXIT, 0, 0, 0,

/* TOTOKEN */
DUP, TOKENQ, IZBRANCH, 2, EXIT, DUP, FFIQ, IZBRANCH, 8, TOFFIDEF, FFIDEFARITY, ICHARLIT, 232, PLUS, IBRANCH, 5, TODEFTYPE, ICHARLIT, 224, PLUS, EXIT, 0, 0, 0,

/* TOXT */
VM, ICHARLIT, offsetof(EnforthVM, dictionary), PLUS, FETCH, MINUS, XTFLAG, OR, EXIT, 0, 0, 0, 0, 0, 0, 0,

/* TOCOMPILETOKEN */
TOTOKEN, DUP, ICHARLIT, 0xe0 - 1, GREATERTHAN, IZBRANCH, 4, ICHARLIT, 16, PLUS, EXIT, 0, 0, 0, 0, 0,

/* CHANGELATESTDEFTYPE */
LATEST, FETCH, TOLFA, ONEPLUS, ONEPLUS, CFETCH, ICHARLIT, 248, AND, OR, LATEST, FETCH, TOLFA, ONEPLUS, ONEPLUS, CSTORE, EXIT, 0, 0, 0, 0, 0, 0, 0,

/* COLD */
PISQUOTE, 31, 'E', 'n', 'f', 'o', 'r', 't', 'h', ' ', '(', 'C', ')', ' ', 'M', 'i', 'c', 'h', 'a', 'e', 'l', ' ', 'A', 'l', 'y', 'n', ' ', 'M', 'i', 'l', 'l', 'e', 'r', ITYPE, CR, ABORT, EXIT, 0, 0, 0,

/* DIGITQ */
TOUPPER, ICHARLIT, '0', MINUS, DUP, ZEROLESS, IZBRANCH, 4, DROP, ZERO, EXIT, DUP, ICHARLIT, 9, GREATERTHAN, IZBRANCH, 13, DUP, ICHARLIT, 17, LESSTHAN, IZBRANCH, 4, DROP, FALSE, EXIT, ICHARLIT, 7, MINUS, DUP, ONEPLUS, BASE, FETCH, UGREATERTHAN, IZBRANCH, 4, DROP, FALSE, EXIT, TRUE, EXIT, 0, 0, 0, 0, 0, 0, 0,

/* DP */
VM, ICHARLIT, offsetof(EnforthVM, dp), PLUS, EXIT, 0, 0, 0,

/* FFIQ */
TODEFTYPE, ICHARLIT, kDefTypeFFI, EQUALS, EXIT, 0, 0, 0,

/* FFIDEFARITY */
ICHARLIT, offsetof(EnforthFFIDef, arity), PLUS, ICFETCH, EXIT, 0, 0, 0,

/* FFIDEFNAME */
ICHARLIT, offsetof(EnforthFFIDef, name), PLUS, IFETCH, EXIT, 0, 0, 0,

/* FFIDEFNAMELEN */
FFIDEFNAME, DUP, DUP, ICFETCH, IZBRANCH, 4, ONEPLUS, IBRANCH, -6, SWAP, MINUS, EXIT, 0, 0, 0, 0,

/* FINDDEF */
TWOTOR, LATEST, FETCH, QDUP, IZBRANCH, 23, DUP, TWORFETCH, ROT, FOUNDDEFQ, IZBRANCH, 13, DUP, TODEFTYPE, ICHARLIT, kDefTypeCOLONIMMEDIATE, EQUALS, ICHARLIT, 2, AND, ONEMINUS, TWORFROM, TWODROP, EXIT, TOLFA, XTFETCH, IBRANCH, -24, TWORFROM, TWODROP, FALSE, EXIT,

/* FINDFFIDEF */
TWOTOR, VM, ICHARLIT, offsetof(EnforthVM, last_ffi), PLUS, FETCH, QDUP, IZBRANCH, 20, RFETCH, OVER, FFIDEFNAMELEN, EQUALS, IZBRANCH, 11, DUP, TWORFETCH, ROT, FOUNDFFIDEFQ, IZBRANCH, 5, TWORFROM, TWODROP, TRUE, EXIT, IFETCH, IBRANCH, -21, TWORFROM, TWODROP, FALSE, EXIT,

/* FINDPRIM */
TWOTOR, ZERO, TICKNAMES, DUP, ICFETCH, ICHARLIT, 255, NOTEQUALS, IZBRANCH, 29, DUP, TWORFETCH, ROT, FOUNDPRIMQ, IZBRANCH, 16, DROP, ICFETCH, ICHARLIT, 7, AND, ICHARLIT, kDefTypeCOLONIMMEDIATE, EQUALS, ICHARLIT, 2, AND, ONEMINUS, TWORFROM, TWODROP, EXIT, ROT, ONEPLUS, ROT, DROP, SWAP, IBRANCH, -34, TWODROP, TWORFROM, TWODROP, FALSE, EXIT, 0, 0, 0, 0, 0,

/* FINDWORD */
TWODUP, FINDDEF, QDUP, IZBRANCH, 5, TWOSWAP, TWODROP, IBRANCH, 8, TWODUP, FINDPRIM, DUP, IZBRANCH, 3, TWOSWAP, TWODROP, EXIT, 0, 0, 0, 0, 0, 0, 0,

/* FOUNDDEFQ */
DUP, TODEFTYPE, ICHARLIT, kDefTypeCOLONHIDDEN, EQUALS, IZBRANCH, 5, DROP, TWODROP, FALSE, EXIT, TWODUP, NAMELENGTH, NOTEQUALS, IZBRANCH, 5, DROP, TWODROP, FALSE, EXIT, DUP, FFIQ, IZBRANCH, 3, FOUNDFFIQ, EXIT, TONFA, SWAP, QDUP, IZBRANCH, 22, ONEMINUS, TOR, OVER, CFETCH, OVER, CFETCH, CNOTSIMILAR, IZBRANCH, 6, TWODROP, RFROM, DROP, FALSE, EXIT, ONEPLUS, SWAP, ONEPLUS, SWAP, RFROM, IBRANCH, -23, TWODROP, TRUE, EXIT, 0,

/* FOUNDFFIQ */
TOFFIDEF, FOUNDFFIDEFQ, EXIT, 0, 0, 0, 0, 0,

/* FOUNDFFIDEFQ */
FFIDEFNAME, SWAP, QDUP, IZBRANCH, 22, ONEMINUS, TOR, OVER, CFETCH, OVER, ICFETCH, CNOTSIMILAR, IZBRANCH, 6, TWODROP, RFROM, DROP, FALSE, EXIT, ONEPLUS, SWAP, ONEPLUS, SWAP, RFROM, IBRANCH, -23, TWODROP, TRUE, EXIT, 0, 0, 0,

/* FOUNDPRIMQ */
DUP, DUP, ICFETCH, ICHARLIT, 3, RSHIFT, PLUS, ONEPLUS, TOR, DUP, ICFETCH, ICHARLIT, 3, RSHIFT, ROT, NOTEQUALS, IZBRANCH, 5, TWODROP, RFROM, FALSE, EXIT, ONEPLUS, OVER, CFETCH, OVER, ICFETCH, CNOTSIMILAR, IZBRANCH, 5, TWODROP, RFROM, FALSE, EXIT, ONEPLUS, SWAP, ONEPLUS, SWAP, DUP, RFETCH, EQUALS, IZBRANCH, -19, TWODROP, RFROM, TRUE, EXIT, 0,

/* HALT */
PHALT, EXIT, 0, 0, 0, 0, 0, 0,

/* HLD */
VM, ICHARLIT, offsetof(EnforthVM, hld), PLUS, EXIT, 0, 0, 0,

/* HLDEND */
ICHARLIT, kEnforthCellSize * 8 * 3, EXIT, 0, 0, 0, 0, 0,

/* INTERPRET */
VM, ICHARLIT, offsetof(EnforthVM, source_len), PLUS, TWOSTORE, ZERO, TOIN, STORE, BL, PARSEWORD, DUP, IZBRANCH, 37, FINDWORD, QDUP, IZBRANCH, 14, ONEPLUS, STATE, FETCH, ZEROEQUALS, OR, IZBRANCH, 4, EXECUTE, IBRANCH, 21, COMPILECOMMA, IBRANCH, 18, NUMBERQ, IZBRANCH, 8, STATE, FETCH, IZBRANCH, 11, LITERAL, IBRANCH, 8, TYPE, SPACE, ICHARLIT, '?', EMIT, CR, ABORT, IBRANCH, -40, TWODROP, EXIT, 0, 0, 0, 0, 0,

/* ITYPE */
OVER, PLUS, SWAP, TWODUP, NOTEQUALS, IZBRANCH, 7, DUP, ICFETCH, EMIT, ONEPLUS, IBRANCH, -9, TWODROP, EXIT, 0,

/* NAMELENGTH */
TOLFA, ONEPLUS, ONEPLUS, CFETCH, ICHARLIT, 3, RSHIFT, EXIT,

/* NFALENGTH */
DUP, FFIQ, IZBRANCH, 5, DROP, ZERO, IBRANCH, 8, TOLFA, ONEPLUS, ONEPLUS, CFETCH, ICHARLIT, 3, RSHIFT, EXIT,

/* NUMBERQ */
OVER, CFETCH, DUP, ICHARLIT, '-', EQUALS, OVER, ICHARLIT, '+', EQUALS, OR, IZBRANCH, 17, ICHARLIT, '-', EQUALS, IZBRANCH, 4, TRUE, IBRANCH, 2, FALSE, TOR, ICHARLIT, 1, SLASHSTRING, RFROM, IBRANCH, 3, DROP, ZERO, TOR, TWODUP, ZERO, ZERO, TWOSWAP, TONUMBER, IZBRANCH, 8, DROP, TWODROP, RFROM, DROP, ZERO, IBRANCH, 10, DROP, TWONIP, DROP, RFROM, ZEROLESS, IZBRANCH, 2, NEGATE, TRUE, EXIT,

/* PARSEWORD */
TOR, SOURCE, TOIN, FETCH, SLASHSTRING, RFETCH, TOR, OVER, CFETCH, RFETCH, EQUALS, OVER, AND, IZBRANCH, 6, ICHARLIT, 1, SLASHSTRING, IBRANCH, -12, RFROM, DROP, OVER, SWAP, RFROM, TOR, OVER, CFETCH, RFETCH, EQUALS, IZBRANCH, 6, RFROM, TWODROP, TRUE, IBRANCH, 15, DUP, ZEROEQUALS, IZBRANCH, 6, RFROM, TWODROP, FALSE, IBRANCH, 6, ICHARLIT, 1, SLASHSTRING, IBRANCH, -24, OVER, SOURCE, DROP, MINUS, SWAP, IZBRANCH, 2, ONEPLUS, TOIN, STORE, OVER, MINUS, EXIT,

/* TIB */
VM, ICHARLIT, offsetof(EnforthVM, tib), PLUS, EXIT, 0, 0, 0,

/* TIBSIZE */
ICHARLIT, 80, EXIT, 0, 0, 0, 0, 0,

/* TOKENQ */
XTFLAG, AND, ZEROEQUALS, EXIT, 0, 0, 0, 0,

/* XTCOMMA */
DUP, CCOMMA, ICHARLIT, 8, RSHIFT, CCOMMA, EXIT, 0,

/* XTFETCH */
DUP, CFETCH, SWAP, ONEPLUS, CFETCH, ICHARLIT, 8, LSHIFT, OR, EXIT, 0, 0, 0, 0, 0, 0,

/* XTFLAG */
ICHARLIT, 128, ICHARLIT, 8, LSHIFT, EXIT, 0, 0,

/* XTMASK */
ICHARLIT, 255, ICHARLIT, 127, ICHARLIT, 8, LSHIFT, OR, EXIT, 0, 0, 0, 0, 0, 0, 0,

