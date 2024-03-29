#include "Array.hpp"

int main(void) {

    std::cout << "Array" << std::endl;
    try {
        Array<int> intArray(0);
        intArray.printArray();
        intArray.size();
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "Array0" << std::endl;
    try {
        Array<int> intArray0(5);
        intArray0[0] = 1;
        intArray0[1] = 3;
        intArray0[2] = 2;
        intArray0[3] = 5;
        intArray0[4] = 4;
        intArray0.printArray();
        intArray0.size();
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    } 

    std::cout << "Array1" << std::endl;
    Array<int> intArray1(5);
    try {
        intArray1[2] = 3;
        intArray1.printArray();
        intArray1.size();
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    } 

    std::cout << "Array2" << std::endl;
    Array<int> intArray2(intArray1);
    int j = 0;
    try {
        intArray2.printArray();
        intArray2.size();
        for(int i = 42; i >= 30; i-= 3)
            intArray2[j++] = i;
        intArray2.printArray();
        intArray2.size();
        }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "Array3" << std::endl;
    try {
        Array<int> intArray3 = intArray2;
        intArray3.printArray();
        std::cout << intArray3[3] << std::endl;
        std::cout << intArray3[6] << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    
    

    return ( 0 );
    
}