// dealer.c
// Chapter 24
// Learn C Programming, 2nd Edition
//
// Demonstrate
// 1) how to group data structures and functions that
//    manipulate them into .c/.h pairs.
// 2) use a common header file for all source files.
// 3) use preprocessor directives to eliminate redundant include file preprocessing
// 4) build a multi-file program
//
// Dependencies:
//
//   card.h   card.c
//   hand.h   hand.c
//   deck.h   deck.c
//
// Compile with:
//
//    cc -c dealer.c -Wall -Werror -std=c17
//    cc dealer.o card.o hand.o deck.o -o dealer -Wall -Werror -std=c17


#include <stdbool.h>   // for Boolean
#include <stdio.h>     // for printf()

#include "hand.h"
#include "deck.h"


void  PrintDeck(        Deck* pDeck );


extern bool bRandomize; // defined in deck.c


int main( void )  {
  Deck  deck;
  Deck* pDeck = &deck;

  bRandomize = false;

  InitializeDeck( pDeck );
  PrintDeck(      pDeck );

  ShuffleDeck( pDeck );
  PrintDeck(   pDeck );

  Hand h1 , h2 , h3 , h4;

  Hand* hands[] = { &h1 , &h2 , &h3 , &h4 };

  for( int i = 0 ; i < kNumHands ; i++ )  {
    InitializeHand( hands[i] );
  }

  for( int i = 0 ; i < kCardsInHand ; i++ )  {
    for( int j = 0 ; j < kNumHands ; j++ )  {
      AddCardToHand( hands[j] , DealCardFromDeck( pDeck ) );
    }
  }
  PrintAllHands( hands );
  PrintDeck(     pDeck );

  return 0;
}


void PrintDeck( Deck* pDeck )  {
  printf( "%d cards in the deck\n" ,
    kCardsInDeck );
  printf( "Deck %s shuffled\n",
    pDeck->bIsShuffled ? "is" : "is not" );
  printf( "%d cards dealt into %d hands\n" ,
    pDeck->numDealt ,  kNumHands );

  if( pDeck->bIsShuffled == true )  {        // Deck is shuffled.
    if( pDeck->numDealt > 0 )  {
      printf( "The remaining shuffled deck:\n" );
    } else {
      printf( "The full shuffled deck:\n");
    }
    for( int i = pDeck->numDealt , j = 0 ; i < kCardsInDeck ; i++ , j++ )  {
      printf( "(%2d)" , i+1 );
      PrintCard( pDeck->shuffled[ i ] );
      if( j == 3  )  {
        printf( "\n" );
        j = -1;
      } else {
        printf( "\t");
      }
    }
  } else {                                    // Deck is not shuffled.
    printf( "The ordered deck: \n" );
    for( int i = 0 ; i < kCardsInSuit ; i++ )  {
      int index  = i + (0*kCardsInSuit);
      printf( "(%2d)" , index+1 );
      PrintCard( &(pDeck->ordered[ index ] ) );

      index = i + (1*kCardsInSuit);
      printf( "   (%2d)" , index+1 );
      PrintCard( &(pDeck->ordered[ index ] ) );

      index = i + (2*kCardsInSuit);
      printf( "   (%2d)" , index+1 );
      PrintCard( &(pDeck->ordered[ i + (2*kCardsInSuit) ] ) );

      index = i + (3*kCardsInSuit);
      printf( "   (%2d)" , index+1 );
      PrintCard( &(pDeck->ordered[ index ] ) );
      printf( "\n" );
    }
  }
  printf( "\n\n" );
}


  /* eof */
