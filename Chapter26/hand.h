// hand.h
// Chapter 26
// Learn C Programming, 2nd Edition
//
// Header file for hand.c


#ifndef _HAND_H_
#define _HAND_H_


#include <stdio.h>     // for printf()

#include "card.h"


enum {
  kCardsInHand = 5,
  kNumHands    = 4
};

  // A Hand
typedef struct  {
  int   cardsDealt;
  Card* hand[ kCardsInHand ];
} Hand;

  // Operations on a Hand
void InitializeHand( Hand* pHand );
void AddCardToHand(  Hand* pHand , Card* pCard );
void PrintHand(      Hand* pHand , char* pHandStr , char* pLeadStr );
void PrintAllHands(  Hand* hands[ kNumHands ] );


#endif
