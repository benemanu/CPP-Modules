#include "Span.hpp"

int main() {

    std::vector<int> numbers1 = generateRandomIntegers(1000, 0, 1000);
    Span span1(10000);
    span1.addNumbers(numbers1);
    std::cout << span1.shortestSpan() << std::endl;
    std::cout << span1.longestSpan() << std::endl;
    Span span2(10);

    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << "shortest: " << sp.shortestSpan() << std::endl;
    std::cout << "longest: " << sp.longestSpan() << std::endl;

    return (0);
}