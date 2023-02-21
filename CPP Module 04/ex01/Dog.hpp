#pragma once

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog : public Animal
{
    private:
    Brain *brain;
    std::string type;

    public:
        Dog();
        Dog(const Dog &copy);
        Dog &operator=(const Dog &copy);
        virtual ~Dog();

        virtual void makeSound() const;
};