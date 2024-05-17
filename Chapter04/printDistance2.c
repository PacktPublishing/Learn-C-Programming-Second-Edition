//  printDistance2.c
//  Chapter 4: Using Variables and Assignment
//  Learn C Programming, 2nd Edition
//
//  A better function that demonstrates the use of
//  assignment via actual parameters and
//  explicit assignment inside the function.
//
//  This one is better because
//  1) actual parameter name is meaningful of its use, and
//  2) local variable yards is explicitly declared so its
//     value and use are clear.
//

#include <stdio.h>

  // Function prototypes.
void printDistance( double );

int main( void )  {
  double feet = 5280.0;
  printf( "feet = %5.4g\n\n" , feet );

  printDistance( feet );
  return 0;
}

  // Given feet, print the distance in feet and yards.
  //
void printDistance( double feet )  {
  double yards = feet / 3.0;

  printf( "The distance in feet is %5.3g\n"  , feet );
  printf( "The distance in yards is %5.3g\n\n" , yards );
}

  // eof
