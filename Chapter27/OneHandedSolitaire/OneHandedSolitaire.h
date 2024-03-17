// OneHandedSolitaire.h
// Chapter 27 - Complete Solitaire Game
// Learn C Programming, 2nd Edition
//
// use makefile to build.


#ifndef _ONEHANDEDSOLITAIRE_H_
#define _ONEHANDEDSOLITAIRE_H_


#include "hand.h"
#include "deck.h"


extern bool bRandomize; // defined in deck.c


typedef enum {
  eNone,
  ePlay,
  eHelp,
  eSameSuit,
  eSameFace,
  eNext,
  ePrint,
  eQuit
} Command;


Command  GetGameOption( void );
Command  GetPlayOption( void );
void     DoGameHelp( void );
void     DoPlayHelp( void );
void     DoPlay( Deck* pDeck , Hand* pHands );

void     PrintDeck( Deck* pDeck );

#endif

  /* eof */
