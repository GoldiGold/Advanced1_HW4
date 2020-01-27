//
// Created by yoavst22 on 23/01/2020.
//

#ifndef ADVANCED1_HW3__MATRIXPROBLEM_H_
#define ADVANCED1_HW3__MATRIXPROBLEM_H_
#include "Searchable.h"
#include <utility>
#include <vector>


#include <iostream>
class MatrixProblem: public Searchable{
  std::vector<std::vector<int>>* matrix; //matrix of costs
//  std::vector<std::vector<State<std::pair<int, int>>>>* states;
  State* init;
  State* goal;
 public:
  MatrixProblem(std::vector<std::vector<int>>* m, int xi, int yi, int xg, int yg);
  State* GetInitState() override{ return init;}
  State* GetGoalState() override{ return goal;}
  std::list<State*>* GetPossibleStates(State* s) override;

};
#endif //ADVANCED1_HW3__MATRIXPROBLEM_H_
