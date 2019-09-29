#include <stdio.h>
#include "concepts.h"

namespace zg{
    template<typename T, typename P = typename enable_if<is_not_class<T>::value >::type>
    //template<typename T>
    void isParamNotAClass(T number)
    {
    	printf("T is Not a User Defined type\n");
    }

    template<typename T, typename P = typename enable_if<is_integral<T>::value >::type>
    void isParamIntegral(T number)
    {
    	printf("T is Integral\n");
    }
    
    template<typename T, typename P = typename enable_if<is_floating_point<T>::value >::type>
    void isParamFloat(T number)
    {
    	printf("T is Floating point\n");
    }
    struct A{};
}


int main()
{

#ifdef _TEST_IS_NOT_CLASS_H_
    zg::isParamNotAClass(10);

    //compile error
    //zg::isParamNotAClass(zg::A());
#endif

#ifdef _TEST_IS_INTEGRAL_H_
    zg::isParamIntegral(10);

    //compile error
    //zg::isParamIntegral(10.0f); 
#endif

#ifdef _TEST_IS_FLOATING_POINT_H_
    zg::isParamFloat(10.0f);
    zg::isParamFloat(10.0);

    //compile error
    //zg::isParamFloat(10); 
#endif
}
