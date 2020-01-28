//
// Created by yoavst22 on 28/01/2020.
//

#include "BreadthFirstSearch.h"

BreadthFirstSearch::BreadthFirstSearch() {
  this->openList = new MyQueue();
  closed = new std::unordered_map<std::string, State*>();
  cost = 0;
}


std::list<char>* BreadthFirstSearch::path(State* s){
  using namespace std;
  cost = s->GetCost();
  auto l = new list<char>();
  auto cf = s->GetCameFrom();
  auto stmp = s;
  auto x = stmp->GetX();
  auto y = stmp->GetY();
  while (cf != nullptr) {
    x = stmp->GetX();
    y = stmp->GetY();
    auto cfx = cf->GetX();
    auto cfy = cf->GetY();
    if(cfx == x-1) {
      l->push_front('d');
    } else if(cfx == x+1) {
      l->push_front('u');
    } else if(cfy == y-1) {
      l->push_front('r');
    } else if(cfy == y+1) {
      l->push_front('l');
    } else {
      throw "invalid step";
    }
    stmp = cf;
    cf = cf->GetCameFrom();
  }
  return l;
}



std::list<char>* BreadthFirstSearch::solve(Searchable* searchable){
  using namespace std;

  openList->push(searchable->GetInitState());

  while(openList->length()> 0){
    State* n = openList->pop();
    closed->insert(std::pair<string, State*>(n->toString(), n));
    if(searchable->isGoalState(n)){
      return path(n);
    }
    list<State*>* succ = searchable->GetPossibleStates(n);
    for(State* s: *succ){
      auto str = s->toString();
      if(closed->find(str) == closed->end() && !openList->contains(s)){
        openList->push(s);
      } else if(!openList->contains(s) && closed->at(s->toString())->GetCost() > s->GetCost()){
        openList->push(s);
        closed->erase(s->toString());
      } else if(openList->contains(s) && openList->get(s->toString())->GetCost() > s->GetCost()){
        openList->update(s);
      }
    }
  }
}