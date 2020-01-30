//
// Created by חן גולדשטיין on 27/01/2020.
//

#ifndef ADVANCED1_HW4__MYTESTCLIENTHANDLER_H_
#define ADVANCED1_HW4__MYTESTCLIENTHANDLER_H_
#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"
#include <iostream>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#define BUFFER_SIZE 1024

//std::vector<std::string> split(const std::string &s, char delimiter) {
//	std::vector<std::string> tokens;
//	std::string token;
//	std::istringstream tokenStream(s);
//	while (std::getline(tokenStream, token, delimiter)) {
//		tokens.push_back(token);
//	}

//	return tokens;
//}

class MyTestClientHandler : public ClientHandler {
 public:
	Solver<std::string, std::string> *s;
	CacheManager<std::string, std::string> *cm;

 public:

	MyTestClientHandler *clone() override {
		return new MyTestClientHandler(this->s->clone(), this->cm->clone());
	}
	MyTestClientHandler(Solver<std::string, std::string> *solver,
						CacheManager<std::string, std::string> *cache_manager) {
		this->s = solver;
		this->cm = cache_manager;
	}

	int handleClient(int sockfd) override {
		char buffer[BUFFER_SIZE];
//		std::vector<std::string> sub_n;
		std::string t;
		int counter = 0;
		int i = 0;
		do {
			ssize_t size = read(sockfd, buffer, BUFFER_SIZE);
			t = buffer;
//			std::cout << buffer << std::endl;
//			if (t.find('\n') != std::string::npos) {
//				++counter;
//			}
//			++i;
//			sub_n = split(t, "\n");
			if (t.find('\r') != std::string::npos) {
				t = t.substr(0, t.find('\r'));
			}
			if (t.find('\n') != std::string::npos) {
				t = t.substr(0, t.find('\n'));
			}

			std::cout << "input from client: " << t << std::endl;

			if (this->cm->is_exist(t)) {
				std::string solution = this->cm->get_solution(t);
				std::cout << "message to client: " << solution << std::endl;
				solution += '\n';
				send(sockfd, solution.c_str(), solution.length(), 0);
				std::cout << "new problem" << std::endl;
			} else {
				std::string solution = this->s->solve(t);
				std::cout << "message to client: " << solution << std::endl;
				this->cm->insert(t, solution);
				solution = solution.append("\n");
				send(sockfd, solution.c_str(), solution.length(), 0);
				std::cout << "solution exist" << std::endl;
			}
		} while (t.find("end") == std::string::npos);
		std::cout << "message was sent" << std::endl;
		close(sockfd);

//		std::cout << "solution from file: " << this->cm->get_solution("end") << std::endl;


		return 1;
	}

};

#endif //ADVANCED1_HW4__MYTESTCLIENTHANDLER_H_
