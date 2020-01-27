//
// Created by yoavst22 on 26/01/2020.
//

#ifndef ADVANCED1_HW4__MYPRIORITYQUEUE_H_
#define ADVANCED1_HW4__MYPRIORITYQUEUE_H_
#include "State.h"
#include "MyCmp.h"
#include <queue>
class MyPriorityQueue{
  std::priority_queue<State*, std::vector<State*>, MyCmp>* q;

 public:
  MyPriorityQueue(){
    q = new std::priority_queue<State*, std::vector<State*>, MyCmp>(MyCmp());
  }
  ~MyPriorityQueue(){delete q;}
  int length() {return q->size();}
  void push(State* s){
    q->push(s);
  }
  State* pop(){
    auto tmp = q->top();
    q->pop();
    return tmp;
  }
};
#endif //ADVANCED1_HW4__MYPRIORITYQUEUE_H_
