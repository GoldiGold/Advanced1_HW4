//
// Created by yoavst22 on 24/01/2020.
//

#ifndef ADVANCED1_HW4__SEARCHER_H_
#define ADVANCED1_HW4__SEARCHER_H_

#include <list>
#include "Searchable.h"
#include "Solver.h"
class Searcher: public Solver<Searchable*, std::list<char>*>{
  std::list<char>* solve(Searchable* searchable) override = 0;
};
#endif //ADVANCED1_HW4__SEARCHER_H_
