/* NUMSIGN */
0, 0, 1, '#', DOCOLONROM,
#define ROMDEF_PFA_NUMSIGN 5
194, 44, FETCH, 204, 104, ROT, DUP, ICHARLIT, 9, GREATERTHAN, ICHARLIT, 7, AND, PLUS, ICHARLIT, 48, PLUS, 196, 166, EXIT,

/* NUMSIGNGRTR */
0, 192, 2, '#', '>', DOCOLONROM,
#define ROMDEF_PFA_NUMSIGNGRTR 31
DROP, DROP, 203, 44, FETCH, 196, 141, 203, 53, PLUS, OVER, MINUS, EXIT,

/* NUMSIGNS */
25, 192, 2, '#', 'S', DOCOLONROM,
#define ROMDEF_PFA_NUMSIGNS 50
192, 4, TWODUP, OR, IZBRANCH, 3, IBRANCH, -7, EXIT,

/* TICK */
44, 192, 1, '\'', DOCOLONROM,
#define ROMDEF_PFA_TICK 64
194, 67, 197, 104, 201, 246, ZEROEQUALS, IZBRANCH, 11, 198, 200, 198, 140, ICHARLIT, '?', EMIT, 194, 240, ABORT, EXIT,

/* PAREN */
59, 192, 129, '(', DOCOLONROM,
#define ROMDEF_PFA_PAREN 89
ICHARLIT, ')', 197, 104, TWODROP, EXIT,

/* STAR */
84, 192, 1, '*', DOCOLONROM,
#define ROMDEF_PFA_STAR 100
UMSTAR, DROP, EXIT,

/* STARSLASH */
95, 192, 2, '*', '/', DOCOLONROM,
#define ROMDEF_PFA_STARSLASH 109
192, 121, NIP, EXIT,

/* STARSLASHMOD */
103, 192, 5, '*', '/', 'M', 'O', 'D', DOCOLONROM,
#define ROMDEF_PFA_STARSLASHMOD 122
TOR, 197, 67, RFROM, 198, 95, EXIT,

/* PLUSLOOP */
113, 192, 133, '+', 'L', 'O', 'O', 'P', DOCOLONROM,
#define ROMDEF_PFA_PLUSLOOP 138
ICHARLIT, PPLUSLOOP, 201, 1, EXIT,

/* COMMA */
129, 192, 1, ',', DOCOLONROM,
#define ROMDEF_PFA_COMMA 148
196, 141, STORE, ICHARLIT, 1, 194, 108, 194, 32, EXIT,

/* DOT */
143, 192, 1, '.', DOCOLONROM,
#define ROMDEF_PFA_DOT 163
194, 44, FETCH, ICHARLIT, 10, NOTEQUALS, IZBRANCH, 4, 198, 221, EXIT, DUP, ABS, ZERO, 193, 16, 192, 49, ROT, 198, 77, 192, 30, 198, 200, 198, 140, EXIT,

/* SLASH */
158, 192, 1, '/', DOCOLONROM,
#define ROMDEF_PFA_SLASH 196
192, 207, NIP, EXIT,

/* SLASHMOD */
191, 192, 4, '/', 'M', 'O', 'D', DOCOLONROM,
#define ROMDEF_PFA_SLASHMOD 208
TOR, 198, 66, RFROM, 198, 95, EXIT,

/* SLASHSTRING */
200, 192, 7, '/', 'S', 'T', 'R', 'I', 'N', 'G', DOCOLONROM,
#define ROMDEF_PFA_SLASHSTRING 226
ROT, OVER, PLUS, ROT, ROT, MINUS, EXIT,

/* COLON */
215, 192, 1, ':', DOCOLONROM,
#define ROMDEF_PFA_COLON 238
194, 254, 203, 25, ZERO, ONEMINUS, 194, 32, ICHARLIT, DOCOLON, 194, 76, 200, 27, EXIT,

/* SEMICOLON */
233, 192, 129, ';', DOCOLONROM,
#define ROMDEF_PFA_SEMICOLON 258
ICHARLIT, EXIT, 194, 161, 204, 9, 199, 226, EXIT,

/* LESSNUMSIGN */
253, 192, 2, '<', '#', DOCOLONROM,
#define ROMDEF_PFA_LESSNUMSIGN 273
196, 141, 203, 53, PLUS, 203, 44, STORE, EXIT,

/* TOBODY */
11, 193, 5, '>', 'B', 'O', 'D', 'Y', DOCOLONROM,
#define ROMDEF_PFA_TOBODY 291
DUP, 204, 95, IZBRANCH, 4, DROP, ZERO, EXIT, DUP, 204, 53, IZBRANCH, 5, 204, 28, ONEPLUS, EXIT, DUP, 203, 187, SWAP, 200, 68, ONEPLUS, ONEPLUS, ONEPLUS, PLUS, ONEPLUS, EXIT,

/* TOIN */
26, 193, 3, '>', 'I', 'N', DOCOLONROM,
#define ROMDEF_PFA_TOIN 327
VM, ICHARLIT, offsetof(EnforthVM, to_in), PLUS, EXIT,

/* TONUMBER */
64, 193, 7, '>', 'N', 'U', 'M', 'B', 'E', 'R', DOCOLONROM,
#define ROMDEF_PFA_TONUMBER 343
DUP, IZBRANCH, 32, OVER, CFETCH, 200, 201, ZEROEQUALS, IZBRANCH, 2, EXIT, TOR, TWOSWAP, 194, 44, FETCH, DUP, TOR, UMSTAR, DROP, SWAP, RFROM, UMSTAR, ROT, PLUS, RFROM, MPLUS, TWOSWAP, ICHARLIT, 1, 192, 225, IBRANCH, -33, EXIT,

/* TOUPPER */
76, 193, 6, '>', 'U', 'P', 'P', 'E', 'R', DOCOLONROM,
#define ROMDEF_PFA_TOUPPER 388
DUP, ICHARLIT, 'a', ONEMINUS, GREATERTHAN, OVER, ICHARLIT, 'z', ONEPLUS, LESSTHAN, AND, IZBRANCH, 4, ICHARLIT, 32, MINUS, EXIT,

