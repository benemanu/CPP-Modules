#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <vector>
#include <list>

template <typename T>
class MutantStack: public std::stack<T> {
    private: 
        std::stack<T> stack;

    public: 
        MutantStack();
        MutantStack(const MutantStack& copy);
        MutantStack &operator=(const MutantStack& assign);
        ~MutantStack();

        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;

        iterator begin() { return std::stack<T>::c.begin();}
        iterator end() { return std::stack<T>::c.end();}
        iterator const_begin() { return std::stack<T>::c.const_begin();}
        iterator const_end() { return std::stack<T>::c.const_end();}
};

template <typename T>
MutantStack<T>::MutantStack() {
}

template <typename T>
MutantStack<T>::~MutantStack() {
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &copy) {
    *this = copy;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &assign)  {
    if(this != &assign)
        this->c = assign.c;
    return *this;
}

#endif