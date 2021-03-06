//
// Created by yoavst22 on 28/01/2020.
//

#ifndef ADVANCED1_HW4__SOLVERSEARCHER_H_
#define ADVANCED1_HW4__SOLVERSEARCHER_H_
#include "Solver.h"
#include "Searcher.h"
#include "Searchable.h"
class SolverSearcher: public Solver<Searchable*, std::list<std::pair<char,int>>*> {
  Searcher* searcher;
 public:
  explicit SolverSearcher(Searcher* searcher1){
    searcher = searcher1;
  }
  std::list<std::pair<char,int>>* solve(Searchable* p) override{
    return searcher->search(p);
  }
  int numberOfClosedNodes() /*override*/ {
    return searcher->numberOfClosedNodes();
  }
  int GetCost() /*override*/{
    return searcher->GetCost();
  }
  SolverSearcher* clone() override{
  	return new SolverSearcher(this->searcher->clone());
  }

};
#endif //ADVANCED1_HW4__SOLVERSEARCHER_H_
