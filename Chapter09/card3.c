// card3.c
// Chapter 9
// Learn C Programming, 2nd Edition
//
// Demonstrate how to create a structure whose
// components are other structures and then how
// to access those sub-components.
//
// Compile with:
//
//    cc card3.c -o card3 -Wall -Werror -std=c17


#include <stdio.h>
#include <stdbool.h>


enum Suit  {
  eClub  = 1,
  eDiamond,
  eHeart,
  eSpade
};


enum Face  {
  eOne = 1,
  eTwo,
  eThree,
  eFour,
  eFive,
  eSix,
  eSeven,
  eEight,
  eNine,
  eTen,
  eJack,
  eQueen,
  eKing,
  eAce
};


struct Card  {
 enum Suit suit;
 int       suitValue;
 enum Face face;
 int       faceValue;
 bool      isWild;
};


struct Hand  {
  int cardsDealt;
  struct Card c1, c2, c3, c4, c5;
};


struct Hand addCard(    struct Hand oldHand , struct Card card );
void        printHand(  struct Hand h );
void        printHand2( struct Hand h );
void        printCard(  struct Card c );


int main( void )  {
  struct Hand h = {0};

  struct Card c1 = { eSpade   , (int)eSpade   , eTen   , (int)eTen   , false };
  struct Card c2 = { eHeart   , (int)eHeart   , eQueen , (int)eQueen , false };
  struct Card c3 = { eDiamond , (int)eDiamond , eFive  , (int)eFive  , false };
  struct Card c4 = { eClub    , (int)eClub    , eAce   , (int)eAce   , false };
  struct Card c5 = { eHeart   , (int)eHeart   , eJack  , (int)eJack  , false };
  struct Card c6 = { eClub    , (int)eClub    , eTwo   , (int)eTwo   , false };

  h = addCard( h , c1 );
  h = addCard( h , c2 );
  h = addCard( h , c3 );
  h = addCard( h , c4 );
  h = addCard( h , c5 );
  h = addCard( h , c6 );

  printHand( h );
  printf("\n");
  printHand2( h );

  return 0;
}


struct Hand addCard( struct Hand oldHand , struct Card card )  {
  struct Hand newHand = oldHand;
  switch( newHand.cardsDealt )
  {
    case 0:
      newHand.c1 = card;  newHand.cardsDealt++;  break;
    case 1:
      newHand.c2 = card;  newHand.cardsDealt++;  break;
    case 2:
      newHand.c3 = card;  newHand.cardsDealt++;  break;
    case 3:
      newHand.c4 = card;  newHand.cardsDealt++;  break;
    case 4:
      newHand.c5 = card;  newHand.cardsDealt++;  break;
    default:
      // Hand is full, what to do now?
      // ERROR --> Ignore new card.
      newHand = oldHand;
      break;
  }
  return newHand;
}

void printHand( struct Hand h )  {
  for( int i = 1; i < h.cardsDealt+1 ; i++ ) {  // 1..5
    struct Card c;
    switch( i )  {
      case 1: c = h.c1; break;
      case 2: c = h.c2; break;
      case 3: c = h.c3; break;
      case 4: c = h.c4; break;
      case 5: c = h.c5; break;
      default:  return; break;
    }
    printCard( c );
  }
}


void printHand2( struct Hand h )  {
  int dealt = h.cardsDealt;
  if( dealt == 0 ) return;
  printCard( h.c1 ); if( dealt == 1 ) return;
  printCard( h.c2 ); if( dealt == 2 ) return;
  printCard( h.c3 ); if( dealt == 3 ) return;
  printCard( h.c4 ); if( dealt == 4 ) return;
  printCard( h.c5 ); return;
}


// yet another version of printHand
//
void printHand3( struct Hand h )  {
  for( int i = 1; i < h.cardsDealt+1 ; i++ )  { // 1..5
    switch( i )  {
      case 1: printCard( h.c1 ); break;
      case 2: printCard( h.c2 ); break;
      case 3: printCard( h.c3 ); break;
      case 4: printCard( h.c4 ); break;
      case 5: printCard( h.c5 ); break;
      default:
          // here is makes sense to do nothing
          // (we only need 1 to 5 cards, not less than 1, not more than 5)
        return;
        break;
    }
  }
}


void printCard( struct Card c )  {
  switch( c.face )  {
    case eTwo:   printf( "    2 " ); break;
    case eThree: printf( "    3 " ); break;
    case eFour:  printf( "    4 " ); break;
    case eFive:  printf( "    5 " ); break;
    case eSix:   printf( "    6 " ); break;
    case eSeven: printf( "    7 " ); break;
    case eEight: printf( "    8 " ); break;
    case eNine:  printf( "    9 " ); break;
    case eTen:   printf( "   10 " ); break;
    case eJack:  printf( " Jack " ); break;
    case eQueen: printf( "Queen " ); break;
    case eKing:  printf( " King " ); break;
    case eAce:   printf( "  Ace " ); break;
    default:    printf( "  ??? " ); break;
  }
  switch( c.suit )  {
    case eSpade:   printf( "of Spades\n");   break;
    case eHeart:   printf( "of Hearts\n");   break;
    case eDiamond: printf( "of Diamonds\n"); break;
    case eClub:    printf( "of Clubs\n");    break;
    default:      printf( "of ???s\n");     break;
  }
}

//  eof
