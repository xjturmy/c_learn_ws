# g++ vector.cpp -o vector  -lstdc++ 

# ubuntu-debug
g++ -DDEBUG  -std=c++11  -g vector.cpp -o vector

# ubuntu-release
# g++ -std=c++11 -O2 vector.cpp -o vector