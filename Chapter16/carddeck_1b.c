// carddeck_1b.c
// Chapter 16
// Learn C Programming, 2nd Edition
//
// carddeck_1b.c builds upon carddeck_1a.c.
// In this version, we add an array of structures, called Deck
// and some functions to manipulate the Deck array.
//
// compile with
//   cc carddeck_1b.c -o carddeck_1b -Wall -Werror =std=c17


#include <stdio.h>
#include <stdbool.h>
#include <string.h>    // for strcpy() and strcat()


    // Useful constants (avoid "magic numbers" whose meaning is
    // sometimes vague and whose values may change). Use these instead
    // of literals; when you need to change these, they are applied
    // everywhere.
    //
  enum  {
    kCardsInDeck = 52,  // For now, 52 cards in a deck. This will change
                        // depending upon the card game and the # of wild
                        // cards, etc.
    kCardsInSuit = 13   // For now, kCardsInDeck / 4. This will change
                        // depending upon the card game.
  };

const bool kWildCard    = true;
const bool kNotWildCard = false;


  // ============================================
  // Definitions related to a Card
  // ============================================

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
  eTwo ,
  eThree ,
  eFour ,
  eFive ,
  eSix ,
  eSeven ,
  eEight ,
  eNine ,
  eTen ,
  eJack ,
  eQueen ,
  eKing ,
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


int main( void )
{
  Card deck[ kCardsInDeck ];
  Card* pCard = &deck[3];
  InitializeCard( pCard , eSpade , eFive , kNotWildCard );
  PrintCard( &deck[3] );
  printf( "\n" );
}


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


  // For now, rely upon proper definition of enum Faces.
  // If, at some future time, face values need to change,
  // this function can be changed as needed and program will continue
  // to work as expected.
inline int GetCardFaceValue( Card* pCard )  {
  return (int)pCard->face;
}


  // For now, rely upon proper definition of enum Suits.
  // If, at some future time, the suit values need to change,
  // this function can be changed as needed and program will continue
  // to work as expected.
inline int GetCardSuitValue( Card* pCard ) {
  return (int)pCard->suit;
}

  /*  eof  */
