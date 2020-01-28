//
// Created by חן גולדשטיין on 27/01/2020.
//

#ifndef ADVANCED1_HW4__MYTESTCLIENTHANDLER_H_
#define ADVANCED1_HW4__MYTESTCLIENTHANDLER_H_
#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"
#include <string>
#include <sstream>
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

template<class Problem, class Solution>
class MyTestClientHandler : public ClientHandler {
 public:
	Solver<Problem, Solution> *s;
	CacheManager<Problem, Solution> *cm;

 public:
	MyTestClientHandler(Solver<Problem, Solution> *solver, CacheManager<Problem, Solution> *cache_manager){
		this->s = solver;
		this->cm = cache_manager;
	}

	// TODO: CREATE A FULL STRING THAT WILL REPRESENT - PROBLEM (FOR THE CACHE). AND CREATE A VECTOR OF VECTORS FOR PART 3
//	int handleClient(int sockfd) override {
//		char buffer[BUFFER_SIZE];
////		std::vector<std::string> sub_n;
//		std::string t;
//		int counter = 0;
//		int i = 0;
//		do {
//			ssize_t size = read(sockfd, buffer, BUFFER_SIZE);
//			t = buffer;
////			std::cout << buffer << std::endl;
//			if (t.find('\n') != std::string::npos) {
//				++counter;
//			}
//			++i;
////			sub_n = split(t, "\n");
//		} while (t.find("end") == std::string::npos);
//		std::string sol = this->s->solve("end");
//		this->cm->insert("end", sol);
//
//		std::cout << "the amount of lines is: " << counter << std::endl;
//		send(sockfd, "hello", strlen("hello"), 0);
//		send(sockfd, sol.c_str(), sol.length(), 0);
////		write(sockfd, sol.c_str(), ((size_t)sol.length()));
//		std::cout << "message was sent" << std::endl;
//		close(sockfd);
//
//		std::cout << "solution from file: " << this->cm->get_solution("end") << std::endl;
//
//
//		return 1;
//	}

};

#endif //ADVANCED1_HW4__MYTESTCLIENTHANDLER_H_
