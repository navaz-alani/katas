let upperBound = 100;
for ( let i = 0; i <= upperBound; ++i ) {
  let div3 = i % 3;
  let div5 = i % 5;
  if ( div3 === 0 && div5 === 0 ) {
    console.log(i, " fizzbuzz");
  } else if ( div3 === 0 ) {
    console.log(i, " fizz");
  } else if ( div5 === 0 ) {
    console.log(i, " buzz");
  } else {
    console.log(i);
  }
}
