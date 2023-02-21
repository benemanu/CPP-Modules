
#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &copy)
{
    *this = copy;
    std::cout << "Brain copy constructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &copy)
{
    if (this != &copy)
        for(int i = 0; i < 100; i++)
            this->ideas[i] = copy.ideas[i];
    std::cout << "Brain assignation operator called" << std::endl;
    return (*this);
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}

std::string Brain::getIdea(int i) const
{
    return (this->ideas[i]);
}

void Brain::setIdea(int i, std::string idea)
{
    this->ideas[i] = idea;
}