#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#pragma once

#include <algorithm>
#include <vector>
#include <iostream>
#include <list>
#include <stdexcept>
#include <iterator>

class NotAnIntegerException : public std::runtime_error {
public:
    NotAnIntegerException() : std::runtime_error("NotAnIntegerException") { }
    virtual const char* what() const throw() {
        return std::runtime_error::what();
    }
};

class TargetNotFoundException : public std::runtime_error {
public:
    TargetNotFoundException() : std::runtime_error("TargetNotFoundException") { }
    virtual const char* what() const throw() {
        return std::runtime_error::what();
    }
};



template <typename T>
typename T::size_type easyfind(const T& container, int find) {
    if (find > 2147483647 || find < -2147483648) {
        throw NotAnIntegerException();
    }
    
    typename T::const_iterator it = std::find(container.begin(), container.end(), find);
    if (it != container.end()) {
        return std::distance(container.begin(), it);
    } else {
        throw TargetNotFoundException();
    }
}


#endif