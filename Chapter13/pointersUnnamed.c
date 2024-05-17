// pointersUnamed.c
// Chapter 13
// Learn C Programming, 2nd Edition
//
// Demonstrate how to
// 1) declare a pointer to int
// 2) get info about the pointer (its address, size)
// 3) assign targets to the pointer
// 4) print out info about the targets.
//
// compile with:
//
//   cc pointersUnamed.c -o pointersUnamed -Wall -Werror -std=c17


#include <stdio.h>


int main( void )  {
  int height = 10;
  int width  = 20;
  int length = 40;

  int* pDimension;

  printf( "\nValues:\n\n");

  printf( "  sizeof(int)  = %2lu\n" , sizeof(int) );
  printf( "  sizeof(int*) = %2lu\n" , sizeof(int*) );
  printf( "  [height,width,length] = [%2d,%2d,%2d]\n\n" ,
             height , width , length );
  printf( "    address of pDimension = %p\n" ,
             &pDimension  );

  pDimension = &height;
  printf( "      address of height = %p, value at address = %2d\n" ,
             pDimension , *pDimension );
//  pDimension += sizeof(int); // 4
//  pDimension++;
  pDimension += 1;
  printf( "    value of pDimension = %p, value at address = %2d\n" ,
             pDimension , *pDimension );
//  pDimension += sizeof(int); // 4
//  pDimension++;
  pDimension += 1;
  printf( "    value of pDimension = %p, value at address = %2d\n" ,
              pDimension , *pDimension );

  printf( "\nCONCLUSION: Can't use autoincrement or pointer addition\n" );
  printf( "            to move from one named variable to another.\n\n");

  return 0;
}

  /* eof */
