// deck.c
// Chapter 27 - One Handed Solitaire
// Learn C Programming, 2nd Edition
//
// use makefile to build.


#include "deck.h"

bool bRandomize   = false; // false --> a constant srand() seed (results constant)
                           // true  --> a changing srand() seed (results vary)
                           // if not set elsewhere, default value is true.


  // ============================================
  // Operations on a Deck of Cards
  // ============================================


void InitializeDeck( Deck* pDeck )  {
  Face f[13] = { eTwo   , eThree , eFour , eFive , eSix   , eSeven ,
    eEight , eNine  , eTen  , eJack , eQueen , eKing  , eAce };
  Card* pC;
  for( int i = 0 ; i < kCardsInSuit ; i++ )  {
    pC = &(pDeck->ordered[ i + (0*kCardsInSuit) ]);
    InitializeCard( pC , eSpade , f[i], bNotWildCard );

    pC = &(pDeck->ordered[ i + (1*kCardsInSuit) ]);
    InitializeCard( pC , eHeart , f[i], bNotWildCard );

    pC = &(pDeck->ordered[ i + (2*kCardsInSuit) ]);
    InitializeCard( pC , eDiamond , f[i], bNotWildCard );

    pC = &(pDeck->ordered[ i + (3*kCardsInSuit) ]);
    InitializeCard( pC , eClub , f[i], bNotWildCard );
  }

  pDeck->bIsShuffled = false;
  pDeck->numDealt    = 0;
}


void ShuffleDeck( Deck* pDeck )  {
  long randIndex;
  unsigned int seed;
  if( true == bRandomize ) {

    // Seed our PRNG using time() function. Because time() ever increases,
    // we'll get a different series each time we run the program.
    seed = time(NULL);
  } else {
    printf( "Using non-random distribution (constant seed). ");

    // Using a constant will give the same sequence each time.
    // The actual number doesn't matter (could be 1). This is handy for
    // reproducibility to verify your program as you develop it.
    seed = 0x800000;   // Just some number ( 8*1024*1024 for giggles)
  }
  printf( "srand seed is %u [%#x]\n\n" , seed , seed );
  srand( seed );

    // Initialize shuffled array.
  for( int i = 0 ; i < kCardsInDeck ; i++ )  {
    pDeck->shuffled[i] = &(pDeck->ordered[i]);
  }

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
  pDeck->numDealt    = 0;
}


Card* DealCardFromDeck( Deck* pDeck )  {
  Card* pCard = pDeck->shuffled[ pDeck->numDealt ];
  pDeck->shuffled[ pDeck->numDealt ] = NULL;
  pDeck->numDealt++;
  return pCard;
}


  /*  eof  */
