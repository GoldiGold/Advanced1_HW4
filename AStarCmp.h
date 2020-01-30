//
// Created by yoavst22 on 28/01/2020.
//

#ifndef ADVANCED1_HW4__ASTARCMP_H_
#define ADVANCED1_HW4__ASTARCMP_H_
#include "State.h"
#include "MyCmp.h"
class AStarCmp: public MyCmp{
  int gx;
  int gy;
 public:
  AStarCmp(){
    gx = 0;
    gy = 0;
  }
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
