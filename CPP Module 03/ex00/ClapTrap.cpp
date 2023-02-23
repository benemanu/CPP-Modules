
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
    this->name = name;
    this->hp = 10;
    this->ep = 10;
    this->ad = 0;
    std::cout << this->name << " has been constructed. " << std::endl; 
}

ClapTrap::ClapTrap(const ClapTrap& copy)
{
    this->name = copy.name;
    this->hp = copy.hp;
    this->ep = copy.ep;
    this->ad = copy.ad;
    std::cout << this->name << " has been copied. " << std::endl; 
}

ClapTrap& ClapTrap::operator=(const ClapTrap& copy)
{
    this->name = copy.name;
    this->hp = copy.hp;
    this->ep = copy.ep;
    this->ad = copy.ad;
    std::cout << this->name << " has been assigned. " << std::endl; 
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << this->name << " has been destroyed" << std::endl; 
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