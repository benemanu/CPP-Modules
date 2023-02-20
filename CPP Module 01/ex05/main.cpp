
#include "Harl.hpp"

int main()
{
    int i;
    Harl harl;
    std::string level;

    while (1)
    {
        i = -1;
        std::cout << "Enter a level: ";
        std::cin >> level;
        while (level[++i])
            level[i] = toupper(level[i]);
        if (level == "EXIT")
            break;
        harl.complain(level);
    }
}