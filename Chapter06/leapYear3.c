  // leapYear3.c
  // Chapter 6
  // Learn C Programming, 2nd Edition
  //
  // Our third `pass at a leap year program.
  // In this version, we use nested if statements.
  //
  // Compile with:
  //
  //    cc leapyear3.c -o leapyear3 -Wall -Werror -std=c17


#include <stdio.h>
#include <stdbool.h>


bool isLeapYear( int );


int main( void )  {
  int year;

  printf( "Determine if a year is a leap year or not.\n\n" );
  printf( "Enter year: ");
  scanf(  "%d" , &year );

    // A more C-like version.
  printf( "%d year is%sa leap year\n" , year , isLeapYear( year ) ? " " : " not " );

  return 0;
}


bool isLeapYear( int year )  {
  bool isLeap = false;

    // Leap years in the Gregorian calendar.
    // Cannot use years before 1 using BC or BCE notation.
    //
  if( (year % 4 ) != 0 )        // Year is not a multiple of 4.
    isLeap = false;
  else  {                       // Year is a multiple of 4.
    if( (year % 400 ) == 0 )
      isLeap = true;
    else if( (year % 100 ) == 0 )
      isLeap = false;
    else
      isLeap = true;
  }
  return isLeap;
}

  // eof