/* QDO */
122, 193, 131, '?', 'D', 'O', DOCOLONROM,
#define ROMDEF_PFA_QDO 412
ICHARLIT, PQDO, 194, 161, 196, 141, 200, 36, STORE, ZERO, 194, 76, 196, 141, EXIT,

/* ACCEPT */
149, 193, 6, 'A', 'C', 'C', 'E', 'P', 'T', DOCOLONROM,
#define ROMDEF_PFA_ACCEPT 437
OVER, PLUS, OVER, KEY, DUP, ICHARLIT, 10, NOTEQUALS, IZBRANCH, 44, DUP, ICHARLIT, 8, EQUALS, OVER, ICHARLIT, 127, EQUALS, OR, IZBRANCH, 19, TWOOVER, DROP, NIP, OVER, NOTEQUALS, IZBRANCH, 10, ONEMINUS, ICHARLIT, 8, EMIT, 198, 140, ICHARLIT, 8, EMIT, IBRANCH, 13, DUP, TWOOVER, NOTEQUALS, IZBRANCH, 7, EMIT, OVER, CSTORE, ONEPLUS, IBRANCH, 2, TWODROP, IBRANCH, -49, DROP, NIP, SWAP, MINUS, EXIT,

/* AGAIN */
171, 193, 133, 'A', 'G', 'A', 'I', 'N', DOCOLONROM,
#define ROMDEF_PFA_AGAIN 504
ICHARLIT, BRANCH, 194, 161, 196, 141, MINUS, 194, 76, EXIT,

/* ALIGN */
239, 193, 5, 'A', 'L', 'I', 'G', 'N', DOCOLONROM,
#define ROMDEF_PFA_ALIGN 523
EXIT,

/* ALIGNED */
2, 194, 7, 'A', 'L', 'I', 'G', 'N', 'E', 'D', DOCOLONROM,
#define ROMDEF_PFA_ALIGNED 535
EXIT,

/* ALLOT */
12, 194, 5, 'A', 'L', 'L', 'O', 'T', DOCOLONROM,
#define ROMDEF_PFA_ALLOT 545
200, 248, PLUSSTORE, EXIT,

/* BASE */
24, 194, 4, 'B', 'A', 'S', 'E', DOCOLONROM,
#define ROMDEF_PFA_BASE 557
VM, ICHARLIT, offsetof(EnforthVM, base), PLUS, EXIT,

/* BEGIN */
37, 194, 133, 'B', 'E', 'G', 'I', 'N', DOCOLONROM,
#define ROMDEF_PFA_BEGIN 571
196, 141, EXIT,

/* BL */
50, 194, 2, 'B', 'L', DOCOLONROM,
#define ROMDEF_PFA_BL 580
ICHARLIT, ' ', EXIT,

/* CCOMMA */
62, 194, 2, 'C', ',', DOCOLONROM,
#define ROMDEF_PFA_CCOMMA 589
196, 141, CSTORE, ICHARLIT, 1, 194, 148, 194, 32, EXIT,

/* CELLPLUS */
71, 194, 5, 'C', 'E', 'L', 'L', '+', DOCOLONROM,
#define ROMDEF_PFA_CELLPLUS 608
ICHARLIT, kEnforthCellSize, PLUS, EXIT,

/* CELLS */
87, 194, 5, 'C', 'E', 'L', 'L', 'S', DOCOLONROM,
#define ROMDEF_PFA_CELLS 621
ICHARLIT, kEnforthCellSize, 192, 99, EXIT,

/* CHAR */
100, 194, 4, 'C', 'H', 'A', 'R', DOCOLONROM,
#define ROMDEF_PFA_CHAR 634
194, 67, 197, 104, DROP, CFETCH, EXIT,

/* CHARPLUS */
114, 194, 5, 'C', 'H', 'A', 'R', '+', DOCOLONROM,
#define ROMDEF_PFA_CHARPLUS 650
ONEPLUS, EXIT,

/* CHARS */
129, 194, 5, 'C', 'H', 'A', 'R', 'S', DOCOLONROM,
#define ROMDEF_PFA_CHARS 661
EXIT,

/* COMPILECOMMA */
140, 194, 8, 'C', 'O', 'M', 'P', 'I', 'L', 'E', ',', DOCOLONROM,
#define ROMDEF_PFA_COMPILECOMMA 674
DUP, 204, 95, IZBRANCH, 4, 194, 76, EXIT, DUP, 204, 53, IZBRANCH, 10, DUP, 204, 28, OVER, 204, 43, MINUS, IBRANCH, 8, DUP, 200, 45, OVER, 200, 68, MINUS, PLUS, 204, 118, EXIT,

/* CONSTANT */
150, 194, 8, 'C', 'O', 'N', 'S', 'T', 'A', 'N', 'T', DOCOLONROM,
#define ROMDEF_PFA_CONSTANT 719
194, 254, ZERO, ONEMINUS, 194, 32, ICHARLIT, DOCONSTANT, 194, 76, 192, 147, EXIT,

/* COUNT */
195, 194, 5, 'C', 'O', 'U', 'N', 'T', DOCOLONROM,
#define ROMDEF_PFA_COUNT 741
DUP, CFETCH, SWAP, ONEPLUS, SWAP, EXIT,

/* CR */
220, 194, 2, 'C', 'R', DOCOLONROM,
#define ROMDEF_PFA_CR 753
ICHARLIT, 10, EMIT, EXIT,

/* CREATE */
235, 194, 6, 'C', 'R', 'E', 'A', 'T', 'E', DOCOLONROM,
#define ROMDEF_PFA_CREATE 767
194, 67, 197, 104, DUP, ZEROEQUALS, IZBRANCH, 2, ABORT, 196, 141, 200, 125, 196, 230, FETCH, 203, 161, 196, 230, STORE, DUP, 194, 76, TUCK, 196, 141, SWAP, MOVE, 194, 32, ICHARLIT, DOCREATE, 194, 76, 194, 10, EXIT,

/* CNOTSIMILAR */
245, 194, 3, 'C', '{', '}', DOCOLONROM,
#define ROMDEF_PFA_CNOTSIMILAR 812
195, 53, INVERT, EXIT,

