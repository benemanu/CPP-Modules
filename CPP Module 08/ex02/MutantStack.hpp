#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <vector>

template <typename T>
class MutantStack: public std::stack<T> {
    public: 
        using std::stack<T>::c;

    std::iterator iterator = typename std::stack<T>::container_type::iterator;
    std::iterator const_iterator = typename std::stack<T>::container_type::const_iterator;

    iterator begin() { return c.begin(); }
    iterator end() { return c.end(); }
    
};

#endif