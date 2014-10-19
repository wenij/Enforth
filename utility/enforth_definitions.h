/* NUMSIGN */
0, 0, 1, '#', DOCOLONROM,
#define ROMDEF_PFA_NUMSIGN 5
194, 44, FETCH, 204, 105, ROT, DUP, ICHARLIT, 9, GREATERTHAN, ICHARLIT, 7, AND, PLUS, ICHARLIT, 48, PLUS, 196, 166, EXIT,

/* NUMSIGNGRTR */
0, 192, 2, '#', '>', DOCOLONROM,
#define ROMDEF_PFA_NUMSIGNGRTR 31
DROP, DROP, 203, 45, FETCH, 196, 141, 203, 54, PLUS, OVER, MINUS, EXIT,

/* NUMSIGNS */
25, 192, 2, '#', 'S', DOCOLONROM,
#define ROMDEF_PFA_NUMSIGNS 50
192, 4, TWODUP, OR, IZBRANCH, 3, IBRANCH, -7, EXIT,

/* TICK */
44, 192, 1, '\'', DOCOLONROM,
#define ROMDEF_PFA_TICK 64
194, 67, 197, 104, 201, 247, ZEROEQUALS, IZBRANCH, 11, 198, 192, 198, 132, ICHARLIT, '?', EMIT, 194, 240, ABORT, EXIT,

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
TOR, 197, 67, RFROM, 198, 87, EXIT,

/* PLUSLOOP */
113, 192, 133, '+', 'L', 'O', 'O', 'P', DOCOLONROM,
#define ROMDEF_PFA_PLUSLOOP 138
ICHARLIT, PPLUSLOOP, 201, 2, EXIT,

/* COMMA */
129, 192, 1, ',', DOCOLONROM,
#define ROMDEF_PFA_COMMA 148
196, 141, STORE, ICHARLIT, 1, 194, 108, 194, 32, EXIT,

/* DOT */
143, 192, 1, '.', DOCOLONROM,
#define ROMDEF_PFA_DOT 163
194, 44, FETCH, ICHARLIT, 10, NOTEQUALS, IZBRANCH, 4, 198, 213, EXIT, DUP, ABS, ZERO, 193, 16, 192, 49, ROT, 198, 69, 192, 30, 198, 192, 198, 132, EXIT,

/* SLASH */
158, 192, 1, '/', DOCOLONROM,
#define ROMDEF_PFA_SLASH 196
192, 207, NIP, EXIT,

/* SLASHMOD */
191, 192, 4, '/', 'M', 'O', 'D', DOCOLONROM,
#define ROMDEF_PFA_SLASHMOD 208
TOR, 198, 58, RFROM, 198, 87, EXIT,

/* SLASHSTRING */
200, 192, 7, '/', 'S', 'T', 'R', 'I', 'N', 'G', DOCOLONROM,
#define ROMDEF_PFA_SLASHSTRING 226
ROT, OVER, PLUS, ROT, ROT, MINUS, EXIT,

/* COLON */
215, 192, 1, ':', DOCOLONROM,
#define ROMDEF_PFA_COLON 238
194, 254, 203, 26, ZERO, ONEMINUS, 194, 32, ICHARLIT, DOCOLON, 194, 76, 200, 15, EXIT,

/* SEMICOLON */
233, 192, 129, ';', DOCOLONROM,
#define ROMDEF_PFA_SEMICOLON 258
ICHARLIT, EXIT, 194, 161, 204, 10, 199, 214, EXIT,

/* LESSNUMSIGN */
253, 192, 2, '<', '#', DOCOLONROM,
#define ROMDEF_PFA_LESSNUMSIGN 273
196, 141, 203, 54, PLUS, 203, 45, STORE, EXIT,

/* TOBODY */
11, 193, 5, '>', 'B', 'O', 'D', 'Y', DOCOLONROM,
#define ROMDEF_PFA_TOBODY 291
DUP, 204, 96, IZBRANCH, 4, DROP, ZERO, EXIT, DUP, 204, 54, IZBRANCH, 5, 204, 29, ONEPLUS, EXIT, DUP, 203, 188, SWAP, 200, 56, ONEPLUS, ONEPLUS, ONEPLUS, PLUS, ONEPLUS, EXIT,

/* TOIN */
26, 193, 3, '>', 'I', 'N', DOCOLONROM,
#define ROMDEF_PFA_TOIN 327
VM, ICHARLIT, offsetof(EnforthVM, to_in), PLUS, EXIT,

/* TONUMBER */
64, 193, 7, '>', 'N', 'U', 'M', 'B', 'E', 'R', DOCOLONROM,
#define ROMDEF_PFA_TONUMBER 343
DUP, IZBRANCH, 32, OVER, CFETCH, 200, 202, ZEROEQUALS, IZBRANCH, 2, EXIT, TOR, TWOSWAP, 194, 44, FETCH, DUP, TOR, UMSTAR, DROP, SWAP, RFROM, UMSTAR, ROT, PLUS, RFROM, MPLUS, TWOSWAP, ICHARLIT, 1, 192, 225, IBRANCH, -33, EXIT,

/* TOUPPER */
76, 193, 6, '>', 'U', 'P', 'P', 'E', 'R', DOCOLONROM,
#define ROMDEF_PFA_TOUPPER 388
DUP, ICHARLIT, 'a', ONEMINUS, GREATERTHAN, OVER, ICHARLIT, 'z', ONEPLUS, LESSTHAN, AND, IZBRANCH, 4, ICHARLIT, 32, MINUS, EXIT,

