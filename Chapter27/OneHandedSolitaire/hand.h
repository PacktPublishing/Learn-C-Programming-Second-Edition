// hand.h
// Chapter 27 - One Handed Solitaire
// Learn C Programming, 2nd Edition
//
// Header file for hand.c


#ifndef _HAND_H_
#define _HAND_H_


#include <stdio.h>     // for printf()

#include "card.h"
#include "linkedlist_card.h"


enum {
  kCardsInHand = 52,
  kNumHands    = 1
};

  // A Hand
typedef struct  {
  int   cardsRemaining;
  int   currentTopCard;
  bool  bHandChanged;
  LinkedList* pHandList;
} Hand;

  // Operations on a Hand
void InitializeHand( Hand* pHand );
void AddCardToHand(  Hand* pHand , Card* pCard );
void PrintHand(      Hand* pHand , char* pHandStr , char* pLeadStr );

void PrintTop4Cards( Hand* pHand );
void RemovedCardsFromHand( Hand* pHand , int beginCard , int numCards );


#endif
