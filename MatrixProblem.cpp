//
// Created by yoavst22 on 23/01/2020.
//

#include "MatrixProblem.h"
MatrixProblem::MatrixProblem(std::vector<std::vector<int>> *m, int xi, int yi, int xg, int yg) {
	matrix = m;
//	std::cout << "fuck off bitch:" << matrix->size() << std::endl;
	init = new State(xi, yi);
	init->SetCameFrom(nullptr);
	init->SetCost(matrix->at(xi).at(yi));
//  std::cout<<matrix->at(xi).at(yi)<<"\n";
	goal = new State(xg, yg);
}

std::list<State *> *MatrixProblem::GetPossibleStates(State *s) {
	auto l = new std::list<State *>();
	int x = s->GetX();
	int y = s->GetY();
	if (x > 0) {
		auto s1 = new State(x - 1, y);
		s1->SetCameFrom(s);
		s1->SetCost(s->GetCost() + matrix->at(x - 1).at(y));
		l->push_back(s1);
	}
	if (x < matrix->size() - 1) {
		auto s1 = new State(x + 1, y);
		s1->SetCameFrom(s);
		s1->SetCost(s->GetCost() + matrix->at(x + 1).at(y));
		l->push_back(s1);
	}
	if (y > 0) {
		auto s1 = new State(x, y - 1);
		s1->SetCameFrom(s);
		s1->SetCost(s->GetCost() + matrix->at(x).at(y - 1));
		l->push_back(s1);
	}
	if (y < matrix->at(0).size() - 1) {
		auto s1 = new State(x, y + 1);
		s1->SetCameFrom(s);
		s1->SetCost(s->GetCost() + matrix->at(x).at(y + 1));
		l->push_back(s1);
	}
	return l;
}
std::string MatrixProblem::toString() {
	std::string desc;
	std::cout << "bigger size: " << (*matrix).size() << std::endl;

	for (const std::vector<int> &vec:*this->matrix) {
//		for (int val : vec) {
	std::cout << "size: " << vec.size() << std::endl;
		for (int kI = 0; kI < vec.size(); ++kI) {
			desc += std::to_string(vec[kI]);
			desc += ',';
			std::cout << "val: "<< std::to_string(vec[kI])<< std::endl;
		}
		std::cout << "description is: " << desc << std::endl;
		if (!desc.empty()) {
			desc.pop_back();
			desc += '\n';
		}
	}
	desc += std::to_string(this->init->GetX()) + ',' + std::to_string(this->init->GetY()) + '\n';
	desc += std::to_string(this->goal->GetX()) + ',' + std::to_string(this->goal->GetY()) + '\n';
	std::cout << "description is: " << desc << std::endl;
	return desc;
}
