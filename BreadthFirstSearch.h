//
// Created by yoavst22 on 28/01/2020.
//

#ifndef ADVANCED1_HW4__BREADTHFIRSTSEARCH_H_
#define ADVANCED1_HW4__BREADTHFIRSTSEARCH_H_
#include "State.h"
#include "Searchable.h"
#include "Searcher.h"
#include <unordered_map>
#include "MyQueue.h"

class BreadthFirstSearch: public Searcher{
  MyQueue* openList;
  std::unordered_map<std::string, State*>* closed;
  int cost;

  std::list<std::pair<char,int>>* path(State* s);
 public:
  BreadthFirstSearch();
  ~BreadthFirstSearch(){delete openList;}
  std::list<std::pair<char,int>>* search(Searchable* searchable) override;
  int GetCost() override {return cost;}
  int numberOfClosedNodes() override {return closed->size();}

};

#endif //ADVANCED1_HW4__BREADTHFIRSTSEARCH_H_
