
#include "Dog.hpp"
#include "Animal.hpp"
#include "Brain.hpp"
#include "AAnimal.hpp"

Dog::Dog() : AAnimal("Dog")
{
    std::cout << "Dog constructor called" << std::endl;
    this->brain = new Brain();
    if (!this->brain)
        std::cout << "Memory allocation failed" << std::endl;
}

Dog::Dog(const Dog &copy)
{
    *this = copy;
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &copy)
{
    if (this != &copy)
    {
        this->type = copy.type;
        this->brain = new Brain(*copy.brain);
    }
    std::cout << "Dog assignation operator called" << std::endl;
    return (*this);
}

Dog::~Dog()
{
    delete this->brain;
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << this->type << " sound" << std::endl;
}
