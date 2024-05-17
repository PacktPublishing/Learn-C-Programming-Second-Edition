// EOF_IntVsUnsignedChar.c
// Chapter 22
// Learn C Programming, 2nd Edition
//
// Demonstrate
//  1) comparison of EOF to unsigned char with and without casting.
//
// When a value has an unsigned type and is converted to a wider signed type,
// its most-significant will be treated as part of the value, not as the signed bit.
//
// When a value has an unsigned type and is converted to a wider unsigned type,
// its most-significant will be treated as part of the value.
//
// When a value has a signed type and is converted to a wider signed type,
// its signed-bit (most significant bit) will be preserved in the wider type.
//
// When a value has a signed type and is converted to a wider unsigned type,
// its signed-bit (most significant bit) will be preserved in the wider type.
//
// compile with:
//   cc EOF_IntVsUnsignedChar.c -o EOF_IntVsUnsignedChar -Wall -Werror -std=c17


#include <stdio.h>


int main(int argc, char *argv[])  {
  unsigned char uc = 255; // -1
    signed char sc =  -1; // -1
           char c  =  -1; // ?? (implementation dependent)

  signed int unsignedCh = uc; // unsigned char (-1) converted to int:
                              //   unsigned bit pattern persevered in wider int size.

  signed int signedCh = sc;   // signed char (-1) converted to int
                              //   signed-ness extended from byte to wider int size.

  signed int plainCh = c;     // plain char (-1) converted to 1nt
                              //   IMPLEMENTATION DEPENDENT: you need to verify.

  printf( " unsigned char is %2lu bytes\n"   , sizeof( unsigned char) );
  printf( "   signed char is %2lu bytes\n"   , sizeof( signed char) );
  printf( "    plain char is %2lu byte\n"    , sizeof( char) );
  printf( "  unsigned int is %2lu bytes\n"   , sizeof( unsigned int) );
  printf( "    signed int is %2lu bytes\n\n" , sizeof( signed int) );

  printf( " unsigned char uc (-1) as unsigned int is [%d]\n"   , unsignedCh );
  printf( "   signed char sc (-1) as   signed int is [%d]\n"   , signedCh );
  printf( "    plain char  c (-1) as   signed int is [%d]\n\n" , plainCh );

  printf( "(constant) EOF is %d\n\n", EOF );

  uc = EOF;  // converts -1 to 255.
  printf( " uc = EOF is %d (%d is converted to %d)\n\n", uc , EOF , uc );

  printf( "    (constant) EOF [%d] and unsigned char uc [%d] are NOT equal\n" , EOF , uc );

  if( (unsigned char) EOF == uc )
       printf( "(unsigned char)EOF [%d] and unsigned char uc [%d] are equal\n" ,
               (unsigned char)EOF , uc );
  else printf( "(unsigned char)EOF [%d] and unsigned char uc [%d] are NOT equal\n" ,
               (unsigned char)EOF , uc );

  if( EOF == (signed char)uc )
       printf( "    (constant) EOF [%d] and (signed char)uc [%d] are equal\n" ,
               EOF , (signed char)uc );
  else printf( "    (constant) EOF [%d] and (signed char)uc [%d] are NOT equal\n" ,
               EOF , (signed char)uc );

  if( EOF == (signed int)uc )
       printf( "    (constant) EOF [%d] and (signed int)uc [%d] are equal\n" ,
               EOF , (signed int)uc );
  else printf( "    (constant) EOF [%d] and (signed int)uc [%d] are NOT equal\n" ,
               EOF , (signed int)uc );

  return 0;
}

  /* eof */