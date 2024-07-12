#include "complex.hpp"
#include <cmath>

double complex::module()
{
  return std::sqrt(real*real+imag*imag);
}

double complex::arg()
{
  return std::atan2(imag, real);
}

double complex::Re()
{
  return real;
}

double complex::Im()
{
  return imag;
}

template<typename T>
complex complex::operator+(const T value) const
{
  return complex(real + value, imag);
}

complex complex::operator+(const complex & value) const
{
  return complex(real + value.real, imag + value.imag);
}

template<typename T>
complex operator+(T value, const complex& c)
{
  return complex(value + c.real, c.imag);
}

template<typename T>
complex complex::operator-(const T value) const
{
  return complex(real - value, imag);
}
  
complex complex::operator-(const complex & value) const
{
  return complex(real - value.real, imag - value.imag);
}

template<typename T>
complex operator-(T value, const complex& c)
{
  return complex(value - c.real, -c.imag);
}

template<typename T>
complex complex::operator*(const T value) const
{
  return complex(real*value, imag*value);
}
  
complex complex::operator*(const complex & value) const
{
  return complex(real*value.real - imag*value.imag, imag*value.imag + real*value.imag);
}

template<typename T>
complex operator*(T value, const complex& c)
{
  return complex(value*c.imag, value*c.imag);
}

template<typename T>
complex complex::operator/(const T value) const
{
  return complex(real/value, imag);
}
  
complex complex::operator/(const complex & value) const
{
  double n2 = value.real*value.real + value.imag*value.imag;
  return complex((real*value.real + imag*value.imag)/n2, (imag*value.real - real*value.imag)/n2);
}

template<typename T>
complex operator/(T value, const complex& c)
{
  double n2 = c.real*c.real + c.real*c.real;
  return complex(value*c.real/n2, value*c.imag/n2);
}

// Overwrite out stream

std::ostream & operator<<(std::ostream & os, const complex & c)
{
  os << c.real << "+" << c.imag << "i";
  return os;
}

// Overwrite = operator
  
complex & complex::operator=(const complex & c)
{
  if(this != &c)
    {
      real = c.real;
      imag = c.imag;
    }
  return *this;
}

complex exp(const complex & c)
{
  return complex(std::exp(c.real)*std::cos(c.imag), std::exp(c.real)*std::sin(c.imag));
}
