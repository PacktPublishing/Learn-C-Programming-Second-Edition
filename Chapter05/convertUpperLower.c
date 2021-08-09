  // convertUpperLower.c
  // Chapter 5: Exploring Operators and Expressions
  // Learn C Programming, 2nd Edition
  //
  // Program to convert a lower case letter to upper case
  // and an upper case letter to lower case (operations on
  // characters).


#include <stdio.h>


int main( void )  {
  char lowerChar = 'e';
  char upperChar = 'S';

  char anUpper = lowerChar - 32;
  char aLower  = upperChar + 32;

  printf( "Lower case '%c' can be changed to upper case '%c'\n" ,
           lowerChar , anUpper );
  printf( "Upper case '%c' can be changed to lower case '%c'\n" ,
           upperChar , aLower );
  return 0;
}

  // eof