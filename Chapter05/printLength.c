  // printLength.c
  // Chapter 5: Exploring Operators and Expressions
  // Learn C Programming, 2nd Edition
  //
  // Program to print a length in given meters as well as
  // in feed (converted from meters). Consideration must be
  // given to values effectively 1.0 feet but which will never
  // be exactly 1.0 feet -- they'll be more like 1.0000000987 feet,
  // or 1.0 for any practical purpose.
  // We consider 1.0 feet within 4 significant digits.


#include <stdio.h>


const double inchesPerFoot = 12.0;
const double inchesPerMeter = 39.67;


void printLength( double meters );


int main( void )  {
  printLength( 0.0 );
  printLength( 1.0 );
  printLength( inchesPerFoot / inchesPerMeter );
  printLength( 2.5 );

  return 0;
}


void printLength(  double meters )  {
  double feet = meters * inchesPerMeter / inchesPerFoot;
  printf( "Length = %f meter%c\n" ,
          meters,
          meters == 1.0 ? ' ' : 's'  );
  printf( "Length = %f %s\n\n" ,
          feet,
          0.99995 < feet && feet < 1.00005 ? "foot" : "feet" );
}

  //  eof
