// readString.c
// Chapter 21
// Learn C Programming, 2nd Edition
//
// Demonstrate how to read a string with scanf().
// Compare to readString2.c
//
// compile with: cc readString.c -o readString -Wall -Werror -std=c17


#include <stdio.h>


// Test inputs:
//
// Anything up to the white space<return>
//
// Every_thing%before;any:white'space\(will%be read into an array.)<return>
//
//     Skipping initial white space.<return>


enum { bufferSize = 80 };


int main( void )  {
  char stringBuffer[ bufferSize ] = {0};

  printf( "Enter a string: " );
  scanf(  "%s" , stringBuffer );
  printf( "Processed string: [%s]\n\n" , stringBuffer );

  return 0;
}

  /* eof */
