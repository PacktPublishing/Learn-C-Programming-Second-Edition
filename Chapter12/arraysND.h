// arrayND.h
// Chapter 12
// Learn C Programming, 2nd Edition
//
// Header file for arrayND.c.
//


  // Function prototypes.

  // col is the x-axis (x-dimension)
  // row is the y-axis (y-dimension)

void initialize2DArray(  int col , int row , int array[row][col] );
void print2DArray(       int col , int row , int array[row][col] );
void prettyPrint2DArray( int col , int row , int array[row][col] );
int  sum2DArray(         int col , int row , int array[row][col] );

void initialize3DArray(  int x , int y , int z , int array[z][y][x] );
void print3DArray(       int x , int y , int z , int array[z][y][x] );
void prettyPrint3DArray( int x , int y , int z , int array[z][y][x] );
int  sum3DArray(         int x , int y , int z , int array[z][y][x] );

  /* eof */
