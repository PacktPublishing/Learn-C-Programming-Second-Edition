// hand.c
// Chapter 24
// Learn C Programming, 2nd Edition
//
// To compile:
//   see main program source file: dealer.c


#include "dealer.h"


  // ============================================
  // Operations on a Hand
  // ============================================


void InitializeHand( Hand* pHand )  {
  pHand->cardsDealt = 0;
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
  pHand->cardsDealt++;
}


void PrintHand(      Hand* pHand , char* pHandStr , char* pLeadStr )  {
  printf( "%s%s\n" , pLeadStr , pHandStr );
  for( int i = 0; i < kCardsInHand ; i++ )  {  // 0..4
    Card* pCard = pHand->hand[i];
    printf("%s" , pLeadStr );
    PrintCard( pCard );
    printf("\n");
  }
}


void PrintAllHands(  Hand* hands[ kNumHands ] )  {
  PrintHand( hands[0] , "Hand 1:" , "                  " );
  PrintHand( hands[1] , "Hand 2:" , "  " );
  PrintHand( hands[2] , "Hand 3:" , "                                    " );
  PrintHand( hands[3] , "Hand 4:" , "                  ");
}

  /* eof */
