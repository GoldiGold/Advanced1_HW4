//
// Created by חן גולדשטיין on 27/01/2020.
//

#ifndef ADVANCED1_HW4__SERVER_H_
#define ADVANCED1_HW4__SERVER_H_
#include "ClientHandler.h"
//#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
//#include <sstream>
#include <iostream>
#include <sys/select.h>
#include <sys/time.h>


class Server {
 public:
	virtual int open(int port, ClientHandler* c) = 0; // will return positive if succeeded
	virtual int stop() = 0;
};
#endif //ADVANCED1_HW4__SERVER_H_
