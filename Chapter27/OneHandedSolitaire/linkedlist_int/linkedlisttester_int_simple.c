// linkedlisttester_int_simple.c
// Chapter 27
// Learn C Programming, 2nd Edition
//
// This is an alternative file to linkedlisttester_int.c.
// This test file does the same thing as linkedlisttester_int.c.
// Instead of using a bunch of test functions, it makes all of the
// calls directly to test them.
//
// Every library that you use or develop for yourself or others SHOULD
// have a corresponding test program which exercises the library as
// completely as possible.
//
// compile with:
//   cc linkedlisttester_int_simple.c linkedlist_int.c \
//   -o linkedlisttester_int_simple -Wall -Werror -std=c17

#include "linkedlist_int.h"


// =================================================
// main() function and

int main( void )
{
  LinkedList* pLL = CreateLinkedList();

  ListData  data;
  ListData* pData;
  ListNode* pNode;

  printf( "Using int array[ 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10 ]\n\n" );
  int dataArray[] = { 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10 };
  int dataArraySize = 10;

  for( int i = 0 ; i < dataArraySize ; i++)  {
    pData = (ListData*)calloc( 1 , sizeof( data ) );
    *pData = dataArray[ i ];
    pNode = CreateNode( pData );
    AddNode( pLL , pNode , 0 );
  }

  printf( "The Linked List has %d entries.  " , Size( pLL ) );
  PrintList( pLL , PrintData );
  printf( "\n\n" );

  pNode = GetNode( pLL , 0 );
  printf( "Examined 1st entry from list, value = " );
  PrintNode( pNode, PrintData );
  printf( "\n" );
  printf( "The Linked List has %d entries. " , Size( pLL ) );
  PrintList( pLL , PrintData );
  printf( "\n\n" );

  pNode = RemoveNode( pLL , 0 );
  printf( "Removed 1st entry from list, value = " );
  PrintNode( pNode, PrintData );
  printf( "\n" );
  printf( "The Linked List has %d entries.  " , Size( pLL ) );
  PrintList( pLL , PrintData );
  printf( "\n\n" );

  pNode = RemoveNode( pLL , -1 );
  printf( "Removed last entry from list, value = " );
  PrintNode( pNode, PrintData );
  printf( "\n" );
  printf( "The Linked List has %d entries.  " , Size( pLL ) );
  PrintList( pLL , PrintData );
  printf( "\n\n" );

  pNode = RemoveNode( pLL , 2 ); // 0-based indexing.
  printf( "Removed 3rd entry from list, value = " );
  PrintNode( pNode, PrintData );
  printf( "\n" );
  printf( "The Linked List has %d entries.  " , Size( pLL ) );
  PrintList( pLL , PrintData );
  printf( "\n\n" );

  pNode = RemoveNode( pLL , 1 ); // 0-based indexing.
  printf( "Removed 2nd entry from list, value = " );
  PrintNode( pNode, PrintData );
  printf( "\n" );
  printf( "The Linked List has %d entries.  " , Size( pLL ) );
  PrintList( pLL , PrintData );
  printf( "\n\n" );

  pNode = RemoveNode( pLL , 5 ); // 0-based indexing.
  printf( "Removed 6th entry from list, value = " );
  PrintNode( pNode, PrintData );
  printf( "\n" );
  printf( "The Linked List has %d entries.  " , Size( pLL ) );
  PrintList( pLL , PrintData );
  printf( "\n\n" );

  pNode = RemoveNode( pLL , 3 ); // 0-based indexing.
  printf( "Removed 4th entry from list, value = " );
  PrintNode( pNode, PrintData );
  printf( "\n" );
  printf( "The Linked List has %d entries.  " , Size( pLL ) );
  PrintList( pLL , PrintData );
  printf( "\n\n" );

  pData = (ListData*)calloc( 1 , sizeof( data ) );
  *pData = 20;
  pNode = CreateNode( pData );
  AddNode( pLL , pNode , 0 );
  printf( "Added to front of the list, value = %d\n" , 20 );
  printf( "The Linked List has %d entries.  " , Size( pLL ) );
  PrintList( pLL , PrintData );
  printf( "\n\n" );

  pData = (ListData*)calloc( 1 , sizeof( data ) );
  *pData = 30;
  pNode = CreateNode( pData );
  AddNode( pLL , pNode , -1 );
  printf( "Added to last element of the list, value = %d\n" , 30 );
  printf( "The Linked List has %d entries.  " , Size( pLL ) );
  PrintList( pLL , PrintData );
  printf( "\n\n" );

  pData = (ListData*)calloc( 1 , sizeof( data ) );
  *pData = 40;
  pNode = CreateNode( pData );
  AddNode( pLL , pNode , 3 );
  printf( "Added to 3rd element of the list, value = %d\n" , 40 );
  printf( "The Linked List has %d entries.  " , Size( pLL ) );
  PrintList( pLL , PrintData );
  printf( "\n\n" );

  pData = (ListData*)calloc( 1 , sizeof( data ) );
  *pData = 11;
  pNode = CreateNode( pData );
  AddNode( pLL , pNode , 0 );
  printf( "Added to front of the list, value = %d\n" , 11 );
  printf( "The Linked List has %d entries.  " , Size( pLL ) );
  PrintList( pLL , PrintData );
  printf( "\n\n" );

  pData = (ListData*)calloc( 1 , sizeof( data ) );
  *pData = 12;
  pNode = CreateNode( pData );
  AddNode( pLL , pNode , 1 );
  printf( "Added to 1st element of the list, value = %d\n" , 12 );
  printf( "The Linked List has %d entries.  " , Size( pLL ) );
  PrintList( pLL , PrintData );
  printf( "\n\n" );
}

  // eof
