
#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout << "FragTrap " << this->name << " has been constructed" << std::endl;
    this->hp = 100;
    this->ep = 100;
    this->ad = 30;
}

FragTrap::FragTrap(const FragTrap& copy) : ClapTrap(copy)
{
    std::cout << "FragTrap " << this->name << " has been copied" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& copy)
{
    this->name = copy.name;
    this->hp = copy.hp;
    this->ep = copy.ep;
    this->ad = copy.ad;
    std::cout << "FragTrap " << this->name << " has been assigned" << std::endl;
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << this->name << " has been destructed" << std::endl;
}

void FragTrap::highFive()
{
    std::cout << "Frag Trap " << this->name << " has entered High Five mode" << std::endl;
}