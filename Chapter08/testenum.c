// testenum.c
// Chapter 8
// Learn C Programming, 2nd Edition
//
// An experiment to see if
// 1) can we give all the enumerated items the same constant value?
//
//    Yes, we can.
//
//    But does it make sense? Yes, but only if we do not treat the
//    enumerated items as a related group, but as a collection of
//    named values.
//
// 2) Is this meaningful when we try to differentiate one named value
//    from another?
//
//    No, it isn't. When comparing enumerated items, in an if()...
//    statement or switch()... statement, they MUST have unique
//    values in the enumerated list.
//
// Compile with:
//
//    cc testenum.c -o testenum -Wall -Werror -std=c17


#include <stdio.h>

//  // all enumerated constants have the unique values.
//  // Uncomment these lines and comment the ones below to
//  // see the desired behavior.
//
//enum suit {
//  eSpade   = 1,
//  eHeart   = 2,
//  eDiamond = 3,
//  eDlub    = 4
//};

  // all enumerated constants have the same value.
enum suit {
  eSpade   = 5,
  eHeart   = 5,
  eDiamond = 5,
  eclub    = 5
};


int main( void )  {
  enum suit card;

  card = eSpade;
  //  card = eHeart;
  //  card = eDiamond;
  //  card = eClub;
  //  card = 100;

  if(      card == eClub )    printf( "club\n" );
  else if( card == eDiamond ) printf( "diamond\n" );
  else if( card == eHeart )   printf( "heart\n" );
  else if( card == eSpade )   printf( "spade\n" );
  else
      printf( "Unknown enumerated value\n" );

  return 0;
}

  /* eof */
