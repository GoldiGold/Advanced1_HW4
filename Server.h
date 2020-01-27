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


class Server {
 public:
	virtual int open(int port, ClientHandler c); // will return positive if succeeded
	virtual int stop();
};
#endif //ADVANCED1_HW4__SERVER_H_
