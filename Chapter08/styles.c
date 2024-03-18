  // styles.c
  // Chapter 8
  // Learn C Programming, 2nd Edition
  //
  // Compile with:
  //
  //    cc styles.c -o styles -Wall -Werror -std=c17


#include <stdio.h>


enum textStyle  {
  lowercase     = 1, // equivalent to 0b00000001
  bold          = 2, // equivalent to 0b00000010
  italic        = 4, // equivalent to 0b00000100
  underline     = 8, // equivalent to 0b00001000
  strikethrough = 16 // equivalent to 0b00010000
};


int main( void )  {
  int style      = bold | italic;      // Style has bold and italic
                                       // turned on.
  int otherStyle = italic + underline; // OtherStyle has italic and
                                       // underline turned on.

  if( style & bold )
    printf( "For 'style' bold is turned on.\n");
  if( !(otherStyle & bold) )
    printf( "For 'otherStyel' bold is turned off\n" );
  return 0;
}

  /*  eof  */
