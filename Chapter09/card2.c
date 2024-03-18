// card2.c
// Chapter 9
// Learn C Programming, 2nd Edition
//
// Demonstrate how to access components of structures
// and perform operations on structures with functions.
//
// Compile with:
//
//    cc card2.c -o card2 -Wall -Werror -std=c17


#include <stdio.h>
#include <stdbool.h>


enum Suit  {
  eClub  = 1,
  eDiamond,
  eHeart,
  eSpade
};


enum Face  {
  eOne = 1,
  eTwo,
  eThree,
  eFour,
  eFive,
  eSix,
  eSeven,
  eEight,
  eNine,
  eTen,
  eJack,
  eQueen,
  eKing,
  eAce
};


struct Card  {
 enum Suit suit;
 int       suitValue;
 enum Face face;
 int       faceValue;
 bool      isWild;
};


bool isEqual(  struct Card c1 , struct Card c2 );
int  sumCards( struct Card c1 , struct Card c2 );


int main( void )  {
  struct Card card1 = { eHeart , (int)eHeart , eKing, (int)eKing , false };

  struct Card card2 = card1;  // card 2 is now identical to card 1

  struct Card card3 = {0};
  card3.suit      = eSpade;
  card3.suitValue = (int)eSpade;
  card3.face      = eAce;
  card3.faceValue = (int)eAce;
  card3.isWild    = true;

  bool cardsEqual = isEqual( card1 , card2 );
  printf( "card1 is%s equal to card2\n" , cardsEqual? "" : " not" );

  cardsEqual = isEqual( card2 , card3 );
  printf( "card2 is%s equal to card3\n" , cardsEqual? "" : " not" );

  printf( "The combined faceValue of card2(%d) + card3(%d) is %d\n" ,
           card2.faceValue ,
           card3.faceValue ,
           sumCards( card2 , card3 ) );

  return 0;
}


bool isEqual( struct Card c1 , struct Card c2 )  {
  if( c1.suit   != c2.suit ) return false;
  if( c1.face   != c2.face ) return false;
  if( c1.isWild != c2.isWild ) return false;
  return true;
}


int  sumCards( struct Card c1 , struct Card c2 )  {
  int cardSum = c1.faceValue + c2.faceValue;
  return cardSum;
}

  /*  eof */

