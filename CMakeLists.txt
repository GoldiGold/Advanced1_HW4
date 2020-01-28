cmake_minimum_required(VERSION 3.15)
project(Advanced1_HW4)

set(CMAKE_CXX_STANDARD 14)

add_executable(Advanced1_HW4
        main.cpp
        Server.h
        ClientHandler.h
        Solver.h
        MyTestClientHandler.h
        FileCacheManager.h
        CacheManager.h
        MySerialServer.h
        MySerialServer.cpp
        BestFirstSearch.h
        BestFirstSearch.cpp
        MatrixProblem.h
        MatrixProblem.cpp
        MyCmp.h
        MyPriorityQueue.h
        MyPriorityQueue.cpp
        Searchable.h
        Searcher.h
        MyPriorityQueue.cpp
        MyPriorityQueue.h MyCmp.h
        Solver.h
        CostCmp.h AStarCmp.h BreadthFirstSearch.cpp BreadthFirstSearch.h MyQueue.h MyQueue.cpp DepthFirstSearch.cpp DepthFirstSearch.h MyStack.h MyStack.cpp
        State.h
        State.cpp ShitSolver.cpp ShitSolver.h)