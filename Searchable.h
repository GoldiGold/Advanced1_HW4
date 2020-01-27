//
// Created by yoavst22 on 23/01/2020.
//

#ifndef ADVANCED1_HW4__SEARCHABLE_H_
#define ADVANCED1_HW4__SEARCHABLE_H_
#include "State.h"
#include <list>
class Searchable {
 public:
  virtual ~Searchable()= default;
  virtual State* GetInitState() = 0;
  virtual State* GetGoalState() = 0;
  virtual std::list<State*>* GetPossibleStates(State* s) = 0;
};
#endif //ADVANCED1_HW4__SEARCHABLE_H_
