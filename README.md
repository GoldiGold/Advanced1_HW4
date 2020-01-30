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
In the matrix -1 means inf. 
In order to run BestFirstSearch we create BestFirstSearch<CostCmp> when CostCmp is a comparator by cost.
In order to run A* we create BestFirstSearch<AStarCmp> when AStarCmp is a comparator by cost an heuristic.

the problem represented with a string that sent from the, then are transferred
into a vector of vectors, so we can use a the MatrixProblem and then solve them.

The program return list of moves to the clients that takes from the start to the goal.

