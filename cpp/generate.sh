bash runcpp.sh gen
# bash runcpp.sh main
bash runcpp.sh brute

./gen > input
# ./main < input > output1
./brute < input > output2