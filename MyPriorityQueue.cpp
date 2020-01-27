//
// Created by yoavst22 on 26/01/2020.
//

#include "MyPriorityQueue.h"
void MyPriorityQueue::update(State* s){
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