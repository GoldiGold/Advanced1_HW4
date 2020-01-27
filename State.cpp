//
// Created by yoavst22 on 23/01/2020.
//

#include "State.h"
void State::print(){
  std::cout<<"("<<x<<","<<y<<")   cost: "<<cost<<"   came from: ";
  if(this->cameFrom == nullptr){
    std::cout<<"null\n";
  } else {
    std::cout<<"("<<cameFrom->GetX()<<","<<cameFrom->GetY()<<")\n";
  }
}

std::string State::toString(){
  using namespace std;
  string str = "(";
  str += to_string(x);
  str += ",";
  str += to_string(y);
  str += ")";
  return str;
}