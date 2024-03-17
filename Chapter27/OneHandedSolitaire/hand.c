// hand.c
// Chapter 27 - One Handed Solitaire
// Learn C Programming, 2nd Edition
//
// use makefile to build.


#include "hand.h"
#include <stdio.h>
#include <stdlib.h>


  // ============================================
  // Operations on a Hand
  // ============================================


void InitializeHand( Hand* pHand )  {
  pHand->cardsRemaining = 0;
  pHand->currentTopCard = 0; // an index into hand array
  pHand->bHandChanged   = false;
  pHand->pHandList      = CreateLinkedList();
}


void AddCardToHand( Hand* pHand , Card* pCard )  {
  if( pHand->cardsRemaining == kCardsInHand )  {
    printf( "ERROR: hand is full\n" );
    return;
  }

  ListNode* pNode = CreateNode( pCard );
  AddNode( pHand->pHandList , pNode , eBack );
  pHand->cardsRemaining++;
}


void PrintHand( Hand* pHand , char* pHandStr , char* pLeadStr )  {
  printf( "%s%s\n" , pLeadStr , pHandStr );
  for( int i = 0 ; i < pHand->cardsRemaining ; i++ )  {
    ListNode* pNode = GetNode( pHand->pHandList , i );
    printf("%s" , pLeadStr );
    PrintData( pNode->data );
    printf( "\n" );
  }
}


  // beginCard & endCard are indices (0-based)
  // Do bounds-checking for beginCard & endCard.
void PrintTop4Cards( Hand* pHand ) {

  int beginCard = pHand->currentTopCard;
  int endCard   = beginCard+4;
  if( endCard > pHand->cardsRemaining ) endCard = pHand->cardsRemaining;

  printf( "\n" );
  for( int i = beginCard ; i < endCard; i++ )  {
    printf( "\t" );
    ListNode* pNode = GetNode( pHand->pHandList , i );
    PrintData( pNode->data );
    printf( "\n" );
  }
  printf( "\t\t\t[%d cards remaining]\n\n", pHand->cardsRemaining );
}


  // beginCard is a 0-based index, numCards is an offset.
  // Do bounds-checking for endCard index.
void RemovedCardsFromHand( Hand* pHand , int beginCard , int numCards )  {
  if( pHand->cardsRemaining < numCards ) numCards = pHand->cardsRemaining;
  int endCard = beginCard + numCards;
  for( int i = beginCard ; i < endCard ; i++) {
    ListNode* pNode = RemoveNode( pHand->pHandList , beginCard );
    printf( "                                          Removing " );
    PrintData( pNode->data );
    printf( "\n" );
    DeleteNode( pNode );
    pHand->cardsRemaining--;
  }
  pHand->bHandChanged = true;
}


  /* eof */
