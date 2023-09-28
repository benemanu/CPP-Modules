#ifndef ITER_HPP
#define ITER_HPP

#include <stdlib.h>
#include <iostream>

template<class T> void	print(T& element) {
	std::cout << element << std::endl;
}


template <class T> void iter(T *addr, size_t length, void(*function)(T& element)) {
    for (size_t i = 0; i < length; i++) {
        function(addr[i]);
    }
}

#endif