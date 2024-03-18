  // leapyeari1.c
  // Chapter 6
  // Learn C Programming, 2nd Edition
  //
  // Our first pass at a leap year program.
  // In this version, we use "fall through" logic
  // using return to end the evaluation.
  //
  // Compile with:
  //
  //    cc leapyear1.c -o leapyear1 -Wall -Werror -std=c17


#include <stdio.h>
#include <stdbool.h>


bool isLeapYear( int );


int main( void )  {
  int year;

  printf( "Determine if a year is a leap year or not.\n\n" );
  printf( "Enter year: ");
  scanf(  "%d" , &year );

   // A simple version.
   //
  if( isLeapYear( year ) )
    printf( "%d year is a leap year\n" , year );
  else
    printf( "%d year is not a leap year \n" , year );

   // A more C-like version.
   //
  printf( "%d year is%sa leap year\n" , year , isLeapYear( year ) ? " " : " not " );

  return 0;
}


bool isLeapYear( int year )  {
  if( (year % 4) == 0  ) return true;

  return false;
}

  // eof

