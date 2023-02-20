
#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    this->name = name;
    this->weapon = NULL;
}

HumanB::~HumanB()
{
    return;
}

void HumanB::setWeapon(Weapon& weapon)
{
    this->weapon = &weapon;
}

void HumanB::attack()
{
    if (this->weapon != NULL && this->weapon->get_Type() != "")
        std::cout << this->name << " attacks with his " << this->weapon->get_Type() << std::endl;
    else
        std::cout << this->name << " attacks with his fists" << std::endl;
}