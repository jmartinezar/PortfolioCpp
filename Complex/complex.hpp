#pragma once

#include <iostream>
#include <cmath>

#pragma pack(push, 1)

class complex
{
 public:
  double real, imag;
 public:
  
 complex(): real(0.0), imag(0.0) {};
 complex(double _real, double _imag): real(_real), imag(_imag) {};
  
  double module();
  double arg();
  double Re();
  double Im();

  // Overwrite + operator

  template<typename T>
  complex operator+(const T value) const;
  
  complex operator+(const complex & value) const;
  
  template<typename T>
  friend complex operator+(T value, const complex& c);

  // Overwrite - operator
  
  template<typename T>
  complex operator-(const T value) const;
  
  complex operator-(const complex & value) const;

  template<typename T>
  friend complex operator-(T value, const complex& c);

  // Overwrite * operator
  
  template<typename T>
  complex operator*(const T value) const;
  
  complex operator*(const complex & value) const;

  template<typename T>
  friend complex operator*(T value, const complex& c);

  // Overwrite / operator
  
  template <typename T>
    complex operator/(const T value) const;
  
  complex operator/(const complex & value) const;

  template<typename T>
  friend complex operator/(T value, const complex& c);

  // Overwrite = operator
  
  complex & operator=(const complex & c);

  // Overwrite the strandart output

  friend std::ostream & operator<<(std::ostream & os, const complex & c);

  friend complex exp(const complex & c);

  /*
  template<typename SE>
  complex operator+=(const SE value);
  complex operator+=(const complex & value);
  friend complex operator+=(SE value, const complex& c);

  template<typename RE>
  complex operator-=(const RE value);
  complex operator-=(const complex & value);
  friend complex operator-=(RE value, const complex& c);

  template<typename ME>
  complex operator*=(const ME value);
  complex operator*=(const complex & value);
  friend complex operator*=(ME value, const complex& c);

  template<typename DE>
  complex operator/=(const DE value);
  complex operator/=(const complex & value);
  friend complex operator/=(DE value, const complex& c);
  */
};

#pragma pack(pop)
