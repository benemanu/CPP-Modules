
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->hp = 100;
    this->ep = 50;
    this->ad = 20;
    std::cout << "Scav Trap " << this->name << " has been constructed. " << std::endl; 
} 

ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap(copy)
{
    std::cout << "Scav Trap " << this->name << " has been copied. " << std::endl; 
}

ScavTrap& ScavTrap::operator=(const ScavTrap& copy)
{
    this->name = copy.name;
    this->hp = copy.hp;
    this->ep = copy.ep;
    this->ad = copy.ad;
    std::cout << "Scav Trap " << this->name << " has been assigned. " << std::endl; 
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "Scav Trap " << this->name << " has been destroyed" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
    if (this->ep <= 0)
        std::cout << "Scav Trap " << this->name << " has no energy left" << std::endl;
    else
    {
        std::cout << "Scav Trap " << this->name << " attacks " << target << " causing " << this->ad << " damage" << std::endl;
        this->ep -= 1;
    }
    return;
}

void ScavTrap::guardGate()
{
    std::cout << "Scav Trap " << this->name << " has entered Gate keeper mode" << std::endl;
}