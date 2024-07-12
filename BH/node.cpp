#include <vector>
#include <cmath>
#include "node.hpp"
#include "include.hpp"

/*
The initialization function take all values like 0.0 and pointer like nullptr
the node isn't divided and ocuped
the size of the node is 5x5x5
*/
node::node()
{
  c_x = 0.0;
  c_y = 0.0;
  c_z = 0.0;

  depth = 1.0;
  width = 1.0;
  heigth = 1.0;

  mass = 0.0;
  cm_x = 0.0;
  cm_y = 0.0;
  cm_z = 0.0;

  v_cm_x = 0.0;
  v_cm_y = 0.0;
  v_cm_z = 0.0;

  node1 = nullptr;
  node2 = nullptr;
  node3 = nullptr;
  node4 = nullptr;
  node5 = nullptr;
  node6 = nullptr;
  node7 = nullptr;
  node8 = nullptr;

  divided = false;
  ocuped = false;
}

/*
inits contain coordinates at center of node anda its size
other all values are initialized in 0.0
*/

node::node(std::vector<double> inits)
{
  c_x = inits[0];
  c_y = inits[1];
  c_z = inits[2];

  depth = inits[3];
  width = inits[4];
  heigth = inits[5];

  mass = 0.0;
  cm_x = 0.0;
  cm_y = 0.0;
  cm_z = 0.0;

  v_cm_x = 0.0;
  v_cm_y = 0.0;
  v_cm_z = 0.0;

  node1 = nullptr;
  node2 = nullptr;
  node3 = nullptr;
  node4 = nullptr;
  node5 = nullptr;
  node6 = nullptr;
  node7 = nullptr;
  node8 = nullptr;

  divided = false;
  ocuped = false;
}

node::~node()
{
  if(node1 != nullptr)
    {
      delete node1;
    }
  if(node2 != nullptr)
    {
      delete node2;
    }
  if(node3 != nullptr)
    {
      delete node3;
    }
  if(node4 != nullptr)
    {
      delete node4;
    }
  if(node5 != nullptr)
    {
      delete node5;
    }
  if(node6 != nullptr)
    {
      delete node6;
    }
  if(node7 != nullptr)
    {
      delete node7;
    }
  if(node8 != nullptr)
    {
      delete node8;
    }
}

/*
verifique if a particle is contain in the node
*/

bool node::its_contain(std::vector<double> particle)
{
  if((c_x - depth/2.0 < particle[1]) and (particle[1]<= c_x + depth/2.0) and (c_y - width/2.0 < particle[2]) and (particle[2] <= c_y + width/2.0) and (c_z - heigth/2.0 < particle[3]) and (particle[3] <= c_z + heigth/2.0))
    {
      return true;
    }
  else
    {
      return false;
    }
}

/*
divides the node in 8 nodes
*/

void node::divide(void)
{
  std::vector<double> inits;

  double aux[] = {c_x+depth/4.0, c_y+width/4.0, c_z+heigth/4.0, depth/2.0, width/2.0, heigth/2.0};

  inits.assign(aux, aux+6);
  //node n1(inits);
  node1 = new node(inits);

  inits[0] = c_x-depth/2.0;
  //  node n2(inits);
  node2 = new node(inits);

  inits[1] = c_y-width/2.0;
  //  node n3(inits);
  node3 = new node(inits);

  inits[2] = c_z-heigth/2.0;
  //  node n4(inits);
  node4 = new node(inits);

  inits[1] = c_y+width/2.0;
  //  node n5(inits);
  node5 = new node(inits);

  inits[0] = c_x-depth/2.0;
  //  node n6(inits);
  node6 = new node(inits);

  inits[1] = c_y-width/2.0;
  //  node n7(inits);
  node7 = new node(inits);

  inits[2] = c_z+heigth/2.0;
  //  node n8(inits);
  node8 = new node(inits);

  divided = true;
}

