#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Error: wrong amount of Arguments!" << std::endl;
        exit(1);
    }
    std::map<std::string, double> _data = readFile();
    inputChecker(argv[1], _data);
    return 0;
}