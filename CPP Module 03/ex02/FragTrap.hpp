#pragma once

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    private: 
        FragTrap();

    public:
        FragTrap(std::string name);
        ~FragTrap();
        void highFive();
};