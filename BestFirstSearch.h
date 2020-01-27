//
// Created by yoavst22 on 23/01/2020.
//

#ifndef ADVANCED1_HW4__BESTFIRSTSEARCH_H_
#define ADVANCED1_HW4__BESTFIRSTSEARCH_H_

#include "State.h"
#include "Searchable.h"
#include "Searcher.h"
#include "MyPriorityQueue.h"
#include <unordered_map>
class BestFirstSearch: public Searcher{
  MyPriorityQueue* openList;
  std::unordered_map<std::string, State*>* closed;

  std::list<char>* path(State* s);
 public:
  BestFirstSearch();
  ~BestFirstSearch(){delete openList;}
  std::list<char>* solve(Searchable* searchable) override ;
};
#endif //ADVANCED1_HW4__BESTFIRSTSEARCH_H_
