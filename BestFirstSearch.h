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
#include "CostCmp.h"
template<class CMP>
class BestFirstSearch: public Searcher{
  MyPriorityQueue<CMP>* openList;
  std::unordered_map<std::string, State*>* closed;
  int cost;

  std::list<char>* path(State* s);
 public:
  BestFirstSearch();
  ~BestFirstSearch(){delete openList;}
  std::list<char>* search(Searchable* searchable) override;
  int GetCost() override {return cost;}
  int numberOfClosedNodes() override{
    return closed->size();
  }

};

template<class CMP>
BestFirstSearch<CMP>::BestFirstSearch() {
  this->openList = new MyPriorityQueue<CMP>();
  closed = new std::unordered_map<std::string, State*>();
  cost = 0;
}

template<class CMP>
std::list<char>* BestFirstSearch<CMP>::path(State* s){
  using namespace std;
  cost = s->GetCost();
  auto l = new list<char>();
  auto cf = s->GetCameFrom();
  auto stmp = s;
  auto x = stmp->GetX();
  auto y = stmp->GetY();
  while (cf != nullptr) {
    auto x = stmp->GetX();
    auto y = stmp->GetY();
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



template<class CMP>
std::list<char>* BestFirstSearch<CMP>::search(Searchable* searchable){
  using namespace std;
  this->openList = new MyPriorityQueue<CMP>();
  closed = new std::unordered_map<std::string, State*>();
  cost = 0;
  openList->setInit(searchable->GetInitState());
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

#endif //ADVANCED1_HW4__BESTFIRSTSEARCH_H_
