//
// Created by חן גולדשטיין on 28/01/2020.
//

#include "ShitSolver.h"
std::string ShitSolver::solve(std::string p) {
//	std::cout << "we solved some shit" << std::endl;

	std::string ret = p;//"tihs";
	int len = p.length();
	for (int kI = 0; kI < p.length(); ++kI) {
		ret[kI] = p[len - kI - 1];
	}
	return ret;
}
