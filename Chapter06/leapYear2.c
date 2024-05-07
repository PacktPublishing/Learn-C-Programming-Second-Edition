  // leapyear2.c
  // Chapter 6
  // Learn C Programming, 2nd Edition
  //
  // Our second pass at a leap year program.
  // In this version, we use "if/else if/else" logic.
  // Note: in if/else logic, only one of each condition is
  //       evaluated. Once the condition is met, execution
  //       resumes at the end of the complex statement.
  //
  // Compile with:
  //
  //    cc leapyear2.c -o leapyear2 -Wall -Werror -std=c17


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


  // isLeapYear logic conforms to algorithm given in
  // https://en.wikipedia.org/wiki/Leap_year.
  //
bool isLeapYear( int year )  {
  bool isLeap = false;

    // Gregorian calendar leap year calculation.
    // Cannot use years before 1 using BC or BCE year notation.
    //
  if( (year % 4 ) != 0 )          // Year is not a multiple of 4.
    isLeap = false;
  else if( ( year % 400 ) == 0 )  // Year is a multiple of 400.
    isLeap = true;
  else if( (year % 100) == 0 )    // Year is multiple of 100.
    isLeap = false;
  else
    isLeap = true;                // Year is a multiple of 4 (other conditions
                                  // 400 years, 100 years) already considered.
  return isLeap;
}

  // eof
