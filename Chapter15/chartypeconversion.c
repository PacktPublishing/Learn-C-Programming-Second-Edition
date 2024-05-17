// chartypeconversion.c
// Chapter 15
// Learn C Programming, 2nd Edition
//
// Demonstrate how
//  * signed char, unsigned char, and plain char
//    are converted to int when their values
//    are -1 (signed) or 255 (unsigned).
//
// This will be revisited in Chapter 22: Working with Files with the program
//   EOF_IntvsUnsignedChar.c
// where use of casting appropriately performs correct conversions.
//
// compile with:
//   cc chartypes.c -o chartypes -Wall -Werror -std=c17


#include <stdio.h>


int main(int argc, char *argv[]) {
  unsigned char uc = -1; // 255
  signed   char sc = -1; // -1
           char c  = -1; // ??

  signed int unsignedCh = uc; // unsigned char (-1) converted to int:
                              //   unsigned bit pattern presevered in wider int size.

  signed int signedCh = sc;   // signed char (-1) converted to int
                              //   signed-ness extended from byte to wider int size.

  signed int plainCh = c;     // plain char (-1) converted to 1nt
                              //   IMPLEMENTATION DEPENDENT: you need to verify.


  printf( " unsigned char(-1) as int is [%d]\n", unsignedCh );
  printf( "   signed char(-1) as int is [%d]\n", signedCh );
  printf( "    plain char(-1) as int is [%d]\n", plainCh );

  return 0;
}