
#include "Weapon.hpp"

Weapon::Weapon(std::string type) 
{
    this->set_Type(type);
}

Weapon::~Weapon()
{
    return;
}

const std::string& Weapon::get_Type()
{
    return this->type;
}

void    Weapon::set_Type(std::string NewType)
{
    this->type = NewType;
}