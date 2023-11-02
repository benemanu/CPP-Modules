#include "Span.hpp"

Span::Span() {}

Span::Span(unsigned int n) {
    _space = n;
    _size = 0;
}

Span::Span(const Span& copy) : _size(copy._size), _space(copy._space) {
    _vector = copy._vector;
}

Span::~Span() {}

Span& Span::operator=(const Span& assign) {
    if (this != &assign) {
        _size = assign._size;
        _space = assign._space;
        _vector = assign._vector;
    }
    return *this;
}

void Span::addNumber(int number) {
    size_t spaceLeft = this->_space - this->_size;
    if (spaceLeft > 0) {
        this->_vector.push_back(number);
    }
    else
        throw SpanAlreadyFullException();
}

void Span::addNumbers(const std::vector<int>& values) {
    size_t spaceLeft = this->_space - this->_size;
    if (spaceLeft > 0) {
    std::vector<int> nonConstValues(values.begin(), values.end());
    std::vector<int>::iterator it = nonConstValues.begin();
    while (spaceLeft > 0 && it != nonConstValues.end()) {
        this->_vector.push_back(*it);
        this->_size++;
        spaceLeft--;
        it = nonConstValues.erase(it);
    }
    if (nonConstValues.size() > 0)
        throw SpanAlreadyFullException();
}   
    else
        throw SpanAlreadyFullException();
}

unsigned int Span::shortestSpan() {
    if (this->_vector.size() < 2)
        throw NotEnoughNumbersInSpanException();
    
    int minSpan = std::numeric_limits<int>::max();

    for (size_t i = 0; i < this->_vector.size(); ++i) {
        for (size_t j = i + 1; j < this->_vector.size(); ++j) {
            int span = std::abs(this->_vector[i] - this->_vector[j]);
            minSpan = std::min(minSpan, span);
        }
    }

    return minSpan;
    
}

unsigned int Span::longestSpan() {
    if (this->_vector.size() < 2)
        throw NotEnoughNumbersInSpanException();

    int maxSpan = std::numeric_limits<int>::min();

    for (size_t i = 0; i < this->_vector.size(); ++i) {
        for (size_t j = i + 1; j < this->_vector.size(); ++j) {
            int span = std::abs(this->_vector[i] - this->_vector[j]);
            maxSpan = std::max(maxSpan, span);
        }
    }

    return maxSpan;
    
}


std::vector<int> generateRandomIntegers(int n, int min, int max) {
    std::vector<int> randomNumbers;
    srand(static_cast<unsigned>(std::time(0)));  // Seed the random number generator

    for (int i = 0; i < n; ++i) {
        int randomValue = min + (std::rand() % (max - min + 1));
        randomNumbers.push_back(randomValue);
    }
    return randomNumbers;
}