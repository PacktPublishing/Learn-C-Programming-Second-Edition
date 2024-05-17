// carddeck_3.c
// Chapter 16
// Learn C Programming, 2nd Edition
//
// carddeck_3.c builds upon carddeck_2b.c.
// In this version, we add an structure with an array of structures, called Deck
// and some functions to manipulate the Deck array.
//
// compile with cc carddeck_3.c -o carddeck_3 -Wall -Werror =std=c11
//


#include <stdbool.h>   // for Boolean
#include <stdio.h>     // for printf()
#include <string.h>    // for strcpy() and strcat()
#include <stdlib.h>    // for rand() and srand()
#include <time.h>      // for date().


  // Useful constants (avoid "magic numbers" whose meaning is
  // sometimes vague and whose values may change). Use these instead
  // of literals; when you need to change these, they are applied
  // everywhere.
  //
  enum  {
    kCardsInDeck = 52,  // For now, 52 cards in a deck. This will change
                        // depending upon the card game and the # of wild
                        // cards, etc.
    kCardsInSuit = 13,  // For now, kCardsInDeck / 4. This will change
                        // depending upon the card game.
    kCardsInHand = 5,   // For now, 5 cards dealt for each change. This will
                        // change depending upon the card game.
    kNumHands    = 4    // For now, for hands per "table". This will change
                        // depending on the game we want to implement.
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


  // ============================================
  // Definitions related to a hand
  // ============================================

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


  // ============================================
  // Definitions related to a Deck
  // ============================================

  // A Deck
typedef struct  {
  Card  ordered[ kCardsInDeck ];
  Card* shuffled[ kCardsInDeck ];
  int   numDealt;
  bool  bIsShuffled;
} Deck;

  // Operations on a Deck of Cards
void  InitializeDeck(   Deck* pDeck );
void  ShuffleDeck(      Deck* pDeck );
Card* DealCardFromDeck( Deck* pDeck );
void  PrintDeck(        Deck* pDeck );

  // At this point, we have only defined structures and
  // declared functions (operations on those structures) for
  // * card
  // * hand
  // * deck
  //
  // For now, a hand loosely corresponds to a player.
  //
  // Nothing has been allocated and each function needs
  // to be fully defined.
  //
int main( void )  {
  Deck  deck;
  Deck* pDeck = &deck;

  InitializeDeck( pDeck );
  PrintDeck(      pDeck );

  ShuffleDeck( pDeck );
  PrintDeck(   pDeck );

  Hand h1 , h2 , h3 , h4;

#if 1
  Hand* hands[] = { &h1 , &h2 , &h3 , &h4 };

  for( int i = 0 ; i < kNumHands ; i++ )  {
    InitializeHand( hands[i] );
  }
#else
  InitializeHand( &h1 );
  InitializeHand( &h2 );
  InitializeHand( &h3 );
  InitializeHand( &h4 );
#endif

  for( int i = 0 ; i < kCardsInHand ; i++ )  {
#if 1
    for( int j = 0 ; j < kNumHands ; j++ )  {
      AddCardToHand( hands[j] , DealCardFromDeck( pDeck ) );
    }
#else
    AddCardToHand( &h1 , DealCardFromDeck( pDeck ) );
    AddCardToHand( &h2 , DealCardFromDeck( pDeck ) );
    AddCardToHand( &h3 , DealCardFromDeck( pDeck ) );
    AddCardToHand( &h4 , DealCardFromDeck( pDeck ) );
#endif
  }
  PrintAllHands( hands );
  PrintDeck(     pDeck );
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


  // ============================================
  // Operations on a Hand
  // ============================================


void InitializeHand( Hand* pHand )  {
  pHand->cardsDealt = 0;
  for( int i = 0; i < kCardsInHand ; i++ )  {
    pHand->hand[i] = NULL;
  }
}


void AddCardToHand( Hand* pHand , Card* pCard )  {
  if( pHand->cardsDealt == kCardsInHand )  {
    printf( "ERROR: hand is full\n" );
    return;
  }

  pHand->hand[ pHand->cardsDealt ] = pCard;
  pHand->cardsDealt++;
}


void PrintHand( Hand* pHand , char* pHandStr , char* pLeadStr )  {
  printf( "%s%s\n" , pLeadStr , pHandStr );
  for( int i = 0; i < kCardsInHand ; i++ ) // 1..5
  {
    printf("%s" , pLeadStr );
    PrintCard( pHand->hand[i] );
    printf("\n");
  }
}


void PrintAllHands(  Hand* hands[ kNumHands ] )  {
  PrintHand( hands[0] , "Hand 1:" , "                  " );
  PrintHand( hands[1] , "Hand 2:" , "  " );
  PrintHand( hands[2] , "Hand 3:" , "                                    " );
  PrintHand( hands[3] , "Hand 4:" , "                  ");
}


  // ============================================
  // Operations on a Deck of Cards
  // ============================================

void InitializeDeck( Deck* pDeck )  {
  Face f[] = { eTwo   , eThree , eFour , eFive , eSix   , eSeven ,
               eEight , eNine  , eTen  , eJack , eQueen , eKing  , eAce };
  Card* pC;
  for( int i = 0 ; i < kCardsInSuit ; i++ )  {
    pC = &(pDeck->ordered[ i + (0*kCardsInSuit) ]);
    InitializeCard( pC , eSpade , f[i], kNotWildCard );

    pC = &(pDeck->ordered[ i + (1*kCardsInSuit) ]);
    InitializeCard( pC , eHeart , f[i], kNotWildCard );

    pC = &(pDeck->ordered[ i + (2*kCardsInSuit) ]);
    InitializeCard( pC , eDiamond , f[i], kNotWildCard );

    pC = &(pDeck->ordered[ i + (3*kCardsInSuit) ]);
    InitializeCard( pC , eClub , f[i], kNotWildCard );
  }

  for( int i = 0 ; i < kCardsInDeck ; i++ )  {
    pDeck->shuffled[i] = &(pDeck->ordered[i]);
  }

  pDeck->bIsShuffled = false;
  pDeck->numDealt    = 0;
}


void ShuffleDeck( Deck* pDeck )  {
  long randIndex;
#if 1
  srand( 8*1024*1024 ); // Just some number (8 megabits for giggles)
                        // The actual number doesn't matter (could be 1).
                        // this is handy for reproducibility and verifying
                        // your program as you develop it.
#else
  srand( time(NULL) );  // Seed our PRNG using time() function.
                        // Because time() ever increases, we'll
                        // get a different series each time we
                        // run the program.
#endif
  Card* pTmpCard;

    // Now, walk through the shuffled array, swapping the pointer
    // at a random card index in shuffled with the pointer at the
    // current card index.
    //
  for( int thisIndex = 0 ; thisIndex < kCardsInDeck ; thisIndex++ )  {
      // get a random index
    randIndex = rand() % kCardsInDeck;  // get next random number between 0..52

      // swap card pointers between thisIndex and randIndex
    pTmpCard = pDeck->shuffled[ thisIndex ];
    pDeck->shuffled[ thisIndex ] = pDeck->shuffled[ randIndex ];
    pDeck->shuffled[ randIndex ] = pTmpCard;
  }
  pDeck->bIsShuffled = true;
}


Card* DealCardFromDeck( Deck* pDeck )  {
  Card* pCard = pDeck->shuffled[ pDeck->numDealt ];
  pDeck->shuffled[ pDeck->numDealt ] = NULL;
  pDeck->numDealt++;
  return pCard;
}


void PrintDeck( Deck* pDeck )  {
  printf( "%d cards in the deck\n" ,
          kCardsInDeck );
  printf( "Deck %s shuffled\n",
          pDeck->bIsShuffled ? "is" : "is not" );
  printf( "%d cards dealt into %d hands\n" ,
          pDeck->numDealt ,  kNumHands );

  if( pDeck->bIsShuffled == true )  {   // Deck is shuffled.
    if( pDeck->numDealt > 0 )  {
      printf( "The remaining shuffled deck:\n" );
    } else {
      printf( "The full shuffled deck:\n");
    }
    for( int i = pDeck->numDealt , j = 0 ; i < kCardsInDeck ; i++ , j++ )  {
      printf( "(%2d)" , i+1 );
      PrintCard( pDeck->shuffled[ i ] );
      if( j == 3 )  {
        printf( "\n" );
        j = -1;
      } else {
        printf( "\t");
      }
    }
  } else {                               // Deck is not shuffled.
    printf( "The ordered deck: \n" );
    for( int i = 0 ; i < kCardsInSuit ; i++ )  {
      int index  = i + (0*kCardsInSuit);
      printf( "(%2d)" , index+1 );
      PrintCard( &(pDeck->ordered[ index ] ) );

      index = i + (1*kCardsInSuit);
      printf( "   (%2d)" , index+1 );
      PrintCard( &(pDeck->ordered[ index ] ) );

      index = i + (2*kCardsInSuit);
      printf( "   (%2d)" , index+1 );
      PrintCard( &(pDeck->ordered[ i + (2*kCardsInSuit) ] ) );

      index = i + (3*kCardsInSuit);
      printf( "   (%2d)" , index+1 );
      PrintCard( &(pDeck->ordered[ index ] ) );
      printf( "\n" );
    }
  }
  printf( "\n\n" );
}

  /*  eof  */

