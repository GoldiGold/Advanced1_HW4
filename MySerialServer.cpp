//
// Created by חן גולדשטיין on 27/01/2020.
//

#include "MySerialServer.h"

int MySerialServer::open(int port, ClientHandler c) {
	sockaddr_in serv_addr;
	this->sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0) {
		std::cerr << "\n Socket creation error \n" << std::endl;
	}

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(port);

	int bind_flag = bind(this->sockfd, (struct sockaddr *) (&serv_addr), sizeof(*(&serv_addr)));
	int new_socket;
	if (bind_flag < 0) {
		std::cerr << "bind failed" << std::endl;
		exit(EXIT_FAILURE);
	}
	if (listen(this->sockfd, 1) < 0) {
		std::cerr << "listen error" << std::endl;
		exit(EXIT_FAILURE);
	}
	if ((new_socket = accept(this->sockfd, (struct sockaddr *) (&serv_addr), (socklen_t *) (&serv_addr))) < 0) {
		std::cerr << "accept error" << std::endl;
		exit(EXIT_FAILURE);
	} else {
		this->clients_queue.push(new_socket);
	}
////	TODO: CHECK IF YOU NEED TO OPEN A THREAD FOR SOMETHING, IF YES THEN FOR WHAT' AND WHAT DO YOU DO WITH THE
//// 	TODO: CLIENT_HANDLER IN THIS FUNCTION. in the end need to close the client's new socket.
//	std::thread openServer(acceptClient, this);
//	openServer.detach();

	close(new_socket);
	return new_socket;
}

int MySerialServer::stop() {
	close(this->sockfd);

	return 1;
}
