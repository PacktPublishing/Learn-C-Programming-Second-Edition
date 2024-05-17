// linkedlist_card.h
// Chapter 27 - One Handed Solitaire
// Learn C Programming, 2nd Edition
//
// use makefile to build.
//
// Modified from linklist_int.h.
//
// Only typedef Card ListData changed from linkedlist_int.h
// and card.h included.
// Function prototypes otherwise identical.


#ifndef _LINKED_LIST_CARD_
#define _LINKED_LIST_CARD_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "card.h"


typedef Card ListData;

typedef struct _Node ListNode;
typedef struct _Node  {
  ListNode*  next;
  ListData*  data;
} ListNode;


typedef struct  {
  ListNode*  firstNode;
  int        nodeCount;
} LinkedList;


enum  {
  eFront = 0,
  eBack  = -1
};


void              PrintData(  ListData* pData ); // defined for specific typedef
ListData*         CreateData( ListData  d );


LinkedList*       CreateLinkedList();
void              AddNode(    LinkedList* pList , ListNode* pNode , int pos );
ListNode*         RemoveNode( LinkedList* pList , int pos );

bool              IsEmpty(    LinkedList* pList );
int               Size(       LinkedList* pList );

ListNode*         GetNode(    LinkedList* pList , int pos );

ListNode*         CreateNode( ListData* pData );
void              DeleteNode( ListNode* pNode );

void              OutOfStorage( void );

void              PrintList(  LinkedList* pList ,
                              void (*printData)(ListData* pData ) );
void              PrintNode(  ListNode* pNode ,
                              void (*printData)(ListData* pData));


#endif

 // eof