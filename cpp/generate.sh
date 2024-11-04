bash compileCpp.sh gen
bash compileCpp.sh main
bash compileCpp.sh brute

for ((i = 1; i <= 5; i++)); do
  echo "Checking test #$i"
  ./gen > input
  ./main < input > outputMain
  ./brute < input > outputBrute
  diff -w outputMain outputBrute || break
  # diff -w <(./main < input) <(./brute < input) || break
  echo "Done #$i"
done;

# -w ignoring white spaces