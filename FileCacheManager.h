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
//template<class Problem, class Solution>
class FileCacheManager : public CacheManager<std::string, std::string> {

//	std::unordered_map<Problem, std::string> *cache;
 public:
	FileCacheManager() = default;
	std::string get_solution(std::string p) override {
//		if(this->cache->find(p) != this->cache->end()){
		std::ifstream solutionFile;
		solutionFile.open("../" + std::to_string(std::hash<std::string>()(p)) + ".txt");
		if (!solutionFile) {
			std::cerr << "the file wasn't able to open - it doesn't exist maybe" << std::endl;
		}
		std::string s;
		std::string line;
		while (std::getline(solutionFile, line)) {
			s += line;
		}
//		solutionFile.((char *) &s, sizeof(s));
		solutionFile.close();
		return s;
	}
	void insert(std::string p, std::string s) override {
		std::ofstream solutionFile;
		solutionFile.open("../" + std::to_string(std::hash<std::string>()(p)) + ".txt",
						  std::ios::trunc); // TODO: make sure you need trunc or if there is a different flag to use
		if (!solutionFile) {
			std::cerr << "the file wasn't able to open - it doesn't exist maybe" << std::endl;
		}
		solutionFile << s;
		solutionFile.close();
	}

	bool is_exist(std::string p) override {
		std::ifstream solutionFile;
		solutionFile.open("../" + std::to_string(std::hash<std::string>()(p)) + ".txt");
		return !(!solutionFile);
	}

	FileCacheManager *clone() override {
		return new FileCacheManager();
	}

// public:
//	FileCacheManager() {
////		this->cache = new std::unordered_map<Problem, std::string>;
//	}
};

#endif //ADVANCED1_HW4__FILECACHEMANAGER_H_
