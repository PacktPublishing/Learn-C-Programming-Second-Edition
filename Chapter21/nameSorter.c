// nameSorter.c
// Chapter 21
// Learn C Programming, 2nd Edition
//
// Demonstrates a simple "insertion sort" using an array.
// Input and output is primarily done with fgets() and fputs().
//
// compile with: cc nameSorter.c -o nameSorter -Wall -Werror -std=c17


#include <stdio.h>
#include <string.h> 
#include <stdbool.h>


enum   {
  kListMax   = 100,
  kStringMax =  80
};

typedef char string [ kStringMax ]; 

void addName(    string* names , string newOne , int* listSize ); 
void printNames( string* names , int listSize ); 


void removeNewline( string s )  {
  s[ strlen( s )-1 ]='\0';
}


int main( void )  {
  string newName; 
  string nameList[ kListMax ]; 
  int    numNames = 0;
 
  while( printf( "Name: %d: ", numNames+1 ),
         fgets( newName , kStringMax , stdin ),
         removeNewline( newName ) ,
         strlen( newName ) > 0 )  {
    addName( nameList , newName , &numNames ); 
  }
  printNames( nameList , numNames ); 

  return 0;
}


void addName( string* names , string newName , int* pNumEntries )  { 
  if( *pNumEntries >= kListMax )  {
    puts( "List is full!" );
    return; /* the array is full  (this return is unnecessary) */ 
  } else { 
    int  k     = 0;     /* k is position in list to insert newName. */
    bool found = false; /* When found is true, newName goes before an existing 
                           name in the list. */
     
      /* Scan through list looking for existing name that newName should come 
         before. If not found, k is the end of the list. */
    while( !found && k < *pNumEntries )  {
      found = (strcmp( newName, names[ k++ ] ) < 0);
    }
    
    if( found )  {
         /* Move k back one place to insert newName at k-th position.*/ 
      k-- ;
         /* Move each exising name back in the list, making a space newName */
      for( int j = *pNumEntries ; j > k ; j-- )  {
        strcpy( names[ j ] , names[ j-1 ] ); 
      }
    }
      /* Insert new string in list at k-th position. */
    strcpy( names[ k ] , newName ); 
    (*pNumEntries)++; 
  }
}


void printNames( string *names , int numEntries )  {
  printf("\nNumber of Entries: %d\n\n" , numEntries ); 
  for( int i = 0 ; i < numEntries ; i++ )  {
    fputs( names[i] , stdout );
    fputc( '\n' , stdout );
  }
}

  /* eof */
