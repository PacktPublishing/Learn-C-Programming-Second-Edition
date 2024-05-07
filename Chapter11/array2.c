// array2.c
// Chapter 11
// Learn C Programming, 2nd Edition
//
// Demonstrate arroy bounds issues.
//
// Compile with:
//
//    cc array2.c -o array2 -Wall -Werror -std=c17


#include <stdio.h>


int main( void )  {
  int anArray[10] = {0};  // Initialize the whole thing to 0.
  int x, y , z;
  x = 11;
  y = 12;
  z = 13;

//  anArray[ 11 ] = 7;  // Compiler error!
  anArray[ x ]  = 0;  // No compiler error, but runtime error!

  return 0;
}

  /* eof */
