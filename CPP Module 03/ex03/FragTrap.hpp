#pragma once

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
    private: 
        FragTrap();

    public:
        FragTrap(std::string name);
        FragTrap(const FragTrap& copy);
        FragTrap& operator=(const FragTrap& copy);
        ~FragTrap();
        void highFive();
};