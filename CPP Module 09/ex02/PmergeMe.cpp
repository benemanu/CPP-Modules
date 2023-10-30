#include "PmergeMe.hpp"

void checkInputTwoArgs(std::string input) {
    std::list<int> _list;
    std::vector<int> _vector;

    _vector = inputToVector(input);

    sortVector(_vector, 0, _vector.size() - 1);

    for (int num : _vector) {
        std::cout << num << " ";
    }
}

std::vector<int> inputToVector(std::string input) {
    std::istringstream iss(input);
    std::vector<int> numbers;

    int number;
    while(iss >> number) {
        numbers.push_back(number);
    }
    // for (int num : numbers) {
    //     std::cout << num << " ";
    // }
    // std::cout << std::endl;
    return numbers;
}

void sortVector(std::vector<int>& _vector, int const start, int const end) {
    if (start >= end)
        return;
    
    int mid = start + (end - start) / 2;

        sortVector(_vector, start, mid);
        sortVector(_vector, mid + 1, end);
        mergeVector(_vector, start, mid, end);
}

void mergeVector(std::vector<int>& _vector, int const start, int const mid, int const end) {
    int const n1 = mid - start + 1;
    int const n2 = end - mid;

    std::vector<int> startVec(n1);
    std::vector<int> endVec(n2);

    for (int i = 0; i < n1; i++) {
        startVec[i] = _vector[start + i];
    }
    for (int j = 0; j < n2; j++) {
        endVec[j] = _vector[mid + j];
    }

    int i = 0;
    int j = 0;
    int k = start;
    while (i < n1 && j < n2) {
        if (startVec[i] <= endVec[j]) 
            _vector[k] = startVec[i++];   
        else
            _vector[k] = endVec[j++];
        k++;
    }
    while (i < n1) {
        _vector[k] = startVec[i];
        i++;
        k++;
    }

    while (j < n2) {
        _vector[k] = startVec[j];
        j++;
        k++;
    }
}