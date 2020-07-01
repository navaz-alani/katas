prog=${1}
if [ -z ${prog} ]; then
  echo "Program not specified"
  exit 1
fi
cd tests
for t in $(ls *.in); do
  input="${t}"
  expected="${t%.in}.out"
  tmpOutFile="$(mktmp -q)"
  if [ $? -ne 0 ]; then
    echo "failed to allocate temporary output file"
    exit 1
  fi
  ./../${prog} ${input} > ${tmpOutFile}
  if [ "$(cat ${tmpOutFile})" != "$(cat ${expected})" ]; then
    echo "test failed: ${t}"
    echo "expected:"
    cat ${expected}
    echo "actual:"
    cat ${tmpOutFile}
  fi
  rm ${tmpOutFile}
done
