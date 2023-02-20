
#include "Harl.hpp"

Harl::Harl()
{
    return;
}

Harl::~Harl()
{
    return;
}

void    Harl::debug(void)
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special burger. I really do!" << std::endl;
}

void    Harl::info(void)
{
    std::cout << "I cannot believe adding extra bacon cost more money. You don't put enough! If you did I would not have to ask for it!" << std::endl;
}

void    Harl::warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month!" << std::endl;
}

void    Harl::error(void)
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void    Harl::complain(std::string level)
{
    int i = 0;
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    while (level != levels[i] && i < 3)
        i++;
    if (i == 3 && level != "ERROR")
        i++;
   switch (i)
    {
        case DEBUG:
            Harl::debug();
        case INFO:
            Harl::info();
        case WARNING:
            Harl::warning();
        case ERROR:
            Harl::error();
            break;
        case 4:
            std::cout << "[ Hes probably complaining about unsignificant problems ]" << std::endl;
        break;
    }
}