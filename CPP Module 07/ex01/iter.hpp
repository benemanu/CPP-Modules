#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <ostream>

template< typename T >
void printElement( T& x )
{
  std::cout << x << std::endl;
  return;
}


template <typename T, typename T2> 
void iter(T *addr, int length, void(*function)(T2&)) {
    for (int i = 0; i < length; i++) {
        function(addr[i]);
    }
}

#endif