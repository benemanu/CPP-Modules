
#include "Strrep.hpp"

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Error: Invalid number of arguments" << std::endl;
        return (1);
    }
    Strrep s(argv[1]);
    s.myreplace(argv[2], argv[3]);
    return (0);
}