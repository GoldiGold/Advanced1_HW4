//
// Created by yoavst22 on 28/01/2020.
//

#ifndef ADVANCED1_HW4__MYQUEUE_H_
#define ADVANCED1_HW4__MYQUEUE_H_
#include "State.h"
#include "MyCmp.h"
#include <queue>
#include <unordered_map>
#include <list>

//wrapping class to std::queue
class MyQueue{
  std::queue<State*>* q;
  std::unordered_map<std::string, State*>* m;//map of the states in the queue


 public:
  MyQueue(){
    q = new std::queue<State*>();
    m = new std::unordered_map<std::string, State*>();
  }
  ~MyQueue(){delete q;}
  int length() {return q->size();}
  void push(State* s){
    q->push(s);
    m->insert(std::pair<std::string, State*>(s->toString(),s));
  }
  bool contains(State* s){
    return (m->find(s->toString()) != m->end());
  }
  State* pop(){
    auto tmp = q->front();
    q->pop();
    m->erase(tmp->toString());
    return tmp;
  }
  State* get(std::string str){
    return m->at(str);
  }

  void update(State* s);
};

#endif //ADVANCED1_HW4__MYQUEUE_H_
