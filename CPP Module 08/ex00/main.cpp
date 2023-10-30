#include "easyfind.hpp"

int main() {
    try {
        std::vector<int> numbers1;
        for(int i = 1; i < 6; i++)
            numbers1.push_back(i);

        int target1 = 3;
        std::vector<int>::size_type result1  = easyfind(numbers1, target1);
        if(result1 != numbers1.size())
            std::cout << "Test 1: " << "Found " << target1 << " at position " << result1 << std::endl;
    }
    catch (const TargetNotFoundException& e) {
        std::cerr << "Error 1: " << e.what() << std::endl;
    }
    catch (const NotAnIntegerException& e) {
        std::cerr << "Error 1: " << e.what() << std::endl;
    }

    try {
        std::vector<int> numbers2;
        for(int i = 1; i < 6; i++)
            numbers2.push_back(i);

        int target2 = 6;
        std::vector<int>::size_type result2 = easyfind(numbers2, target2);
        if(result2 != numbers2.size())
            std::cout << "Test 2: " << "Found " << target2 << " at position " << result2 << std::endl;
    }
    catch (const TargetNotFoundException& e) {
        std::cerr << "Error 2: " << e.what() << std::endl;
    }
    catch (const NotAnIntegerException& e) {
        std::cerr << "Error 2: " << e.what() << std::endl;
    }
        
    try {
        std::list<int> myList;
        for(int i = 10; i < 60; i += 10 )
            myList.insert(myList.begin(), i);
        int target3 = 20;
        std::list<int>::size_type result3 = easyfind(myList, target3);
        if(result3 != myList.size())
            std::cout << "Test 3: " << "Found " << target3 << " at position " << result3 << std::endl;
    }
    catch (const TargetNotFoundException& e) {
        std::cerr << "Error 3: " << e.what() << std::endl;
    }
    catch (const NotAnIntegerException& e) {
        std::cerr << "Error 3: " << e.what() << std::endl;
    }

    try {
        std::vector<double> doubles;
        doubles.push_back(1.0);
        doubles.push_back(2.5);
        doubles.push_back(3.7);
        doubles.push_back(4.2);
        double target4 = 3.7;
        std::vector<double>::size_type result4 = easyfind(doubles, target4); 
        if (result4 != doubles.size())
            std::cout << "Test 4: " << "Found " << target4 << " at position " << result4 << std::endl;
    } 
    catch (const TargetNotFoundException& e) {
        std::cerr << "Error 4: " << e.what() << std::endl;
    }
    catch (const NotAnIntegerException& e) {
        std::cerr << "Error 4: " << e.what() << std::endl; 
    }
    return 0;
}
