//
// Created by חן גולדשטיין on 27/01/2020.
//

#ifndef ADVANCED1_HW4__FILECACHEMANAGER_H_
#define ADVANCED1_HW4__FILECACHEMANAGER_H_
#include "CacheManager.h"
#include <list>
#include <unordered_map>
#include <fstream>
#include <iostream>
template<class Problem, class Solution>
class FileCacheManager : public CacheManager<Problem, Solution> {

//	std::unordered_map<Problem, std::string> *cache;

	FileCacheManager() {
//		this->cache = new std::unordered_map<Problem, std::string>;
	}
	Solution get_solution(Problem p) override {
//		if(this->cache->find(p) != this->cache->end()){
		std::ifstream solutionFile;
		solutionFile.open("../" + std::hash<Problem>(p) + ".txt", std::ios::binary);
		if (!solutionFile) {
			std::cerr << "the file wasn't able to open - it doesn't exist maybe" << std::endl;
		}
		Solution s;
		solutionFile.read((char *) &s, sizeof(s));
		solutionFile.close();
		return s;
	}
	void insert(Problem p, Solution s) override {
		std::ofstream solutionFile;
		solutionFile.open("../" + std::hash<Problem>(p) + ".txt", std::ios::binary | std::ios::trunc); // TODO: make sure you need trunc or if there is a different flag to use
		if (!solutionFile) {
			std::cerr << "the file wasn't able to open - it doesn't exist maybe" << std::endl;
		}
		solutionFile.write((char *) &s, sizeof(s));
		solutionFile.close();
	}

	bool is_exist(Problem p) override {
		std::ifstream solutionFile;
		solutionFile.open("../" + std::hash<Problem>(p) + ".txt", std::ios::binary);
		return !(!solutionFile);
	}

};

#endif //ADVANCED1_HW4__FILECACHEMANAGER_H_
