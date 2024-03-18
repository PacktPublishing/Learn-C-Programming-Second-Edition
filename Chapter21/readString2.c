// readString2.c
// Chapter 21
// Learn C Programming, 2nd Edition
//
// Demonstrate how to read and write a string with
// gets() and puts().
// Compare this program to readString.c
//
// compile with:
//   cc readString2.c -o readString2 -Wall -Werror -std=c17


// DANGER: Do Not Ever Use gets().
//
//         Instead, use fgets().


#include <stdio.h>


enum { kBufferSize = 132 };


  // safe_gets uses fgets() and then removes the trailing '\n'
  // from the character buffer/input string.
  // Like fgets(), safe_gets() returns either the pointer
  // to the string to indicate success or
  // NULL to indicate invalid input, EOF, or some other error.

char* safe_gets(char* buf, int size )  {
  if( fgets( buf , size , stdin ) )  {   // fgets() preserves last '\n'
    for( int i = 0; i < size ; i++ )  {  // Find the last '\n'.
      if( '\n' == buf[i] )  {            // Found it.
        buf[i] = '\0';                   // Replace '\n' with '\0'
        break;
      }
    }
    return buf;   // fgets() succeeded; return the string pointer.
  } else {
    return NULL;  // fgets() failed; return NULL to indicate failure.
  }
}


int main( void )  {
  char stringBuffer[ kBufferSize ] = {0};

    // UNSAFE: Do Not Ever Use gets().
    //         gets() removed in C11 and later, but may still  be present.
    //         Even if present, do not use.

  printf( "Enter a string: " );
  gets( stringBuffer );
  puts( "You entered: " );
  puts( stringBuffer );

    // SAFE: Instead, use fgets() & remove trailing '\n'.
    //       Or, use safe_gets() given above.
    //       Or, if available, use gets_s().

  printf( "\nEnter another string: " );
  safe_gets( stringBuffer , kBufferSize );
  puts( "You entered: " );
  puts( stringBuffer );

  return 0;
}

  /* eof */
