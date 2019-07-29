#include <iostream>
#include <vector>

/* Templated */
template<unsigned N>
struct Fibonacci
{
  constexpr static unsigned val = Fibonacci<N-2>::val + Fibonacci<N-1>::val;
};
template<>
struct Fibonacci<1>
{
  constexpr static unsigned val = 1;
};
template<>
struct Fibonacci<0>
{
  constexpr static unsigned val = 0;
};

/* Recursive */
unsigned FibonacciRecursive(unsigned N)
{
  if(N == 0) return 0;
  if(N == 1) return 1;
  return FibonacciRecursive(N-2) + FibonacciRecursive(N-1);
}

/* Iterative forloop */
unsigned FibonacciItreativeFor(unsigned N)
{
  if(N == 0) return 0;
  if(N == 1) return 1;
  unsigned fib0 = 0;
  unsigned fib1 = 1;
  unsigned tmp  = fib1;
  for(unsigned i = 2; i < N; ++i)
  {
    tmp  = fib1;
    fib1 += fib0;
    fib0 = tmp;
  }
  return fib0 + fib1;
}

/* Iterative while */
unsigned FibonacciItreativeWhile(unsigned N)
{
  if(N == 0) return 0;
  if(N == 1) return 1;
  unsigned fib0 = 0;
  unsigned fib1 = 1;
  unsigned tmp  = fib1;
  --N;
  while(--N)
  {
    tmp  = fib1;
    fib1 += fib0;
    fib0 = tmp;
  }
  return fib0 + fib1;
}

/* Get Sequences */
//std::vector<int> GetFibonacciSequence(unsigned N, bool startsFrom0_)
std::vector<int> GetFibonacciSequence(unsigned N)
{
  std::vector<int> tmp;
  //if(startsFrom0_)
  {
    //starts from 0
    tmp.reserve(N + 1);
    tmp.push_back(0);
    if(N == 0) return tmp;
    tmp.push_back(1);
    if(N == 1) return tmp;
    tmp.push_back(1);
    if(N == 2) return tmp;
    
    N -= 2;
    auto e = tmp.end();
    while(N--)
    {
      tmp.push_back( *(e-2) + *(e-1) );
      e = tmp.end();
    }
  }
  //else 
  {
    ////starts from 1
    //tmp.reserve(N );
    //tmp.push_back(1);
    //if(N == 0) return tmp;
    //tmp.push_back(1);
    //if(N == 1) return tmp;
    //
    //N -= 1;
    //auto e = tmp.end();
    //while(N--)
    //{
    //  tmp.push_back( *(e-2) + *(e-1) );
    //  e = tmp.end();
    //}
  }
  return tmp;
}

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
  std::cout << Fibonacci<0>::val  << " " << FibonacciRecursive(0)  << " " << FibonacciItreativeWhile(0) << " " << FibonacciItreativeFor(0) << std::endl;
	std::cout << Fibonacci<1>::val  << " " << FibonacciRecursive(1)  << " " << FibonacciItreativeWhile(1) << " " << FibonacciItreativeFor(1) << std::endl;
  std::cout << Fibonacci<2>::val  << " " << FibonacciRecursive(2)  << " " << FibonacciItreativeWhile(2) << " " << FibonacciItreativeFor(2) << std::endl;	
  std::cout << Fibonacci<3>::val  << " " << FibonacciRecursive(3)  << " " << FibonacciItreativeWhile(3) << " " << FibonacciItreativeFor(3) << std::endl;	
  std::cout << Fibonacci<10>::val << " " << FibonacciRecursive(10) << " " << FibonacciItreativeWhile(10)<< " " << FibonacciItreativeFor(10) << std::endl;

  auto get = GetFibonacciSequence(10);
  PrintVector(get);
}
