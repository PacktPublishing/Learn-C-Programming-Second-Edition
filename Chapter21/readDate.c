// readDate.c
// Chapter 21
// Learn C Programming, 2nd Edition
//
// Demonstrate how to use field width specifiers
// to read data elements with the non-assighnment operater
// to parse characters between date elements.
//
// compile with: cc readDate.c -o readDate -Wall -Werror -std=c17


#include <stdio.h>


// Test Inputs:
//
// 12x01x2021<return>
//
//   12   02   2021<return>
//
// 12^25^2021<return>
//
//  9!30!2022<return>
//
// 12x 5y2021<return>
//
// 7/4/2022<return>
//
// x<return>


int main( void )  {
  int year , month , day;
  int numScanned;
  while( printf("Enter mm*dd*yyyy (any other character to quit): "),
         numScanned = scanf( "%2d%*c%2d%*c%4d" , &month , &day , &year ) ,
         numScanned > 0 )  {
    printf( "%d.%d.%d\n\n" , month , day , year );
  }
  printf( "\nDone\n" );

  return 0;
}

  /* eof */
