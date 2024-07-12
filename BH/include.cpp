#include <iostream>
#include <vector>
#include "include.hpp"
#include "tree.hpp"

/*
 * La función range_adjust proporciona un valor para ajustar el tamaño del árbol según las partículas que se encuentran en su interior. 
 * Este proceso se realiza tomando todos los valores de las componentes x, y, z de todas las partículas que se introducen en el árbol y asignando este valor a la variable 'max'
 * La función recibe: un vector 3D que almacenena los datos de la evolución del sistema en cada tiempo calculado, se toman los valores de las partículas en el instante actual de la simulación y se calcula 'max' con el estado de las partículas en dicho momento.
 * La función devuelve: el valor máximo en alguna componente de todas las partículas en el instante actual de evolución temporal.
*/

double range_adjust(std::vector<std::vector<std::vector<double>>> inits)
{
  double max = 0.0;
  int final_index = inits.size() - 1;
  for (unsigned int j = 0; j < inits[final_index].size(); j++) {
    for (int k = 1; k < 4; k++) {
      if(std::abs(inits[final_index][j][k]) > max)
	{
	  max = std::abs(inits[final_index][j][k]);
	}
    }
  }
  return max;
}

/*
 * Función auxiliar implementada para sumar de forma sencilla dos vectores -del mismo tamaño-.
 * La función recibe: recibe dos vectores del mismo tamaño
 * La función devuelve: un vector del mismo tamaño de los vectores ingresados el cual es la suma de ambos
*/

std::vector<double> AddVector(std::vector<double> v1, std::vector<double> v2)
{
  if(v1.size() != v2.size())
    {
      std::cout << "The vectors haven't the same size.\n";
      return std::vector<double>();
    }

  std::vector<double> result(v1.size());

  for(unsigned int ii = 0; ii < v1.size(); ++ii)
    {
      result[ii] = v1[ii] + v2[ii];
    }

  return result;
}

/*
 * La función está diseñada para arrancar el método de integración de Verlet, por lo que calcula el estado del sistema para el instante inmediatemente posterior a 0s y lo almacena.
 * La función recibe: El árbol para el instante de tiempo inicial, el arreglo 3D que almacena el estado del sistema en todos los instantes de tiempo, el tamaño del paso de tiempo.
 * La función devuelve: No devuelve nada, simplemente almacena el estado del sistema en el nuevo instante de tiempo en el arreglo dedicado para ello.
*/

void initialized(tree QT, std::vector<std::vector<std::vector <double>>> & p_inits, double dt)
{
  std::vector<std::vector<double>> result(p_inits[0].size(), std::vector<double>(7, 0.0));
  for(unsigned int ii = 0; ii < p_inits[0].size(); ++ii)
    {
      std::vector<double> aux = QT.get_acel(p_inits[0][ii]);
      result[ii][0] = p_inits[0][ii][0];
      result[ii][1] = p_inits[0][ii][1] + p_inits[0][ii][4]*dt + 0.5*aux[0]*dt*dt;
      result[ii][2] = p_inits[0][ii][2] + p_inits[0][ii][5]*dt + 0.5*aux[1]*dt*dt;
      result[ii][3] = p_inits[0][ii][3] + p_inits[0][ii][6]*dt + 0.5*aux[2]*dt*dt;
      result[ii][4] = p_inits[0][ii][4] + aux[0]*dt;
      result[ii][5] = p_inits[0][ii][5] + aux[1]*dt;
      result[ii][6] = p_inits[0][ii][6] + aux[2]*dt;
    }
  p_inits.push_back(result);
}

void integration(tree & QT, double ti, double tf, double dt, std::vector<std::vector<std::vector<double>>> & particles)
{
  int N = (tf - ti)/dt;
  for(int ii = 1; ii <= N; ++ii)
    {
      std::vector<std::vector<double>> result(particles[0].size());
      for(unsigned int jj; jj < particles[0].size(); ++jj)
	{
	  std::vector<double> aux = QT.get_acel(particles[ii][jj]);
	  result[jj][0] = particles[ii][jj][0];
	  result[jj][1] = 2*particles[ii][jj][1] - particles[ii-1][jj][1] + aux[0]*dt*dt;
	  result[jj][2] = 2*particles[ii][jj][2] - particles[ii-1][jj][2] + aux[1]*dt*dt;
	  result[jj][3] = 2*particles[ii][jj][3] - particles[ii-1][jj][3] + aux[2]*dt*dt;
	  result[jj][4] = (result[jj][1] - particles[ii-1][jj][1])/(2*dt);
	  result[jj][5] = (result[jj][2] - particles[ii-1][jj][2])/(2*dt);
	  result[jj][6] = (result[jj][3] - particles[ii-1][jj][3])/(2*dt);
	}
      particles.push_back(result);
      QT.update(particles);
    }
}

void init_gnuplot(void)
{
  std::cout << "set contour\n";
  std::cout << "set terminal gif animate\n";
  std::cout << "set out 'n_bodies.gif'\n";
}

void print_data(std::vector<std::vector<double>> data)
{
  for(unsigned int ii = 0; ii < data.size(); ++ii)
    {
      std::cout << data[ii][1] << " " <<data[ii][2] << " " <<data[ii][3] << "\n";
    }
  std::cout << "\n";
}

void plot_data(std::vector<std::vector<double>> data)
{
  std::cout << "splot '-' w p pt 7\n";
  print_data(data);
  std::cout << "e\n";
}

void animate_data(std::vector<std::vector<std::vector<double>>> h_data)
{
  for(unsigned int ii = 0; ii < h_data.size(); ++ii)
    {
      init_gnuplot();
      plot_data(h_data[ii]);
    }
}
