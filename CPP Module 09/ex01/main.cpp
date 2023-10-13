#include "RPN.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Error: Wrong Input, Need exactly 2 arguments!" << std::endl;
        exit (1);
    }
    try {
        checkInput(argv[1]);
    }
    catch (const std::exception &e){
        std::cerr << e.what() << std::endl;
    }
           
}