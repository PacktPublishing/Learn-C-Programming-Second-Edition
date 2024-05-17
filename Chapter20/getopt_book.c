// getopt_book.c
// Chapter 20
// Learn C Programming, 2nd Edition
//
// Demonstrate how to
// * retrieve arguments entered on the command line with the C Standard
//   Library routine getopts().
//
// compile with:
//   cc getopt_book.c -o getopt_book -Wall -Werror -std=c17
//
// sample inputs;
//
//  ./getopt_book -t "There and Back" -a "Bilbo Baggins" -p -y 1955 -r
//  ./getopt_book -a "Jeff Szuhay" -t "Learn C Programming" -y 2020 -p
//  ./getopt_book -x



#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


static char* options_string = "pra:t:y:";


typedef struct _book {
    bool  bPublished;
    bool  bReprint;
    char* title;
    char* author;
    char* year;
} Book;


void Usage( char* exec ) {
  printf( "\nUsage: %s -r -p -t 'title' -a 'name' -y year\n\n" , exec );
  exit(1);
}


void PrintArgs( int argc , char** argv )  {
  printf( "argument count = [%d]\n" , argc );
  printf( "%s " , argv[0] );
  for( int i = 1 ; i < argc ; i++ )  {
    printf( "%s " , argv[i] );
  }
  putchar( '\n' );
  putchar( '\n' );
}


int main(int argc, char *argv[]) {
  char ch;
  Book book = { false , false , 0 , 0, 0 };

  PrintArgs( argc , argv );

  while( (ch = getopt( argc , argv , options_string ) ) != -1 ) {
    switch (ch) {
      case 'p':
        book.bPublished = true;
        break;
      case 'r':
        book.bReprint = true;
        break;
      case 't':
        book.title = optarg;
        break;
      case 'a':
        book.author = optarg;
        break;
      case 'y':
        book.year = optarg;
        break;
      default:
        Usage( argv[0] );
        break;
    }
  }
  printf( " Title is [%s]\n" , book.title );
  printf( "Author is [%s]\n" , book.author );
  printf( "Published [%s]\n" , book.bPublished ? "yes" : "no" );
  if( book.year ) printf( "  Year is [%s]\n" , book.year );
  printf( "Reprinted [%s]\n" , book.bReprint? "yes" : "no" );
  if( optind < argc )  {
    printf( "non-option ARGV-elements: " );
    while( optind < argc )  {
      printf( "%s ", argv[ optind++ ] );
    }
    putchar( '\n' );
  }
  putchar( '\n' );
  return 0;
}

  /* eof */
