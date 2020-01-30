//
// Created by חן גולדשטיין on 28/01/2020.
//

#include "StringReverser.h"
std::string StringReverser::solve(std::string p) {
//	std::cout << "we solved some shit" << std::endl;

	std::string ret = p;//"tihs";
	int len = p.length();
	for (int kI = 0; kI < len; ++kI) {
		ret[kI] = p[len - kI - 1];
	}
	return ret;
}
