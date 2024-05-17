// pageCounter.c
// Chapter 18
// Learn C Programming, 2nd Edition
//
// Demonstrate how to use a static variable in
// a function to print the next page number each time the
// function is called.
//
// compile with:
//   cc pageCounter.c -o pageCounter -Wall -Werror -std=c17


#include <stdio.h>


void printPage( const char* aHeading );


int main( void )  {
  printPage( "Title Page" );
  printPage( "Chapter 1 " );
  printPage( "          " );
  printPage( "Chapter 2 " );
  printPage( "Conclusion" );
}

void printPage( const char* aHeading )  {
#if 0
  static int pageNo = 1;
#else
  int pageNo = 1;
#endif
  printf( "---------------------\n"
          "| %10s        |\n" , aHeading );

  printf( "|                   |\n"
          "|    Page Content   |\n"
          "|     Goes Here     |\n"
          "|                   |\n");

  printf( "|            Page %1d |\n"
          "---------------------\n" , pageNo );
  pageNo++;
}

  /*  eof  */
