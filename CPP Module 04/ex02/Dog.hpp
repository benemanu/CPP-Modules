#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog : public AAnimal
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