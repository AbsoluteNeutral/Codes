/*
  Ref collasping Rule:
  &   &  -> &
  &   && -> &
  &&  &  -> &
  &&  && -> &&
  
  Link:
  https://stackoverflow.com/questions/13725747/concise-explanation-of-reference-collapsing-rules-requested-1-a-a-2
*/
  
namespace zg
{
  /*
    default parent class
  */
  template<typename T>
  struct remove_ref
  {
    using type = T;
  };
  
  /*
    specialize class to remove T&& 
  */
  template<typename T>
  struct remove_ref<T&&>
  {
    using type = T;
  };
  
  /*
    specialize class to remove T& 
  */
  template<typename T>
  struct remove_ref<T&>
  {
    using type = T;
  };
  
  
  /*
    forward lvalue as lvalue,
    forward rvalue as rvalue
  */
  template<typename T>
  //T&& forward(T& value)
  T&& forward(typename remove_ref<T>::type& value)
  {
    /* 
    Note:
      "typename remove_ref<T>::type" is a non-deduce context,
      forcing the function template to "act" like a class template.
      It's a design as it's forces the user to take note of perfect forwarding
      such as <obj>, <obj&>, <obj&&>
      
      T&& forward(typename remove_ref<T>::type& value) can be just written as
      T&& forward(T& value) and it will work.
      
    More explaination/examples:
    https://stackoverflow.com/questions/25245453/what-is-a-nondeduced-context
    
    example deduction
      eg.1
      if:       forward<obj1&>(arg) is passed,    
      deduce:   T is obj1&,
      deduce:   remove_ref<obj1&>::type = obj1 
      deduce:   value is now of type obj1& 
      returning
      deduce:   return static_cast<T &&>(value);
      deduce:   return static_cast<obj1& &&>(value);
      into->    return static_cast<obj1&>(value);    (lvalue)
      
      eg.2
      if:       forward<obj1>(arg) is passed,     
      deduce:   T is obj1,
      deduce:   remove_ref<obj1>::type = obj1 
      deduce:   value is now of type obj1& 
      returning
      deduce:   return static_cast<T &&>(value);
      deduce:   return static_cast<obj1 &&>(value);
      into->    return static_cast<obj1&&>(value);    (rvalue)
      
      eg.3
      if:       forward<obj1&&>(arg) is passed,     
      deduce:   T is obj1&&,
      deduce:   remove_ref<obj1>::type = obj1 
      deduce:   value is now of type obj1& 
      returning
      deduce:   return static_cast<T &&>(value);
      deduce:   return static_cast<obj1&& &&>(value);
      into->    return static_cast<obj1&&>(value);    (rvalue)
    */
    return static_cast<T&&>(value);
  }
  
  /*
    make lvalue or rvalue move to a rvalue
  */
  template<typename T>
  typename remove_ref<T>::type&& move(T&& value) noexcept
  {
    typedef typename remove_ref<T>::type&& rvalueref;
    return static_cast<rvalueref>(value);
  }
}
