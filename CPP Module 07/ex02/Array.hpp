#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>
#include <iostream>
#include <ostream>
#include <exception>
#include <vector>

template <class T> 
class Array {
    private:

    T*              _elements;
    unsigned int    _size;

    public:

    Array() : _elements(NULL), _size(0) {}

    Array(unsigned int n) {
        _size = n;
        _elements = new T[n];
        for(unsigned int i = 0; i < n; i++)
            _elements[i] = T();
    }

    Array(const Array &copy) {
        _size = copy._size;
        _elements = new T[_size];
        for (unsigned int i = 0; i < _size; i++ ){
            _elements[i] = copy._elements[i];
        }
    }

    ~Array() {
        delete[]_elements;
    }

    Array& operator=(const std::vector<T>& initList) {
        delete[] _elements;
        
        _size = initList.size();

        _elements = new T[_size];
        std::copy(initList.begin(), initList.end(), _elements);

        return *this;
    }

    T &operator[](unsigned int index) {
        if (index < _size)
            return (_elements[index]);
        else
            throw ArrayNotAccessible();
    }
    
    class ArrayNotAccessible: public std::exception {
		virtual const char *what() const throw() {
			return ("The Array is not Accessible.");
		}
	};

    void printArray() {
        for (unsigned int i = 0; i < _size; i++) {
        std::cout << _elements[i] << " ";
    }
    std::cout << std::endl;
    }

    void size() {
        unsigned int i = 0;
        while(i < this->_size)
            i++;
        std::cout << i << std::endl;
    }
};

#endif