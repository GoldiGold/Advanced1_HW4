//
// Created by yoavst22 on 23/01/2020.
//

#ifndef ADVANCED1_HW4__STATE_H_
#define ADVANCED1_HW4__STATE_H_
#include <limits>
#include <iostream>
class State{
  int x;
  int y;
  State* cameFrom;
  int cost;

 public:
  State(int x1, int y1){
    x = x1;
    y = y1;
    cost = std::numeric_limits<int>::infinity();
    cameFrom = nullptr;
  }
  ~State() = default;
  void SetCameFrom(State *came_from){cameFrom = came_from; }
  void SetCost(int cost1){cost = cost1;}
  int GetX() const {return x;}
  int GetY() const {return y;}
  State *GetCameFrom() const {return cameFrom;}
  int GetCost() const {return cost;}
  void print();
  std::string toString();

  bool operator== (const State* other) const{
    if (other== nullptr) {
      return false;
    }
    return (x == other->GetX() && y == other->GetY());
  }
};

#endif //ADVANCED1_HW4__STATE_H_
