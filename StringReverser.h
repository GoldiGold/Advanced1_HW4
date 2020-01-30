//
// Created by חן גולדשטיין on 28/01/2020.
//

#ifndef ADVANCED1_HW4__STRINGREVERSER_H_
#define ADVANCED1_HW4__STRINGREVERSER_H_
#include "Solver.h"
#include <iostream>
 class StringReverser : public Solver<std::string, std::string>{
	std::string solve(std::string p) override;
	StringReverser* clone() override {
		return new StringReverser();
	}
};
#endif //ADVANCED1_HW4__STRINGREVERSER_H_
