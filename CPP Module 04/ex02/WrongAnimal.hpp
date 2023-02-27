#pragma once

#include "Animal.hpp"

class WrongAnimal
{
    private:
        std::string type;

    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal &copy);
        WrongAnimal &operator=(const WrongAnimal &copy);
        ~WrongAnimal();

        std::string getType() const;
        void makeSound() const;
};