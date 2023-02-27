
#include "Animal.hpp"
#include "Brain.hpp"

Animal::Animal()
{
    std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(std::string type)
{
    this->type = type;
    std::cout << this->type << " type-assignment constructor called" << std::endl;
}

Animal::Animal(const Animal &copy)
{
    this->type = copy.type;
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &copy)
{
    this->type = copy.type;
    std::cout << "Animal assignation operator called" << std::endl;
    return (*this);
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const
{
    return (this->type);
}

void Animal::makeSound() const
{
    std::cout << this->type << "Animal sound" << std::endl;
}