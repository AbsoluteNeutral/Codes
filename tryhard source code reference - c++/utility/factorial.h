#ifndef _ZG_FACTORIAL_H
#define _ZG_FACTORIAL_H

/* Templated */
template<unsigned N_>
struct Factorial
{
  constexpr static unsigned val = Factorial<N_-1>::val * N_;
};
template<>
struct Factorial<1>
{
  constexpr static unsigned val = 1;
};
template<>
struct Factorial<0>
{
  constexpr static unsigned val = 1;
};

unsigned GetFactorial(unsigned N_);

#endif //#ifndef _ZG_FACTORIAL_H
