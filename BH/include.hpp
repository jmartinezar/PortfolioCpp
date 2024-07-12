#ifndef _INCLUDE_H_
#define _INCLUDE_H_

#include <iostream>
#include <vector>
#include "tree.hpp"

std::vector<double> AddVector(std::vector<double> v1, std::vector<double> v2);

double range_adjust(std::vector<std::vector<std::vector<double>>> inits);

void initialized(tree QT, std::vector<std::vector<std::vector <double>>> & p_inits, double dt);

void integration(tree & QT, double ti, double tf, double dt, std::vector<std::vector<std::vector<double>>> & particles);

void init_gnuplot(void);

void print_data(std::vector<std::vector<double>> data);

void animate_data(std::vector<std::vector<std::vector<double>>> h_data);

#endif
