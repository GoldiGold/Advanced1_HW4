//
// Created by חן גולדשטיין on 30/01/2020.
//

#ifndef ADVANCED1_HW4_CMAKE_BUILD_DEBUG_MYPARALLELSERVER_H_
#define ADVANCED1_HW4_CMAKE_BUILD_DEBUG_MYPARALLELSERVER_H_

#include "Server.h"
#include "MyClientHandler.h"
#include <thread>

class MyParallelServer: public Server {
 private:
//	std::queue<int> *clients_queue;
	int sockfd; // lets make it so it will take only one client (anyway we need PARALLEL)

 public:
	MyParallelServer();
	int open(int port, ClientHandler* c) override ;
	int stop() override ;
};

#endif //ADVANCED1_HW4_CMAKE_BUILD_DEBUG_MYPARALLELSERVER_H_