/* QDO */
122, 193, 131, '?', 'D', 'O', DOCOLONROM,
#define ROMDEF_PFA_QDO 412
ICHARLIT, PQDO, 194, 161, 196, 141, 200, 24, STORE, ZERO, 194, 76, 196, 141, EXIT,

/* ACCEPT */
149, 193, 6, 'A', 'C', 'C', 'E', 'P', 'T', DOCOLONROM,
#define ROMDEF_PFA_ACCEPT 437
OVER, PLUS, OVER, KEY, DUP, ICHARLIT, 10, NOTEQUALS, IZBRANCH, 44, DUP, ICHARLIT, 8, EQUALS, OVER, ICHARLIT, 127, EQUALS, OR, IZBRANCH, 19, TWOOVER, DROP, NIP, OVER, NOTEQUALS, IZBRANCH, 10, ONEMINUS, ICHARLIT, 8, EMIT, 198, 132, ICHARLIT, 8, EMIT, IBRANCH, 13, DUP, TWOOVER, NOTEQUALS, IZBRANCH, 7, EMIT, OVER, CSTORE, ONEPLUS, IBRANCH, 2, TWODROP, IBRANCH, -49, DROP, NIP, SWAP, MINUS, EXIT,

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
200, 249, PLUSSTORE, EXIT,

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
DUP, 204, 96, IZBRANCH, 4, 194, 76, EXIT, DUP, 204, 54, IZBRANCH, 10, DUP, 204, 29, OVER, 204, 44, MINUS, IBRANCH, 8, DUP, 200, 33, OVER, 200, 56, MINUS, PLUS, 204, 119, EXIT,

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
194, 67, 197, 104, DUP, ZEROEQUALS, IZBRANCH, 2, ABORT, 196, 141, 200, 126, 196, 230, FETCH, 203, 162, 196, 230, STORE, DUP, 194, 76, TUCK, 196, 141, SWAP, MOVE, 194, 32, ICHARLIT, DOCREATE, 194, 76, 194, 10, EXIT,

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
DUP, 200, 140, EXIT,

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
ZERO, 200, 24, STORE, ICHARLIT, PDO, 194, 161, 196, 141, EXIT,

/* DUMP */
109, 195, 4, 'D', 'U', 'M', 'P', DOCOLONROM,
#define ROMDEF_PFA_DUMP 902
194, 44, FETCH, TOR, 196, 152, DUP, ZERO, PIQDO, 102, 194, 240, OVER, I, PLUS, OVER, I, MINUS, ICHARLIT, 16, MIN, OVER, ZERO, 193, 16, 192, 4, 192, 4, 192, 4, 192, 4, 192, 4, 192, 4, 192, 4, 192, 4, 192, 30, 198, 192, ICHARLIT, 2, 198, 146, DUP, ZERO, PDO, OVER, I, PLUS, CFETCH, ZERO, 193, 16, 192, 4, 192, 4, 192, 30, 198, 192, 198, 132, PILOOP, -18, ICHARLIT, 16, OVER, MINUS, ICHARLIT, 3, 192, 99, 198, 146, 198, 132, ZERO, PDO, DUP, I, PLUS, CFETCH, DUP, ICHARLIT, 32, LESSTHAN, OVER, ICHARLIT, 127, GREATERTHAN, OR, IZBRANCH, 4, DROP, ICHARLIT, '.', EMIT, PILOOP, -20, DROP, ICHARLIT, 16, PIPLUSLOOP, -100, TWODROP, RFROM, 194, 44, STORE, EXIT,

/* ELSE */
126, 195, 132, 'E', 'L', 'S', 'E', DOCOLONROM,
#define ROMDEF_PFA_ELSE 1027
ICHARLIT, BRANCH, 194, 161, 196, 141, ZERO, 194, 76, SWAP, 198, 177, EXIT,

/* EXECUTE */
251, 195, 7, 'E', 'X', 'E', 'C', 'U', 'T', 'E', DOCOLONROM,
#define ROMDEF_PFA_EXECUTE 1051
DUP, 200, 90, SWAP, 193, 34, PEXECUTE, EXIT,

/* FFIS */
16, 196, 4, 'F', 'F', 'I', 'S', DOCOLONROM,
#define ROMDEF_PFA_FFIS 1067
VM, ICHARLIT, offsetof(EnforthVM, last_ffi), PLUS, FETCH, QDUP, IZBRANCH, 14, DUP, 201, 49, OVER, 201, 58, 203, 129, 198, 132, IFETCH, IBRANCH, -15, EXIT,

/* FIND */
35, 196, 4, 'F', 'I', 'N', 'D', DOCOLONROM,
#define ROMDEF_PFA_FIND 1097
194, 228, 201, 247, EXIT,

/* FMSLASHMOD */
65, 196, 6, 'F', 'M', '/', 'M', 'O', 'D', DOCOLONROM,
#define ROMDEF_PFA_FMSLASHMOD 1112
DUP, TOR, TWODUP, XOR, SWAP, ABS, DUP, TOR, SWAP, TOR, TOR, 195, 68, RFROM, UMSLASHMOD, RFROM, ZEROLESS, IZBRANCH, 18, NEGATE, OVER, ZERONOTEQUALS, IZBRANCH, 9, ONEMINUS, SWAP, RFROM, SWAP, MINUS, SWAP, IBRANCH, 7, RFROM, DROP, IBRANCH, 3, RFROM, DROP, RFROM, ZEROLESS, IZBRANCH, 4, SWAP, NEGATE, SWAP, EXIT,

