// usingAtoi.c
// Chapter 21
// Learn C Programming, 2nd Edition
//
// Demonstrate how to
// 1) blah
// 2) blah
// 3) blah
//
// compile with: cc usingAtoi.c -o usingAtoi -Wall -Werror -std=c17


#include <stdio.h>
#include <stdlib.h>


int main( void )  {
  int     anInteger   = -1;
  double  aDouble     = -1.0;

  char sInteger[] = "1234" ;
  char sDouble[]  = "5678.9012";

  printf("As strings: integer=\"%s\" double=\"%s\"\n" ,
          sInteger , sDouble );
  anInteger = atoi( sInteger );
  aDouble   = atof( sDouble );
  printf("As values:  integer=[%d] double=[%lf]\n\n" ,
          anInteger , aDouble );

  return 0;
}

  /* eof */
