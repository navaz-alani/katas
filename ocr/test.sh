prog=${1}
if [ -z ${prog} ]; then
  echo "Program not specified"
  exit 1
fi
cd tests
for t in $(ls *.in); do
  input="${t}"
  expected="${t%.in}.out"
  if [ "$(./../${prog} ${input})" != "$(cat ${expected})" ]; then
    echo "Test failed: ${t}"
  fi
done
