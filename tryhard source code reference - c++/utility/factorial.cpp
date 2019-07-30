#include "factorial.h"

unsigned GetFactorial(unsigned N_)
{
  unsigned value = 1;
  while(N_)
    value *= N_--;
  return value;
}

//#include <iostream>
//#define _TEST_THIS 1

#ifdef _TEST_THIS

/* Recursive */
unsigned FactorialRecursive(unsigned N_)
{
  if(N_ <= 1) return 1;

  return FactorialRecursive(N_- 1) * N_;
}

/* Iterative forloop */
unsigned FactorialItreativeFor(unsigned N_)
{
  unsigned value = 1;
  for(unsigned i = N_; i > 1; --i)
  {
    value *= N_;
    --N_;
  }
  return value;
}

/* Iterative while */
unsigned FactorialItreativeWhile(unsigned N_)
{
  unsigned value = 1;
  while(N_)
    value *= N_--;
  return value;
}

int main()
{
  std::cout << Factorial<0>::val  << " " << FactorialRecursive(0)  << " " << FactorialItreativeWhile(0) << " " << FactorialItreativeFor(0) << std::endl;
	std::cout << Factorial<1>::val  << " " << FactorialRecursive(1)  << " " << FactorialItreativeWhile(1) << " " << FactorialItreativeFor(1) << std::endl;
  std::cout << Factorial<2>::val  << " " << FactorialRecursive(2)  << " " << FactorialItreativeWhile(2) << " " << FactorialItreativeFor(2) << std::endl;	
  std::cout << Factorial<3>::val  << " " << FactorialRecursive(3)  << " " << FactorialItreativeWhile(3) << " " << FactorialItreativeFor(3) << std::endl;	
  std::cout << Factorial<10>::val << " " << FactorialRecursive(10) << " " << FactorialItreativeWhile(10)<< " " << FactorialItreativeFor(10) << std::endl;
}

#endif