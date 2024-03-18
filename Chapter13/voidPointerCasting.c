// voidPointerCasting.c
// Chapter 13
// Learn C Programming, 2nd Edition
//
// Demonstrate how to
// 1) declare a void pointer
// 2) assign the address of various data types to the void pointer
// 3) correctly get the target value of the void pointer with casting
// 4) print out info about the data types directly and via the void pointer.
// 5) correctly set the target value of the the void pointer with casting.
// compile with:
//
//   cc voidPointerCasting.c -o voidPointerCasting -Wall -Werror -std=c17


#include <stdio.h>


int main(int argc, char *argv[]) {
  int height = 10;
  void* aPtr = NULL;
  aPtr       = &height; // Value of aPter is address of height,
                        // but we don't yet know the type that aPtr points to.

    // get the value at the target

  int h = *(int*)aPtr;  // Cast aPtr to (int*) from (void*) with
                        //      (int*)aPtr
                        // Get the integer value found there with
                        //     *(int*)aPtr
                        //
                        // Or, to me more explicit:
                        //   *((int*)aPtr))
                        // The extra set of () is only for clarity and are not
                        // required.
                        //
                        // NOTE: Must cast aPtr _before_ dereferencing the pointer.

  printf( "             height = [%d]\n" , height );
  printf( "        *(int*)aPtr = [%d]\n" , *(int*)aPtr );
  printf( "                  h = [%d]\n" , h );
  printf( "   sizeof( height ) = %lu\n" , sizeof( height ) );
  printf( "sizeof(*(int*)aPtr) = %lu\n" , sizeof( *(int*)aPtr ) );
    // set the value at the target
  *(int*)aPtr = 3;
  printf( "        *(int*)aPtr = [%d]\n" , *(int*)aPtr );
  printf( "             height = [%d]\n\n" , height );

    // same thing but using a double data type.

  double width = 36.8651;
  aPtr         = &width;
    // get the value at the target
  double w     = *( (double*)aPtr );
  printf( "                 width = [%f]\n" , width );
  printf( "        *(double*)aPtr = [%f]\n" , *(double*)aPtr );
  printf( "                     w = [%f]\n" , w );
  printf( "       sizeof( width ) = %lu\n" , sizeof( width ) );
  printf( "sizeof(*(double*)aPtr) = %lu\n" , sizeof( *(double*)aPtr ) );
    // set the value at the target
  *(double*)aPtr = 1.7439;
  printf( "        *(double*)aPtr = [%f]\n" , *(double*)aPtr );
  printf( "                 width = [%f]\n\n" , width );

  // same thing but using a char data type.

  char ch = 'A';
  aPtr    = &ch;
    // get the value at the target
  char c  = *((char*)aPtr);
  printf( "                  ch = [%c]\n" , ch );
  printf( "        *(char*)aPtr = [%c]\n" , *(char*)aPtr );
  printf( "                   c = [%c]\n" , c );
  printf( "        sizeof( ch ) = %lu\n" , sizeof( ch ) );
  printf( "sizeof(*(char*)aPtr) = %lu\n" , sizeof( *(char*)aPtr ) );
    // set the value at the target
  *(char*)aPtr = 'z';
  printf( "        *(char*)aPtr = [%c]\n" , *(char*)aPtr );
  printf( "                  ch = [%c]\n\n" , ch );

  return 0;
}

  /* eof */
