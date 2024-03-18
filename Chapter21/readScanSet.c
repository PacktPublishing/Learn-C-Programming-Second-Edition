// readScanSet.c
// Chapter 21
// Learn C Programming, 2nd Edition
//
// Demonstrate how to use a scan set to limit
// character inputs.
//
// compile with: cc readScanSet.c -o readScanSet -Wall -Werror -std=c17


#include <stdio.h>


// Test inputs:
//
// aayyeeuuiioo<return>
//
// aeimwouy<return>
//
// a e i o u y<return>


enum { kBufferSize = 80 };


int main( void )  {
  char stringBuffer[ kBufferSize ] = {0};
  printf( "Enter only vowels: " );
  scanf(  "%[aeiouy]" , stringBuffer );
  printf( "Processed string: [%s]\n\n" , stringBuffer );

  return 0;
}

  /* eof */
