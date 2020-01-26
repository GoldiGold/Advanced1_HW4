//
// Created by חן גולדשטיין on 27/01/2020.
//

#ifndef ADVANCED1_HW4__CACHEMANAGER_H_
#define ADVANCED1_HW4__CACHEMANAGER_H_
template <class Problem, class Solution>
class CacheManager{
 public:
	Solution get_solution(Problem p);
	void insert(Problem p, Solution s);
	bool is_exist(Problem p);
};
#endif //ADVANCED1_HW4__CACHEMANAGER_H_
