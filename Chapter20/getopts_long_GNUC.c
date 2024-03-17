// getopts_long_GNUC.c
// Chapter 20
// Learn C Programming, 2nd Edition
//
// NOTE: getopt.h and getopt_long() is not a part of the C Standard Library.
//       It is a system-dependent library that was first a part of the GNU C
//       Library and is included with most compilers.
//
// Demonstrate how to
// * retrieve arguments entered on the command line using the C Standard
//   Library routine getopt_long()
// * use various argument types:
//   1. flag arguments with no parameters
//   2. required arguments
//   3. optional arguments with default setting
//      (can be set to something else.)
// For each option, we show the option and its parameter. When using
// this in a program, instead of showing the option, you would set the
// appropriate variable with the value for that option. Later, your program
// would use that variable as appropriate.
//
// compile with:
//   cc getopts_long_GNUC.c -o getopts_long_GNUC -Wall -Werror -std=c17
//
// Sample inputs:
//
//   getopts_long_GNUC --verbose -a -p --num=3 --size=10 --delete=Bye-bye \
//                     -c Hello -f AFile.dat Red Green Blue
//   (try many other variations yourself)


#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>


  /* Flag set by ‘--verbose’. */
static int verbose_flag = 0;
static int num_flag = 0;


static struct option long_options[] = {
    // These options set a flag. They are handled by getopt_long()
    // and are not processed in the switch statement.
    // When --verbose is encountered, verbose_flag is set to 1.
    // When --brief is encountered, verbose_flag is set to 0.
  {"verbose", no_argument,       &verbose_flag, 1},
  {"brief",   no_argument,       &verbose_flag, 0},
    // These options don’t set a flag.
    // We distinguish them by their single character.
    // Each is processed in the switch statement.
    //
    // Options without any following argument.
  {"add",     no_argument,       0, 'a'},
  {"append",  no_argument,       0, 'p'},
    // Options with a required following argument.
  {"delete",  required_argument, 0, 'd'},
  {"create",  required_argument, 0, 'c'},
  {"file",    required_argument, 0, 'f'},
    // Option which sets a default value if no additional argument
    // is given. The default value is specified here as 14.
    // An additional argument is optional.
    // This option will only be processed in the switch statement if
    // the optional following argument is given.
  {"number",  optional_argument, &num_flag, 14},
    // Option with an optional following argument.
    // In this case, this option will always be processed in the switch
    // statement.
  {"size",    optional_argument, 0 , 's'},
  {0, 0, 0, 0}
};

  // These are the single-character options to be processed in the
  // switch statement.
static char* option_string = "apc:d:f:s:n:";


void PrintArgs( int argc , char** argv )  {
  printf( "argument count = [%d]\n" , argc );
  printf( "%s " , argv[0] );
  for( int i = 1 ; i < argc ; i++ )  {
    printf( "%s " , argv[i] );
  }
  putchar( '\n' );
  putchar( '\n' );
}

void Usage( int c , char** argv )  {
  printf( "Invalid option: %c\n" , c );
  printf( "Usage: %s \n\t\t--verbose | --brief \n"
    "\t\t--add --append --num <n> \n"
    "\t\t--create <string> --delete=<string>\n"
    "\t\t[--file <string>] [--size=<n>]\n" , argv[0] );
  exit(1);
}


int main( int argc , char** argv )  {
  int c;

  PrintArgs( argc , argv );

  while (1) {
      // getopt_long stores the option index here.
    int option_index = 0;

    c = getopt_long( argc, argv, option_string,
                     long_options, &option_index );

      // Detect the end of the options.
    if (c == -1)
      break;

      // switch statement where each option is processed.
    switch (c)  {
      case 0:
        // The options which are configured to set
        // a flag (verbose, brief, and number without an additional argument)
        // return zero, so do nothing.
        break;

      case 'a':
        puts ("Option -a or --add");
        break;

      case 'p':
        puts ("Option -p or --append");
        break;

      case 'n':
         // This will only occur if --num has an additional argument.
        printf( "Option -n or --num");
        if( optarg )
          printf( " with value %s" , optarg );
        putchar( '\n' );
        num_flag = atoi( optarg );
        break;

      case 'c':
          printf ("Option -c or --create with value `%s'\n", optarg);
          break;

      case 'd':
        printf ("Option -d or --delete with value `%s'\n", optarg);
        break;

      case 'f':
        printf ("Option -f or --file with value `%s'\n", optarg);
        break;

      case 's':
        printf( "Option -s or --size");
        if( optarg ) printf( " with value %s" , optarg );
        putchar( '\n' );
        break;

      default:
        Usage( c , &argv[0] );
        break;
      }
    }

    // If the optional additional argument is encountered, num_flag will be set
    // to that value in the switch statement.
    // If no additional argument is encountered, the value given in the options table
    // will be assigned by getopt_long().
  if( num_flag )
    printf( "num_flag=%d\n" , num_flag );

    // Instead of reporting ‘--verbose’
    // and ‘--brief’ as they are encountered,
    // we report the final status resulting from them.
  if( verbose_flag )
    puts( "verbose flag is set" );

    // Print any remaining command line arguments (not options).
  if( optind < argc ) {
    printf ("non-option ARGV-elements: ");
    while( optind < argc )
      printf( "%s " , argv[optind++] );
    putchar( '\n' );
  }

  return 0;
}

  /* eof */
