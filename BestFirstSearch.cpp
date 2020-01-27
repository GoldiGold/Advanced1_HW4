//
// Created by yoavst22 on 23/01/2020.
//

#include "BestFirstSearch.h"
std::list<char>* BestFirstSearch::path(State<std::pair<int,int>>* s){
  using namespace std;
  auto l = new list<char>();
  auto cf = s->GetCameFrom();
  auto sState = s->GetState();
  while (cf != nullptr) {
    auto cfState = cf->GetState();
    if(cfState->first == sState->first-1) {
      l->push_front('r');
    } else if(cfState->first == sState->first+1) {
      l->push_front('l');
    } else if(cfState->second == sState->second-1) {
      l->push_front('d');
    } else if(cfState->second == sState->second+1) {
      l->push_front('u');
    } else {
      throw "invalid step";
    }
    auto sState = cf->GetState();
    cf = cf->GetCameFrom();
  }
  return l;
}




std::list<char> BestFirstSearch::search(Searchable<std::pair<int,int>>* searchable){
//  using namespace std;
//  openList->push(searchable->GetInitState());
//  auto closed = new __gnu_cxx::hash_set<State<pair<int,int>>*>();
//  while(openList->size() > 0){
//    State<std::pair<int,int>>* n = openList->top();
//    openList->pop();
//    closed->insert(n);
//    if(n == searchable->GetGoalState()){
//      return path(n);
//    }
//  }
}