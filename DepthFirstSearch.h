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
//like BFS with stack instaed of queue
class DepthFirstSearch: public Searcher{
  MyStack* openList;
  std::unordered_map<std::string, State*>* closed;
  int cost;

  std::list<std::pair<char,int>>* path(State* s);
 public:
  DepthFirstSearch();
  ~DepthFirstSearch(){delete openList;}
  std::list<std::pair<char,int>>* search(Searchable* searchable) override;
  int GetCost() override {return cost;}
  int numberOfClosedNodes() override {return closed->size();}
  DepthFirstSearch* clone() override {
  	return new DepthFirstSearch();
  }
};

#endif //ADVANCED1_HW4__DEPTHFIRSTSEARCH_H_