void node::insert(std::vector<double> particle)
{
  if((not divided) and (not ocuped) and (its_contain(particle)))
    {
	mass = particle[0];
	cm_x = particle[1];
	cm_y = particle[2];
	cm_z = particle[3];
	v_cm_x = particle[4];
	v_cm_y = particle[5];
	v_cm_z = particle[6];

	ocuped = true;
    }
  else if((not divided) and (ocuped) and (its_contain(particle)))
    {
      double m_aux = mass;
      mass += particle[0];
      cm_x += (m_aux*cm_x + particle[0]*particle[1])/mass;
      cm_y += (m_aux*cm_y + particle[0]*particle[2])/mass;
      cm_z += (m_aux*cm_z + particle[0]*particle[3])/mass;

      v_cm_x = 0.0;
      v_cm_y = 0.0;
      v_cm_z = 0.0;

      divide();

      if((c_x < particle[1]) and (particle[1] <= c_x+depth/2.0) and (c_y < particle[2]) and (particle[2] <= c_y+width/2.0) and (c_z < particle[3]) and (particle[3] <= c_z+heigth/2.0))
	{
	  node1->insert(particle);
	}
      else if((c_x-depth/2.0 < particle[1]) and (particle[1] <= c_x) and (c_y < particle[2]) and (particle[2] <= c_y+width/2.0) and (c_z < particle[3]) and (particle[3] <= c_z+heigth/2.0))
	{
	  node2->insert(particle);
	}
      else if((c_x-depth/2.0 < particle[1]) and (particle[1] <= c_x) and (c_y-width/2.0 < particle[2]) and (particle[2] <= c_y) and (c_z < particle[3]) and (particle[3] <= c_z+heigth/2.0))
	{
	  node3->insert(particle);
	}
      else if((c_x-depth/2.0 < particle[1]) and (particle[1] <= c_x) and (c_y-width/2.0 < particle[2]) and (particle[2] <= c_y) and (c_z-heigth/2.0 < particle[3]) and (particle[3] <= c_z))
	{
	  node4->insert(particle);
	}
      else if((c_x-depth/2.0 < particle[1]) and (particle[1] <= c_x) and (c_y < particle[2]) and (particle[2] <= c_y+width/2.0) and (c_z-heigth/2.0 < particle[3]) and (particle[3] <= c_z))
	{
	  node5->insert(particle);
	}
      else if((c_x < particle[1]) and (particle[1] <= c_x+depth/2.0) and (c_y < particle[2]) and (particle[2] <= c_y+width/2.0) and (c_z-heigth/2.0 < particle[3]) and (particle[3] <= c_z))
	{
	  node6->insert(particle);
	}
      else if((c_x < particle[1]) and (particle[1] <= c_x+depth/2.0) and (c_y-width/2.0 < particle[2]) and (particle[2] <= c_y) and (c_z-heigth/2.0 < particle[3]) and (particle[3] <= c_z))
	{
	  node7->insert(particle);
	}
      else if((c_x < particle[1]) and (particle[1] <= c_x+depth/2.0) and (c_y-width/2.0 < particle[2]) and (particle[2] <= c_y) and (c_z < particle[3]) and (particle[3] <= c_z+heigth/2.0))
	{
	  node8->insert(particle);
	}
    }
  else if(its_contain(particle))
    {
      if((c_x < particle[1]) and (particle[1] <= c_x+depth/2.0) and (c_y < particle[2]) and (particle[2] <= c_y+width/2.0) and (c_z < particle[3]) and (particle[3] <= c_z+heigth/2.0))
	{
	  node1->insert(particle);
	}
      else if((c_x-depth/2.0 < particle[1]) and (particle[1] <= c_x) and (c_y < particle[2]) and (particle[2] <= c_y+width/2.0) and (c_z < particle[3]) and (particle[3] <= c_z+heigth/2.0))
	{
	  node2->insert(particle);
	}
      else if((c_x-depth/2.0 < particle[1]) and (particle[1] <= c_x) and (c_y-width/2.0 < particle[2]) and (particle[2] <= c_y) and (c_z < particle[3]) and (particle[3] <= c_z+heigth/2.0))
	{
	  node3->insert(particle);
	}
      else if((c_x-depth/2.0 < particle[1]) and (particle[1] <= c_x) and (c_y-width/2.0 < particle[2]) and (particle[2] <= c_y) and (c_z-heigth/2.0 < particle[3]) and (particle[3] <= c_z))
	{
	  node4->insert(particle);
	}
      else if((c_x-depth/2.0 < particle[1]) and (particle[1] <= c_x) and (c_y < particle[2]) and (particle[2] <= c_y+width/2.0) and (c_z-heigth/2.0 < particle[3]) and (particle[3] <= c_z))
	{
	  node5->insert(particle);
	}
      else if((c_x < particle[1]) and (particle[1] <= c_x+depth/2.0) and (c_y < particle[2]) and (particle[2] <= c_y+width/2.0) and (c_z-heigth/2.0 < particle[3]) and (particle[3] <= c_z))
	{
	  node6->insert(particle);
	}
      else if((c_x < particle[1]) and (particle[1] <= c_x+depth/2.0) and (c_y-width/2.0 < particle[2]) and (particle[2] <= c_y) and (c_z-heigth/2.0 < particle[3]) and (particle[3] <= c_z))
	{
	  node7->insert(particle);
	}
      else if((c_x < particle[1]) and (particle[1] <= c_x+depth/2.0) and (c_y-width/2.0 < particle[2]) and (particle[2] <= c_y) and (c_z < particle[3]) and (particle[3] <= c_z+heigth/2.0))
	{
	  node8->insert(particle);
	}
      mass = node1->mass + node2->mass + node3->mass + node4->mass + node5->mass + node6->mass + node7->mass + node8->mass;
      cm_x = ((node1->mass)*(node1->cm_x) + (node2->mass)*(node2->cm_x) + (node3->mass)*(node3->cm_x) + (node4->mass)*(node4->cm_x) + (node5->mass)*(node5->cm_x) + (node6->mass)*(node6->cm_x) + (node7->mass)*(node7->cm_x) + (node8->mass)*(node8->cm_x))/mass;
      cm_y = ((node1->mass)*(node1->cm_y) + (node2->mass)*(node2->cm_y) + (node3->mass)*(node3->cm_y) + (node4->mass)*(node4->cm_y) + (node5->mass)*(node5->cm_y) + (node6->mass)*(node6->cm_y) + (node7->mass)*(node7->cm_y) + (node8->mass)*(node8->cm_y))/mass;
      cm_z = ((node1->mass)*(node1->cm_z) + (node2->mass)*(node2->cm_z) + (node3->mass)*(node3->cm_z) + (node4->mass)*(node4->cm_z) + (node5->mass)*(node5->cm_z) + (node6->mass)*(node6->cm_z) + (node7->mass)*(node7->cm_z) + (node8->mass)*(node8->cm_z))/mass;
      ocuped = false;
    }
}

