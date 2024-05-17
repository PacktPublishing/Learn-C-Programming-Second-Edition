// linkedlist_int.h
// Chapter 27
// Learn C Programming, 2nd Edition
//
// This is the linkedlist "library" program derived from linkedlisttester.c from
// Chapter 18, herein called linked linkedlisttester_int_1file.c.
// This test file contains all of the structures & function prototypes
// implemented in linkedlist_int.c.
//
// Every library that you use or develop for yourself or others SHOULD
// have a corresponding test program which exercises the library as
// completely as possible.
//
// Include this file and its source code file in your project.


#ifndef _LINKED_LIST_INT_
#define _LINKED_LIST_INT_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef int ListData;


typedef struct _Node ListNode;
typedef struct _Node
{
  ListNode*  next;
  ListData*  data;
} ListNode;

typedef struct
{
  ListNode*  firstNode;
  int        nodeCount;
} LinkedList;


  // These two functions MAY have to be modified to reflect the type of
  // ListData.

void              PrintData(  ListData* data ); // defined for specific typedef
ListData*         CreateData( ListData  d );

  // These functions should never have to be modified regardless of the type
  // of ListData.

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
