// deck.h
// Chapter 24
// Learn C Programming, 2nd Edition
//
// Header file for deck.c


#ifndef _DECK_H_
#define _DECK_H_


#include <stdbool.h>   // for Boolean
#include <stdlib.h>    // for rand() and srand()
#include <time.h>      // for date().

#include "card.h"


enum {
  kCardsInDeck = 52
};

  // A Deck
typedef struct {
  Card  ordered[ kCardsInDeck ];
  Card* shuffled[ kCardsInDeck ];
  int   numDealt;
  bool  bIsShuffled;
} Deck;

  // Operations on a Deck of Cards
void  InitializeDeck(   Deck* pDeck );
void  ShuffleDeck(      Deck* pDeck );
Card* DealCardFromDeck( Deck* pDeck );


#endif
