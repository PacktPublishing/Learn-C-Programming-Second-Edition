// hand.c
// Chapter 27 - Complete Blackjack Game
// Learn C Programming, 2nd Edition
//
// use makefile to build.


#include "hand.h"
#include <stdio.h>


  // ============================================
  // Operations on a Hand
  // ============================================


void InitializeHand( Hand* pHand )  {
  pHand->cardsDealt = 0;
  pHand->handValue  = 0;
  for( int i = 0; i < kCardsInHand ; i++ )  {
    pHand->hand[i] = NULL;
  }
}


void AddCardToHand( Hand* pHand , Card* pCard )  {
  if( pHand->cardsDealt == kCardsInHand )  {
    printf( "ERROR: hand is full\n" );
    return;
  }

  pHand->hand[ pHand->cardsDealt ] = pCard;
  pHand->handValue += pCard->faceValue;
  pHand->cardsDealt++;
}


void PrintHand(      Hand* pHand , char* pHandStr , char* pLeadStr )  {
  printf( "%s%s\n" , pLeadStr , pHandStr );
  for( int i = 0; i < pHand->cardsDealt ; i++ )  {  // 0..11
    Card* pCard = pHand->hand[i];
    printf("%s" , pLeadStr );
    PrintCard( pCard );
    if( i+1 < pHand->cardsDealt )
      printf( "\n" );
    else
      printf( " [%d]\n" , pHand->handValue );
  }
}


void PrintAllHands(  Hand* hands[ kNumHands ] )  {
  PrintHand( hands[0] , "Dealer Hand:" , "  " );
  PrintHand( hands[1] , "My Hand:" , "                             " );
}

int  GetHandValue(   Hand* pHand )  {
  int value = 0;
  for( int i = 0 ; i < pHand->cardsDealt ; i++ )
    value += (pHand->hand[i])->faceValue;
  pHand->handValue = value;
  return pHand->handValue;
}


  /* eof */
