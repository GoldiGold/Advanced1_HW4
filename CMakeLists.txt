cmake_minimum_required(VERSION 3.15)
project(Advanced1_HW4)

set(CMAKE_CXX_STANDARD 14)

add_executable(Advanced1_HW4 main.cpp Server.h ClientHandler.h Solver.h MySerialServer.cpp MySerialServer.h MyTestClientHandler.h FileCacheManager.cpp FileCacheManager.h CacheManager.cpp CacheManager.h)