//
// Created by חן גולדשטיין on 30/01/2020.
//

#include "MyParallelServer.h"

//static void printSeconds() {
//	std::cout << "entered the thread" << std::endl;
//	int seconds = 1;
//	while (true) {
//		sleep(1);
//		std::cout << "a second passed:" << seconds << std::endl;
//		++seconds;
//	}
//}

MyParallelServer::MyParallelServer() {
//	this->clients_queue = new std::queue<int>;
}
int MyParallelServer::open(int port, ClientHandler *c) {
	this->sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0) {
		std::cerr << "\n Socket creation error \n" << std::endl;
		exit(EXIT_FAILURE);
	}

	struct sockaddr_in serv_addr;
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(port);

	int bind_flag = bind(this->sockfd, (struct sockaddr *) (&serv_addr), sizeof(serv_addr));
	int new_socket;
	if (bind_flag < 0) {
		std::cerr << "bind failed" << std::endl;
		exit(EXIT_FAILURE);
	}
	if (listen(this->sockfd, 10) < 0) {
		std::cerr << "listen error" << std::endl;
		exit(EXIT_FAILURE);
	}

	struct timeval tv;
	tv.tv_sec = 120;
	tv.tv_usec = 0;
	setsockopt(this->sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *) &tv, sizeof(tv));
//	std::cout << "about to accept shit..." << std::endl;

//	std::cout << "here we go accepting" << std::endl;
//	std::thread seconds(printSeconds);
//	seconds.detach();

//	bool ok = true;
//	while (ok) {
//		struct fd_set rfds;
//		struct timeval connection;
//		FD_ZERO(&rfds);
//		FD_SET(this->sockfd, &rfds);
//		connection.tv_sec = 60;
//		connection.tv_usec = 0;
//		std::cout << "point 0" << std::endl;
//
//		new_socket = accept(this->sockfd, (struct sockaddr *) (&serv_addr), (socklen_t *) (&serv_addr));
//		c->handleClient(new_socket);
//
//		int retval = select(1, &rfds, NULL, NULL, &connection);
//		std::cout << "point 1" << std::endl;
//		switch(retval) {
//			case 0: //timeout
//				std::cout << "point STOP" << std::endl;
//		ff		this->stop();
//			case -1: // error
//				std::cout << "point ERROR" << std::endl;
//				ok = false;
//				break;
//			default: // can do accept on socket
//				std::cout << "trying to accept" << std::endl;
//				new_socket = accept(this->sockfd, (struct sockaddr *) (&serv_addr), (socklen_t *) (&serv_addr));
//				std::cout << "about to handle a client" << std::endl;
//				//goy stuff
//				c->handleClient(new_socket);
//				break;
//		}
//	}
	std::list<std::thread *> threadS;
	while ((new_socket = accept(this->sockfd, (struct sockaddr *) (&serv_addr), (socklen_t *) (&serv_addr))) != -1) {

		std::cout << "we accepted a client" << std::endl;
		std::cout << "handling client" << std::endl;
		auto new_client_handler = c->clone();
//		threadS.push_back(new std::thread (&MyClientHandler::handleClient, new_client_handler, new_socket));
		threadS.push_back(new std::thread([new_client_handler, new_socket]() {
		  new_client_handler->handleClient(new_socket);
		}));


	}
	for (auto &t: threadS) {
		t->join();
		threadS.remove(t);
		delete t;
      std::cout << "FINISHED handling client" << std::endl;
      std::cout << "closed socket" << std::endl;
	}

//	std::cout << "SHIT" << std::endl;
	std::cout << "didn't accept" << std::endl;
	this->stop();
//	std::thread openServer(acceptClient, this);
//	openServer.detach();
	return 1;
}
int MyParallelServer::stop() {
	close(this->sockfd);

	return 1;
}

