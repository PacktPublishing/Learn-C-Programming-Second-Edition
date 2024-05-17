// pointers3.c
// Chapter 13
// Learn C Programming, 2nd Edition
//
// This program builds on program pointers2.c
//
// Demonstrates how to use target addresses without
// pointer variables.
//
// Specifically
// 1) removes the pointer variables in main()
// 2) call function with references w/o pointer variables.
//
// compile with:
//
//   cc pointers3.c -o pointers3 -Wall -Werror -std=c17


#include <stdio.h>


void showInfo( int height, int width , int length )  {
  printf( "  sizeof(int)  = %2lu\n" ,  sizeof(int) );
  printf( "  sizeof(int*) = %2lu\n" , sizeof(int*) );
  printf( "  [height, width, length] = [%2d,%2d,%2d]\n\n" ,
          height , width , length );
}


void showVariable( char* pId , int* pDim )  {
  printf( "  address of %s = %p, value at address = %2d\n" ,
              pId, pDim , *pDim );
}

int main( void )  {
  int height = 10;
  int width  = 20;
  int length = 40;

  printf( "\nValues:\n\n");

  showInfo( height , width , length );

  printf( "\nUsing address of each named variables...\n\n");

  showVariable( "height" , &height );
  showVariable( "width " , &width );
  showVariable( "length" , &length );

  return 0;
}

  /* eof */
