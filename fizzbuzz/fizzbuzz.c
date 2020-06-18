#include <stdio.h>

int main(void) {
  int upperBound = 100;
  int div3, div5;;
  for ( int i = 0; i <= upperBound; ++i ) {
    div3 = i % 3; div5 = i % 5;
    if ( div3 == 0 && div5 == 0 ) {
      printf("%d fizzbuzz\n", i);
    } else if ( div3 == 0 ) {
      printf("%d fizz\n", i);
    } else if ( div5 == 0 ) {
      printf("%d buzz\n", i);
    } else {
      printf("%d\n", i);
    }
  }
}
