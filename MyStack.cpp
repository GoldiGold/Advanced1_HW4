//
// Created by yoavst22 on 28/01/2020.
//

#include "MyStack.h"
void MyStack::update(State* s){
  (*m)[s->toString()] = s;
  auto l = new std::list<State*>();
  while (!q->empty()){
    auto tmp = q->top();
    if (*s == tmp){
      l->push_back(s);
    } else {
      l->push_back(tmp);
    }
    q->pop();
  }
  while (!l->empty()){
    q->push(l->back());
    l->pop_back();
  }
}