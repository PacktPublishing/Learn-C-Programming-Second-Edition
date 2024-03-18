// simpleStrings.c
// Chapter 15
// <book title>
//
// Demonstrate how to
// 1) declare and initialize strings in various ways
// 2) manipulate (change) a single characger within a string
// 3) illustrate the difference between strings and string literals (constant)
// 4) some experiments with strings:
//    a) try to modify a string literal
//    b) loop through string with for()...
//    c) loop through string with while()...
//
// compile with:
//   cc simpleStrings.c -o simpleStrings -Wall -Werror -std=c17


#include <stdio.h>  // for printf()
#include <ctype.h>  // for toupper()
#include <string.h> // for strlen()


int main( void )  {
  char  string0[8] = { 0 };
  char  string1[8] = { 'h' , 'e' , 'l' , 'l', 'o' , '\0' };
  char  string2[8] = "hello";
  char  string3[]  = "hello";
  char* string4    = "hello";

  printf( "A) 0:\"%s\"   1:\"%s\"  2:\"%s\"  3:\"%s\"  4:\"%s\"\n\n" ,
          string0 , string1 , string2 , string3 , string4 );

  string0[0] = 'H';
  string1[0] = 'H';
  string2[0] = toupper( string2[0] );
  string3[0] = toupper( string3[0] );
// string4[0] = 'H';     // Can't do this because its a pointer
                         // to a literal string (a constant).
  string4    = "Hello";  // assign pointer to new string.

  printf( "B) 0:\"%s\"  1:\"%s\"  2:\"%s\"  3:\"%s\"  4:\"%s\"\n\n" ,
          string0 , string1 , string2 , string3 , string4 );


// EXPERIMENTS
//
// To do each experiment, change #if 0 to #if 1 and then build and run the
// program.

  // Experiment 1: initialize an array with a string too long.
  //
  // This should cause compiler error; but it is useful to know what an error
  // of this kind looks like.
  //

#if 0
    // Should fail.
  char string6[8] = "Ladies and Gentlemen"; // size specified but string too long.

    // Will succeed.
  char string7[] = "Ladies and Gentlemen";  // size not specified; size determined by initializer.
#endif


  // Experiment 2:  convert string2 to all upper case using loop.
  //                For loop is counter-controlled. The count is
  //                determined by call to strlen().

#if 0
  int length = strlen( string2 );
  for( int i = 0 ; i < length ; i++ )  {
    string2[i] = toupper( string2[i]);
  }
  printf( "E2) \"%s\" \n" , string2 );
#endif

  // Experiment 3: convert string3 to all upper case using loop.
  //               While loop is sentinel-controlled. The sentinel
  //               value is '\0'.

#if 0
  int i = 0;
  while( string3[i] != '\0' )  {
    string3[i] = toupper( string7[i]);
    i++;
  }
  printf( "E3) \"%s\" \n" , string3 );
#endif

  return 0;
}

  /* eof */
