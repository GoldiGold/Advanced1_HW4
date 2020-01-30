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
//wrapping class to priority queue
template<class CMP>
class MyPriorityQueue{
  std::priority_queue<State*, std::vector<State*>, CMP>* q;
  std::unordered_map<std::string, State*>* m;
  CMP* cmp;

 public:
  MyPriorityQueue(){
    cmp = new CMP();
    q = new std::priority_queue<State*, std::vector<State*>, CMP>(*cmp);
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
  void setInit(State* s){
    cmp->setInit(s);
  }
  void update(State* s);
};



template<class CMP>
void MyPriorityQueue<CMP>::update(State* s){
  (*m)[s->toString()] = s;
  auto l = new std::list<State*>();
  while (q->size()>0){
    auto tmp = q->top();
    if (*s == tmp){
      l->push_front(s);
    } else {
      l->push_front(tmp);
    }
    q->pop();
  }
  while (l->size() > 0){
    q->push(l->back());
    l->pop_back();
  }
}
#endif //ADVANCED1_HW4__MYPRIORITYQUEUE_H_
