#include "tree.hpp"
#include "node.hpp"
#include "include.hpp"
#include <iostream>

tree::tree(std::vector<std::vector<std::vector<double>>> inits)
{
  double max = range_adjust(inits);
  
  std::vector<double> size_node{0.0, 0.0, 0.0, 2.1*max, 2.1*max, 2.1*max};
  ninit = new node(size_node);
  
  for (unsigned int j = 0; j < inits[0].size(); j++)
    {
      ninit->insert(inits[0][j]);
    }
  counter = 0;
}

tree::~tree()
{
  delete ninit;
}

void tree::update(std::vector<std::vector<std::vector<double>>> inits)
{
  double max = range_adjust(inits);
  //counter += 1;

  std::vector<double> size_node{0.0, 0.0, 0.0, 2.1*max, 2.1*max, 2.1*max};

  node aux(size_node);

  for(unsigned int j = 0; j < inits[counter].size(); j++)
    {
      aux.insert(inits[counter][j]);
    }

  ninit->change_x(aux.get_x());
  ninit->change_y(aux.get_y());
  ninit->change_z(aux.get_z());
  ninit->change_depth(aux.get_depth());
  ninit->change_width(aux.get_width());
  ninit->change_heigth(aux.get_heigth());
  ninit->change_mass(aux.get_mass());
  ninit->change_x_cm(aux.get_x_cm());
  ninit->change_y_cm(aux.get_y_cm());
  ninit->change_z_cm(aux.get_z_cm());
  ninit->change_v_x_cm(aux.get_v_x_cm());
  ninit->change_v_y_cm(aux.get_v_y_cm());
  ninit->change_v_z_cm(aux.get_v_z_cm());
  counter += 1;
}

std::vector<double> tree::get_acel(std::vector<double> particle)
{
  std::vector<double> result = ninit->get_acel(particle);
  return result;
}
