#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon
{
    private:
        std::string type;

    public:
    Weapon(std::string type);
    ~Weapon();
    const std::string& get_Type();
    void set_Type(std::string NewType);
};

#endif