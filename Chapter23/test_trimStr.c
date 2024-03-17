// test_trim.c
// Chapter 23
// Learn C Programming, 2nd Edition
//
// This program tests the trimStr() and trimStrInPlace()
// functions.
//
//   trimStr() returns a pointer to the beginning of the trimmed string,
//             modifying the original string.
//
//   trimStrInPlace() (1) copies the trimmed string back to the original
//             string using same pointer and (2) returns length of the
//             trimmed string.
//
// Compile with:
//   cc test_trim.c -o test_trim -Wall -Werror -std=c17


#include <stdio.h>
#include <ctype.h>
#include <string.h>


char* trimStr(        char* pStr );
int   trimStrInPlace( char* pStr );
void  testTrim( int testNum , char* pStr );


int main( void )  {
  testTrim( 1 , "Hello, World!\n" );
  testTrim( 2 , "Box of frogs \t \n" );
  testTrim( 3 , " \t  Bag of hammers" );
  testTrim( 4 , "\t\t  Sack of ferrets\t\t   " );
  testTrim( 5 , "   \t\n\v\t\r   " );
  testTrim( 6 , "" );
  testTrim( 7 , "Goodbye, World!" );
  return 0;
}

  // trimStr - Trims beginning and end of a string.
  //           Pointer to beginning of input string may be
  //           modified; therefore, return value is essential.
  //
  // Parameter:
  //   pStr - pointer to string to be trimmed.
  // Returns:
  //   A pointer to the beginning of the trimmed string.
  //
char* trimStr( char* pStr )  {
  size_t first , last , len ;
  first = last = len = 0;

    // Left Trim
    // Find 1st non-whitespace char; pStr will point to that.
  while( isspace( pStr[ first ] ) )
    first++;
  pStr += first;

  len = strlen( pStr ); // Get new length after Left Trim.
  if( len )  {          // Check for empty string. e.g. "   " trimmed to nothing.
      // Right Trim
      // Find 1st non-whitespace char & set NUL character there.
    last = len-1; // off-by-1 adjustment.
    while( isspace( pStr[ last ] ) )
      last--;
    pStr[ last+1 ] = 0;  // Terminate trimmed string.
  }
  return pStr;
}


  // trimStrInPlace - Trims beginning and end of a string.
  //                  Creates a working copy of string, trims that,
  //                  and copies the trimmed string back to original.
  //
  //                  Because a trimmed string will always be the same
  //                  or fewer characters than the original, the only
  //                  side effect of this function is the modification of
  //                  the original string in place.
  //
  // Parameter:
  //   pStr - pointer of string to be trimmed/modified.
  // Returns:
  //   The length of the string after trimming.
  //
int trimStrInPlace( char* pStr )  {
  size_t first , last , lenIn , lenOut ;
  first = last = lenIn = lenOut = 0;

  lenIn = strlen( pStr );   //
  char tmpStr[ lenIn+1 ];   // Create working copy.
  strcpy( tmpStr , pStr );  //
  char* pTmp = tmpStr;      // pTmp may change in Left Trim segment.

    // Left Trim
    // Find 1st non-whitespace char; pStr will point to that.
  while( isspace( pTmp[ first ] ) )
    first++;
  pTmp += first;

  lenOut = strlen( pTmp );     // Get new length after Left Trim.
  if( lenOut )  {              // Check for empty string.
                               //  e.g. "   " trimmed to nothing.
      // Right Trim
      // Find 1st non-whitespace char & set NUL character there.
    last = lenOut-1;           // off-by-1 adjustment.
    while( isspace( pTmp[ last ] ) )
      last--;
    pTmp[ last+1 ] = '\0';  // Terminate trimmed string.
  }
  lenOut = strlen( pTmp );  // Length of trimmed string.
  if( lenIn != lenOut )     // Did we change anything?
    strcpy( pStr , pTmp );  // Yes, copy trimmed string back.
  return lenOut;
}


void testTrim( int testNum , char* pStr )  {
  size_t len;
  char testStr[ strlen( pStr ) + 1];
  char* pTest;

  strcpy( testStr , pStr );
  fprintf( stderr , "%1d. original: \"%s\" [len:%d]\n"   , testNum, testStr , (int)strlen( pStr ) );
  pTest = trimStr( testStr );
  fprintf( stderr , "    trimStr: \"%s\" [len:%d]\n" , pTest ,  (int)strlen( pTest ));

  strcpy( testStr , pStr );
  len = trimStrInPlace( testStr );
  fprintf( stderr , "   trimStr2: \"%s\" [len:%d]\n\n" , testStr , (int)len ) ;
}

  /* eof */
