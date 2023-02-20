
#include "Fixed.hpp"

Fixed::Fixed()
{
    this->fixed_point_value = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
    this->fixed_point_value = copy.getRawBits();
    std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &copy)
{
    if (this != &copy)
        this->fixed_point_value = copy.getRawBits();
    std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

Fixed::Fixed(const int integer)
{
    this->fixed_point_value = integer << this->fractional_bits;
    std::cout << "Int constructor called" << std::endl;
}

int Fixed::toInt(void) const
{
    return this->fixed_point_value >> this->fractional_bits;
}

Fixed::Fixed(const float floating_point)
{
    this->fixed_point_value = roundf(floating_point * (1 << this->fractional_bits));
    std::cout << "Float constructor called" << std::endl;
}

float Fixed::toFloat(void) const
{
    return (float)this->fixed_point_value / (1 << this->fractional_bits);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
    return;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->fixed_point_value;
}

void Fixed::setRawBits(int const raw)
{
    this->fixed_point_value = raw;
}

