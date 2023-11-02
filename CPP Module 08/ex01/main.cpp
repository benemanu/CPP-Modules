#include "Span.hpp"

int main() {

    try {
    std::vector<int> numbers1 = generateRandomIntegers(100, 0, 100000);
    Span span1(10000);
    span1.addNumbers(numbers1);
    
    std::cout << span1.shortestSpan() << std::endl;
    std::cout << span1.longestSpan() << std::endl;
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "shortest: " << sp.shortestSpan() << std::endl;
        std::cout << "longest: " << sp.longestSpan() << std::endl;
    }
    catch (const std::exception& e){
        std::cerr << e.what() << std::endl;
    }

    return (0);
}