/* CSIMILAR */
37, 195, 2, 'C', '~', DOCOLONROM,
#define ROMDEF_PFA_CSIMILAR 822
193, 131, SWAP, 193, 131, EQUALS, EXIT,

/* DABS */
48, 195, 4, 'D', 'A', 'B', 'S', DOCOLONROM,
#define ROMDEF_PFA_DABS 837
DUP, 200, 139, EXIT,

/* DECIMAL */
61, 195, 7, 'D', 'E', 'C', 'I', 'M', 'A', 'L', DOCOLONROM,
#define ROMDEF_PFA_DECIMAL 852
ICHARLIT, 10, 194, 44, STORE, EXIT,

/* DNEGATE */
73, 195, 7, 'D', 'N', 'E', 'G', 'A', 'T', 'E', DOCOLONROM,
#define ROMDEF_PFA_DNEGATE 869
INVERT, SWAP, INVERT, SWAP, ICHARLIT, 1, MPLUS, EXIT,

/* DO */
90, 195, 130, 'D', 'O', DOCOLONROM,
#define ROMDEF_PFA_DO 883
ZERO, 200, 36, STORE, ICHARLIT, PDO, 194, 161, 196, 141, EXIT,

/* DUMP */
109, 195, 4, 'D', 'U', 'M', 'P', DOCOLONROM,
#define ROMDEF_PFA_DUMP 902
194, 44, FETCH, TOR, 196, 152, DUP, ZERO, PIQDO, 102, 194, 240, OVER, I, PLUS, OVER, I, MINUS, ICHARLIT, 16, MIN, OVER, ZERO, 193, 16, 192, 4, 192, 4, 192, 4, 192, 4, 192, 4, 192, 4, 192, 4, 192, 4, 192, 30, 198, 200, ICHARLIT, 2, 198, 154, DUP, ZERO, PDO, OVER, I, PLUS, CFETCH, ZERO, 193, 16, 192, 4, 192, 4, 192, 30, 198, 200, 198, 140, PILOOP, -18, ICHARLIT, 16, OVER, MINUS, ICHARLIT, 3, 192, 99, 198, 154, 198, 140, ZERO, PDO, DUP, I, PLUS, CFETCH, DUP, ICHARLIT, 32, LESSTHAN, OVER, ICHARLIT, 127, GREATERTHAN, OR, IZBRANCH, 4, DROP, ICHARLIT, '.', EMIT, PILOOP, -20, DROP, ICHARLIT, 16, PIPLUSLOOP, -100, TWODROP, RFROM, 194, 44, STORE, EXIT,

/* ELSE */
126, 195, 132, 'E', 'L', 'S', 'E', DOCOLONROM,
#define ROMDEF_PFA_ELSE 1027
ICHARLIT, BRANCH, 194, 161, 196, 141, ZERO, 194, 76, SWAP, 198, 185, EXIT,

/* EXECUTE */
251, 195, 7, 'E', 'X', 'E', 'C', 'U', 'T', 'E', DOCOLONROM,
#define ROMDEF_PFA_EXECUTE 1051
DUP, 200, 102, SWAP, 193, 34, PEXECUTE, EXIT,

/* FFIS */
16, 196, 4, 'F', 'F', 'I', 'S', DOCOLONROM,
#define ROMDEF_PFA_FFIS 1067
VM, ICHARLIT, offsetof(EnforthVM, last_ffi), PLUS, FETCH, QDUP, IZBRANCH, 14, DUP, 201, 48, OVER, 201, 57, 203, 128, 198, 140, IFETCH, IBRANCH, -15, EXIT,

/* FIND */
35, 196, 4, 'F', 'I', 'N', 'D', DOCOLONROM,
#define ROMDEF_PFA_FIND 1097
194, 228, 201, 246, EXIT,

/* FMSLASHMOD */
65, 196, 6, 'F', 'M', '/', 'M', 'O', 'D', DOCOLONROM,
#define ROMDEF_PFA_FMSLASHMOD 1112
DUP, TOR, TWODUP, XOR, SWAP, ABS, DUP, TOR, SWAP, TOR, TOR, 195, 68, RFROM, UMSLASHMOD, RFROM, ZEROLESS, IZBRANCH, 18, NEGATE, OVER, ZERONOTEQUALS, IZBRANCH, 9, ONEMINUS, SWAP, RFROM, SWAP, MINUS, SWAP, IBRANCH, 7, RFROM, DROP, IBRANCH, 3, RFROM, DROP, RFROM, ZEROLESS, IZBRANCH, 4, SWAP, NEGATE, SWAP, EXIT,

/* HERE */
78, 196, 4, 'H', 'E', 'R', 'E', DOCOLONROM,
#define ROMDEF_PFA_HERE 1166
200, 248, FETCH, EXIT,

/* HEX */
134, 196, 3, 'H', 'E', 'X', DOCOLONROM,
#define ROMDEF_PFA_HEX 1177
ICHARLIT, 16, 194, 44, STORE, EXIT,

/* HOLD */
146, 196, 4, 'H', 'O', 'L', 'D', DOCOLONROM,
#define ROMDEF_PFA_HOLD 1191
203, 44, FETCH, ONEMINUS, DUP, 203, 44, STORE, CSTORE, EXIT,

/* IF */
159, 196, 130, 'I', 'F', DOCOLONROM,
#define ROMDEF_PFA_IF 1207
ICHARLIT, ZBRANCH, 194, 161, 196, 141, ZERO, 194, 76, EXIT,

/* IMMEDIATE */
177, 196, 9, 'I', 'M', 'M', 'E', 'D', 'I', 'A', 'T', 'E', DOCOLONROM,
#define ROMDEF_PFA_IMMEDIATE 1230
196, 230, FETCH, 200, 68, ONEPLUS, ONEPLUS, DUP, CFETCH, ICHARLIT, 128, OR, SWAP, CSTORE, EXIT,

/* LATEST */
193, 196, 6, 'L', 'A', 'T', 'E', 'S', 'T', DOCOLONROM,
#define ROMDEF_PFA_LATEST 1255
VM, ICHARLIT, offsetof(EnforthVM, latest), PLUS, EXIT,

