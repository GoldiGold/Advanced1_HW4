//
// Created by חן גולדשטיין on 27/01/2020.
//

#ifndef ADVANCED1_HW4__SOLVER_H_
#define ADVANCED1_HW4__SOLVER_H_
template<class Problem, class Solution>
class Solver {
 public:
	virtual Solution solve(Problem p) = 0;
	virtual Solver* clone() = 0;
//	virtual int numberOfClosedNodes() = 0;
//	virtual int GetCost() = 0;
};
#endif //ADVANCED1_HW4__SOLVER_H_
