#ifndef _ZG_FACTORIAL_H
#define _ZG_FACTORIAL_H

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

unsigned GetFibonacci(unsigned N);

/* Get Sequences */
//std::vector<int> GetFibonacciSequence(unsigned N, bool startsFrom0_)
template<typename T = unsigned>
std::vector<T> GetFibonacciSequence(unsigned N)
{
  std::vector<T> tmp;
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

#endif //_ZG_FACTORIAL_H