/* LEAVE */
221, 196, 133, 'L', 'E', 'A', 'V', 'E', DOCOLONROM,
#define ROMDEF_PFA_LEAVE 1269
ICHARLIT, UNLOOP, 194, 161, ICHARLIT, BRANCH, 194, 161, 196, 141, 200, 36, FETCH, DUP, IZBRANCH, 5, 196, 141, SWAP, MINUS, 194, 76, 200, 36, STORE, EXIT,

/* LITERAL */
236, 196, 135, 'L', 'I', 'T', 'E', 'R', 'A', 'L', DOCOLONROM,
#define ROMDEF_PFA_LITERAL 1306
DUP, ICHARLIT, 255, INVERT, AND, ZEROEQUALS, IZBRANCH, 9, ICHARLIT, CHARLIT, 194, 76, 194, 76, IBRANCH, 7, ICHARLIT, LIT, 194, 76, 192, 147, EXIT,

/* LOOP */
15, 197, 132, 'L', 'O', 'O', 'P', DOCOLONROM,
#define ROMDEF_PFA_LOOP 1337
ICHARLIT, PLOOP, 201, 1, EXIT,

/* MSTAR */
49, 197, 2, 'M', '*', DOCOLONROM,
#define ROMDEF_PFA_MSTAR 1348
TWODUP, XOR, ZEROLESS, TOR, ABS, SWAP, ABS, UMSTAR, RFROM, 200, 139, EXIT,

/* MOD */
62, 197, 3, 'M', 'O', 'D', DOCOLONROM,
#define ROMDEF_PFA_MOD 1367
192, 207, DROP, EXIT,

/* PARSEWORD */
80, 197, 10, 'P', 'A', 'R', 'S', 'E', '-', 'W', 'O', 'R', 'D', DOCOLONROM,
#define ROMDEF_PFA_PARSEWORD 1385
TOR, 198, 125, 193, 70, FETCH, 192, 225, RFETCH, TOR, OVER, CFETCH, RFETCH, EQUALS, OVER, AND, IZBRANCH, 7, ICHARLIT, 1, 192, 225, IBRANCH, -13, RFROM, DROP, OVER, SWAP, RFROM, TOR, DUP, ZEROEQUALS, IZBRANCH, 6, RFROM, TWODROP, FALSE, IBRANCH, 18, OVER, CFETCH, RFETCH, EQUALS, IZBRANCH, 6, RFROM, TWODROP, TRUE, IBRANCH, 7, ICHARLIT, 1, 192, 225, IBRANCH, -25, OVER, 198, 125, DROP, MINUS, SWAP, IZBRANCH, 2, ONEPLUS, 193, 70, STORE, OVER, MINUS, EXIT,

/* POSTPONE */
91, 197, 136, 'P', 'O', 'S', 'T', 'P', 'O', 'N', 'E', DOCOLONROM,
#define ROMDEF_PFA_POSTPONE 1468
194, 67, 197, 104, 201, 246, QDUP, ZEROEQUALS, IZBRANCH, 11, 198, 200, 198, 140, ICHARLIT, '?', EMIT, 194, 240, ABORT, ZEROLESS, IZBRANCH, 22, ICHARLIT, LIT, 194, 161, 192, 147, ICHARLIT, ((uint8_t)(((ROMDEF_PFA_COMPILECOMMA - 1) >> 8) & 0xff)), ICHARLIT, 192, OR, ICHARLIT, 8, LSHIFT, ICHARLIT, ((uint8_t)(((ROMDEF_PFA_COMPILECOMMA - 1)     ) & 0xff)), OR, 204, 118, IBRANCH, 3, 194, 161, EXIT,

/* QUIT */
176, 197, 4, 'Q', 'U', 'I', 'T', DOCOLONROM,
#define ROMDEF_PFA_QUIT 1523
INITRP, ZERO, 198, 172, STORE, 204, 79, DUP, 204, 88, 193, 180, 198, 140, 203, 60, 194, 240, 198, 172, FETCH, ZEROEQUALS, IZBRANCH, 8, PISQUOTE, 3, 'o', 'k', ' ', 203, 128, IBRANCH, -27,

/* REPEAT */
235, 197, 134, 'R', 'E', 'P', 'E', 'A', 'T', DOCOLONROM,
#define ROMDEF_PFA_REPEAT 1566
193, 247, 198, 185, EXIT,

/* SQUOTE */
20, 198, 130, 'S', '"', DOCOLONROM,
#define ROMDEF_PFA_SQUOTE 1577
ICHARLIT, '"', 197, 104, ICHARLIT, PSQUOTE, 194, 161, DUP, 194, 76, 196, 141, OVER, 194, 32, SWAP, MOVE, EXIT,

/* STOD */
35, 198, 3, 'S', '>', 'D', DOCOLONROM,
#define ROMDEF_PFA_STOD 1603
DUP, ZEROLESS, EXIT,

/* SIGN */
60, 198, 4, 'S', 'I', 'G', 'N', DOCOLONROM,
#define ROMDEF_PFA_SIGN 1614
ZEROLESS, IZBRANCH, 5, ICHARLIT, '-', 196, 166, EXIT,

/* SMSLASHREM */
70, 198, 6, 'S', 'M', '/', 'R', 'E', 'M', DOCOLONROM,
#define ROMDEF_PFA_SMSLASHREM 1632
OVER, TOR, TWODUP, XOR, TOR, ABS, TOR, 195, 68, RFROM, UMSLASHMOD, RFROM, 200, 149, SWAP, RFROM, 200, 149, SWAP, EXIT,

/* SOURCE */
86, 198, 6, 'S', 'O', 'U', 'R', 'C', 'E', DOCOLONROM,
#define ROMDEF_PFA_SOURCE 1662
VM, ICHARLIT, offsetof(EnforthVM, source_len), PLUS, TWOFETCH, EXIT,

/* SPACE */
116, 198, 5, 'S', 'P', 'A', 'C', 'E', DOCOLONROM,
#define ROMDEF_PFA_SPACE 1677
194, 67, EMIT, EXIT,

/* SPACES */
132, 198, 6, 'S', 'P', 'A', 'C', 'E', 'S', DOCOLONROM,
#define ROMDEF_PFA_SPACES 1691
QDUP, IZBRANCH, 6, 198, 140, ONEMINUS, IBRANCH, -7, EXIT,

