//
// Created by yoavst22 on 26/01/2020.
//

#ifndef ADVANCED1_HW4__MYCMP_H_
#define ADVANCED1_HW4__MYCMP_H_
#include "State.h"
class MyCmp{
 public:
  bool operator() (State* left, State* right) {
    return left->GetCost() > right->GetCost();
  }
};
#endif //ADVANCED1_HW4__MYCMP_H_
