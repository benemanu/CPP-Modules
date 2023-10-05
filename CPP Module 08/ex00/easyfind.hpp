#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#pragma once

#include <algorithm>
#include <vector>
#include <iostream>
#include <list>
#include <stdexcept>

class TargetNotFoundException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Target not found in the container.";
    }
};

class NotAnIntegerException : public std::exception {
public:
    const char* what() const noexcept override {
        return "The searched number is not an Integer";
    }
};

template <typename T>
bool easyfind(const T& container, int find) {
    if (find > 2147483647 && find < (-2147483648))
        throw NotAnIntegerException();
    auto result = std::find(container.begin(), container.end(), find);
    if (result != container.end()) {
        return true;
    } else {
        throw TargetNotFoundException();
    }
}


#endif