/* HERE */
78, 196, 4, 'H', 'E', 'R', 'E', DOCOLONROM,
#define ROMDEF_PFA_HERE 1166
200, 249, FETCH, EXIT,

/* HEX */
134, 196, 3, 'H', 'E', 'X', DOCOLONROM,
#define ROMDEF_PFA_HEX 1177
ICHARLIT, 16, 194, 44, STORE, EXIT,

/* HOLD */
146, 196, 4, 'H', 'O', 'L', 'D', DOCOLONROM,
#define ROMDEF_PFA_HOLD 1191
203, 45, FETCH, ONEMINUS, DUP, 203, 45, STORE, CSTORE, EXIT,

/* IF */
159, 196, 130, 'I', 'F', DOCOLONROM,
#define ROMDEF_PFA_IF 1207
ICHARLIT, ZBRANCH, 194, 161, 196, 141, ZERO, 194, 76, EXIT,

/* IMMEDIATE */
177, 196, 9, 'I', 'M', 'M', 'E', 'D', 'I', 'A', 'T', 'E', DOCOLONROM,
#define ROMDEF_PFA_IMMEDIATE 1230
196, 230, FETCH, 200, 56, ONEPLUS, ONEPLUS, DUP, CFETCH, ICHARLIT, 128, OR, SWAP, CSTORE, EXIT,

/* LATEST */
193, 196, 6, 'L', 'A', 'T', 'E', 'S', 'T', DOCOLONROM,
#define ROMDEF_PFA_LATEST 1255
VM, ICHARLIT, offsetof(EnforthVM, latest), PLUS, EXIT,

/* LEAVE */
221, 196, 133, 'L', 'E', 'A', 'V', 'E', DOCOLONROM,
#define ROMDEF_PFA_LEAVE 1269
ICHARLIT, UNLOOP, 194, 161, ICHARLIT, BRANCH, 194, 161, 196, 141, 200, 24, FETCH, DUP, IZBRANCH, 5, 196, 141, SWAP, MINUS, 194, 76, 200, 24, STORE, EXIT,

/* LITERAL */
236, 196, 135, 'L', 'I', 'T', 'E', 'R', 'A', 'L', DOCOLONROM,
#define ROMDEF_PFA_LITERAL 1306
DUP, ICHARLIT, 255, INVERT, AND, ZEROEQUALS, IZBRANCH, 9, ICHARLIT, CHARLIT, 194, 76, 194, 76, IBRANCH, 7, ICHARLIT, LIT, 194, 76, 192, 147, EXIT,

/* LOOP */
15, 197, 132, 'L', 'O', 'O', 'P', DOCOLONROM,
#define ROMDEF_PFA_LOOP 1337
ICHARLIT, PLOOP, 201, 2, EXIT,

/* MSTAR */
49, 197, 2, 'M', '*', DOCOLONROM,
#define ROMDEF_PFA_MSTAR 1348
TWODUP, XOR, ZEROLESS, TOR, ABS, SWAP, ABS, UMSTAR, RFROM, 200, 140, EXIT,

/* MOD */
62, 197, 3, 'M', 'O', 'D', DOCOLONROM,
#define ROMDEF_PFA_MOD 1367
192, 207, DROP, EXIT,

/* PARSEWORD */
80, 197, 10, 'P', 'A', 'R', 'S', 'E', '-', 'W', 'O', 'R', 'D', DOCOLONROM,
#define ROMDEF_PFA_PARSEWORD 1385
TOR, 198, 117, 193, 70, FETCH, 192, 225, RFETCH, TOR, OVER, CFETCH, RFETCH, EQUALS, OVER, AND, IZBRANCH, 7, ICHARLIT, 1, 192, 225, IBRANCH, -13, RFROM, DROP, OVER, SWAP, RFROM, TOR, DUP, ZEROEQUALS, IZBRANCH, 6, RFROM, TWODROP, FALSE, IBRANCH, 18, OVER, CFETCH, RFETCH, EQUALS, IZBRANCH, 6, RFROM, TWODROP, TRUE, IBRANCH, 7, ICHARLIT, 1, 192, 225, IBRANCH, -25, OVER, 198, 117, DROP, MINUS, SWAP, IZBRANCH, 2, ONEPLUS, 193, 70, STORE, OVER, MINUS, EXIT,

/* POSTPONE */
91, 197, 136, 'P', 'O', 'S', 'T', 'P', 'O', 'N', 'E', DOCOLONROM,
#define ROMDEF_PFA_POSTPONE 1468
194, 67, 197, 104, 201, 247, QDUP, ZEROEQUALS, IZBRANCH, 11, 198, 192, 198, 132, ICHARLIT, '?', EMIT, 194, 240, ABORT, ZEROLESS, IZBRANCH, 14, ICHARLIT, LIT, 194, 161, 192, 147, ICHARLIT, 194, 161, 194, 161, IBRANCH, 3, 194, 161, EXIT,

/* QUIT */
176, 197, 4, 'Q', 'U', 'I', 'T', DOCOLONROM,
#define ROMDEF_PFA_QUIT 1515
INITRP, ZERO, 198, 164, STORE, 204, 80, DUP, 204, 89, 193, 180, 198, 132, 203, 61, 194, 240, 198, 164, FETCH, ZEROEQUALS, IZBRANCH, 8, PISQUOTE, 3, 'o', 'k', ' ', 203, 129, IBRANCH, -27,

