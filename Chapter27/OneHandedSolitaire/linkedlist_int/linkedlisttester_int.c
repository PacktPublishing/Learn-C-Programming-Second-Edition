// linkedlisttester_int.c
// Chapter 27
// Learn C Programming, 2nd Edition
//
// This is an test program derived from linkedlisttester.c from
// Chapter 18, herein called linked linkedlisttester_int_1file.c.
// This test file does the same thing as linkedlisttester_int_1file.c.
//
// Notice that the use of test functions make this source file much smaller
// than the companion versions, linkedlisttester_int_simple.c.
//
// Every library that you use or develop for yourself or others SHOULD
// have a corresponding test program which exercises the library as
// completely as possible.
//
// compile with:
//   cc linkedlisttester_int.c linkedlist_int.c -o linkedlisttester_int_simple -Wall -Werror -std=c17


#include "linkedlist_int.h"


// ======= For testing
// Describe location of element being manipulated.
//
typedef enum  {
  eFront = 0 ,
  eBack
} eWhere;

// Describe actions being performed upon the list.
//
typedef enum  {
  eLook = 0 ,
  eInsert ,
  eDelete
} eAction;


// ---- Test functions to exercise our linked list.

void TestCreateNodeAndInsert( LinkedList* pLL , ListData data ,  eWhere where )  {
  ListData* pData = CreateData( data );
  ListNode* pNode = CreateNode( pData );

  switch( where ) {
    case eFront: AddNode( pLL , pNode , 0  ); break;
    case eBack:  AddNode( pLL , pNode , -1 ); break;
  }
}


ListData TestExamineNode( LinkedList* pLL , eWhere where )  {
  ListNode * pNode;
  switch( where ) {
    case eFront: pNode = GetNode( pLL , 0 ); break;
    case eBack:  pNode = GetNode( pLL , pLL->nodeCount ); break;
  }
  ListData data = *(pNode->data);
  return data;
}


ListData TestRemoveNodeAndFree( LinkedList* pLL , eWhere where )  {
  ListNode * pNode;
  switch( where ) {
    case eFront: pNode = RemoveNode( pLL , 0  ); break;
    case eBack:  pNode = RemoveNode( pLL , -1 ); break;
  }
  ListData data = *(pNode->data);
  DeleteNode( pNode );
  return data;
}


void TestPrintOperation( LinkedList* pLL , eAction action ,
  ListData data , eWhere where )  {
    switch( action )  {
      case eLook:
        data = TestExamineNode( pLL , where );
        printf( "Get %s node, see [%2d].  " ,
          where==eFront ? "front" : " back" , data );
        break;
      case eInsert:
        printf( "Insert [%2d] to %s.      " ,
          data , where==eFront ? "front" : " back" );
        TestCreateNodeAndInsert( pLL , data , where );
        break;
      case eDelete:
        data = TestRemoveNodeAndFree( pLL , where );
        printf( "Remove [%2d] from %s.    " ,
          data , where==eFront ? "front" : " back" );
        break;
      default:
        printf( "::ERROR:: unknown action\n" );
        break;
    }
    PrintList( pLL , PrintData );
  }


//=======================================================================

int main( void )  {
  LinkedList* pLL = CreateLinkedList();

  printf( "Input or operation         "
    "Current state of linked list\n"
    "=========================  "
  "======================================");
  printf( "\nUsing input{ 1  2  3  4 }. " );
  int data1[]   = { 1 , 2 , 3 , 4 };
  int data1Size = 4;

  PrintList( pLL , PrintData );
  for( int i = 0 ; i < data1Size ; i++)  {
    TestPrintOperation( pLL , eInsert , data1[i] , eFront );
  }

  TestPrintOperation( pLL , eLook   , 0   , eFront );
  TestPrintOperation( pLL , eDelete , 0   , eBack );

  printf( "\nUsing input{ 31 32 33 }.   " );
  PrintList( pLL , PrintData );
  int data2[]   = { 31 , 32 , 33 };
  int data2Size = 3;
  for( int i = 0 ; i < data2Size ; i++)  {
    TestPrintOperation( pLL , eInsert , data2[i] , eBack );
  }
  TestPrintOperation( pLL , eLook   , 0   , eBack );

  int count = pLL->nodeCount;
  for( int i = 0 ; i < count ; i++)  {
    TestPrintOperation( pLL , eDelete, 0 , eFront );
  }
}

  /* eof */
