//
// Created by yoavst22 on 23/01/2020.
//

#include "MatrixProblem.h"
MatrixProblem::MatrixProblem(std::vector<std::vector<int>>* m, int xi, int yi, int xg, int yg){
  matrix = m;
  init = new State(xi, yi);
  init->SetCameFrom(nullptr);
  init->SetCost(matrix->at(xi).at(yi));
//  std::cout<<matrix->at(xi).at(yi)<<"\n";
  goal = new State(xg, yg);
}

std::list<State*>* MatrixProblem::GetPossibleStates(State* s){
  auto l = new std::list<State*>();
  int x = s->GetX();
  int y = s->GetY();
  if (x > 0) {
    auto s1 = new State(x - 1, y);
    s1->SetCameFrom(s);
    s1->SetCost(s->GetCost() + matrix->at(x-1).at(y));
    l->push_back(s1);
  }
  if (x < matrix->size()-1) {
    auto s1 = new State(x + 1, y);
    s1->SetCameFrom(s);
    s1->SetCost(s->GetCost() + matrix->at(x+1).at(y));
    l->push_back(s1);
  }
  if (y > 0) {
    auto s1 = new State(x, y-1);
    s1->SetCameFrom(s);
    s1->SetCost(s->GetCost() + matrix->at(x).at(y-1));
    l->push_back(s1);
  }
  if (y < matrix->at(0).size()-1) {
    auto s1 = new State(x, y+1);
    s1->SetCameFrom(s);
    s1->SetCost(s->GetCost() + matrix->at(x).at(y+1));
    l->push_back(s1);
  }
  return l;
}