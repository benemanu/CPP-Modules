
#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->hp = 100;
    this->ep = 100;
    this->ad = 30;
    std::cout << "Frag Trap constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& copy) : ClapTrap(copy)
{
    std::cout << "Frag Trap copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& copy)
{
    this->name = copy.name;
    this->hp = copy.hp;
    this->ep = copy.ep;
    this->ad = copy.ad;
    std::cout << "Frag Trap assignation operator called" << std::endl;
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "Frag Trap destructor called" << std::endl;
}

void FragTrap::highFive()
{
    std::cout << "Frag Trap " << this->name << " has entered High Five mode" << std::endl;
}