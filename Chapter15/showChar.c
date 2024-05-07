// showCar.c
// Chapter 15
// Learn C Programming, 2nd Edition
//
// Demonstrate how to
// 1) create character variables
// 2) assign character values as characters and as integer values
// 3) print out an individual characer as
//    a) a character
//    b) its decimal value
//    c) its hexadecimal value
//
// compile with:
//   cc showCar.c -o showCar -Wall -Werror -std=c17


#include <stdio.h>


void showChar( char ch );

int main( void )  {
    signed char aChar = 'A';
           char c1    = 65 ;
           char c2    = 'a';
           char c3    = 97 ;
           char c4    = '7';
  unsigned char aByte = 7;

  showChar( aChar );
  showChar( c1 );
  showChar( c2 );
  showChar( c3 );
  showChar( c4 );
  showChar( aByte );
  return 0;
}

void showChar( char ch )  {
  printf( "ch = '%c' (%d) [%#x]\n" , ch , ch , ch );
}

  /* eof */
