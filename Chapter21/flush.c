// flush.c
// Chapter 21
// Learn C Programming, 2nd Edition
//
// Demonstrate input buffering works in
// "cooked mode" of console i/o.
// Final output is flushed with \n or when program ends.
//
// compile with:
//   cc flush.c -o flush -Wall -Werror -std=c17


#include <stdio.h>    // For printf()
#include <unistd.h>   // For sleep()


int main( void  )  {
  printf( "You'll see this immediately.\n"
          "Now count to 5 slowly.\n" );
  printf( "Then, this appears ... " );
  sleep( 5 );
  printf( "when the buffer is finally flushed.\n" );

  return 0;
}

  /* eof */
