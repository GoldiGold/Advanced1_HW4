#include <iostream>
#include "MyParallelServer.h"
//#include "MyClientHandler.h"
#include "FileCacheManager.h"
#include "SolverSearcher.h"
#include "BestFirstSearch.h"
#include "AStarCmp.h"
//#include "BreadthFirstSearch.h"
//#include "DepthFirstSearch.h"
//#include "MySerialServer.h"
//#include "MyTestClientHandler.h"
//#include "StringReverser.h"

int main() {
	std::cout << "Hello, World! VERSION 2.0" << std::endl;

	auto my_p_server = new MyParallelServer();
//	auto serial = new MySerialServer();
	auto cache = new FileCacheManager();
//	auto ggg = new MyTestClientHandler(new StringReverser(), cache);
	my_p_server->open(5600,
						   new MyClientHandler(new SolverSearcher(new BestFirstSearch<AStarCmp>()), cache));
//	serial->open(8081, new MyTestClientHandler(new StringReverser(), cache));
	return 0;
}
