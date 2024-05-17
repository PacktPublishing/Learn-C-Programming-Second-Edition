// deck.c
// Chapter 24
// Learn C Programming, 2nd Edition
//
// To compile:
//   see main program source file: dealer.c


#include "dealer.h"

bool bRandomize   = true; // false --> a constant srand() seed (results constant)
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

  for( int i = 0 ; i < kCardsInDeck ; i++ )  {
    pDeck->shuffled[i] = &(pDeck->ordered[i]);
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

  if( pDeck->bIsShuffled == true )  {        // Deck is shuffled.
    if( pDeck->numDealt > 0 )  {
      printf( "The remaining shuffled deck:\n" );
    } else {
      printf( "The full shuffled deck:\n");
    }
    for( int i = pDeck->numDealt , j = 0 ; i < kCardsInDeck ; i++ , j++ )  {
      printf( "(%2d)" , i+1 );
      PrintCard( pDeck->shuffled[ i ] );
      if( j == 3  )  {
        printf( "\n" );
        j = -1;
      } else {
        printf( "\t");
      }
    }
  } else {                                    // Deck is not shuffled.
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

  // eof
