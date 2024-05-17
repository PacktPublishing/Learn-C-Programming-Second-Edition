// readWidth.c
// Chapter 21
// Learn C Programming, 2nd Edition
//
// Demonstrate how to use the field with specifier
// to read data elements (1st approximation).
// See also readDAte.c for a better solution.
//
// compile with: cc readWidth.c -o readWidth -Wall -Werror -std=c17


#include <stdio.h>


// Test inputs:
//
// 12012021<return>
//
//   12   02   2021<return>
//
// 12252021<return>
//
//  9302021<return>
//
// 12 52021<return>
//
// 7/4/2021<return>


int main( void )  {
  int year , month , day;
  int numScanned;
    while( printf("Enter mmddyyyy (any other character to quit): "),
           numScanned = scanf( "%2d%2d%4d" , &month , &day , &year ) ,
           numScanned > 0 )  {
        printf( "%d/%d/%d\n\n" , month , day , year );
      }
  printf( "\nDone\n" );

  return 0;
}

  // eof
