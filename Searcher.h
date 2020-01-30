//
// Created by yoavst22 on 24/01/2020.
//

#ifndef ADVANCED1_HW4__SEARCHER_H_
#define ADVANCED1_HW4__SEARCHER_H_

#include <list>
#include "Searchable.h"
//#include "Solver.h"
// public Solver<Searchable*, std::list<std::pair<char,int>>*>
class Searcher{
 public:
  virtual std::list<std::pair<char,int>>* search(Searchable* searchable) = 0;
  virtual int numberOfClosedNodes() = 0;
  virtual int GetCost() = 0;
};
#endif //ADVANCED1_HW4__SEARCHER_H_
