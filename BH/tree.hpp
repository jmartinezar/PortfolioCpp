#ifndef _TREE_H_
#define _TREE_H_
#include "node.hpp"
#include <vector>
#include <memory>

class tree
{
 public:
  int counter;
  node * ninit;

 public:
  tree(std::vector<std::vector<std::vector<double>>> inits);
  ~tree();
  void update(std::vector<std::vector<std::vector<double>>> inits);
  std::vector<double> get_acel(std::vector<double> particle);
};

#endif
