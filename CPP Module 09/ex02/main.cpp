#include "PmergeMe.hpp"

int main(int argc, char **argv) {
    bool flag = false;
    int tmp = -1;
    if ((argc - 1) % 2 != 0) {
        flag = true;
        tmp = std::atoi(argv[argc - 1]);
    if (tmp < 0)
        exit(1);
    }
    std::cout << "Before : "; 
    if (argc <= 6)
    {
        for (int i = 1; i < argc; i++)
            std::cout << argv[i] << " ";
    }
    else
    {
        for (size_t i = 1; i < 6; i++)
            std::cout << argv[i] << " ";
        std::cout << "[...]";
    }
    argc--;
    checkInput(argc, argv, flag, "std::vector", tmp);
    checkInput(argc, argv, flag, "std::deque", tmp);
}