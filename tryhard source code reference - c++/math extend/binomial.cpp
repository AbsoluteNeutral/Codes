#include "binomial.h"

unsigned GetnCr(unsigned N_, unsigned R_)
{
  return GetFactorial(N_) / (GetFactorial(N_-R_) * GetFactorial(R_));
}

//#define _TEST_THIS 1
//#include <iostream>

#ifdef _TEST_THIS

/* Print Vector, only works for classes with 
  std::os& opeartor<<(std::ostream& os_, const class& classname_) 
  overload 
*/
template<typename T>
void PrintVector(const std::vector<T>& vec_)
{
  for(const auto& elem :vec_) 
  {
    std::cout << elem << " ";
  }
  std::cout << std::endl;
}

int main()
{
  PrintVector(GetBinomialSequence(0));
  PrintVector(GetBinomialSequence(1));
  PrintVector(GetBinomialSequence(2));
  PrintVector(GetBinomialSequence(3));
  PrintVector(GetBinomialSequence(4));
  PrintVector(GetBinomialSequence(5));
  PrintVector(GetBinomialSequence(6));
  PrintVector(GetBinomialSequence(7));
  PrintVector(GetBinomialSequence(8));
  PrintVector(GetBinomialSequence(9));
  PrintVector(GetBinomialSequence(10));
  
  std::cout << nCr<0, 0>::val << std::endl;
  std::cout << nCr<1, 0>::val << " " << nCr<1, 1>::val << std::endl;
  std::cout << nCr<2, 0>::val << " " << nCr<2, 1>::val << " " << nCr<2, 2>::val << std::endl;
  std::cout << nCr<3, 0>::val << " " << nCr<3, 1>::val << " " << nCr<3, 2>::val << " " << nCr<3, 3>::val << std::endl;
  std::cout << nCr<4, 0>::val << " " << nCr<4, 1>::val << " " << nCr<4, 2>::val << " " << nCr<4, 3>::val << " " << nCr<4, 4>::val << std::endl;

  std::cout << GetnCr(0, 0) << std::endl;
  std::cout << GetnCr(1, 0) << " " << GetnCr(1, 1) << std::endl;
  std::cout << GetnCr(2, 0) << " " << GetnCr(2, 1) << " " << GetnCr(2, 2) << std::endl;
  std::cout << GetnCr(3, 0) << " " << GetnCr(3, 1) << " " << GetnCr(3, 2) << " " << GetnCr(3, 3) << std::endl;
  std::cout << GetnCr(4, 0) << " " << GetnCr(4, 1) << " " << GetnCr(4, 2) << " " << GetnCr(4, 3) << " " << GetnCr(4, 4) << std::endl;

}

#endif
