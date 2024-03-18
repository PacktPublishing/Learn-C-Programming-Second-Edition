// bitpattern_0x41.c
// Chapter 4: Using Variables and Assignment
// Learn C Programming, 2nd Edition
//
// This program demonstrates how the bit pattern
// 0100 0001 (hex 41, decimal 65) can yield different valid values
// depending upon the data type used to interpret
// it (as well as the bytes around it).
//
// This will also show how various integer values are internally
// represented. (Little-endian or big-endian).
//
// NOTE: For now, ignore the casting & bit-fiddling that needs to happen
//       to get the internal bytes to print uninterpreted.
//       Instead, pay attention to the bit pattern of each value for
//       each data data type. 0x41 and only 0x41 appears in each.
//
// Compile with:
//
//    cc bitpattern_0x41.c -o bitpattern_0x41 -Wall -Werror -std=c17
//
#include <stdio.h>

void printBytes( int nBytes , unsigned char* pBytes );

int main(int argc, char *argv[])  {
  char           chr = 0x41;      // only 1 byte
  short          sht = 0x41;      // little- or big-endian?
  int            num = 0x41;      // little- or big-endian?
  long           lng = 0x41;      // little- or big-endian?
  float          flt = 8.0f;      // float format specified by IEEE
  double         dbl = 131072.0;  // double format specified by IEEE
  long double    ldbl = 0.0;      // long double format set by IEEE
  unsigned char* pLdbl = (unsigned char*)&ldbl;
  pLdbl[7] = 0x41;

  printf( "       char: %8c    " , chr );
  printBytes( sizeof( chr ) , (unsigned char*)&chr );

  printf( "      short: %8d    " , sht );
  printBytes( sizeof( sht ) , (unsigned char*)&sht );

  printf( "        int: %8d    " , num );
  printBytes( sizeof( num ) , (unsigned char*)&num );

  printf( "       long: %8ld    " , lng );
  printBytes( sizeof( lng ) , (unsigned char*)&lng );

  printf( "      float: %8.1f    " , flt );
  printBytes( sizeof( flt ) , (unsigned char*)&flt );

  printf( "     double: %8.1f    " , dbl );
  printBytes( sizeof( dbl ) , (unsigned char*)&dbl );

  printf( "long double: % 10.2Le " , ldbl );
  printBytes( sizeof( ldbl ) , (unsigned char*)&ldbl );

  printf( "\n" );
}

  // Given the # of bytes, and a pointer to the value,
  // print out each byte in hexadecimal.
  //
  // ALERT! Big-fiddling happens here.
  //
void printBytes( int nBytes , unsigned char* pBytes )  {
  for( int i = 0 ; i < nBytes ; i++)  {
    printf ("%02x ", pBytes[ i ] );
  }
  printf ("\n");
}


  // eof
