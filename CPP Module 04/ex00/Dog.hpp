#pragma once

#include "Animal.hpp"
#include <iostream>

class Dog : public Animal
{
    private:
        std::string name;

    public:
        Dog();
        Dog(const Dog &copy);
        Dog &operator=(const Dog &copy);
        virtual ~Dog();

        virtual void makeSound() const;
};