//
// Created by yoavst22 on 27/01/2020.
//

#ifndef ADVANCED1_HW4__COSTCMP_H_
#define ADVANCED1_HW4__COSTCMP_H_
#include "State.h"
#include "MyCmp.h"
class CostCmp: public MyCmp{
 public:
  bool operator() (State* left, State* right) override {
    return left->GetCost() > right->GetCost();
  }
  void setInit(State *s) override {}
};
#endif //ADVANCED1_HW4__COSTCMP_H_
