//
// Created by חן גולדשטיין on 27/01/2020.
//

#ifndef ADVANCED1_HW4__MYSERIALSERVER_H_
#define ADVANCED1_HW4__MYSERIALSERVER_H_
#include "Server.h"

//#include <queue>

class MySerialServer : public Server {
 private:
//	std::queue<int> clients_queue;
	int sockfd; // lets make it so it will take only one client (anyway we need PARALLEL)


	int open(int port, ClientHandler c);
	virtual int stop();
};

#endif //ADVANCED1_HW4__MYSERIALSERVER_H_
