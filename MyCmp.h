//
// Created by yoavst22 on 26/01/2020.
//

#ifndef ADVANCED1_HW4__MYCMP_H_
#define ADVANCED1_HW4__MYCMP_H_
#include "State.h"
class MyCmp {
 public:
  virtual bool operator()(State *left, State *right)=0;
  virtual void setInit(State *s)=0;
};
#endif //ADVANCED1_HW4__MYCMP_H_
