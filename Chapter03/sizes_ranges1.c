// sizes_ranges1.c
// Chapter 3
// Learn C Programming, 2nd Edition
//
// Print out the sizes and ranges for each of C's data types.
// Save this program and run it on various computer systems you may find
// yourself working on to confirm and verify the system's limits.


#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>


 // function prototypes
 //
void printSizes( void );


int main( void )  {
  printSizes();

  return 0;
}

  // function to print the # of bytes for each of C11's data types
  //
void printSizes( void )  {
  printf( "Size of C data types\n\n"                                 );
  printf( "Type               Bytes\n\n"                             );
  printf( "char                 %lu\n" , sizeof( char )               );
  printf( "int8_t               %lu\n" , sizeof( int8_t )             );
  printf( "unsigned char        %lu\n" , sizeof( unsigned char )      );
  printf( "uint8_t              %lu\n" , sizeof( uint8_t )            );
  printf( "short                %lu\n" , sizeof( short )              );
  printf( "int16_t              %lu\n" , sizeof( int16_t )            );
  printf( "uint16_t             %lu\n" , sizeof( uint16_t )           );
  printf( "int                  %lu\n" , sizeof( int )                );
  printf( "unsigned             %lu\n" , sizeof( unsigned )           );
  printf( "long                 %lu\n" , sizeof( long )               );
  printf( "unsigned long        %lu\n" , sizeof( unsigned long )      );
  printf( "int32_t              %lu\n" , sizeof( int32_t )            );
  printf( "uint32_t             %lu\n" , sizeof( uint32_t )           );
  printf( "long long            %lu\n" , sizeof( long long )          );
  printf( "int64_t              %lu\n" , sizeof( int64_t )            );
  printf( "unsigned long long   %lu\n" , sizeof( unsigned long long ) );
  printf( "uint64_t             %lu\n" , sizeof( uint64_t )           );
  printf( "\n" );
  printf( "float                %lu\n" , sizeof( float )              );
  printf( "double               %lu\n" , sizeof( double )             );
  printf( "long double          %lu\n" , sizeof( long double )        );
  printf( "\n" );
  printf( "bool                 %lu\n" , sizeof( bool )               );
  printf( "_Bool                %lu\n" , sizeof( _Bool )              );
  printf( "\n\n" );
}

  /*  eof  */

