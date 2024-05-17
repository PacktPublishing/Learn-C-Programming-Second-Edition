  // Overflow_Underflow.c
  // Chapter 5: Exploring Operators and Expressions
  // Learn C Programming, 2nd Edition
  //
  // Program to demonstrate overflow and underflow as a result
  // of various values and expressions.
  //
  // NOTE: this example does not demonstrated all possible cases
  //       of overflow/underflow.


#include <stdio.h>
#include <inttypes.h>
#include <float.h>


int main( void ) {
  uint16_t biggest  = UINT16_MAX;
  uint16_t overflow = biggest + 1;
  printf( "Biggest=%d and overflow=%d\n" ,
           biggest , overflow );

  int16_t  smallest  = INT16_MIN;
  int16_t  underflow = smallest - 1;
  printf( "Biggest=%d and underflow=%d\n" ,
          smallest , underflow );

  float    fBiggest  = FLT_MAX;
  float    fOverflow = fBiggest * 2;
  printf( "FloatBiggest  = %g FloatOverflow (FloatBiggest * 2) = %g\n" ,
          fBiggest , fOverflow );

  float    fSmallest  = FLT_MIN;
  float    fUnderflow = fBiggest / fSmallest;
  printf( "FloatSmallest = %g FloatUnderflow (FloatBiggest/FloatSmallest) = %g\n" ,
          fSmallest , fUnderflow );

  return 0;
}

  // eof
