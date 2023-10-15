#Program: Float Comparison
#Author: Kyle Chan
#Execute command: "sh run.sh"

#Purpose: script file to run the program files together.
#Clear any previously compiled outputs
rm *.o
rm *.lis
rm *.out

echo "compile token.cpp using the g++ compiler standard 2017"
g++ -c -Wall -no-pie -m64 -std=c++17 -o token.o token.cpp

echo "Link object files using the gcc Linker standard 2017"
g++ -m64 -no-pie -o final.out token.o -std=c++17

./final.out

echo "\nScript file has terminated."

rm *.o
rm *.lis
rm *.out