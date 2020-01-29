//
// Created by yoavst22 on 28/01/2020.
//

#ifndef ADVANCED1_HW4__DEPTHFIRSTSEARCH_H_
#define ADVANCED1_HW4__DEPTHFIRSTSEARCH_H_
#include "State.h"
#include "Searchable.h"
#include "Searcher.h"
#include <unordered_map>
#include "MyStack.h"

class DepthFirstSearch: public Searcher{
  MyStack* openList;
  std::unordered_map<std::string, State*>* closed;
  int cost;

  std::list<char>* path(State* s);
 public:
  DepthFirstSearch();
  ~DepthFirstSearch(){delete openList;}
  std::list<char>* search(Searchable* searchable) override;
  int GetCost() override {return cost;}
  int numberOfClosedNodes() override {return closed->size();}

};

#endif //ADVANCED1_HW4__DEPTHFIRSTSEARCH_H_
