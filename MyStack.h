//
// Created by yoavst22 on 28/01/2020.
//

#ifndef ADVANCED1_HW4__MYSTACK_H_
#define ADVANCED1_HW4__MYSTACK_H_
#include "State.h"
#include "MyCmp.h"
#include <stack>
#include <unordered_map>
#include <list>

class MyStack{
  std::stack<State*>* q;
  std::unordered_map<std::string, State*>* m;


 public:
  MyStack(){
    q = new std::stack<State*>();
    m = new std::unordered_map<std::string, State*>();
  }
  ~MyStack(){delete q;}
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
#endif //ADVANCED1_HW4__MYSTACK_H_
