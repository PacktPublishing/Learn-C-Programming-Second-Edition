// card.c
// Chapter 27 - Complete Blackjack Game
// Learn C Programming, 2nd Edition
//
// use makefile to build.


#include "card.h"


const bool bWildCard    = true;
const bool bNotWildCard = false;

  // ============================================
  // Operations on a Card
  // ============================================


void InitializeCard( Card* pCard, Suit s , Face f , bool w )  {
  pCard->suit = s;
  pCard->suitValue = GetCardSuitValue( pCard );

  pCard->face = f;
  pCard->faceValue = GetCardFaceValue( pCard );

  pCard->isWild = w;
}


void PrintCard( Card* pCard )  {
  char cardStr[20] = {0};
  CardToString( pCard , cardStr );
//  printf( "%18s [%2d]" , cardStr , pCard->faceValue );
  printf( "%18s" , cardStr );
}


void CardToString( Card* pCard , char pCardStr[20] )  {
  switch( pCard->face ) {
    case eTwo:   strcpy( pCardStr , "    2 " ); break;
    case eThree: strcpy( pCardStr , "    3 " ); break;
    case eFour:  strcpy( pCardStr , "    4 " ); break;
    case eFive:  strcpy( pCardStr , "    5 " ); break;
    case eSix:   strcpy( pCardStr , "    6 " ); break;
    case eSeven: strcpy( pCardStr , "    7 " ); break;
    case eEight: strcpy( pCardStr , "    8 " ); break;
    case eNine:  strcpy( pCardStr , "    9 " ); break;
    case eTen:   strcpy( pCardStr , "   10 " ); break;
    case eJack:  strcpy( pCardStr , " Jack " ); break;
    case eQueen: strcpy( pCardStr , "Queen " ); break;
    case eKing:  strcpy( pCardStr , " King " ); break;
    case eAce:   strcpy( pCardStr , "  Ace " ); break;
    default:     strcpy( pCardStr , "  ??? " ); break;
  }
  switch( pCard->suit )  {
    case eSpade:   strcat( pCardStr , "of Spades  "); break;
    case eHeart:   strcat( pCardStr , "of Hearts  "); break;
    case eDiamond: strcat( pCardStr , "of Diamonds"); break;
    case eClub:    strcat( pCardStr , "of Clubs   "); break;
    default:       strcat( pCardStr , "of ???s    "); break;
  }
}


  // In Blackjack, cards have specific values.
  // This routine sets them initially for Blackjack.
  // NOTE: Aces will start out with value=11. We'll later
  //       give the option to change to value = 1.
inline int GetCardFaceValue( Card* pCard )  {
  int value = 0;
  switch( pCard->face )  {
    case eTwo:    value = 2; break;
    case eThree:  value = 3; break;
    case eFour:   value = 4; break;
    case eFive:   value = 5; break;
    case eSix:    value = 6; break;
    case eSeven:  value = 7; break;
    case eEight:  value = 8; break;
    case eNine:   value = 9; break;

    case eTen:
    case eJack:
    case eQueen:
    case eKing:   value = 10; break;

    case eAce:    value = 11; break;
    default:  value = 0; break;
  }
  return value;
}


  // For now, rely upon proper definition of enum Suits.
  // If, at some future time, the suit values need to change,
  // this function can be changed as needed and program will continue
  // to work as expected.
inline int GetCardSuitValue( Card* pCard ) {
  return (int)pCard->suit;
}

  /* eof */
