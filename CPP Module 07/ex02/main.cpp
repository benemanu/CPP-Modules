#include "Array.hpp"

int main(void) {

    Array<int> intArray0(5);
    intArray0 = {1, 3, 2, 5, 4};
    intArray0.printArray();
    intArray0.size();
    
    Array<int> intArray1(5);
    intArray1[1] = 3;
    intArray1.printArray();
    intArray1.size();

    Array<int> intArray2(intArray1);
    intArray2.printArray();
    intArray2.size();
    intArray2 = {42, 39, 36, 33, 30};
    intArray2.printArray();
    intArray2.size();
    
    Array<int> intArray3 = intArray2;
    intArray3.printArray();
    std::cout << intArray3[3] << std::endl;
    std::cout << intArray3[6] << std::endl;

    return ( 0 );
    
}