/* REPEAT */
227, 197, 134, 'R', 'E', 'P', 'E', 'A', 'T', DOCOLONROM,
#define ROMDEF_PFA_REPEAT 1558
193, 247, 198, 177, EXIT,

/* SQUOTE */
12, 198, 130, 'S', '"', DOCOLONROM,
#define ROMDEF_PFA_SQUOTE 1569
ICHARLIT, '"', 197, 104, ICHARLIT, PSQUOTE, 194, 161, DUP, 194, 76, 196, 141, OVER, 194, 32, SWAP, MOVE, EXIT,

/* STOD */
27, 198, 3, 'S', '>', 'D', DOCOLONROM,
#define ROMDEF_PFA_STOD 1595
DUP, ZEROLESS, EXIT,

/* SIGN */
52, 198, 4, 'S', 'I', 'G', 'N', DOCOLONROM,
#define ROMDEF_PFA_SIGN 1606
ZEROLESS, IZBRANCH, 5, ICHARLIT, '-', 196, 166, EXIT,

/* SMSLASHREM */
62, 198, 6, 'S', 'M', '/', 'R', 'E', 'M', DOCOLONROM,
#define ROMDEF_PFA_SMSLASHREM 1624
OVER, TOR, TWODUP, XOR, TOR, ABS, TOR, 195, 68, RFROM, UMSLASHMOD, RFROM, 200, 150, SWAP, RFROM, 200, 150, SWAP, EXIT,

/* SOURCE */
78, 198, 6, 'S', 'O', 'U', 'R', 'C', 'E', DOCOLONROM,
#define ROMDEF_PFA_SOURCE 1654
VM, ICHARLIT, offsetof(EnforthVM, source_len), PLUS, TWOFETCH, EXIT,

/* SPACE */
108, 198, 5, 'S', 'P', 'A', 'C', 'E', DOCOLONROM,
#define ROMDEF_PFA_SPACE 1669
194, 67, EMIT, EXIT,

/* SPACES */
124, 198, 6, 'S', 'P', 'A', 'C', 'E', 'S', DOCOLONROM,
#define ROMDEF_PFA_SPACES 1683
QDUP, IZBRANCH, 6, 198, 132, ONEMINUS, IBRANCH, -7, EXIT,

/* STATE */
137, 198, 5, 'S', 'T', 'A', 'T', 'E', DOCOLONROM,
#define ROMDEF_PFA_STATE 1701
VM, ICHARLIT, offsetof(EnforthVM, state), PLUS, EXIT,

/* THEN */
156, 198, 132, 'T', 'H', 'E', 'N', DOCOLONROM,
#define ROMDEF_PFA_THEN 1714
196, 141, OVER, MINUS, SWAP, CSTORE, EXIT,

/* TYPE */
170, 198, 4, 'T', 'Y', 'P', 'E', DOCOLONROM,
#define ROMDEF_PFA_TYPE 1729
OVER, PLUS, SWAP, TWODUP, NOTEQUALS, IZBRANCH, 7, DUP, CFETCH, EMIT, ONEPLUS, IBRANCH, -9, TWODROP, EXIT,

/* UDOT */
185, 198, 2, 'U', '.', DOCOLONROM,
#define ROMDEF_PFA_UDOT 1750
ZERO, 193, 16, 192, 49, 192, 30, 198, 192, 198, 132, EXIT,

/* UDDOT */
208, 198, 3, 'U', 'D', '.', DOCOLONROM,
#define ROMDEF_PFA_UDDOT 1769
193, 16, 192, 49, 192, 30, 198, 192, 198, 132, EXIT,

/* UNUSED */
226, 198, 6, 'U', 'N', 'U', 'S', 'E', 'D', DOCOLONROM,
#define ROMDEF_PFA_UNUSED 1790
VM, ICHARLIT, offsetof(EnforthVM, dictionary), PLUS, FETCH, VM, ICHARLIT, offsetof(EnforthVM, dictionary_size), PLUS, FETCH, PLUS, 196, 141, MINUS, EXIT,

/* USE */
244, 198, 4, 'U', 'S', 'E', ':', DOCOLONROM,
#define ROMDEF_PFA_USE 1813
194, 67, 197, 104, DUP, ZEROEQUALS, IZBRANCH, 2, ABORT, TWODUP, 201, 166, ZEROEQUALS, IZBRANCH, 11, 198, 192, 198, 132, ICHARLIT, '?', EMIT, 194, 240, ABORT, 196, 141, 200, 126, 196, 230, FETCH, 204, 119, 196, 230, STORE, SWAP, ICHARLIT, 32, OR, 194, 76, ICHARLIT, DOFFI0, 194, 76, 194, 10, 192, 147, DROP, EXIT,

/* VARIABLE */
13, 199, 8, 'V', 'A', 'R', 'I', 'A', 'B', 'L', 'E', DOCOLONROM,
#define ROMDEF_PFA_VARIABLE 1878
194, 254, ZERO, ONEMINUS, 194, 32, ICHARLIT, DOVARIABLE, 194, 76, ZERO, 192, 147, EXIT,

/* WHILE */
74, 199, 133, 'W', 'H', 'I', 'L', 'E', DOCOLONROM,
#define ROMDEF_PFA_WHILE 1901
196, 182, SWAP, EXIT,

