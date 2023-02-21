#pragma once

#include "Animal.hpp"

class Cat : public Animal
{
    private:
        std::string name;

    public:
        Cat();
        Cat(const Cat &copy);
        Cat &operator=(const Cat &copy);
        virtual ~Cat();

        virtual void makeSound() const;
};