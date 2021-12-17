// readString2.c
// Chapter 21
// Learn C Programming, 2nd Edition
//
// Demonstrate how to read and write a string with
// gets() and puts().
// Compare this program to readString.c
//
// compile with: 
//   cc readString2.c -o readString2 -Wall -Werror -std=c17


// DANGER: Do Not Ever Use gets().
//
//         Instead, use fgets() or gets_s() (C11 and later).


#include <stdio.h>


enum { kBufferSize = 80 };


int main( void )  {
  char stringBuffer[ kBufferSize ] = {0};
  
    // UNSAFE: Do Not Ever Use gets().

  printf( "Enter a string: " );
  gets( stringBuffer );
  puts( "You entered: " );
  puts( stringBuffer );
  
    // SAFE: Instead, use fgets() 
    //       Or use gets_s() in C11 and later.

  printf( "\nEnter another string: " );
  fgets( stringBuffer , kBufferSize , stdin );
  puts( "You entered: " );
  puts( stringBuffer );
  
  return 0;
}

  /* eof */
  