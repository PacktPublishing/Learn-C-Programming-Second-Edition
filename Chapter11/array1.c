// array1.c
// Chapter 11
// Learn C Programming, 2nd Edition
//
// Demonstrate how to declare and initialize
// arrays.
//
// Compile with:
//
//    cc array1.c -o array1 -Wall -Werror -std=c17


#include <stdio.h>


int main( void )  {
  int   anArray[10]  = {0}; // Initialize the whole thing to 0.

  short typeSize   = sizeof( short );
  short arraySize  = sizeof( anArray );
  short elementNum = arraySize / typeSize;

  printf( "    sizeof(short) = %2d bytes\n" , typeSize  );
  printf( "  sizeof(anArray) = %2d bytes\n" , arraySize  );
  printf( "      anArray[] has %2d elements\n\n" , elementNum );

     // Dynamically allocate array size via initialization.

  float lengthArray[] = { 1.0 , 2.0 , 3.0 , 4.0 , 3.0 , 2.0 , 1.0 };

  typeSize   = sizeof( float );
  arraySize  = sizeof( lengthArray );
  elementNum = arraySize / typeSize;

  printf( "        sizeof(float) = %2d bytes\n" , typeSize  );
  printf( "  sizeof(lengthArray) = %2d bytes\n" , arraySize  );
  printf( "      lengthArray[] has %2d elements\n\n" , elementNum );

  // Allocate a VLA

  const int kVLASize = 12;

  long  vlArray[ kVLASize ];

  typeSize  = sizeof( long );
  arraySize  = sizeof( vlArray );
  elementNum = arraySize / typeSize;

  printf( "      sizeof(long) = %2d bytes\n" , typeSize  );
  printf( "   sizeof(vlArray) = %2d bytes\n" , arraySize  );
  printf( "         vlArray has %2d elements\n\n" , elementNum );

  return 0;
}

  /* eof */
