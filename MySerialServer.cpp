//
// Created by חן גולדשטיין on 27/01/2020.
//

#include "MySerialServer.h"

MySerialServer::MySerialServer() {
//	this->clients_queue = new std::queue<int>;
}
int MySerialServer::open(int port, ClientHandler *c) {
	this->sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0) {
		std::cerr << "\n Socket creation error \n" << std::endl;
	}

	struct sockaddr_in serv_addr;
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(port);

	int bind_flag = bind(this->sockfd, (struct sockaddr *) (&serv_addr), sizeof(*(&serv_addr)));
	int new_socket;
	if (bind_flag < 0) {
		std::cerr << "bind failed" << std::endl;
		exit(EXIT_FAILURE);
	}
	if (listen(this->sockfd, 5) < 0) {
		std::cerr << "listen error" << std::endl;
		exit(EXIT_FAILURE);
	}

	struct timeval tv;
	tv.tv_sec = 10; // TODO: change to 120 seconds
	tv.tv_usec = 0;
	std::cout << "about to accept shit..." << std::endl;
	setsockopt(this->sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char *) &tv, sizeof(tv));

	/* TODO: THERE IS NO NEED FOR A QUEUE OF CLIENTS BECAUSE THE ACCEPT WILL ACCEPT ONLY AFTER FINISHING DEALING WITH THE PREVIOUS
	 * TODO: CLIENT WE GOT THROUGH THE ACCEPT
	 *
	 * TODO: NEED TO FIND WHERE TO PUT THE STOP - HOW TO KNOW IF NO CLIENT WANTS TO JOIN.
	 */
	while (true) {
		std::cout << "here we go accepting" << std::endl;
		if ((new_socket = accept(this->sockfd, (struct sockaddr *) (&serv_addr), (socklen_t *) (&serv_addr))) < 0) {
			std::cout << "SHIT" << std::endl;
			std::cerr << "accept error" << std::endl;
			this->stop();
			exit(EXIT_FAILURE);
		} else {
			std::cout << "for some reason ot thinks we accepted a client" << std::endl;
//			this->clients_queue->push(new_socket);
		}

		std::cout << "point 1" << std::endl;
		std::thread clientHandler(&ClientHandler::handleClient, c, new_socket);
		std::cout << "point 2" << std::endl;
		clientHandler.join();
		std::cout << "point 3" << std::endl;
//		close(this->clients_queue->front());
		std::cout << "point 4" << std::endl;
//		this->clients_queue->pop();
//		if (this->clients_queue->empty()){
//			this->stop();
//		}
		return 1;
	}
////	TODO: CHECK IF YOU NEED TO OPEN A THREAD FOR SOMETHING, IF YES THEN FOR WHAT' AND WHAT DO YOU DO WITH THE
//// 	TODO: CLIENT_HANDLER IN THIS FUNCTION. in the end need to close the client's new socket.
//	std::thread openServer(acceptClient, this);
//	openServer.detach();
	return 1;
}

int MySerialServer::stop() {
	close(this->sockfd);

	return 1;
}
