//
// Created by yoavst22 on 23/01/2020.
//

#ifndef ADVANCED1_HW3__BESTFIRSTSEARCH_H_
#define ADVANCED1_HW3__BESTFIRSTSEARCH_H_

#include "State.h"
#include "Searchable.h"
#include "Searcher.h"
#include "MyPriorityQueue.h"
//#include <hash_set>
class BestFirstSearch: public Searcher{
  MyPriorityQueue openList;

  std::list<char>* path(State<std::pair<int,int>>* s);
 public:
  std::list<char> search(Searchable<std::pair<int,int>>* searchable);
};
#endif //ADVANCED1_HW3__BESTFIRSTSEARCH_H_
