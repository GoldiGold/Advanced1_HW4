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

  std::list<std::pair<char,int>>* path(State* s);
 public:
  BestFirstSearch();
  ~BestFirstSearch(){delete openList;}
  std::list<std::pair<char,int>>* search(Searchable* searchable) override;
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
std::list<std::pair<char,int>>* BestFirstSearch<CMP>::path(State* s){
  using namespace std;
  cost = s->GetCost();
  cout<<cost<<"\n";
  auto l = new list<std::pair<char,int>>();
  auto cf = s->GetCameFrom();
  auto sTmp = s;

  while (cf != nullptr) {
	  auto p = pair<char, int>();
	  p.second = (sTmp->GetCost());
    auto x = sTmp->GetX();
    auto y = sTmp->GetY();
    auto cfx = cf->GetX();
    auto cfy = cf->GetY();
    if(cfx == x-1) {
    	p.first = 'd';
    } else if(cfx == x+1) {
		p.first = 'u';
    } else if(cfy == y-1) {
		p.first = 'r';
    } else if(cfy == y+1) {
		p.first = 'l';
    } else {
      throw "invalid step";
    }
    l->push_front(p);
    sTmp = cf;
    cf = cf->GetCameFrom();
//    if(cf== nullptr){
//    	p.second+=sTmp.
//    }
  }
  return l;
}



template<class CMP>
std::list<std::pair<char,int>>* BestFirstSearch<CMP>::search(Searchable* searchable){
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
