
#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_ClapTrap"), ScavTrap(name), FragTrap(name)
{
    this->name = name;
    this->hp = FragTrap::hp;
    this->ep = ScavTrap::ep;
    this->ad = FragTrap::ad;
    std::cout << "Diamond Trap " << this->name << " created" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
{
    this->name = copy.name;
    std::cout << "Diamond Trap " << this->name << " copied" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& copy)
{
    this->name = copy.name;
    ClapTrap::name = copy.ClapTrap::name;
    FragTrap::hp = copy.FragTrap::hp;
    ScavTrap::ep = copy.ScavTrap::ep;
    FragTrap::ad = copy.FragTrap::ad;
    std::cout << "Diamond Trap " << this->name << " assigned" << std::endl;
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "Diamond Trap " << this->name << " destroyed" << std::endl;
}

void DiamondTrap::whoAmI()
{
    std::cout << "Diamond Trap " << this->name << " is actually " << ClapTrap::name << std::endl;
}