/* WORDS */
100, 199, 5, 'W', 'O', 'R', 'D', 'S', DOCOLONROM,
#define ROMDEF_PFA_WORDS 1914
196, 230, FETCH, QDUP, IZBRANCH, 49, DUP, 201, 26, IZBRANCH, 16, DUP, 200, 48, DUP, 201, 49, SWAP, 201, 58, 203, 129, 198, 132, IBRANCH, 23, DUP, 200, 56, ONEPLUS, ONEPLUS, CFETCH, ICHARLIT, 64, AND, ZEROEQUALS, IZBRANCH, 11, DUP, 200, 70, OVER, 203, 188, 198, 192, 198, 132, 200, 56, 204, 132, IBRANCH, -50, TICKNAMES, DUP, ICFETCH, ICHARLIT, 255, NOTEQUALS, IZBRANCH, 25, DUP, ICFETCH, ICHARLIT, 31, AND, TUCK, OVER, PLUS, ONEPLUS, SWAP, ONEPLUS, ROT, QDUP, IZBRANCH, 7, 203, 129, 198, 132, IBRANCH, 2, DROP, IBRANCH, -30, DROP, EXIT,

/* LTBRACKET */
113, 199, 129, '[', DOCOLONROM,
#define ROMDEF_PFA_LTBRACKET 2007
FALSE, 198, 164, STORE, EXIT,

/* BRACKETTICK */
210, 199, 131, '[', '\'', ']', DOCOLONROM,
#define ROMDEF_PFA_BRACKETTICK 2019
192, 63, ICHARLIT, LIT, 194, 161, 192, 147, EXIT,

/* BRACKETCHAR */
220, 199, 134, '[', 'C', 'H', 'A', 'R', ']', DOCOLONROM,
#define ROMDEF_PFA_BRACKETCHAR 2038
194, 121, ICHARLIT, CHARLIT, 194, 161, 194, 76, EXIT,

/* BACKSLASH */
236, 199, 129, '\\', DOCOLONROM,
#define ROMDEF_PFA_BACKSLASH 2052
198, 117, NIP, 193, 70, STORE, EXIT,

/* RTBRACKET */
255, 199, 1, ']', DOCOLONROM,
#define ROMDEF_PFA_RTBRACKET 2064
TRUE, 198, 164, STORE, EXIT,

/* TICKPREVLEAVE */
11, 200, 0, DOCOLONROM,
#define ROMDEF_PFA_TICKPREVLEAVE 2073
VM, ICHARLIT, offsetof(EnforthVM, prev_leave), PLUS, EXIT,

/* TOCFA */
21, 200, 0, DOCOLONROM,
#define ROMDEF_PFA_TOCFA 2082
DUP, 203, 188, SWAP, 200, 56, ONEPLUS, ONEPLUS, ONEPLUS, PLUS, EXIT,

/* TOFFIDEF */
30, 200, 0, DOCOLONROM,
#define ROMDEF_PFA_TOFFIDEF 2097
193, 34, FETCH, EXIT,

/* TOLFA */
45, 200, 0, DOCOLONROM,
#define ROMDEF_PFA_TOLFA 2105
204, 156, AND, VM, ICHARLIT, offsetof(EnforthVM, dictionary), PLUS, FETCH, PLUS, EXIT,

/* TONFA */
53, 200, 0, DOCOLONROM,
#define ROMDEF_PFA_TONFA 2119
200, 56, ONEPLUS, ONEPLUS, ONEPLUS, EXIT,

/* TOROMNFA */
67, 200, 0, DOCOLONROM,
#define ROMDEF_PFA_TOROMNFA 2129
204, 44, ONEPLUS, ONEPLUS, ONEPLUS, EXIT,

/* TOTOKEN */
77, 200, 0, DOCOLONROM,
#define ROMDEF_PFA_TOTOKEN 2139
DUP, 204, 96, IZBRANCH, 2, EXIT, DUP, 201, 26, IZBRANCH, 9, 200, 48, 201, 40, ICHARLIT, 248, PLUS, EXIT, DUP, 204, 54, IZBRANCH, 5, 204, 29, ICFETCH, EXIT, 200, 33, CFETCH, EXIT,

/* TOXT */
87, 200, 0, DOCOLONROM,
#define ROMDEF_PFA_TOXT 2175
VM, ICHARLIT, offsetof(EnforthVM, dictionary), PLUS, FETCH, MINUS, 204, 146, OR, EXIT,

/* QDNEGATE */
123, 200, 0, DOCOLONROM,
#define ROMDEF_PFA_QDNEGATE 2189
ZEROLESS, IZBRANCH, 3, 195, 100, EXIT,

/* QNEGATE */
137, 200, 0, DOCOLONROM,
#define ROMDEF_PFA_QNEGATE 2199
ZEROLESS, IZBRANCH, 2, NEGATE, EXIT,

/* COLD */
147, 200, 0, DOCOLONROM,
#define ROMDEF_PFA_COLD 2208
PISQUOTE, 31, 'E', 'n', 'f', 'o', 'r', 't', 'h', ' ', '(', 'C', ')', ' ', 'M', 'i', 'c', 'h', 'a', 'e', 'l', ' ', 'A', 'l', 'y', 'n', ' ', 'M', 'i', 'l', 'l', 'e', 'r', 203, 129, 194, 240, ABORT, EXIT,

