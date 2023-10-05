#include "easyfind.hpp"

int main() {
    try {
        std::vector<int> numbers1 = {1, 2, 3, 4, 5};

        int target1 = 3;
        auto result1 = easyfind(numbers1, target1);
        if(result1)
            std::cout << "Test 1: " << "Found " << target1 << std::endl;
    }
    catch (const TargetNotFoundException& e) {
        std::cerr << "Error 1: " << e.what() << std::endl;
    }
    catch (const NotAnIntegerException& e) {
        std::cerr << "Error 1: " << e.what() << std::endl;
    }

    try {
        std::vector<int> numbers2 = {1, 2, 3, 4, 5};

        int target2 = 6;
        auto result2 = easyfind(numbers2, target2);
        if(result2)
            std::cout << "Test 2: " << "Found " << target2 << std::endl;
    }
    catch (const TargetNotFoundException& e) {
        std::cerr << "Error 2: " << e.what() << std::endl;
    }
    catch (const NotAnIntegerException& e) {
        std::cerr << "Error 2: " << e.what() << std::endl;
    }
        
    try {
        std::list<int> myList = {10, 20, 30, 40, 50};
        int target3 = 20;
        auto result3 = easyfind(myList, target3);
        if(result3)
            std::cout << "Test 3: " << "Found " << target3 << std::endl;
    }
    catch (const TargetNotFoundException& e) {
        std::cerr << "Error 3: " << e.what() << std::endl;
    }
    catch (const NotAnIntegerException& e) {
        std::cerr << "Error 3: " << e.what() << std::endl;
    }

    try {
         std::vector<double> doubles = {1.0, 2.5, 3.7, 4.2};
        double target4 = 3.7;
        auto result4 = easyfind(doubles, target4); 
        if (result4)
            std::cout << "Test 4: " << "Found " << target4 << std::endl;
    } 
    catch (const TargetNotFoundException& e) {
        std::cerr << "Error 4: " << e.what() << std::endl;
    }
    catch (const NotAnIntegerException& e) {
        std::cerr << "Error 4: " << e.what() << std::endl; 
    }
    return 0;
}