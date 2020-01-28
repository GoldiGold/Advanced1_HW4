cmake_minimum_required(VERSION 3.15)
project(Advanced1_HW4)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-pthread")

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
        State.h
        State.cpp ShitSolver.cpp ShitSolver.h)