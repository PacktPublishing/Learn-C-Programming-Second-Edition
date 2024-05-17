
// linkedlist_card.c
// Chapter 27 - One Handed Solitaire
// Learn C Programming, 2nd Edition
//
// use makefile to build.
//
// Modified from linklist_int.c.
//
// Only PrintData() function needed to be modified to call PrintCard()
// instead of calling printf(). Otherwise, functions identical to
// linkedlist_int.c


#include "linkedlist_card.h"

// functions internal to this file
void  AddNodeToFront(    LinkedList* pList , ListNode* pNode );
void  AddNodeToBack(     LinkedList* pList , ListNode* pNode );
void  AddNodeAtPosition( LinkedList* pList , ListNode* pNode , int pos );

ListNode*  RemoveNodeFromFront(  LinkedList* pList );
ListNode*  RemoveNodeFromBack(   LinkedList* pList );
ListNode*  RemoveNodeAtPosition( LinkedList* pList , int pos );


///////////////////////////////////////////////////////////////////////////////
// Redefine this to match datatype of ListData
///////////////////////////////////////////////////////////////////////////////
void PrintData( ListData* pData )  {
  PrintCard( pData );
}
///////////////////////////////////////////////////////////////////////////////
ListData* CreateData( ListData d )  {
  ListData* pD = (ListData*)calloc( 1 , sizeof( ListData ) );
  if( NULL == pD )  OutOfStorage();
  *pD = d;
  return pD;
}
///////////////////////////////////////////////////////////////////////////////


LinkedList*  CreateLinkedList()  {
  LinkedList* pLL = (LinkedList*) calloc( 1 , sizeof( LinkedList ) );

  if( pLL == NULL) OutOfStorage();

  return pLL;
}


void  AddNodeToFront( LinkedList* pList , ListNode* pNode )  {
  ListNode* next   = pList->firstNode;
  pList->firstNode = pNode;
  pNode->next      = next;

  pList->nodeCount++;
}


void AddNodeToBack( LinkedList* pList , ListNode* pNode )  {
  if( IsEmpty( pList ) )  {  // list is empty
    pList->firstNode = pNode;
    pNode->next  = NULL;
  } else {
    ListNode* curr = pList->firstNode ;
    while( curr->next != NULL )  {
      curr = curr->next;
    }
    curr->next  = pNode;
    pNode->next = NULL;
  }
  pList->nodeCount++;
}


void AddNodeAtPosition( LinkedList* pList , ListNode* pNode , int pos )  {
  ListNode* curr = GetNode( pList , pos-1 );

  ListNode* next = curr->next;
  curr->next  = pNode;
  pNode->next = next;

  pList->nodeCount++;
}


void  AddNode(   LinkedList* pList , ListNode* pNode , int pos )  {
  if( pos == eFront ) {
    AddNodeToFront( pList , pNode );
  } else if ( pos == eBack ) {
    AddNodeToBack(  pList , pNode );
  } else {
    AddNodeAtPosition( pList , pNode , pos );
  }
}


ListNode*  RemoveNodeFromFront( LinkedList* pList )  {
  if( IsEmpty( pList )) return NULL;

  ListNode* curr   = pList->firstNode;
  ListNode* next   = pList->firstNode->next;
  pList->firstNode = next;

  pList->nodeCount--;
  return curr;
}


ListNode* RemoveNodeFromBack( LinkedList* pList )  {
  if( IsEmpty( pList ) )  { // list is empty
    return NULL;
  } else {
    ListNode* curr = pList->firstNode ;
    ListNode* prev = NULL;
    while( curr->next != NULL )  {
      prev = curr;
      curr = curr->next;
    }
    prev->next = NULL;
    pList->nodeCount--;

    return curr;
  }
}


ListNode* RemoveNodeAtPosition( LinkedList* pList , int pos )  {
  if( pos == 0 )
    return RemoveNodeFromFront( pList );
  if( pos < 0 )
    return RemoveNodeFromBack( pList );
  if( pos >= Size( pList ) )
    return RemoveNodeFromBack( pList );

#if 1
  ListNode* curr = pList->firstNode;
  ListNode* prev = NULL;

  for( int i=0 ; i<pos ; i++ )  {
   prev = curr;
   curr = curr->next;
  }
  prev->next = curr->next;
  pList->nodeCount--;
  return curr;
#else
  ListNode* curr = pList->firstNode;
  ListNode* prev = NULL;

  if( pos == 1 )  {
  pList->firstNode = pList->firstNode->next;
  pList->nodeCount--;
  return curr;
  } else {
  for( int i=1 ; i<pos ; i++ )  {
  prev = curr;
  curr = curr->next;
  }
  prev->next = curr->next;
  pList->nodeCount--;
  return curr;
  }
#endif
}


ListNode* RemoveNode( LinkedList* pList , int pos )  {
  if( pos == eFront ) {
    return RemoveNodeFromFront( pList );
  } else if ( pos == eBack ) {
    return RemoveNodeFromBack(  pList );
  } else {
    return RemoveNodeAtPosition( pList , pos );
  }
}


void  PrintList( LinkedList* pList , void (*printData)(ListData* pData ) )  {
  ListNode* curr = pList->firstNode;

  while( curr != NULL )  {
    printData( curr->data );
    curr = curr->next;
  }
}


bool  IsEmpty( LinkedList* pList )  {
  return( pList->nodeCount == 0 );
}


int  Size( LinkedList* pList )  {
  return pList->nodeCount;
}


ListNode*  GetNode( LinkedList* pList , int pos )  {
  ListNode* curr = pList->firstNode;
  if( curr == NULL ){
    return pList->firstNode;
  } else if ( pos == eFront ) {
    return pList->firstNode;
  } else {
    int i = 0;
    while( curr->next != NULL )  {
      if( i == pos ) return curr;
      i++;
      curr = curr->next;
    }
    return curr;
  }
}


ListNode*  CreateNode( ListData* pData )  {
  ListNode* newNode = (ListNode*) calloc( 1 , sizeof( ListNode ) );
  if( newNode == NULL ) OutOfStorage();

  newNode->data = pData;
  newNode->next = NULL;  // Not needed because calloc clears what it allocates.

  return newNode;
}


void  DeleteNode( ListNode* pNode )  {
//  free( pNode->data );  // Card is held by another structure. No need to delete it.
  free( pNode );
}


void PrintNode( ListNode* pNode , void(*printData)( ListData* pData ) )  {
  printData( pNode->data );
}


void OutOfStorage( void )  {
  fprintf( stderr , "### FATAL RUNTIME ERROR ### No Memory Available" );
  exit( EXIT_FAILURE );
}

// eof