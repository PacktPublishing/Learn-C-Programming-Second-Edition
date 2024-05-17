// arraysND.c
// Chapter 12
// Learn C Programming, 2nd Edition
//
// Demonstrate how to declare, initialize, and
// manipulate 2D and 3D arrays.
// ND means N-dimensional. Here, N=2 and N=3.
//
// Pretty printing functions included which add
// row and column headings (as array offsets).
//
// Compile with:
//
//    cc arraysND.c -o arraysND -Wall -Werror -std=c17


#include <stdio.h>
#include <stdbool.h>
#include "arraysND.h"


  // enumerated constants for array dimension sizes.
  //
enum {
  size1D = 5,  /* x-axis */
  size2D = 4,  /* y-axis */
  size3D = 3   /* z-axis */
};

  // Because we have initializer functions for these arrays, we could have
  // used constant variables to define their sizes, as follows:
  //
  //   const int   size1D = 5;
  //   const int   size2D = 4;
  //   const int   size3D = 3;
  //
  // This would, of course, have made these VLA-defined arrays.
  //
  // I believe, however, it is a better practice to use constant enumerations
  // so that we can initialize our arrays at the time of definitiona and then
  // re-initialize them later as needed.


int main( void )  {
    //
    // This variable determines whether arrays are printed with or without
    // row and column headings.
    //
  bool pretty = true;

  int array2D[size2D][size1D]         = {0}; // define & initialize constant array
  int array3D[size3D][size2D][size1D] = {0}; // define & initialize constant array

  int total = 0;

    // 2D array

  initialize2DArray(  size1D , size2D , array2D );

  if( !pretty ) print2DArray(       size1D , size2D , array2D );
  else          prettyPrint2DArray( size1D , size2D , array2D );

  total = sum2DArray( size1D , size2D , array2D );
  printf( "Total for array2D is %d\n\n" , total );

    // 3D array

  initialize3DArray(  size1D , size2D , size3D , array3D );

  if( !pretty) print3DArray(       size1D , size2D , size3D , array3D );
  else         prettyPrint3DArray( size1D , size2D , size3D , array3D );

  total = sum3DArray( size1D , size2D , size3D , array3D );
  printf( "Total for array3D is %d\n\n" , total );

  return 0;
}


void initialize2DArray( int col , int row , int array[row][col] )  {
  for( int j = 0 ; j < row ; j++ )  {    // j : 0..(row-1)
    for( int i = 0 ; i < col ; i++ )  {  // i : 0..(col-1)
      array[j][i] = (10*(j+1)) + (i+1);
 //     array[j][i] = (10*j) + i;
    }
  }
}


void initialize3DArray( int x , int y , int z , int array[z][y][x] )  {
  for( int k = 0 ; k < z ; k++ )  {      // k : 0..(z-1)
    for( int j = 0 ; j < y ; j++ )  {    // j : 0..(y-1)
      for( int i = 0; i < x ; i++ )   {  // i : 0..(x-1)
        array[k][j][i] = (100*(k+1)) + (10*(j+1)) + (i+1);
//        array[k][j][i] = (100*k) + (10*j) + i;
      }
    }
  }
}


void print2DArray( int col , int row , int array[row][col] )  {
  for( int j = 0 ; j < row ; j++ )  {   // j : 0..(row-1)
    for( int i = 0 ; i < col ; i++ )  {  // i : 0..(col-1)
      printf("%4d" , array[j][i]);
    }
    printf("\n");
  }
  printf("\n");
}


void prettyPrint2DArray( int col , int row , int array[row][col] )  {
    // Print column offsets as heading.
  printf("   ");
  for( int i = 0; i < col ; i++) printf(" [%1d]", i);
  printf("\n");

  for( int j = 0 ; j < row ; j++ )  {  // j : 0..(row-1)
      // Print row offset as lead-in.
    printf("[%1d]", j);

    for( int i = 0 ; i < col ; i++ )  { // i : 0..(col-1)
      printf("%4d" , array[j][i]);
    }
    printf("\n");
  }
  printf("\n");
}


// In this function, we print the 3-d array as a series of 2-d arrays.
//
void print3DArray( int x , int y , int z , int array[z][y][x] )  {
  for( int k = 0 ; k < z ; k++ )  {     // k : 0..(z-1)
    for( int j = 0 ; j < y ; j++ )  {   // j : 0..(y-1)
      for( int i = 0; i < x ; i++ )  {  // i : 0..(x-1)
        printf("%4d" , array[k][j][i]);
      }
      printf("\n");
    }
    printf("\n");
  }
}


  // In this function, we print the 3-d array as a series of 2-d arrays.
  //
void prettyPrint3DArray( int x , int y , int z , int array[z][y][x] )  {
  for( int k = 0 ; k < z ; k++ )  {   // k : 0..(z-1)
      // Print z offset as lead-in.
    printf("[%1d]", k );
      // Print x offset as heading.
    printf("    ");
    for( int i = 0; i < x ; i++) printf(" [%1d]", i);
    printf("\n");

    for( int j = 0 ; j < y ; j++ )  {  // j : 0..(y-1)
        // Print y offset as lead-in.
      printf("    [%1d]", j);
      for( int i = 0; i < x ; i++ )  {  // i : 0..(x-1)
        printf("%4d" , array[k][j][i]);
      }
      printf("\n");
    }
    printf("\n");
  }
}


int sum2DArray( int col , int row , int array[row][col] )  {
  int sum = 0;
  for( int j = 0 ; j < row ; j++ )  {    // j : 0..(row-1)
    for( int i = 0 ; i < col ; i++ )  {  // i : 0..(col-1)
      sum += array[j][i];
    }
  }
  return sum;
}


int sum3DArray( int x , int y , int z , int array[z][y][x] )
{
  int sum = 0;
  for( int k = 0 ; k < z ; k++ )  {      // k : 0..(z-1)
    for( int j = 0 ; j < y ; j++ )  {    // j : 0..(y-1)
      for( int i = 0 ; i < x ; i++ )  {  // i : 0..(x-1)
        sum += array[k][j][i];
      }
    }
  }
  return sum;
}


 /* eof */
