// showArgs.c
// Chapter 20
// Learn C Programming, 2nd Edition
//
// Demonstrate how to
// * retrieve arguments entered on the command line
//
// compile with:
//   cc showArgs.c -o showArgs -Wall -Werror -std=c17


#include <stdio.h>


void Usage( char* exec ) {
  printf( " usage: %s <argument1> <argument2> ... <argumentN>\n\n" ,
          exec );
}


int main(int argc, char *argv[])  {

    // argc will never be 0.
    // The program name is always argv[0]

  if( 1 == argc )  {
    printf( " No arguments given on command line.\n" );
    Usage( argv[0] );
    return 0;
  }

    // At this point, we know argc is greater than 1.

  printf( "argument count = [%d]\n" , argc );
  printf( "executable = [%s]\n" , argv[0] );
  for( int i = 1 ; i < argc ; i++ )  {
    printf( "argument %d = [%s]\n" , i , argv[i] );
  }
  putchar( '\n' );

  return 0;
}

  /* eof */
