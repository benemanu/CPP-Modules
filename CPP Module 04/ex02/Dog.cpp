
#include "Dog.hpp"
#include "Animal.hpp"
#include "Brain.hpp"
#include "AAnimal.hpp"

Dog::Dog() : AAnimal()
{
    this->type = "Dog";
    std::cout << "Dog constructor called" << std::endl;
    this->brain = new Brain();
}

Dog::Dog(const Dog &copy) : AAnimal(copy)
{
    this->type = copy.type;
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &copy)
{
    this->type = copy.type;
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
