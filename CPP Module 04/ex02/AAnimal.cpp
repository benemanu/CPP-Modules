
#include "AAnimal.hpp"
#include "Brain.hpp"

AAnimal::AAnimal() : type("AAnimal")
{
    std::cout << this->type << " constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &copy)
{
    *this = copy;
    std::cout << "AAnimal copy constructor called" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &copy)
{
    if (this != &copy)
    {
        this->type = copy.type;
    }
    std::cout << "AAnimal assignation operator called" << std::endl;
    return (*this);
}

AAnimal::AAnimal(std::string type)
{
    this->type = type;
    std::cout << "AAnimal " << this->type << "constructor classed" << std::endl;
}

AAnimal::~AAnimal()
{
    std::cout << "AAnimal destructor called" << std::endl;
}

std::string AAnimal::getType() const
{
    return (this->type);
}

void AAnimal::makeSound() const
{
    std::cout << this->type << "Animal sound" << std::endl;
}