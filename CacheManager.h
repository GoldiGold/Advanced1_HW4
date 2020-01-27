//
// Created by חן גולדשטיין on 27/01/2020.
//

#ifndef ADVANCED1_HW4__CACHEMANAGER_H_
#define ADVANCED1_HW4__CACHEMANAGER_H_

template<class Problem, class Solution>
class CacheManager {
 public:
	virtual Solution get_solution(Problem p);
	virtual void insert(Problem p, Solution s);
	virtual bool is_exist(Problem p);
};


#endif //ADVANCED1_HW4__CACHEMANAGER_H_
