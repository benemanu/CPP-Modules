
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
    setHp(10);
    setEp(10);
    setAd(0);
    setName(name);
    std::cout << "ClapTrap " << this->name << " has been constructed" << std::endl; 
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << this->name << " has been destroyed" << std::endl; 
    return;
}

void ClapTrap::attack    (const std::string& target)
{
    if (this->ep <= 0)
        std::cout << this->name << " has no energy left" << std::endl;
    else
    {
        std::cout << this->name << " attacks " << target << " causing " << this->ad << " damage" << std::endl;
        this->ep -= 1;
    }
    return;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    this->hp -= amount;
    std::cout << this->name << " has taken " << amount << " damage" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->ep <= 0)
        std::cout << this->name << " has no energy left" << std::endl;
    else
    {
        this->hp += amount;
        this->ep -= 1;
        std::cout << this->name << " has repaired "  << amount << " Health Points." << std::endl;
        std::cout << this->name << " currently has " << this->hp << " Health Points." << std::endl;
    }
}

void ClapTrap::setHp(int hp)
{
    this->hp = hp;
}

void ClapTrap::setEp(int ep)
{
    this->ep = ep;
}

void ClapTrap::setAd(int ad)
{
    this->ad = ad;
}

int ClapTrap::getHp()
{
    return this->hp;
}

int ClapTrap::getEp()
{
    return this->ep;
}

int ClapTrap::getAd()
{
    return this->ad;
}

void ClapTrap::setName(std::string name)
{
    this->name = name;
}

std::string ClapTrap::getName()
{
    return this->name;
}