package main

import "fmt"

func main() {
  upperBound := 100;
  for i := 1; i <= upperBound; i++ {
    div3 := i % 3
    div5 := i % 5
    if div3 == 0 && div5 == 0 {
      fmt.Printf("%d fizzbuzz\n", i)
    } else if div3 == 0 {
      fmt.Printf("%d buzz\n", i)
    } else if div5 == 0 {
      fmt.Printf("%d fizz\n", i)
    } else {
      fmt.Printf("%d\n", i)
    }
  }
}
