//
// Created by חן גולדשטיין on 29/01/2020.
//

#ifndef ADVANCED1_HW4__MYCLIENTHANDLER_H_
#define ADVANCED1_HW4__MYCLIENTHANDLER_H_
//#include "ClientHandler.h"
//#include "Solver.h"
#include "Searchable.h"
//#include "Searcher.h"
//#include "CacheManager.h"
//#include "MatrixProblem.h"
#include <sys/socket.h>
//#include <sstream>
//#include <string>

#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"
//#include <string>
#include <sstream>
#include <unistd.h>
#include <netinet/in.h>
#include <vector>

#define BUFFER_SIZE 1024

class MyClientHandler : public ClientHandler {
 private:
	Solver<Searchable *, std::list<char> *> *solver;
	CacheManager<Searchable *, std::list<char> *> *cache_manager;

 public:
	MyClientHandler(Solver<Searchable *, std::list<char> *> *sol,
					CacheManager<Searchable *, std::list<char> *> *cm) {
		this->solver = sol;
		this->cache_manager = cm;
	}

	int handleClient(int sockfd) override;

};

#endif //ADVANCED1_HW4__MYCLIENTHANDLER_H_
