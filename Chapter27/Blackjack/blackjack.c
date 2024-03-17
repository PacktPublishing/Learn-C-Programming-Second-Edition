// blackjack.c
// Chapter 27 - Complete Blackjack Game
// Learn C Programming, 2nd Edition
//
// A simplified game of blackjack.
//
// build with "make"


#include <stdbool.h>   // for Boolean
#include <stdio.h>     // for printf()
#include <ctype.h>     // for isspace() in command input functions

#include "blackjack.h"


enum  {
  kDealerHand = 0,
  kPlayerHand = 1
};


int main( void )  {
  Deck  deck;
  Deck* pDeck = &deck;
  InitializeDeck( pDeck );

  bRandomize = true;

  Hand h1 , h2 ;
  Hand* hands[] = { &h1 , &h2 };

  Command command;

  do {
    command  = GetGameOption();
    switch( command ) {
      case ePlay:
        DoPlay( pDeck  , hands );
        break;
      case eHelp:
        DoGameHelp();
        continue;
        break;
      case eQuit:
        break;
      default:
        break;
    }
  } while( command != eQuit );
  return 0;
}


void DoGameHelp( void )  {
  fprintf( stdout , "Usage: the game accepts the following commands:\n"
                    "       y or Y (Yes) to play\n"
                    "       n or N (No) to quit\n"
                    "       q or Q (Quit) to quit\n"
                    "       ? to print this help help text.\n\n" );
}


void DoPlayHelp( void )  {
  fprintf( stdout , "Usage: while playing a game, the following commands apply:\n"
                    "       h or H (Hit) to get another card\n"
                    "       s or S (Stand) to signal you are done\n"
                    "       q or Q (Quit) to quit at any time\n"
                    "       ? to print this help help text.\n\n" );
}


Command GetGameOption( void ) {
  char    ch;
  Command command;
  char*   prompt = "Would you like to play Blackjack? [ynQ?] " ;
  char    inputStr[80]={0};

  printf( "%s" , prompt );
  fgets( (char*)inputStr , 79 , stdin ); // Get a string, but...
  ch = inputStr[0];                 // Throw away everything but 1st character
  if( isspace( ch ) ) ch = 'q';     // <return>-only string. Set to default.
  ch = tolower( ch );
  switch( ch ) {
    case 'y':
      command = ePlay;
      break;
    case 'n':
    case 'q':
      command = eQuit;
      break;
    case '?':
      command = eHelp;
      break;
    default:
      command = eNone;
      break;
  }
  return command;
}


Command GetPlayOption( void )  {
  char    ch;
  Command command;
  char*   prompt = "Hit or stand? [hsq?] " ;
  char    inputStr[80]={0};

  printf( "%s" , prompt );
  fgets( (char*)inputStr , 80 , stdin ); // Get a string, but...
  ch = inputStr[0];                 // Throw away everything but 1st character
  if( isspace( ch ) ) ch = ' ';     // <return>-only string. Set to default.
  ch = tolower( ch );
  switch( ch ) {
    case 'h':
      command = eHit;
      break;
    case 's':
      command = eStand;
      break;
    case 'q':
      command = eQuit;
      break;
    case '?':
      command = eHelp;
      break;
    default:
      command = eNone;
      break;
  }
  return command;
}


void DoPlay( Deck* pDeck , Hand* hands[] ) {
  bool bPlayerDone = false;
  bool bDealerDone = false;

  int playerHandValue;
  int dealerHandValue;

  ShuffleDeck( pDeck );

  for( int i = 0 ; i < kNumHands ; i++ )  {
    InitializeHand( hands[i] );
  }

  for( int i = 0 ; i < 2 ; i++ )  {
    for( int j = 0 ; j < kNumHands ; j++ )  {
      AddCardToHand( hands[j] , DealCardFromDeck( pDeck ) );
    }
  }
  PrintAllHands( hands );

  // while 1) you are under 21 and 2) dealer is under 17
  //  ask you for another card
  //  see if dealer wants another card
  //  if you are over 21 or delayer over 21, game over.

  Command command;
  do {
    command = GetPlayOption();
    switch( command ) {
      case eHit:
          // Player has chosen another card.
        printf( "  Player requests a card.\n");
        AddCardToHand( hands[ kPlayerHand ] , DealCardFromDeck( pDeck ) );
        break;
      case eStand:
        printf( "  Player stands.\n" );
        bPlayerDone = true;
        break;
      case eHelp:
        DoPlayHelp();
        continue;
        break;
      case eQuit:
        exit( 0 );
        break;
      default:
        break;
    }

      // play logic goes here.
    playerHandValue = GetHandValue( hands[kPlayerHand] );
    dealerHandValue = GetHandValue( hands[kDealerHand] );

       //if dealerHand < 17, --> dealer gets a card.

    if( playerHandValue < 22 && dealerHandValue < 17 )  {
      printf( "  Dealer requests a card.\n");
      AddCardToHand( hands[ kDealerHand ] , DealCardFromDeck( pDeck ) );
      dealerHandValue = GetHandValue( hands[kDealerHand] );
    }

    PrintAllHands( hands );

    if( dealerHandValue > 16 )  bDealerDone = true;
    if( dealerHandValue > 21 || playerHandValue > 21 )  {
      bPlayerDone = true;
      bDealerDone = true;
    }

  } while( !bPlayerDone && !bDealerDone );

    // winner logic goes here.

  if( playerHandValue > 21 )
    printf( "\n    Sorry, you lost.\n\n" );
  else if( dealerHandValue > 21 )
    printf( "\n    YOU WON!\n\n" );
  else if( playerHandValue < dealerHandValue )
    printf( "\n    Sorry, you lost.\n\n" );
  else if( 21 == playerHandValue &&
           playerHandValue == dealerHandValue )
    printf( "\n    A tie game!\n\n" );
  else
    printf( "\n    YOU WON!\n\n" );
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


  /* eof */
