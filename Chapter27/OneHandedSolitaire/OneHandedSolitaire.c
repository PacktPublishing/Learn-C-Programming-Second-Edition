// OneHandedSolitaire.c
// Chapter 27 - One Handed Solitaire
// Learn C Programming, 2nd Edition
//
// use makefile to build.


#include <stdbool.h>   // for Boolean
#include <stdio.h>     // for printf()
#include <ctype.h>
#include <stdlib.h>

#include "OneHandedSolitaire.h"


extern bool bRandomize; // defined in deck.c


int main( void )  {
  Deck  deck;
  Deck* pDeck = &deck;
  InitializeDeck( pDeck );

  bRandomize = false;

  Hand h1;

  Command command;

  do {
    command  = GetGameOption();
    switch( command ) {
      case ePlay:
        DoPlay( pDeck  , &h1 );
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
    "       s or S (take middle two) when 1st and last are same suit.\n"
    "       f or F (take all four) when 1st and last are same face.\n"
    "       n or N (next card) reveal next card."
    "       q or Q (Quit) to quit at any time.s\n"
    "       ? to print this help help text.\n\n" );
}


Command GetGameOption( void ) {
  char    ch;
  Command command;
  char*   prompt = "Would you like to play One Handed Solitaire? [ynQ?] " ;
  char    inputStr[80]={0};

  printf( "%s" , prompt );
  fgets( (char*)inputStr , 80 , stdin ); // Get a string, but...
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
  char*   prompt = "same Suit, same Face, Neither ? [sfNpq?] " ;
  char    inputStr[80]={0};

  printf( "%s" , prompt );
  fgets( (char*)inputStr , 80 , stdin ); // Get a string, but...
  ch = inputStr[0];                 // Throw away everything but 1st character
  if( isspace( ch ) ) ch = 'N';     // <return>-only string. Set to default.
  ch = tolower( ch );
  switch( ch ) {
    case 's':
      command = eSameSuit; break;
    case 'f':
      command = eSameFace; break;
    case 'n':
      command = eNext;     break;
    case 'q':
      command = eQuit;     break;
    case 'p':
      command = ePrint;    break;
    case '?':
      command = eHelp;     break;
    default:
      command = eNone;     break;
  }
  return command;
}


void DoPlay( Deck* pDeck , Hand* pHand ) {

  bool bDone = false;

  ListNode* p1stNode;
  ListNode* p4thNode;

  ShuffleDeck( pDeck );

  InitializeHand( pHand );

  for( int i = 0 ; i < kCardsInHand ; i++ )  {
    AddCardToHand( pHand , DealCardFromDeck( pDeck ) );
  }

    // The goal is to remove all cards from deck.
    // The game is over when all cards or removed or no additional
    // cards can be removed.

    // Game logic is contained within each switch statement.

  Command command;
  do {
    PrintTop4Cards( pHand );
    command = GetPlayOption();
    switch( command ) {
      case eSameSuit:
        p1stNode = GetNode( pHand->pHandList , pHand->currentTopCard );
        p4thNode = GetNode( pHand->pHandList , pHand->currentTopCard+3 );
        if( p1stNode->data->suit == p4thNode->data->suit ) {
          RemovedCardsFromHand( pHand , pHand->currentTopCard+1 , 2 );
            // backup to show previous cards.
          pHand->currentTopCard -= 2;
          if( pHand->currentTopCard < 0 ) pHand->currentTopCard = 0;
        } else {
          printf( "\nOops! You can't do that, suits not equal!\n");
        }
        break;
      case eSameFace:
        p1stNode = GetNode( pHand->pHandList , pHand->currentTopCard );
        p4thNode = GetNode( pHand->pHandList , pHand->currentTopCard+3 );
        if( p1stNode->data->face == p4thNode->data->face )  {
          RemovedCardsFromHand( pHand , pHand->currentTopCard , 4 );
            // backup to show previous cards.
          pHand->currentTopCard -= 4;
          if( pHand->currentTopCard < 0 ) pHand->currentTopCard = 0;
        } else {
          printf( "\nOops! You can't do that, faces not equal!\n");
        }
        break;
      case eNext:
          // forward to show next card.
        pHand->currentTopCard++;
        break;
      case eHelp:
        DoPlayHelp();
        continue;
        break;
      case ePrint:
        PrintHand( pHand , "Cards in Hand " , "                       " );
        break;
      case eQuit:
        exit( 0 );
        break;
      default:
        break;
    }

    int cardsInHand = pHand->cardsRemaining;
    int leftToShow  = cardsInHand - pHand->currentTopCard;

    if( cardsInHand == 0 )  {
      bDone = true;
    } else if( cardsInHand < 4 ) {
      pHand->currentTopCard = 0;
      printf( "\n%d cards remaining.\n" , cardsInHand );
      PrintTop4Cards( pHand );
      bDone = true;
    } else {  // 4 or more cards left

      if( leftToShow <= 4 )  {
        printf( "\nAt the end of the deck.\n" );

        if( true == pHand->bHandChanged ) {
          pHand->currentTopCard = 0;
          pHand->bHandChanged   = false;
        } else {
          printf( "\nNo cards removed.\n" );
          bDone = true;
        }
      }
    }

  } while( !bDone );

    // winner logic goes here.

  if( pHand->cardsRemaining == 0 )
    printf( "\n    YOU WON!\n\n" );
  else if( pHand->cardsRemaining < 7 )
    printf( "\n    So close but you lost.\n\n" );
  else
    printf( "\n    Sorry, you lost.\n\n" );

}


void PrintDeck( Deck* pDeck )  {
  printf( "%d cards in the deck\n" ,
    kCardsInDeck );
  printf( "Deck %s shuffled\n",
    pDeck->bIsShuffled ? "is" : "is not" );

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
