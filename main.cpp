#include <iostream>
//#include <sys/time.h>
#include "MySerialServer.h"
#include "MyClientHandler.h"
#include "FileCacheManager.h"
#include "ShitSolver.h"
#include "BreadthFirstSearch.h"
#include "MyCmp.h"
#include "SolverSearcher.h"
//#include "MyTestClientHandler.h"

int main() {
	std::cout << "Hello, World! VERSION 2.0" << std::endl;

//	struct timeval tvBefore;
//	struct timeval tvAfter;
////	tv.tv_sec = 10;
//	gettimeofday(&tvBefore, NULL);
//	std::cout << " time try:" << tvBefore.tv_sec << std::endl;
////	while(tv.tv_sec > gettimeofday(&tv, NULL)){
//////		if (tv.tv_sec % 10 == 0){
//////			std::cout << "thing" << std::endl;
//////		}
////	}
//	int i = 0;
//	while (i < 1000000000) {
//		++i;
//	}
//	gettimeofday(&tvAfter, NULL);
//	std::cout << "time ended: " << tvAfter.tv_sec << " i is : " << i << std::endl;

	auto my_serial_server = new MySerialServer();
	auto cache = new FileCacheManager<std::string, std::string>();
	auto string_cache = new FileCacheManager<std::string, std::string>();
	my_serial_server->open(5400, /*new MyTestClientHandler<std::string, std::string>(new ShitSolver(), string_cache)*/
						   new MyClientHandler(new SolverSearcher(new BreadthFirstSearch), cache))
		/*new SolverSearcher(new BreadthFirstSearch()), cache))*/;
	return 0;
}