/* STATE */
145, 198, 5, 'S', 'T', 'A', 'T', 'E', DOCOLONROM,
#define ROMDEF_PFA_STATE 1709
VM, ICHARLIT, offsetof(EnforthVM, state), PLUS, EXIT,

/* THEN */
164, 198, 132, 'T', 'H', 'E', 'N', DOCOLONROM,
#define ROMDEF_PFA_THEN 1722
196, 141, OVER, MINUS, SWAP, CSTORE, EXIT,

/* TYPE */
178, 198, 4, 'T', 'Y', 'P', 'E', DOCOLONROM,
#define ROMDEF_PFA_TYPE 1737
OVER, PLUS, SWAP, TWODUP, NOTEQUALS, IZBRANCH, 7, DUP, CFETCH, EMIT, ONEPLUS, IBRANCH, -9, TWODROP, EXIT,

/* UDOT */
193, 198, 2, 'U', '.', DOCOLONROM,
#define ROMDEF_PFA_UDOT 1758
ZERO, 193, 16, 192, 49, 192, 30, 198, 200, 198, 140, EXIT,

/* UDDOT */
216, 198, 3, 'U', 'D', '.', DOCOLONROM,
#define ROMDEF_PFA_UDDOT 1777
193, 16, 192, 49, 192, 30, 198, 200, 198, 140, EXIT,

/* UNUSED */
234, 198, 6, 'U', 'N', 'U', 'S', 'E', 'D', DOCOLONROM,
#define ROMDEF_PFA_UNUSED 1798
VM, ICHARLIT, offsetof(EnforthVM, dictionary), PLUS, FETCH, VM, ICHARLIT, offsetof(EnforthVM, dictionary_size), PLUS, FETCH, PLUS, 196, 141, MINUS, EXIT,

/* USE */
252, 198, 4, 'U', 'S', 'E', ':', DOCOLONROM,
#define ROMDEF_PFA_USE 1821
194, 67, 197, 104, DUP, ZEROEQUALS, IZBRANCH, 2, ABORT, TWODUP, 201, 165, ZEROEQUALS, IZBRANCH, 11, 198, 200, 198, 140, ICHARLIT, '?', EMIT, 194, 240, ABORT, 196, 141, 200, 125, 196, 230, FETCH, 203, 161, 196, 230, STORE, SWAP, ICHARLIT, 32, OR, 194, 76, ICHARLIT, DOFFI0, OVER, 201, 39, PLUS, 194, 76, 194, 10, 192, 147, DROP, EXIT,

/* VARIABLE */
21, 199, 8, 'V', 'A', 'R', 'I', 'A', 'B', 'L', 'E', DOCOLONROM,
#define ROMDEF_PFA_VARIABLE 1890
194, 254, ZERO, ONEMINUS, 194, 32, ICHARLIT, DOVARIABLE, 194, 76, ZERO, 192, 147, EXIT,

/* WHILE */
86, 199, 133, 'W', 'H', 'I', 'L', 'E', DOCOLONROM,
#define ROMDEF_PFA_WHILE 1913
196, 182, SWAP, EXIT,

/* WORDS */
112, 199, 5, 'W', 'O', 'R', 'D', 'S', DOCOLONROM,
#define ROMDEF_PFA_WORDS 1926
196, 230, FETCH, QDUP, IZBRANCH, 49, DUP, 201, 25, IZBRANCH, 16, DUP, 200, 60, DUP, 201, 48, SWAP, 201, 57, 203, 128, 198, 140, IBRANCH, 23, DUP, 200, 68, ONEPLUS, ONEPLUS, CFETCH, ICHARLIT, 64, AND, ZEROEQUALS, IZBRANCH, 11, DUP, 200, 82, OVER, 203, 187, 198, 200, 198, 140, 200, 68, 204, 131, IBRANCH, -50, TICKNAMES, DUP, ICFETCH, ICHARLIT, 255, NOTEQUALS, IZBRANCH, 25, DUP, ICFETCH, ICHARLIT, 31, AND, TUCK, OVER, PLUS, ONEPLUS, SWAP, ONEPLUS, ROT, QDUP, IZBRANCH, 7, 203, 128, 198, 140, IBRANCH, 2, DROP, IBRANCH, -30, DROP, EXIT,

/* LTBRACKET */
125, 199, 129, '[', DOCOLONROM,
#define ROMDEF_PFA_LTBRACKET 2019
FALSE, 198, 172, STORE, EXIT,

/* BRACKETTICK */
222, 199, 131, '[', '\'', ']', DOCOLONROM,
#define ROMDEF_PFA_BRACKETTICK 2031
192, 63, ICHARLIT, LIT, 194, 161, 192, 147, EXIT,

/* BRACKETCHAR */
232, 199, 134, '[', 'C', 'H', 'A', 'R', ']', DOCOLONROM,
#define ROMDEF_PFA_BRACKETCHAR 2050
194, 121, ICHARLIT, CHARLIT, 194, 161, 194, 76, EXIT,

/* BACKSLASH */
248, 199, 129, '\\', DOCOLONROM,
#define ROMDEF_PFA_BACKSLASH 2064
198, 125, NIP, 193, 70, STORE, EXIT,

/* RTBRACKET */
11, 200, 1, ']', DOCOLONROM,
#define ROMDEF_PFA_RTBRACKET 2076
TRUE, 198, 172, STORE, EXIT,

/* TICKPREVLEAVE */
23, 200, 0, DOCOLONROM,
#define ROMDEF_PFA_TICKPREVLEAVE 2085
VM, ICHARLIT, offsetof(EnforthVM, prev_leave), PLUS, EXIT,

/* TOCFA */
33, 200, 0, DOCOLONROM,
#define ROMDEF_PFA_TOCFA 2094
DUP, 203, 187, SWAP, 200, 68, ONEPLUS, ONEPLUS, ONEPLUS, PLUS, EXIT,

/* TOFFIDEF */
42, 200, 0, DOCOLONROM,
#define ROMDEF_PFA_TOFFIDEF 2109
193, 34, FETCH, EXIT,

/* TOLFA */
57, 200, 0, DOCOLONROM,
#define ROMDEF_PFA_TOLFA 2117
204, 155, AND, VM, ICHARLIT, offsetof(EnforthVM, dictionary), PLUS, FETCH, PLUS, EXIT,

