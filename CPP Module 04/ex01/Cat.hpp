#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    private:
        Brain *brain;
        std::string type;
        
    public:
        Cat();
        Cat(const Cat &copy);
        Cat &operator=(const Cat &copy);
        virtual ~Cat();

        virtual void makeSound() const;
};