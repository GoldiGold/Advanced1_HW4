//
// Created by חן גולדשטיין on 27/01/2020.
//

#ifndef ADVANCED1_HW4__MYSERIALSERVER_H_
#define ADVANCED1_HW4__MYSERIALSERVER_H_
#include "Server.h"
#include <queue>

class MySerialServer: public Server {
 private:
	std::queue<int> clients_queue;


};

#endif //ADVANCED1_HW4__MYSERIALSERVER_H_
