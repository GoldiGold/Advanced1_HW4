//
// Created by חן גולדשטיין on 29/01/2020.
//

#include "MyClientHandler.h"

//std::vector<std::string> split(const std::string &s, char delimiter) {
//	std::vector<std::string> tokens;
//	std::string token;
//	std::istringstream tokenStream(s);
//	while (std::getline(tokenStream, token, delimiter)) {
//		tokens.push_back(token);
//	}
//	return tokens;
//}

std::vector<std::string> split(const std::string &s, char delimiter) {
	std::vector<std::string> tokens;
	std::string token;
	std::istringstream tokenStream(s);
	while (std::getline(tokenStream, token, delimiter)) {
		tokens.push_back(token);
	}
	return tokens;
}

int MyClientHandler::handleClient(int sockfd) {
	char buffer[BUFFER_SIZE];
//		std::vector<std::string> sub_n;
	std::string t;
	std::string problem = nullptr;
	int counter = 0;
	int i = 0;
	do {
		// TODO: UNDERSTAND WHY WE AIN'T GETTING ANY VALUES FROM THE CLIENT (MAYBE SOMETHING EITH THE INCLUDED HEADERS)
		ssize_t size = read(sockfd, buffer, BUFFER_SIZE);
		t = buffer;
		std::cout << buffer << std::endl;
		problem.append(buffer);
		if (t.find('\n') != std::string::npos) {
			++counter;
		}
		++i;
		std::cout << i << std::endl;
//			sub_n = split(t, "\n");
	} while (t.find("end") == std::string::npos);

	int endIndex = problem.find("end\n");
	problem.erase(endIndex, strlen("end\n"));

	std::cout << problem << std::endl;
//	std::string sol = this->solver->solve("end");
//	this->cache_manager->insert("end", sol);
	std::vector<std::string> lines = split(problem, '\n');

// TODO: REMEMBER THAT THE LAST TWO LINES ARE OF THE START-CO AND END-CO.

	std::cout << "the amount of lines is: " << counter << std::endl;
	send(sockfd, "hello", strlen("hello"), 0);
	send(sockfd, "fuckkkkk", strlen("fuckkkkk")/*sol.c_str(), sol.length()*/, 0);
//		write(sockfd, sol.c_str(), ((size_t)sol.length()));
	std::cout << "message was sent" << std::endl;
	close(sockfd);

//		std::cout << "solution from file: " << this->cache_manager->get_solution("end") << std::endl;

	return 1;
}

//int MyClientHandler::handleClient(int sockfd) {
//	char buffer[BUFFER_SIZE];
////		std::vector<std::string> sub_n;
//	std::string t;
//	int counter = 0;
//	int i = 0;
//	do {
//		ssize_t size = read(sockfd, buffer, BUFFER_SIZE);
//		t = buffer;
////			std::cout << buffer << std::endl;
//		if (t.find('\n') != std::string::npos) {
//			++counter;
//		}
//		++i;
////			sub_n = split(t, "\n");
//	} while (t.find("end") == std::string::npos);
////	std::string sol = this->solver->solve("end");
////	this->cache_manager->insert("end", sol);
//
//	std::cout << "the amount of lines is: " << counter << std::endl;
//	send(sockfd, "hello", strlen("hello"), 0);
////	send(sockfd, sol.c_str(), sol.length(), 0);
////		write(sockfd, sol.c_str(), ((size_t)sol.length()));
//	std::cout << "message was sent" << std::endl;
//	close(sockfd);
//
//	std::cout << "solution from file: " << this->cm->get_solution("end") << std::endl;
//
//	return 1;
//}
