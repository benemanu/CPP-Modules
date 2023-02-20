#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : weapon(weapon)
{
    this->name = name;
}

HumanA::~HumanA()
{
    return;
}

void HumanA::attack()
{
    if (this->weapon.get_Type() != "")
        std::cout << this->name << " attacks with his " << this->weapon.get_Type() << std::endl;
    else
        std::cout << this->name << " attacks with his fists" << std::endl;
}