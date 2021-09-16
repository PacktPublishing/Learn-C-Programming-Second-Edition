// testenum.c
// Chapter 8
// Learn C Programming, 2nd Edition
//
// An experiment to see if
// 1) can we give all the enumerated items the same constant value? 
//
//    Yes, we can.
//
//    But does it make sense? Yes, but only if we do not treat the 
//    enumerated items as a related group, but as a collection of 
//    named values.
//
// 2) Is this meaningful when we try to differentiate one named value 
//    from another?
//
//    No, it isn't. When comparing enumerated items, in an if()... 
//    statement or switch()... statement, they MUST have unique 
//    values in the enumerated list.
//
// Compile with:
//
//    cc testenum.c -o testenum -Wall -Werror -std=c17


#include <stdio.h>

//  // all enumerated constants have the unique values.
//  // Uncomment these lines and comment the ones below to 
//  // see the desired behavior.
//
//enum suit {  
//  spade   = 1, 
//  heart   = 2,  
//  diamond = 3,  
//  club    = 4 
//}; 

  // all enumerated constants have the same value.
enum suit {  
  spade   = 5, 
  heart   = 5,  
  diamond = 5,  
  club    = 5 
}; 


int main( void )  {
  enum suit card;
  
  card = spade;
  //  card = heart;
  //  card = diamond;
  //  card = club;
  //  card = 100;

  if(      card == club )    printf( "club\n" ); 
  else if( card == diamond ) printf( "diamond\n" ); 
  else if( card == heart )   printf( "heart\n" );
  else if( card == spade )   printf( "spade\n" ); 
  else 
      printf( "Unknown enumerated value\n" ); 

  return 0; 
}

  /* eof */