/* TONFA */
65, 200, 0, DOCOLONROM,
#define ROMDEF_PFA_TONFA 2131
200, 68, ONEPLUS, ONEPLUS, ONEPLUS, EXIT,

/* TOROMNFA */
79, 200, 0, DOCOLONROM,
#define ROMDEF_PFA_TOROMNFA 2141
204, 43, ONEPLUS, ONEPLUS, ONEPLUS, EXIT,

/* TOTOKEN */
89, 200, 0, DOCOLONROM,
#define ROMDEF_PFA_TOTOKEN 2151
DUP, 204, 95, IZBRANCH, 2, EXIT, DUP, 204, 53, IZBRANCH, 5, 204, 28, ICFETCH, EXIT, 200, 45, CFETCH, EXIT,

/* TOXT */
99, 200, 0, DOCOLONROM,
#define ROMDEF_PFA_TOXT 2174
VM, ICHARLIT, offsetof(EnforthVM, dictionary), PLUS, FETCH, MINUS, 204, 145, OR, EXIT,

/* QDNEGATE */
122, 200, 0, DOCOLONROM,
#define ROMDEF_PFA_QDNEGATE 2188
ZEROLESS, IZBRANCH, 3, 195, 100, EXIT,

/* QNEGATE */
136, 200, 0, DOCOLONROM,
#define ROMDEF_PFA_QNEGATE 2198
ZEROLESS, IZBRANCH, 2, NEGATE, EXIT,

/* COLD */
146, 200, 0, DOCOLONROM,
#define ROMDEF_PFA_COLD 2207
PISQUOTE, 31, 'E', 'n', 'f', 'o', 'r', 't', 'h', ' ', '(', 'C', ')', ' ', 'M', 'i', 'c', 'h', 'a', 'e', 'l', ' ', 'A', 'l', 'y', 'n', ' ', 'M', 'i', 'l', 'l', 'e', 'r', 203, 128, 194, 240, ABORT, EXIT,

/* DIGITQ */
155, 200, 0, DOCOLONROM,
#define ROMDEF_PFA_DIGITQ 2250
193, 131, ICHARLIT, '0', MINUS, DUP, ZEROLESS, IZBRANCH, 4, DROP, ZERO, EXIT, DUP, ICHARLIT, 9, GREATERTHAN, IZBRANCH, 13, DUP, ICHARLIT, 17, LESSTHAN, IZBRANCH, 4, DROP, FALSE, EXIT, ICHARLIT, 7, MINUS, DUP, ONEPLUS, 194, 44, FETCH, UGREATERTHAN, IZBRANCH, 4, DROP, FALSE, EXIT, TRUE, EXIT,

/* DP */
198, 200, 0, DOCOLONROM,
#define ROMDEF_PFA_DP 2297
VM, ICHARLIT, offsetof(EnforthVM, dp), PLUS, EXIT,

/* ENDLOOP */
245, 200, 0, DOCOLONROM,
#define ROMDEF_PFA_ENDLOOP 2306
194, 161, 196, 141, MINUS, 194, 76, 200, 36, FETCH, 202, 253, EXIT,

/* EVALUATE */
254, 200, 0, DOCOLONROM,
#define ROMDEF_PFA_EVALUATE 2323
203, 60, EXIT,

/* FFIQ */
15, 201, 0, DOCOLONROM,
#define ROMDEF_PFA_FFIQ 2330
200, 68, ONEPLUS, ONEPLUS, CFETCH, ICHARLIT, 32, AND, ZERONOTEQUALS, EXIT,

/* FFIDEFARITY */
22, 201, 0, DOCOLONROM,
#define ROMDEF_PFA_FFIDEFARITY 2344
ICHARLIT, offsetof(EnforthFFIDef, arity), PLUS, ICFETCH, EXIT,

/* FFIDEFNAME */
36, 201, 0, DOCOLONROM,
#define ROMDEF_PFA_FFIDEFNAME 2353
ICHARLIT, offsetof(EnforthFFIDef, name), PLUS, IFETCH, EXIT,

/* FFIDEFNAMELEN */
45, 201, 0, DOCOLONROM,
#define ROMDEF_PFA_FFIDEFNAMELEN 2362
201, 48, DUP, DUP, ICFETCH, IZBRANCH, 4, ONEPLUS, IBRANCH, -6, SWAP, MINUS, EXIT,

/* FINDCODEPRIM */
54, 201, 0, DOCOLONROM,
#define ROMDEF_PFA_FINDCODEPRIM 2379
TWOTOR, ZERO, TICKNAMES, DUP, ICFETCH, ICHARLIT, 255, NOTEQUALS, IZBRANCH, 28, DUP, TWORFETCH, ROT, 202, 134, IZBRANCH, 14, DROP, ICFETCH, ICHARLIT, 128, AND, ZERONOTEQUALS, ICHARLIT, 2, AND, ONEMINUS, TWORFROM, TWODROP, EXIT, ROT, ONEPLUS, ROT, DROP, SWAP, IBRANCH, -33, TWODROP, TWORFROM, TWODROP, FALSE, EXIT,

/* FINDDEF */
71, 201, 0, DOCOLONROM,
#define ROMDEF_PFA_FINDDEF 2425
TWOTOR, 196, 230, FETCH, QDUP, IZBRANCH, 31, DUP, TWORFETCH, ROT, 202, 21, IZBRANCH, 18, DUP, 200, 68, ONEPLUS, ONEPLUS, CFETCH, ICHARLIT, 128, AND, ZERONOTEQUALS, ICHARLIT, 2, AND, ONEMINUS, TWORFROM, TWODROP, EXIT, 200, 68, 204, 131, IBRANCH, -32, TWORFROM, TWODROP, FALSE, EXIT,

/* FINDFFIDEF */
117, 201, 0, DOCOLONROM,
#define ROMDEF_PFA_FINDFFIDEF 2470
TWOTOR, VM, ICHARLIT, offsetof(EnforthVM, last_ffi), PLUS, FETCH, QDUP, IZBRANCH, 22, RFETCH, OVER, 201, 57, EQUALS, IZBRANCH, 12, DUP, TWORFETCH, ROT, 202, 99, IZBRANCH, 5, TWORFROM, TWODROP, TRUE, EXIT, IFETCH, IBRANCH, -23, TWORFROM, TWODROP, FALSE, EXIT,

