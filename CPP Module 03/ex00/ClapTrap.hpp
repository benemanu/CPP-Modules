#pragma once

#include <iostream>
#include <string>

class ClapTrap
{
    private: 
        std::string name;
        int hp;
        int ep;
        int ad;

    public:
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap& copy);
        ClapTrap& operator=(const ClapTrap& copy);
        ~ClapTrap();
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount); 
};