std::vector<double> node::get_acel(std::vector<double> particle)
{
  double s = (depth)*(width)*(heigth);
  double d = std::sqrt((cm_x - particle[1])*(cm_x - particle[1]) + (cm_y - particle[2])*(cm_y - particle[2]) + (cm_z - particle[3])*(cm_z - particle[3]));
  if(s/d < 0.5)
    {
      double result_x = -4*M_PI*mass*(cm_x - particle[1])/std::pow(d, 3);
      double result_y = -4*M_PI*mass*(cm_y - particle[2])/std::pow(d, 3);
      double result_z = -4*M_PI*mass*(cm_z - particle[3])/std::pow(d, 3);
      std::vector<double> result{result_x, result_y, result_z};

      return result;
    }
  else
    {
      std::vector<double> result{0.0, 0.0, 0.0};
      std::vector<double> aux{0.0, 0.0, 0.0};
      if(node1 != nullptr)
	{
	  aux = node1->get_acel(particle);
	  result = AddVector(result, aux);
	}
      
      if(node2 != nullptr)
	{
	  aux = node2->get_acel(particle);
	  result = AddVector(result, aux);
	}
      if(node3 != nullptr)
	{
	  aux = node3->get_acel(particle);
	  result = AddVector(result, aux);
	}
      if(node4 != nullptr)
	{
	  aux = node4->get_acel(particle);
	  result = AddVector(result, aux);
	}
      if(node5 != nullptr)
	{
	  aux = node5->get_acel(particle);
	  result = AddVector(result, aux);
	}
      if(node6 != nullptr)
	{
	  aux = node6->get_acel(particle);
	  result = AddVector(result, aux);
	}
      if(node7 != nullptr)
	{
	  aux = node7->get_acel(particle);
	  result = AddVector(result, aux);
	}
      if(node8 != nullptr)
	{
	  aux = node8->get_acel(particle);
	  result = AddVector(result, aux);
	}
      
      return result;
    }
}