/* DIGITQ */
156, 200, 0, DOCOLONROM,
#define ROMDEF_PFA_DIGITQ 2251
193, 131, ICHARLIT, '0', MINUS, DUP, ZEROLESS, IZBRANCH, 4, DROP, ZERO, EXIT, DUP, ICHARLIT, 9, GREATERTHAN, IZBRANCH, 13, DUP, ICHARLIT, 17, LESSTHAN, IZBRANCH, 4, DROP, FALSE, EXIT, ICHARLIT, 7, MINUS, DUP, ONEPLUS, 194, 44, FETCH, UGREATERTHAN, IZBRANCH, 4, DROP, FALSE, EXIT, TRUE, EXIT,

/* DP */
199, 200, 0, DOCOLONROM,
#define ROMDEF_PFA_DP 2298
VM, ICHARLIT, offsetof(EnforthVM, dp), PLUS, EXIT,

/* ENDLOOP */
246, 200, 0, DOCOLONROM,
#define ROMDEF_PFA_ENDLOOP 2307
194, 161, 196, 141, MINUS, 194, 76, 200, 24, FETCH, 202, 254, EXIT,

/* EVALUATE */
255, 200, 0, DOCOLONROM,
#define ROMDEF_PFA_EVALUATE 2324
203, 61, EXIT,

/* FFIQ */
16, 201, 0, DOCOLONROM,
#define ROMDEF_PFA_FFIQ 2331
200, 56, ONEPLUS, ONEPLUS, CFETCH, ICHARLIT, 32, AND, ZERONOTEQUALS, EXIT,

/* FFIDEFARITY */
23, 201, 0, DOCOLONROM,
#define ROMDEF_PFA_FFIDEFARITY 2345
ICHARLIT, offsetof(EnforthFFIDef, arity), PLUS, ICFETCH, EXIT,

/* FFIDEFNAME */
37, 201, 0, DOCOLONROM,
#define ROMDEF_PFA_FFIDEFNAME 2354
ICHARLIT, offsetof(EnforthFFIDef, name), PLUS, IFETCH, EXIT,

/* FFIDEFNAMELEN */
46, 201, 0, DOCOLONROM,
#define ROMDEF_PFA_FFIDEFNAMELEN 2363
201, 49, DUP, DUP, ICFETCH, IZBRANCH, 4, ONEPLUS, IBRANCH, -6, SWAP, MINUS, EXIT,

/* FINDCODEPRIM */
55, 201, 0, DOCOLONROM,
#define ROMDEF_PFA_FINDCODEPRIM 2380
TWOTOR, ZERO, TICKNAMES, DUP, ICFETCH, ICHARLIT, 255, NOTEQUALS, IZBRANCH, 28, DUP, TWORFETCH, ROT, 202, 135, IZBRANCH, 14, DROP, ICFETCH, ICHARLIT, 128, AND, ZERONOTEQUALS, ICHARLIT, 2, AND, ONEMINUS, TWORFROM, TWODROP, EXIT, ROT, ONEPLUS, ROT, DROP, SWAP, IBRANCH, -33, TWODROP, TWORFROM, TWODROP, FALSE, EXIT,

/* FINDDEF */
72, 201, 0, DOCOLONROM,
#define ROMDEF_PFA_FINDDEF 2426
TWOTOR, 196, 230, FETCH, QDUP, IZBRANCH, 31, DUP, TWORFETCH, ROT, 202, 22, IZBRANCH, 18, DUP, 200, 56, ONEPLUS, ONEPLUS, CFETCH, ICHARLIT, 128, AND, ZERONOTEQUALS, ICHARLIT, 2, AND, ONEMINUS, TWORFROM, TWODROP, EXIT, 200, 56, 204, 132, IBRANCH, -32, TWORFROM, TWODROP, FALSE, EXIT,

/* FINDFFIDEF */
118, 201, 0, DOCOLONROM,
#define ROMDEF_PFA_FINDFFIDEF 2471
TWOTOR, VM, ICHARLIT, offsetof(EnforthVM, last_ffi), PLUS, FETCH, QDUP, IZBRANCH, 22, RFETCH, OVER, 201, 58, EQUALS, IZBRANCH, 12, DUP, TWORFETCH, ROT, 202, 100, IZBRANCH, 5, TWORFROM, TWODROP, TRUE, EXIT, IFETCH, IBRANCH, -23, TWORFROM, TWODROP, FALSE, EXIT,

/* FINDROMDEF */
163, 201, 0, DOCOLONROM,
#define ROMDEF_PFA_FINDROMDEF 2509
TWOTOR, LASTROMDEF, QDUP, IZBRANCH, 31, DUP, TWORFETCH, ROT, 202, 187, IZBRANCH, 18, DUP, 204, 44, ONEPLUS, ONEPLUS, ICFETCH, ICHARLIT, 128, AND, ZERONOTEQUALS, ICHARLIT, 2, AND, ONEMINUS, TWORFROM, TWODROP, EXIT, 204, 44, 203, 148, IBRANCH, -32, TWORFROM, TWODROP, FALSE, EXIT,

/* FINDWORD */
201, 201, 0, DOCOLONROM,
#define ROMDEF_PFA_FINDWORD 2552
TWODUP, 201, 121, QDUP, IZBRANCH, 4, TWOSWAP, TWODROP, EXIT, TWODUP, 201, 75, QDUP, IZBRANCH, 4, TWOSWAP, TWODROP, EXIT, TWODUP, 201, 204, DUP, IZBRANCH, 3, TWOSWAP, TWODROP, EXIT,

