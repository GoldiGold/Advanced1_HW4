//
// Created by yoavst22 on 24/01/2020.
//

#ifndef ADVANCED1_HW3__SEARCHER_H_
#define ADVANCED1_HW3__SEARCHER_H_

#include <list>
#include "Searchable.h"
class Searcher{
  virtual std::list<char> search(Searchable* searchable);

};
#endif //ADVANCED1_HW3__SEARCHER_H_
