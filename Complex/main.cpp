#include "complex.hpp"
#include <iostream>

int main(void)
{
  complex a(1.0, 1.0);
  complex b(a.module(), a.arg());

  complex c = exp(a), d = exp(b);
  
  std::cout << c/d << '\n';
  
  return 0;
}
