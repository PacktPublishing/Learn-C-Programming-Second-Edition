// hand.h
// Chapter 24
// Learn C Programming - Fundamentals of C
// Learn C Programming, 2nd Edition
//
// Header file for hand.c
//
// To compile:
//   see main program source file: dealer.c


#ifndef _HAND_H_
#define _HAND_H_


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
