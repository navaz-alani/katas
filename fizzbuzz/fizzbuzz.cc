#include <iostream>

int main(void) {
  const int upperBound = 100;
  for (int i = 1; i <= upperBound; ++i) {
    int div3 = i % 3, div5 = i % 5;
    if ( div3 == 0 && div5 == 0 ) {
      std::cout << i << " fizzbuzz" << std::endl;
    } else if ( div3 == 0 ) {
      std::cout << i << " fizz" << std::endl;
    } else if ( div5 == 0 ) {
      std::cout << i << " buzz" << std::endl;
    } else {
      std::cout << i << std::endl;
    }
  }
}
