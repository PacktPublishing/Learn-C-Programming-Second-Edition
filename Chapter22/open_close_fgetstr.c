// open_close_fgetstr.c
// Chapter 22
// Learn C Programming, 2nd Edition
//
// Builds on open_close_string.c
// Demonstrate how to get filenames for input and output
// via prompt, and a safe_gets() function which is a wrapper
// function around the call to fgets().
//
// compile with:
//   cc open_close_fgetstr.c -o open_close_fgetstr -Wall -Werror -std=c17


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/errno.h>  // for errno


  // safe_gets() uses fgets() and then
  // 1) removes the trailing '\n' from the character buffer/input string.
  //
  // Like fgets(), safe_gets() returns either
  // 2) the pointer to the string to indicate success or
  // 3) NULL to indicate invalid input, EOF, or some other error.

char* safe_gets(char* buf, int size )  {
  if( fgets( buf , size , stdin ) )  {
    for( int i = 0; i < size ; i++ )  {  /* 1 */
      if( '\n' == buf[i] )  {
        buf[i] = '\0';
        break;
      }
    }
    return buf;   /* 2 */
  } else {
    return NULL;  /* 3 */
  }
}


int main( void ) {
  FILE* inputFile;
  FILE* outputFile;

    // You need to verify the maximum filename size on your system.
    // It may be very large or it may be very small.
    // If FILENAME_MAX is very large, consider allocating on heap
    // with calloc() as is done here, otherwise simply allocate array
    // inline.
    //
    // Also, if using UTF-8 or Unicode, size is bytes, not characters.

  printf( "FILENAME_MAX on this system is %d bytes\n" ,
          FILENAME_MAX );  // FILENAME_MAX is defined in stdio.h

  char* inputFilename  = (char*)calloc( FILENAME_MAX , 1 );
  char* outputFilename = (char*)calloc( FILENAME_MAX , 1 );
  if( !inputFilename || !outputFilename ) {
    fprintf( stderr , "FATAL ERROR: Not Enough memory for filename strings\n" );
    exit( EXIT_FAILURE );
  }

  fprintf( stdout , "Enter name of input file: " );
  safe_gets( inputFilename , FILENAME_MAX );
  inputFile = fopen( inputFilename , "r" );
  if( NULL == inputFile )  {
    fprintf( stderr, "ERROR: input file [%s]: %s\n", inputFilename , strerror( errno ) );
    exit( EXIT_FAILURE );
  }

  fprintf( stdout , "Enter name of output file: " );
  safe_gets( outputFilename , FILENAME_MAX );
  outputFile = fopen( outputFilename , "w" );
  if( NULL == outputFile )  {
    fprintf( stderr, "ERROR: output file: [%s]: %s\n", outputFilename , strerror( errno ) );
    exit( EXIT_FAILURE );
  }

  fprintf( stdout , "\"%s\" opened for reading.\n" , inputFilename  );
  fprintf( stdout , "\"%s\" opened for writing.\n" , outputFilename );

  fprintf( stderr , "\nDo work here.\n\n" );

  fprintf( stderr , "Closing files.\n" );
  fclose( inputFile );
  fflush( outputFile );
  fclose( outputFile );
  free( inputFilename );
  free( outputFilename );

  fprintf( stderr , "Done.\n" );

  return 0;
}

  /* eof */

