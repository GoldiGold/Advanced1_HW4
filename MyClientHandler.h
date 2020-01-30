//
// Created by חן גולדשטיין on 29/01/2020.
//

#ifndef ADVANCED1_HW4__MYCLIENTHANDLER_H_
#define ADVANCED1_HW4__MYCLIENTHANDLER_H_
//#include "Searchable.h"
#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"
#include "MatrixProblem.h"
//#include <iostream>
#include <sstream>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <vector>
#include <unordered_map>

#define BUFFER_SIZE 1024

class MyClientHandler : public ClientHandler {
 private:
	Solver<Searchable *, std::list<char> *> *solver;
	CacheManager<std::string , std::string> *cache_manager;
	std::unordered_map<char, std::string> *directions;

 public:
	MyClientHandler(Solver<Searchable *, std::list<char> *> *sol,
					CacheManager<std::string, std::string> *cm) {
		this->solver = sol;
		this->cache_manager = cm;
		directions = new std::unordered_map<char, std::string>;
		directions->insert({'d', "Down"});
		directions->insert({'u', "Up"});
		directions->insert({'l', "Left"});
		directions->insert({'r', "Right"});
	}

	MatrixProblem* createMatProblem(const std::vector<std::string>& sub_lines);

	int handleClient(int sockfd) override;
//	{
//		std::cout << "handling client right now" << std::endl;
//		char buffer[BUFFER_SIZE];
////		std::vector<std::string> sub_n;
//		std::string t;
//		std::string problem;
//		int counter = 0;
//		int i = 0;
//		do {
//			// TODO: UNDERSTAND WHY WE AIN'T GETTING ANY VALUES FROM THE CLIENT (MAYBE SOMETHING WITH THE INCLUDED HEADERS)
//			ssize_t size = read(sockfd, buffer, BUFFER_SIZE);
//			t = buffer;
//			std::cout << buffer << std::endl;
//			problem.append(t);
//			if (t.find('\n') != std::string::npos) {
//				++counter;
//			}
//			++i;
////			std::cout << i << std::endl;
////			sub_n = split(t, "\n");
//		} while (t.find("end") == std::string::npos);
//
////		std::cout <<"the problem: " << problem << std::endl;
////
////		std::cout<< "finished the problem" << std::endl;
//
//		int endIndex = problem.find("end\n");
//		problem.erase(endIndex, std::string::npos);
//		std::cout <<"the problem: " << problem << std::endl;
//
//		std::cout<< "finished the problem" << std::endl;
//
////		std::cout << problem << std::endl;
////	std::string sol = this->solver->solve("end");
////	this->cache_manager->insert("end", sol);
////		std::vector<std::string> lines = split(problem, '\n');
//
//// TODO: REMEMBER THAT THE LAST TWO LINES ARE OF THE START-CO AND END-CO.
//
//		std::cout << "the amount of lines is: " << counter << std::endl;
//		send(sockfd, "hello", strlen("hello"), 0);
//		send(sockfd, "fuckkkkk", strlen("fuckkkkk")/*sol.c_str(), sol.length()*/, 0);
////		write(sockfd, sol.c_str(), ((size_t)sol.length()));
//		std::cout << "message was sent" << std::endl;
//		close(sockfd);
//
////		std::cout << "solution from file: " << this->cache_manager->get_solution("end") << std::endl;
//
//		return 1;
//	}

};

#endif //ADVANCED1_HW4__MYCLIENTHANDLER_H_
