#include <iostream>
#include <vector>
#include "node.h"
#include "tree.h"
#include "include.h"
#include "constants.h"

int main(void)
{
  std::vector<std::vector<std::vector<double>>> data_problem{
    {
      {10.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
	{0.1, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0}
    }
  };
  
  tree OctTree(data_problem);

  initialized(OctTree, data_problem, dt);

  OctTree.update(data_problem);

  integration(OctTree, ti, tf, dt, data_problem);

  animate_data(data_problem);
  
  return 0;
}
