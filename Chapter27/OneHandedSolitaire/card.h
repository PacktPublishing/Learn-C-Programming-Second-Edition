// card.h
// Chapter 27 - One Handed Solitaire
// Learn C Programming, 2nd Edition
//
// Header file for card.c


#ifndef _CARD_H_
#define _CARD_H_


#include <stdbool.h>
#include <stdio.h>
#include <string.h>


enum {
  kCardsInSuit = 13
};

extern const bool bWildCard;
extern const bool bNotWildCard;

  // Card Suits
typedef enum  {
  eClub  = 1,
  eDiamond,
  eHeart,
  eSpade
} Suit;

  // Card Faces
typedef enum  {
  eOne = 1,
  eTwo,
  eThree,
  eFour,
  eFive,
  eSix,
  eSeven,
  eEight,
  eNine,
  eTen,
  eJack,
  eQueen,
  eKing,
  eAce
} Face;

  // A Card
typedef struct  {
  Suit suit;
  int  suitValue;
  Face face;
  int  faceValue;
  bool isWild;
} Card;

  // Operations on a Card
void InitializeCard(   Card* pCard , Suit s , Face f , bool w );
void PrintCard(        Card* pCard );
void CardToString(     Card* pCard , char pCardStr[20] );
int  GetCardFaceValue( Card* pCard );
int  GetCardSuitValue( Card* pCard );


#endif