/* FINDROMDEF */
162, 201, 0, DOCOLONROM,
#define ROMDEF_PFA_FINDROMDEF 2508
TWOTOR, LASTROMDEF, QDUP, IZBRANCH, 31, DUP, TWORFETCH, ROT, 202, 186, IZBRANCH, 18, DUP, 204, 43, ONEPLUS, ONEPLUS, ICFETCH, ICHARLIT, 128, AND, ZERONOTEQUALS, ICHARLIT, 2, AND, ONEMINUS, TWORFROM, TWODROP, EXIT, 204, 43, 203, 147, IBRANCH, -32, TWORFROM, TWODROP, FALSE, EXIT,

/* FINDWORD */
200, 201, 0, DOCOLONROM,
#define ROMDEF_PFA_FINDWORD 2551
TWODUP, 201, 120, QDUP, IZBRANCH, 4, TWOSWAP, TWODROP, EXIT, TWODUP, 201, 74, QDUP, IZBRANCH, 4, TWOSWAP, TWODROP, EXIT, TWODUP, 201, 203, DUP, IZBRANCH, 3, TWOSWAP, TWODROP, EXIT,

/* FOUNDDEFQ */
243, 201, 0, DOCOLONROM,
#define ROMDEF_PFA_FOUNDDEFQ 2582
DUP, 200, 68, ONEPLUS, ONEPLUS, CFETCH, ICHARLIT, 64, AND, ZERONOTEQUALS, IZBRANCH, 5, DROP, TWODROP, FALSE, EXIT, TWODUP, 203, 174, NOTEQUALS, IZBRANCH, 5, DROP, TWODROP, FALSE, EXIT, DUP, 201, 25, IZBRANCH, 4, 202, 90, EXIT, 200, 82, SWAP, QDUP, IZBRANCH, 23, ONEMINUS, TOR, OVER, CFETCH, OVER, CFETCH, 195, 43, IZBRANCH, 6, TWODROP, RFROM, DROP, FALSE, EXIT, ONEPLUS, SWAP, ONEPLUS, SWAP, RFROM, IBRANCH, -24, TWODROP, TRUE, EXIT,

/* FOUNDFFIQ */
18, 202, 0, DOCOLONROM,
#define ROMDEF_PFA_FOUNDFFIQ 2651
200, 60, 202, 99, EXIT,

/* FOUNDFFIDEFQ */
87, 202, 0, DOCOLONROM,
#define ROMDEF_PFA_FOUNDFFIDEFQ 2660
201, 48, SWAP, QDUP, IZBRANCH, 23, ONEMINUS, TOR, OVER, CFETCH, OVER, ICFETCH, 195, 43, IZBRANCH, 6, TWODROP, RFROM, DROP, FALSE, EXIT, ONEPLUS, SWAP, ONEPLUS, SWAP, RFROM, IBRANCH, -24, TWODROP, TRUE, EXIT,

/* FOUNDPRIMQ */
96, 202, 0, DOCOLONROM,
#define ROMDEF_PFA_FOUNDPRIMQ 2695
DUP, DUP, ICFETCH, ICHARLIT, 31, AND, PLUS, ONEPLUS, TOR, DUP, ICFETCH, ICHARLIT, 31, AND, ROT, NOTEQUALS, IZBRANCH, 5, TWODROP, RFROM, FALSE, EXIT, ONEPLUS, OVER, CFETCH, OVER, ICFETCH, 195, 43, IZBRANCH, 5, TWODROP, RFROM, FALSE, EXIT, ONEPLUS, SWAP, ONEPLUS, SWAP, DUP, RFETCH, EQUALS, IZBRANCH, -20, TWODROP, RFROM, TRUE, EXIT,

/* FOUNDROMDEFQ */
131, 202, 0, DOCOLONROM,
#define ROMDEF_PFA_FOUNDROMDEFQ 2747
DUP, 204, 43, ONEPLUS, ONEPLUS, ICFETCH, ICHARLIT, 64, AND, ZERONOTEQUALS, IZBRANCH, 5, DROP, TWODROP, FALSE, EXIT, TWODUP, 204, 66, NOTEQUALS, IZBRANCH, 5, DROP, TWODROP, FALSE, EXIT, 200, 92, SWAP, QDUP, IZBRANCH, 23, ONEMINUS, TOR, OVER, CFETCH, OVER, ICFETCH, 195, 43, IZBRANCH, 6, TWODROP, RFROM, DROP, FALSE, EXIT, ONEPLUS, SWAP, ONEPLUS, SWAP, RFROM, IBRANCH, -24, TWODROP, TRUE, EXIT,

/* HALT */
183, 202, 0, DOCOLONROM,
#define ROMDEF_PFA_HALT 2808
PHALT, EXIT,

/* HERETOCHAIN */
244, 202, 0, DOCOLONROM,
#define ROMDEF_PFA_HERETOCHAIN 2814
QDUP, IZBRANCH, 21, DUP, CFETCH, OVER, DUP, 196, 141, SWAP, MINUS, SWAP, CSTORE, QDUP, IZBRANCH, 4, MINUS, IBRANCH, 3, DROP, ZERO, IBRANCH, -22, EXIT,

/* HIDE */
250, 202, 0, DOCOLONROM,
#define ROMDEF_PFA_HIDE 2842
196, 230, FETCH, 200, 68, ONEPLUS, ONEPLUS, DUP, CFETCH, ICHARLIT, 64, OR, SWAP, CSTORE, EXIT,

/* HLD */
22, 203, 0, DOCOLONROM,
#define ROMDEF_PFA_HLD 2861
VM, ICHARLIT, offsetof(EnforthVM, hld), PLUS, EXIT,

/* HLDEND */
41, 203, 0, DOCOLONROM,
#define ROMDEF_PFA_HLDEND 2870
ICHARLIT, kEnforthCellSize * 8 * 3, EXIT,

