#include <iostream>
#include "MyParallelServer.h"
#include "MyClientHandler.h"
#include "FileCacheManager.h"
#include "SolverSearcher.h"
#include "BestFirstSearch.h"
#include "AStarCmp.h"

int main() {
	std::cout << "Hello, World! VERSION 2.0" << std::endl;

	auto my_p_server = new MyParallelServer();
	auto cache = new FileCacheManager();
	my_p_server->open(5400,
						   new MyClientHandler(new SolverSearcher(new BestFirstSearch<AStarCmp>()), cache));
	return 0;
}