/* FOUNDDEFQ */
244, 201, 0, DOCOLONROM,
#define ROMDEF_PFA_FOUNDDEFQ 2583
DUP, 200, 56, ONEPLUS, ONEPLUS, CFETCH, ICHARLIT, 64, AND, ZERONOTEQUALS, IZBRANCH, 5, DROP, TWODROP, FALSE, EXIT, TWODUP, 203, 175, NOTEQUALS, IZBRANCH, 5, DROP, TWODROP, FALSE, EXIT, DUP, 201, 26, IZBRANCH, 4, 202, 91, EXIT, 200, 70, SWAP, QDUP, IZBRANCH, 23, ONEMINUS, TOR, OVER, CFETCH, OVER, CFETCH, 195, 43, IZBRANCH, 6, TWODROP, RFROM, DROP, FALSE, EXIT, ONEPLUS, SWAP, ONEPLUS, SWAP, RFROM, IBRANCH, -24, TWODROP, TRUE, EXIT,

/* FOUNDFFIQ */
19, 202, 0, DOCOLONROM,
#define ROMDEF_PFA_FOUNDFFIQ 2652
200, 48, 202, 100, EXIT,

/* FOUNDFFIDEFQ */
88, 202, 0, DOCOLONROM,
#define ROMDEF_PFA_FOUNDFFIDEFQ 2661
201, 49, SWAP, QDUP, IZBRANCH, 23, ONEMINUS, TOR, OVER, CFETCH, OVER, ICFETCH, 195, 43, IZBRANCH, 6, TWODROP, RFROM, DROP, FALSE, EXIT, ONEPLUS, SWAP, ONEPLUS, SWAP, RFROM, IBRANCH, -24, TWODROP, TRUE, EXIT,

/* FOUNDPRIMQ */
97, 202, 0, DOCOLONROM,
#define ROMDEF_PFA_FOUNDPRIMQ 2696
DUP, DUP, ICFETCH, ICHARLIT, 31, AND, PLUS, ONEPLUS, TOR, DUP, ICFETCH, ICHARLIT, 31, AND, ROT, NOTEQUALS, IZBRANCH, 5, TWODROP, RFROM, FALSE, EXIT, ONEPLUS, OVER, CFETCH, OVER, ICFETCH, 195, 43, IZBRANCH, 5, TWODROP, RFROM, FALSE, EXIT, ONEPLUS, SWAP, ONEPLUS, SWAP, DUP, RFETCH, EQUALS, IZBRANCH, -20, TWODROP, RFROM, TRUE, EXIT,

/* FOUNDROMDEFQ */
132, 202, 0, DOCOLONROM,
#define ROMDEF_PFA_FOUNDROMDEFQ 2748
DUP, 204, 44, ONEPLUS, ONEPLUS, ICFETCH, ICHARLIT, 64, AND, ZERONOTEQUALS, IZBRANCH, 5, DROP, TWODROP, FALSE, EXIT, TWODUP, 204, 67, NOTEQUALS, IZBRANCH, 5, DROP, TWODROP, FALSE, EXIT, 200, 80, SWAP, QDUP, IZBRANCH, 23, ONEMINUS, TOR, OVER, CFETCH, OVER, ICFETCH, 195, 43, IZBRANCH, 6, TWODROP, RFROM, DROP, FALSE, EXIT, ONEPLUS, SWAP, ONEPLUS, SWAP, RFROM, IBRANCH, -24, TWODROP, TRUE, EXIT,

/* HALT */
184, 202, 0, DOCOLONROM,
#define ROMDEF_PFA_HALT 2809
PHALT, EXIT,

/* HERETOCHAIN */
245, 202, 0, DOCOLONROM,
#define ROMDEF_PFA_HERETOCHAIN 2815
QDUP, IZBRANCH, 21, DUP, CFETCH, OVER, DUP, 196, 141, SWAP, MINUS, SWAP, CSTORE, QDUP, IZBRANCH, 4, MINUS, IBRANCH, 3, DROP, ZERO, IBRANCH, -22, EXIT,

/* HIDE */
251, 202, 0, DOCOLONROM,
#define ROMDEF_PFA_HIDE 2843
196, 230, FETCH, 200, 56, ONEPLUS, ONEPLUS, DUP, CFETCH, ICHARLIT, 64, OR, SWAP, CSTORE, EXIT,

/* HLD */
23, 203, 0, DOCOLONROM,
#define ROMDEF_PFA_HLD 2862
VM, ICHARLIT, offsetof(EnforthVM, hld), PLUS, EXIT,

/* HLDEND */
42, 203, 0, DOCOLONROM,
#define ROMDEF_PFA_HLDEND 2871
ICHARLIT, kEnforthCellSize * 8 * 3, EXIT,

/* INTERPRET */
51, 203, 0, DOCOLONROM,
#define ROMDEF_PFA_INTERPRET 2878
VM, ICHARLIT, offsetof(EnforthVM, source_len), PLUS, TWOSTORE, ZERO, 193, 70, STORE, 194, 67, 197, 104, DUP, IZBRANCH, 47, 201, 247, QDUP, IZBRANCH, 17, ONEPLUS, 198, 164, FETCH, ZEROEQUALS, OR, IZBRANCH, 5, 196, 26, IBRANCH, 28, 194, 161, IBRANCH, 24, 203, 204, IZBRANCH, 10, 198, 164, FETCH, IZBRANCH, 15, 197, 25, IBRANCH, 11, 198, 192, 198, 132, ICHARLIT, '?', EMIT, 194, 240, ABORT, IBRANCH, -52, TWODROP, EXIT,

