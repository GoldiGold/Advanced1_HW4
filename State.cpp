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