//
// Created by yoavst22 on 23/01/2020.
//

#include "BestFirstSearch.h"

BestFirstSearch::BestFirstSearch() {
  this->openList = new MyPriorityQueue();
  closed = new std::unordered_map<std::string, State*>();
}


std::list<char>* BestFirstSearch::path(State* s){
  using namespace std;
  auto l = new list<char>();
  auto cf = s->GetCameFrom();
  auto x = s->GetX();
  auto y = s->GetY();
  while (cf != nullptr) {
    auto cfx = cf->GetX();
    auto cfy = cf->GetY();
    if(cfx == x-1) {
      l->push_front('r');
    } else if(cfx == x+1) {
      l->push_front('l');
    } else if(cfy == y-1) {
      l->push_front('d');
    } else if(cfy == y+1) {
      l->push_front('u');
    } else {
      throw "invalid step";
    }
    cf = cf->GetCameFrom();
  }
  return l;
}




std::list<char>* BestFirstSearch::solve(Searchable* searchable){
  using namespace std;
  openList->push(searchable->GetInitState());

  while(openList->length()> 0){
    State* n = openList->pop();
    closed->insert(std::pair<string, State*>(n->toString(), n));
    if(n == searchable->GetGoalState()){
      return path(n);
    }
    list<State*>* succ = searchable->GetPossibleStates(n);
    for(State* s: *succ){
      auto str = s->toString();
      if(closed->find(str) == closed->end()){

      }
    }
  }
}