/* INTERPRET */
50, 203, 0, DOCOLONROM,
#define ROMDEF_PFA_INTERPRET 2877
VM, ICHARLIT, offsetof(EnforthVM, source_len), PLUS, TWOSTORE, ZERO, 193, 70, STORE, 194, 67, 197, 104, DUP, IZBRANCH, 47, 201, 246, QDUP, IZBRANCH, 17, ONEPLUS, 198, 172, FETCH, ZEROEQUALS, OR, IZBRANCH, 5, 196, 26, IBRANCH, 28, 194, 161, IBRANCH, 24, 203, 203, IZBRANCH, 10, 198, 172, FETCH, IZBRANCH, 15, 197, 25, IBRANCH, 11, 198, 200, 198, 140, ICHARLIT, '?', EMIT, 194, 240, ABORT, IBRANCH, -52, TWODROP, EXIT,

/* ITYPE */
57, 203, 0, DOCOLONROM,
#define ROMDEF_PFA_ITYPE 2945
OVER, PLUS, SWAP, TWODUP, NOTEQUALS, IZBRANCH, 7, DUP, ICFETCH, EMIT, ONEPLUS, IBRANCH, -9, TWODROP, EXIT,

/* IXTFETCH */
125, 203, 0, DOCOLONROM,
#define ROMDEF_PFA_IXTFETCH 2964
DUP, ICFETCH, SWAP, ONEPLUS, ICFETCH, ICHARLIT, 8, LSHIFT, OR, EXIT,

/* LFACOMMA */
144, 203, 0, DOCOLONROM,
#define ROMDEF_PFA_LFACOMMA 2978
DUP, 194, 76, ICHARLIT, 8, RSHIFT, 194, 76, EXIT,

/* NAMELENGTH */
158, 203, 0, DOCOLONROM,
#define ROMDEF_PFA_NAMELENGTH 2991
200, 68, ONEPLUS, ONEPLUS, CFETCH, ICHARLIT, 31, AND, EXIT,

/* NFALENGTH */
171, 203, 0, DOCOLONROM,
#define ROMDEF_PFA_NFALENGTH 3004
DUP, 201, 25, IZBRANCH, 5, DROP, ZERO, IBRANCH, 3, 203, 174, EXIT,

/* NUMBERQ */
184, 203, 0, DOCOLONROM,
#define ROMDEF_PFA_NUMBERQ 3020
OVER, CFETCH, DUP, ICHARLIT, '-', EQUALS, OVER, ICHARLIT, '+', EQUALS, OR, IZBRANCH, 18, ICHARLIT, '-', EQUALS, IZBRANCH, 4, TRUE, IBRANCH, 2, FALSE, TOR, ICHARLIT, 1, 192, 225, RFROM, IBRANCH, 3, DROP, ZERO, TOR, TWODUP, ZERO, ZERO, TWOSWAP, 193, 86, IZBRANCH, 8, DROP, TWODROP, RFROM, DROP, ZERO, IBRANCH, 10, DROP, TWONIP, DROP, RFROM, ZEROLESS, IZBRANCH, 2, NEGATE, TRUE, EXIT,

/* REVEAL */
200, 203, 0, DOCOLONROM,
#define ROMDEF_PFA_REVEAL 3082
196, 230, FETCH, 200, 68, ONEPLUS, ONEPLUS, DUP, CFETCH, ICHARLIT, 191, AND, SWAP, CSTORE, EXIT,

/* ROMTOCFA */
6, 204, 0, DOCOLONROM,
#define ROMDEF_PFA_ROMTOCFA 3101
DUP, 204, 66, SWAP, 204, 43, ONEPLUS, ONEPLUS, ONEPLUS, PLUS, EXIT,

/* ROMTOLFA */
25, 204, 0, DOCOLONROM,
#define ROMDEF_PFA_ROMTOLFA 3116
204, 155, AND, TICKROMDEF, PLUS, EXIT,

/* ROMDEFQ */
40, 204, 0, DOCOLONROM,
#define ROMDEF_PFA_ROMDEFQ 3126
ICHARLIT, 8, RSHIFT, ICHARLIT, 192, TUCK, AND, EQUALS, EXIT,

/* ROMNAMELENGTH */
50, 204, 0, DOCOLONROM,
#define ROMDEF_PFA_ROMNAMELENGTH 3139
204, 43, ONEPLUS, ONEPLUS, ICFETCH, ICHARLIT, 31, AND, EXIT,

/* TIB */
63, 204, 0, DOCOLONROM,
#define ROMDEF_PFA_TIB 3152
VM, ICHARLIT, offsetof(EnforthVM, tib), PLUS, EXIT,

/* TIBSIZE */
76, 204, 0, DOCOLONROM,
#define ROMDEF_PFA_TIBSIZE 3161
ICHARLIT, 80, EXIT,

/* TOKENQ */
85, 204, 0, DOCOLONROM,
#define ROMDEF_PFA_TOKENQ 3168
204, 145, AND, ZEROEQUALS, EXIT,

/* UDSLASHMOD */
92, 204, 0, DOCOLONROM,
#define ROMDEF_PFA_UDSLASHMOD 3177
TOR, ZERO, RFETCH, UMSLASHMOD, RFROM, SWAP, TOR, UMSLASHMOD, RFROM, EXIT,

/* XTCOMMA */
101, 204, 0, DOCOLONROM,
#define ROMDEF_PFA_XTCOMMA 3191
DUP, ICHARLIT, 8, RSHIFT, 194, 76, 194, 76, EXIT,

/* XTFETCH */
115, 204, 0, DOCOLONROM,
#define ROMDEF_PFA_XTFETCH 3204
DUP, CFETCH, SWAP, ONEPLUS, CFETCH, ICHARLIT, 8, LSHIFT, OR, EXIT,

/* XTFLAG */
128, 204, 0, DOCOLONROM,
#define ROMDEF_PFA_XTFLAG 3218
ICHARLIT, 128, ICHARLIT, 8, LSHIFT, EXIT,

/* XTMASK */
142, 204, 0, DOCOLONROM,
#define ROMDEF_PFA_XTMASK 3228
ICHARLIT, 255, ICHARLIT, 63, ICHARLIT, 8, LSHIFT, OR, EXIT,

#define ROMDEF_LAST 3224
