//
// Created by חן גולדשטיין on 27/01/2020.
//

#ifndef ADVANCED1_HW4__MYTESTCLIENTHANDLER_H_
#define ADVANCED1_HW4__MYTESTCLIENTHANDLER_H_
#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"
template<class Problem, class Solution>
class MyTestClientHandler : public ClientHandler {
 private:
	Solver<Problem, Solution> s;
	CacheManager<Problem, Solution> cm;

};

#endif //ADVANCED1_HW4__MYTESTCLIENTHANDLER_H_