/* ITYPE */
58, 203, 0, DOCOLONROM,
#define ROMDEF_PFA_ITYPE 2946
OVER, PLUS, SWAP, TWODUP, NOTEQUALS, IZBRANCH, 7, DUP, ICFETCH, EMIT, ONEPLUS, IBRANCH, -9, TWODROP, EXIT,

/* IXTFETCH */
126, 203, 0, DOCOLONROM,
#define ROMDEF_PFA_IXTFETCH 2965
DUP, ICFETCH, SWAP, ONEPLUS, ICFETCH, ICHARLIT, 8, LSHIFT, OR, EXIT,

/* LFACOMMA */
145, 203, 0, DOCOLONROM,
#define ROMDEF_PFA_LFACOMMA 2979
DUP, 194, 76, ICHARLIT, 8, RSHIFT, 194, 76, EXIT,

/* NAMELENGTH */
159, 203, 0, DOCOLONROM,
#define ROMDEF_PFA_NAMELENGTH 2992
200, 56, ONEPLUS, ONEPLUS, CFETCH, ICHARLIT, 31, AND, EXIT,

/* NFALENGTH */
172, 203, 0, DOCOLONROM,
#define ROMDEF_PFA_NFALENGTH 3005
DUP, 201, 26, IZBRANCH, 5, DROP, ZERO, IBRANCH, 3, 203, 175, EXIT,

/* NUMBERQ */
185, 203, 0, DOCOLONROM,
#define ROMDEF_PFA_NUMBERQ 3021
OVER, CFETCH, DUP, ICHARLIT, '-', EQUALS, OVER, ICHARLIT, '+', EQUALS, OR, IZBRANCH, 18, ICHARLIT, '-', EQUALS, IZBRANCH, 4, TRUE, IBRANCH, 2, FALSE, TOR, ICHARLIT, 1, 192, 225, RFROM, IBRANCH, 3, DROP, ZERO, TOR, TWODUP, ZERO, ZERO, TWOSWAP, 193, 86, IZBRANCH, 8, DROP, TWODROP, RFROM, DROP, ZERO, IBRANCH, 10, DROP, TWONIP, DROP, RFROM, ZEROLESS, IZBRANCH, 2, NEGATE, TRUE, EXIT,

/* REVEAL */
201, 203, 0, DOCOLONROM,
#define ROMDEF_PFA_REVEAL 3083
196, 230, FETCH, 200, 56, ONEPLUS, ONEPLUS, DUP, CFETCH, ICHARLIT, 191, AND, SWAP, CSTORE, EXIT,

/* ROMTOCFA */
7, 204, 0, DOCOLONROM,
#define ROMDEF_PFA_ROMTOCFA 3102
DUP, 204, 67, SWAP, 204, 44, ONEPLUS, ONEPLUS, ONEPLUS, PLUS, EXIT,

/* ROMTOLFA */
26, 204, 0, DOCOLONROM,
#define ROMDEF_PFA_ROMTOLFA 3117
204, 156, AND, TICKROMDEF, PLUS, EXIT,

/* ROMDEFQ */
41, 204, 0, DOCOLONROM,
#define ROMDEF_PFA_ROMDEFQ 3127
ICHARLIT, 8, RSHIFT, ICHARLIT, 192, TUCK, AND, EQUALS, EXIT,

/* ROMNAMELENGTH */
51, 204, 0, DOCOLONROM,
#define ROMDEF_PFA_ROMNAMELENGTH 3140
204, 44, ONEPLUS, ONEPLUS, ICFETCH, ICHARLIT, 31, AND, EXIT,

/* TIB */
64, 204, 0, DOCOLONROM,
#define ROMDEF_PFA_TIB 3153
VM, ICHARLIT, offsetof(EnforthVM, tib), PLUS, EXIT,

/* TIBSIZE */
77, 204, 0, DOCOLONROM,
#define ROMDEF_PFA_TIBSIZE 3162
ICHARLIT, 80, EXIT,

/* TOKENQ */
86, 204, 0, DOCOLONROM,
#define ROMDEF_PFA_TOKENQ 3169
204, 146, AND, ZEROEQUALS, EXIT,

/* UDSLASHMOD */
93, 204, 0, DOCOLONROM,
#define ROMDEF_PFA_UDSLASHMOD 3178
TOR, ZERO, RFETCH, UMSLASHMOD, RFROM, SWAP, TOR, UMSLASHMOD, RFROM, EXIT,

/* XTCOMMA */
102, 204, 0, DOCOLONROM,
#define ROMDEF_PFA_XTCOMMA 3192
DUP, ICHARLIT, 8, RSHIFT, 194, 76, 194, 76, EXIT,

/* XTFETCH */
116, 204, 0, DOCOLONROM,
#define ROMDEF_PFA_XTFETCH 3205
DUP, CFETCH, SWAP, ONEPLUS, CFETCH, ICHARLIT, 8, LSHIFT, OR, EXIT,

/* XTFLAG */
129, 204, 0, DOCOLONROM,
#define ROMDEF_PFA_XTFLAG 3219
ICHARLIT, 128, ICHARLIT, 8, LSHIFT, EXIT,

/* XTMASK */
143, 204, 0, DOCOLONROM,
#define ROMDEF_PFA_XTMASK 3229
ICHARLIT, 255, ICHARLIT, 63, ICHARLIT, 8, LSHIFT, OR, EXIT,

#define ROMDEF_LAST 3225
