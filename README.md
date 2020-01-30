# Advanced1_HW4
in this project we implemented searching algorithms liken BFS DFS BestFirstSearch and A*. 


##Link to gihub: 
https://github.com/GoldiGold/Advanced1_HW4

##Usage
First we will make sure that all the files are in the same directory (including the code file).
In order to compile the program we will use this command in the terminal:
g++ -std=c++14 *.cpp -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -o a.out -pthread
and in order to run:
./a.out

The program can handle up to 10 clients in parallel. Each client sends to the program a matrix, a start position and a goal position. 


##Code File (code_file.txt) In this file you write yor commands for the simulator. In order to connect the simulator use in the begining of the code file this two commands: openDataServer(5400) connectControlClient("127.0.0.1",5402)

We are connecting! Now we can use more commands: -Define variables that contains value, and can get and put values in the simulator -Print to the consule -Sleep for milliseconds -Use if and while commands and more...

Good Luck!!!


the problem represented with a string, then are transferred
into a vector of vectors, so we can use a the MatrixProblem and then solve them.

