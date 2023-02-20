#pragma once

#include <iostream>
#include <string>

class ClapTrap
{
    protected: 
        std::string name;
        unsigned int hp;
        unsigned int ep;
        unsigned int ad;

    public:
        ClapTrap(std::string name);
        ~ClapTrap();
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        void setHp(int hp);
        void setEp(int ep);
        void setAd(int ad);
        void setName(std::string name);
        std::string getName();
        int getHp();
        int getEp();
        int getAd();
};
