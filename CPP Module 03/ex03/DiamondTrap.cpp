
#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name)
{
    this->name = name;

    FragTrap::hp = 100;
    ScavTrap::ep = 50;
    FragTrap::ad = 30;
    std::cout << "DiamondTrap " << this->name << " created" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << this->name << " destroyed" << std::endl;
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap " << this->name << " is actually " << ClapTrap::name << std::endl;
}