//
// Created by yoavst22 on 23/01/2020.
//

#ifndef ADVANCED1_HW4__MATRIXPROBLEM_H_
#define ADVANCED1_HW4__MATRIXPROBLEM_H_
#include "Searchable.h"
#include <vector>


class MatrixProblem: public Searchable{
  std::vector<std::vector<int>>* matrix; //matrix of costs
  State* init;
  State* goal;
 public:
  MatrixProblem(std::vector<std::vector<int>>* m, int xi, int yi, int xg, int yg);
  State* GetInitState() override{ return init;}
  bool isGoalState(State* s) override { return (*goal == s);}
  
  //returns all the possible succesors with updating cost and parent
  std::list<State*>* GetPossibleStates(State* s) override;
  std::string toString();

};
#endif //ADVANCED1_HW4__MATRIXPROBLEM_H_
