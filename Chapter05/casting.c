  // casting.c
  // Chapter 5: Exploring Operators and Expressions
  // Learn C Programming, 2nd Edition
  //
  // Program to demonstrate casting
  // for predictable results.


#include <stdio.h>


int main( void )  {
  int    numerator   = 33;
  int    denominator =  5;
  double result      = 0.0;


  result = numerator / denominator;
  printf( "Truncation:       (int) %d   /    (int) %d    = %.1g\n\n" ,
          numerator , denominator , result );

  result = (double) numerator / denominator;
  printf( "No truncation: (double) %.1f /    (int) %d    = %.1f\n" ,
          (double)numerator , denominator , result );

  result = numerator / (double)denominator;
  printf( "                  (int) %d   / (double) %.1f  = %.1f\n" ,
           numerator , (double)denominator , result );

  return 0;
}

   //  eof
