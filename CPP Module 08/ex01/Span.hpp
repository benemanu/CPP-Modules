#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <exception>
#include <vector>
#include <cstddef>
#include <exception>
#include <algorithm>
#include <limits>
#include <ctime>
#include <iterator>

class SpanAlreadyFullException : public std::exception {
public:
    virtual const char* what() const throw() {
        return "The nubmer could not be added. The Span is already full!";
    }
};


class NotEnoughNumbersInSpanException : public std::exception {
public:
     virtual const char* what() const throw() {
        return "A longest or shortest Span couldnt be found, because there are not enough numbers in the Span!";
    }
};

class Span {
    private:
        Span(); 
		std::size_t _size;
        std::size_t _space;
    
    public: 
            
        Span(unsigned int n);
        Span(const Span &copy);
        ~Span();
        Span& operator= (const Span &assign);
        std::vector<int> _vector;
        void addNumbers(const std::vector<int>& values);
        void addNumber(int number);

        unsigned int shortestSpan();
        unsigned int longestSpan();

};

std::vector<int> generateRandomIntegers(int n, int min, int max);

#endif