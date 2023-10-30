#include "ScalarConverter.hpp"

int main( int argc, char **argv )
{
    if ( argc != 2 ) {
        std::cout << "Usage: ./convert number" << std::endl;
        return EXIT_FAILURE;
    }

    try {
        ScalarConverter::convert(argv[1]);
    }
    catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}