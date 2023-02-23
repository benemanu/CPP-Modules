
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
    setHp(10);
    setEp(10);
    setAd(0);
    setName(name);
    std::cout << "Clap Trap " << this->name << " has been constructed. " << std::endl; 
}

ClapTrap::ClapTrap(const ClapTrap& copy)
{
    this->name = copy.name;
    this->hp = copy.hp;
    this->ep = copy.ep;
    this->ad = copy.ad;
    std::cout << "Clap Trap " << this->name << " has been copied. " << std::endl; 
}

ClapTrap& ClapTrap::operator=(const ClapTrap& copy)
{
    this->name = copy.name;
    this->hp = copy.hp;
    this->ep = copy.ep;
    this->ad = copy.ad;
    std::cout << "Clap Trap " << this->name << " has been assigned. " << std::endl; 
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Clap Trap " << this->name << " has been destroyed" << std::endl; 
    return;
}

void ClapTrap::attack    (const std::string& target)
{
    if (this->ep <= 0)
        std::cout << "Clap Trap " << this->name << " has no energy left" << std::endl;
    else
    {
        std::cout << "Clap Trap " << this->name << " attacks " << target << " causing " << this->ad << " damage" << std::endl;
        this->ep -= 1;
    }
    return;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    this->hp -= amount;
    std::cout << "Clap Trap " << this->name << " has taken " << amount << " damage" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->ep <= 0)
        std::cout << "Clap Trap " << this->name << " has no energy left" << std::endl;
    else
    {
        this->hp += amount;
        this->ep -= 1;
        std::cout << "Clap Trap " << this->name << " has repaired "  << amount << " Health Points." << std::endl;
        std::cout << "Clap Trap " << this->name << " currently has " << this->hp << " Health Points." << std::endl;
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