//
// Created by חן גולדשטיין on 27/01/2020.
//

#ifndef ADVANCED1_HW4__SERVER_H_
#define ADVANCED1_HW4__SERVER_H_
#include "ClientHandler.h"
class Server {
 public:
	int open(int port, ClientHandler c); // will return positive if succeeded
	int stop();
};
#endif //ADVANCED1_HW4__SERVER_H_
