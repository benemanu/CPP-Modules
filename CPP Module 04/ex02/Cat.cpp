
#include "Cat.hpp"
#include "Animal.hpp"
#include "Brain.hpp"
#include "AAnimal.hpp"

Cat::Cat() : AAnimal()
{
    this->type = "Cat";
    std::cout << "Cat constructor called" << std::endl;
    this->brain = new Brain();
}

Cat::Cat(const Cat &copy) : AAnimal(copy)
{
    this->type = copy.type;
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &copy)
{
    this->type = copy.type;
    std::cout << "Cat assignation operator called" << std::endl;
    return (*this);
}

Cat::~Cat()
{
    delete this->brain;
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << this->type << " sound" << std::endl;
}