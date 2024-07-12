#ifndef _NODE_H_
#define _NODE_H_
#include <vector>

class node
{
 public:
  /*
    three coordinates of the center of node
   */
  double c_x;
  double c_y;
  double c_z;

  /*
    Three cuantities that define the size of the node
   */
  
  double depth;
  double width;
  double heigth;

  /*
    values of the particle that is in node.
    if the node have more than one particle the velocity is 0.0 in all directions
   */
  
  double mass;
  double cm_x;
  double cm_y;
  double cm_z;

  double v_cm_x;
  double v_cm_y;
  double v_cm_z;

  /*
    pointer at nodes childrens
   */
  
  node * node1;
  node * node2;
  node * node3;
  node * node4;
  node * node5;
  node * node6;
  node * node7;
  node * node8;

  bool divided; 
  bool ocuped;
  
 public:
  node();
  node(std::vector<double> inits);
  ~node();

  bool its_contain(std::vector<double> particle);
  void divide(void);
  void insert(std::vector<double> particle);
  std::vector<double> get_acel(std::vector<double> particle);
 
  double get_x(void) {return c_x;}
  double get_y(void) {return c_y;}
  double get_z(void) {return c_z;}
  double get_depth(void) {return depth;}
  double get_width(void) {return width;}
  double get_heigth(void) {return heigth;}
  double get_mass(void) {return mass;}
  double get_x_cm(void) {return cm_x;}
  double get_y_cm(void) {return cm_y;}
  double get_z_cm(void) {return cm_z;}
  double get_v_x_cm(void) {return v_cm_x;}
  double get_v_y_cm(void) {return v_cm_y;}
  double get_v_z_cm(void) {return v_cm_z;}
  node * get_node1(void) {return node1;}
  node * get_node2(void) {return node2;}
  node * get_node3(void) {return node3;}
  node * get_node4(void) {return node4;}
  node * get_node5(void) {return node5;}
  node * get_node6(void) {return node6;}
  node * get_node7(void) {return node7;}
  node * get_node8(void) {return node8;}
  
  void change_x(double x){c_x = x;}
  void change_y(double y) {c_y = y;}
  void change_z(double z) {c_z = z;}
  void change_depth(double d) {depth = d;}
  void change_width(double w) {width = w;}
  void change_heigth(double h) {heigth = h;}
  void change_mass(double m) {mass = m;}
  void change_x_cm(double x_cm) {cm_x = x_cm;}
  void change_y_cm(double y_cm) {cm_y = y_cm;}
  void change_z_cm(double z_cm) {cm_z = z_cm;}
  void change_v_x_cm(double v_x_cm) {v_cm_x = v_x_cm;}
  void change_v_y_cm(double v_y_cm) {v_cm_y = v_y_cm;}
  void change_v_z_cm(double v_z_cm) {v_cm_z = v_z_cm;}
  void change_node1(node * n1) {node1 = n1;}
  void change_node2(node * n2) {node2 = n2;}
  void change_node3(node * n3) {node3 = n3;}
  void change_node4(node * n4) {node4 = n4;}
  void change_node5(node * n5) {node5 = n5;}
  void change_node6(node * n6) {node6 = n6;}
  void change_node7(node * n7) {node7 = n7;}
  void change_node8(node * n8) {node8 = n8;}
};

#endif
