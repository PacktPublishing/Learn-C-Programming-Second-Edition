// card5.c
// Chapter 10
// Learn C Programming, 2nd Edition
//
// Demonstrate how to create source file with its
// own header file of typedefs, custom types, and
// function prototypes.
//
// Compile with:
//
//    cc card5.c -o card5 -Wall -Werror -std=c17


#include <stdio.h>
#include <stdbool.h>

#include "card.h"


int main( void )  {
  Hand h = {0};

  Card c1 = { eSpade   , (int)eSpade   , eTen   , (int)eTen   , false };
  Card c2 = { eHeart   , (int)eHeart   , eQueen , (int)eQueen , false };
  Card c3 = { eDiamond , (int)eDiamond , eFive  , (int)eFive  , false };
  Card c4 = { eClub    , (int)eClub    , eAce   , (int)eAce   , false };
  Card c5 = { eHeart   , (int)eHeart   , eJack  , (int)eJack  , false };
  Card c6 = { eClub    , (int)eClub    , eTwo   , (int)eTwo   , false };

  h = addCard( h , c1 );
  h = addCard( h , c2 );
  h = addCard( h , c3 );
  h = addCard( h , c4 );
  h = addCard( h , c5 );
  h = addCard( h , c6 );

  printHand( h );
  printf("\n");
  printHand2( h );

  return 0;
}


Hand addCard( Hand oldHand , Card card )  {
  Hand newHand = oldHand;
  switch( newHand.cardsDealt )  {
    case 0:
      newHand.c1 = card;  newHand.cardsDealt++;  break;
    case 1:
      newHand.c2 = card;  newHand.cardsDealt++;  break;
    case 2:
      newHand.c3 = card;  newHand.cardsDealt++;  break;
    case 3:
      newHand.c4 = card;  newHand.cardsDealt++;  break;
    case 4:
      newHand.c5 = card;  newHand.cardsDealt++;  break;
    default:
      // Hand is full, what to do now?
      // ERROR --> Ignore new card.
      newHand = oldHand;
      break;
  }
  return newHand;
}


void printHand( Hand h )  {
  for( int i = 1; i < h.cardsDealt+1 ; i++ )  {  // 1..5
    Card c;
    switch( i )  {
      case 1: c = h.c1; break;
      case 2: c = h.c2; break;
      case 3: c = h.c3; break;
      case 4: c = h.c4; break;
      case 5: c = h.c5; break;
      default:  return; break;
    }
    printCard( c );
  }
}


void printHand2( Hand h )  {
  int dealt = h.cardsDealt;
  if( dealt == 0 ) return;
  printCard( h.c1 ); if( dealt == 1 ) return;
  printCard( h.c2 ); if( dealt == 2 ) return;
  printCard( h.c3 ); if( dealt == 3 ) return;
  printCard( h.c4 ); if( dealt == 4 ) return;
  printCard( h.c5 ); return;
}


// yet another version of printHand
//
void printHand3( Hand h )  {
  for( int i = 1; i < h.cardsDealt+1 ; i++ )  {  // 1..5
    switch( i )  {
      case 1: printCard( h.c1 ); break;
      case 2: printCard( h.c2 ); break;
      case 3: printCard( h.c3 ); break;
      case 4: printCard( h.c4 ); break;
      case 5: printCard( h.c5 ); break;
      default:  return; break;
    }
  }
}


void printCard( Card c )  {
  switch( c.face )  {
    case eTwo:   printf( "    2 " ); break;
    case eThree: printf( "    3 " ); break;
    case eFour:  printf( "    4 " ); break;
    case eFive:  printf( "    5 " ); break;
    case eSix:   printf( "    6 " ); break;
    case eSeven: printf( "    7 " ); break;
    case eEight: printf( "    8 " ); break;
    case eNine:  printf( "    9 " ); break;
    case eTen:   printf( "   10 " ); break;
    case eJack:  printf( " Jack " ); break;
    case eQueen: printf( "Queen " ); break;
    case eKing:  printf( " King " ); break;
    case eAce:   printf( "  Ace " ); break;
    default:    printf( "  ??? " ); break;
  }
  switch( c.suit )  {
    case eSpade:   printf( "of Spades\n");   break;
    case eHeart:   printf( "of Hearts\n");   break;
    case eDiamond: printf( "of Diamonds\n"); break;
    case eClub:    printf( "of Clubs\n");    break;
    default:      printf( "of ???s\n");     break;
  }
}

  /* eof */

