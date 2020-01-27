//
// Created by yoavst22 on 26/01/2020.
//

#ifndef ADVANCED1_HW4__MYPRIORITYQUEUE_H_
#define ADVANCED1_HW4__MYPRIORITYQUEUE_H_
#include "State.h"
#include "MyCmp.h"
#include <queue>
#include <unordered_map>
#include <list>
class MyPriorityQueue{
  std::priority_queue<State*, std::vector<State*>, MyCmp>* q;
  std::unordered_map<std::string, State*>* m;

 public:
  MyPriorityQueue(){
    q = new std::priority_queue<State*, std::vector<State*>, MyCmp>(MyCmp());
    m = new std::unordered_map<std::string, State*>();
  }
  ~MyPriorityQueue(){delete q;}
  int length() {return q->size();}
  void push(State* s){
    q->push(s);
    m->insert(std::pair<std::string, State*>(s->toString(),s));
  }
  bool contains(State* s){
    return (m->find(s->toString()) != m->end());
  }
  State* pop(){
    auto tmp = q->top();
    q->pop();
    m->erase(tmp->toString());
    return tmp;
  }
  State* get(std::string str){
    return m->at(str);
  }
  void update(State* s);
};
#endif //ADVANCED1_HW4__MYPRIORITYQUEUE_H_
