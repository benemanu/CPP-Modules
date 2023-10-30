#include "PmergeMe.hpp"

int main(int argc, char **argv) {
    if (argc == 2)
        checkInputTwoArgs(argv[1]);
    else if (argc > 2) {
        for (int i = 0; i < argc - 1; i++) {

        }
    }
    else
        std::cout << "Error: Too Few Arguments!" << std::endl;
}