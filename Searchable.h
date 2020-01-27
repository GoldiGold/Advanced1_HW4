//
// Created by yoavst22 on 23/01/2020.
//

#ifndef ADVANCED1_HW3__SEARCHABLE_H_
#define ADVANCED1_HW3__SEARCHABLE_H_
#include "State.h"
#include <list>
class Searchable {
 public:
  virtual State* GetInitState();
  virtual State* GetGoalState();
  virtual std::list<State*>* GetPossibleStates(State* s);
};
#endif //ADVANCED1_HW3__SEARCHABLE_H_
