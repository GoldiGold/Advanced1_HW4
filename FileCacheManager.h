//
// Created by חן גולדשטיין on 27/01/2020.
//

#ifndef ADVANCED1_HW4__FILECACHEMANAGER_H_
#define ADVANCED1_HW4__FILECACHEMANAGER_H_
#include "CacheManager.h"
#include <list>
#include <unordered_map>
template<class Problem, class Solution>
class FileCacheManager : public CacheManager<Problem, Solution> {

	std::unordered_map<Problem, std::pair<Solution, typename std::list<Problem>::iterator> > *cache;
	std::list<Problem> *lru_list;
	int capacity;

	FileCacheManager(int capacity) {
		this->cache = new std::unordered_map<Problem, std::pair<Solution, typename std::list<Problem>::iterator> >;
		this->lru_list = new std::list<Problem>;
		this->capacity = capacity;
	}
	Solution get_solution(Problem p) override {

	}
	void insert(Problem p, Solution s) override {

	}
	bool is_exist(Problem p) override {

	}

};

#endif //ADVANCED1_HW4__FILECACHEMANAGER_H_
