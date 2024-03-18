// hand.h
// Chapter 27 - Complete Blackjack Game
// Learn C Programming, 2nd Edition
//
// Header file for hand.c


#ifndef _HAND_H_
#define _HAND_H_


#include <stdio.h>     // for printf()

#include "card.h"


enum {
  kCardsInHand = 9,
  kNumHands    = 2
};

  // A Hand
typedef struct  {
  int   cardsDealt;
  int   handValue;
  Card* hand[ kCardsInHand ];
} Hand;

  // Operations on a Hand
void InitializeHand( Hand* pHand );
void AddCardToHand(  Hand* pHand , Card* pCard );
void PrintHand(      Hand* pHand , char* pHandStr , char* pLeadStr );
void PrintAllHands(  Hand* hands[ kNumHands ] );

int  GetHandValue(   Hand* pHand );


#endif
