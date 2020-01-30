//
// Created by חן גולדשטיין on 27/01/2020.
//

#ifndef ADVANCED1_HW4__CLIENTHANDLER_H_
#define ADVANCED1_HW4__CLIENTHANDLER_H_
class ClientHandler {
 public:
	virtual int handleClient(int sockfd) = 0;
	virtual ClientHandler* clone() = 0;
};
#endif //ADVANCED1_HW4__CLIENTHANDLER_H_
