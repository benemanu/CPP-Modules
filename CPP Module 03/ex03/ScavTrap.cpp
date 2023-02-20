
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->hp = 100;
    this->ep = 50;
    this->ad = 20;
    std::cout << "ScavTrap " << this->name << " has been constructed. " << std::endl; 
} 
 
ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << this->name << " has been destroyed" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
    if (this->ep <= 0)
        std::cout << this->name << " has no energy left" << std::endl;
    else
    {
        std::cout << "ScavTrap " << this->name << " attacks " << target << " causing " << this->ad << " damage" << std::endl;
        this->ep -= 1;
    }
    return;
}

void ScavTrap::guardGate()
{
    std::cout << this->name << " has entered Gate keeper mode" << std::endl;
}