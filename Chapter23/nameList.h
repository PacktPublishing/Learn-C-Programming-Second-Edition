#ifndef _NAME_LIST_H_
#define _NAME_LIST_H_

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

typedef char   ListData;

typedef struct _Node ListNode;
typedef struct _Node {
  ListNode*  pNext;
  ListData*  pData;
} ListNode;

typedef struct {
  ListNode*  pFirstNode;
  int        nodeCount;
} NameList;


ListNode*  CreateListNode( char* pNameToAdd );

void  AddName(     NameList* pNames , char* pNameToAdd );
void  DeleteNames( NameList* pNames );
bool  IsEmpty(     NameList* pNames );
void  PrintNames(  FILE* outputDesc ,  NameList* pNames );

void OutOfStorage( void );

#endif