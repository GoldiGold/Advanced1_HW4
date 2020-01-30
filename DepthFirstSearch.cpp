//
// Created by yoavst22 on 28/01/2020.
//

#include "DepthFirstSearch.h"


DepthFirstSearch::DepthFirstSearch() {
  this->openList = new MyStack();
  closed = new std::unordered_map<std::string, State*>();
  cost = 0;
}


std::list<std::pair<char,int>>* DepthFirstSearch::path(State* s){
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
	}
	return l;
}



std::list<std::pair<char,int>>* DepthFirstSearch::search(Searchable* searchable){
  using namespace std;
  this->openList = new MyStack();
  closed = new std::unordered_map<std::string, State*>();
  cost = 0;
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