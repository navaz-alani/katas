upperBound=100
for i in $(seq 1 100); do
  div3=$(( ${i} % 3 ))
  div5=$(( ${i} % 5 ))
  if [ ${div3} -eq 0 ] && [ ${div5} -eq 0 ]; then
    echo "${i} fizzbuzz"
  elif [ ${div3} -eq 0 ]; then
    echo "${i} fizz"
  elif [ ${div5} -eq 0 ]; then
    echo "${i} buzz"
  else
    echo "${i}"
  fi
done
