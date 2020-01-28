//
// Created by חן גולדשטיין on 28/01/2020.
//

#ifndef ADVANCED1_HW4__SHITSOLVER_H_
#define ADVANCED1_HW4__SHITSOLVER_H_
#include "Solver.h"
#include <iostream>
 class ShitSolver : public Solver<std::string, std::string>{
	std::string solve(std::string p) override;
};
#endif //ADVANCED1_HW4__SHITSOLVER_H_
