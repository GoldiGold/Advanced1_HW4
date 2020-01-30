cmake_minimum_required(VERSION 3.15)
project(Advanced1_HW4)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-pthread")

add_executable(Advanced1_HW4
        main.cpp
        State.cpp
        State.h
        BestFirstSearch.cpp
        BestFirstSearch.h
        MatrixProblem.cpp
        MatrixProblem.h
        Searchable.h
        Searcher.h
        MyPriorityQueue.cpp
        MyPriorityQueue.h MyCmp.h
        Solver.h
        CostCmp.h
        AStarCmp.h
        BreadthFirstSearch.cpp
        BreadthFirstSearch.h
        MyQueue.h
        MyQueue.cpp
        DepthFirstSearch.cpp
        DepthFirstSearch.h
        MyStack.h
        MyStack.cpp
        SolverSearcher.h
        CacheManager.h
        ClientHandler.h
        FileCacheManager.h
        MyClientHandler.h
        MyClientHandler.cpp
        MySerialServer.h
        MySerialServer.cpp
        MyTestClientHandler.h
        Server.h
        ShitSolver.h
        ShitSolver.cpp
        MyParallelServer.cpp
        MyParallelServer.h)
