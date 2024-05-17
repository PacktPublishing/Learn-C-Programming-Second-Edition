  // Inf_Nan.c
  // Chapter 5: Exploring Operators and Expressions
  // Learn C Programming, 2nd Edition
  //
  // Program to demonstrate a complex expression
  // two different ways.
  // First compute the value with a complex expression.
  // Then compute the value again with a sequence of simple expressions.


#include <stdio.h>
#include <math.h>


int main( void ) {
  double y = 1 / 0.0;
  printf( " 1 / 0.0 = %f\n" , y );

  y = -1/0.0;
  printf( "-1 / 0.0 = %f\n" , y );

  y = log( 0 );
  printf( "log( 0 ) = %f\n" , y );

  y = sqrt( -1 );
  printf( "Square root of -1 = %f\n" , y );
  return 0;
}

  // eof
