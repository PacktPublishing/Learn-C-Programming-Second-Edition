  // calcLength.c
  // Chapter 5: Exploring Operators and Expressions
  // Learn C Programming, 2nd Edition
  //
  // Program to demonstrate a complex expression
  // two different ways.
  // First compute the value with a complex expression.
  // Then compute the value again with a sequence of simple expressions.


#include <stdio.h>


int feetToInches( double feet )  {
  int inches = feet * 12;

  return inches;
}


int main(int argc, char *argv[])  {
  int inches   = 8;
  int totalInches  = 0;

    // 3 additions in 1 statement with single assignment to totalInches
    // (a complex statement).
    //
  totalInches = 5 + inches + feetToInches( 3.5 );
  printf( "Calculated length = %d\n" , totalInches );

    // 3 additions in 3 statements accumulated in the variable totalInches.
    //
  totalInches = 5;
  totalInches = totalInches + inches;
  totalInches = totalInches + feetToInches( 3.5 );
  printf( "Calculated length = %d\n" , totalInches );
}

  //  eof
