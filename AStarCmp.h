//
// Created by yoavst22 on 28/01/2020.
//

#ifndef ADVANCED1_HW4__ASTARCMP_H_
#define ADVANCED1_HW4__ASTARCMP_H_
#include "State.h"
#include "MyCmp.h"
//coparator to astar algorithm. includes the cost and the heuristic.
class AStarCmp: public MyCmp{
  int gx;
  int gy;
 public:
  AStarCmp(){
    gx = 0;
    gy = 0;
  }
  //supposed to be set goal. we need to know the x,y of the goal in order to calculate Manheten distance.
  void setInit(State* init) override {
    gx = init->GetY();
    gy = init->GetY();
  }
  int h(State* s){
    return(abs(s->GetX()-gx) + abs(s->GetY()-gy));
  }
  bool operator() (State* left, State* right) override {
    return left->GetCost() + h(left) > right->GetCost() + h(right);
  }
};
#endif //ADVANCED1_HW4__ASTARCMP_H_
