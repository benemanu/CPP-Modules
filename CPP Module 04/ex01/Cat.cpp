
#include "Cat.hpp"
#include "Animal.hpp"
#include "Brain.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat constructor called" << std::endl;
    this->brain = new Brain();
    if (!this->brain)
        std::cout << "Memory Allocation failed" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
   *this = copy;
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &copy)
{
    if (this != &copy)
    {
        this->type = copy.type;
        this->brain = new Brain(*copy.brain);
    }
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
    this->brain->setIdea(0, "CatBrainIdea");
    std::cout << this->brain->getIdea(0) << std::endl;
}