// blackjack.h
// Chapter 27 - Complete Blackjack Game
// Learn C Programming, 2nd Edition
//
// Header file for blackjack.c


#ifndef _BLACKJACK_H_
#define _BLACKJACK_H_


#include "hand.h"
#include "deck.h"


extern bool bRandomize; // defined in deck.c


typedef enum {
  eNone,
  ePlay,
  eHelp,
  eHit,
  eStand,
  eQuit
} Command;


Command  GetGameOption( void );
Command  GetPlayOption( void );
void     DoGameHelp( void );
void     DoPlayHelp( void );
void     DoPlay( Deck* pDeck , Hand* hands[] );

void     PrintDeck( Deck* pDeck );

#endif

  /* eof */
