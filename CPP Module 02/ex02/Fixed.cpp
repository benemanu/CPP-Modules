#include "Fixed.hpp"

Fixed::Fixed()
{
    this->fixed_point_value = 0;
}

Fixed::Fixed(const Fixed &copy)
{
    this->fixed_point_value = copy.getRawBits();
}

Fixed& Fixed::operator=(const Fixed &copy)
{
    if (this != &copy)
        this->fixed_point_value = copy.getRawBits();
    return *this;
}

Fixed Fixed::operator+(const Fixed &copy)
{
    Fixed new_fixed;
    new_fixed.fixed_point_value = this->fixed_point_value + copy.fixed_point_value;
    return new_fixed;
}

Fixed Fixed::operator-(const Fixed &copy)
{
    Fixed new_fixed;
    new_fixed.fixed_point_value = this->fixed_point_value - copy.fixed_point_value;
    return new_fixed;
}

Fixed Fixed::operator*(const Fixed &copy)
{
    return Fixed (this->toFloat() * copy.toFloat());
}

Fixed Fixed::operator/(const Fixed &copy)
{
    Fixed new_fixed;
    new_fixed.fixed_point_value = this->fixed_point_value / copy.fixed_point_value;
    return new_fixed;
}

Fixed Fixed::operator++()
{
    this->fixed_point_value++;
    return *this;
}

Fixed Fixed::operator--()
{
    this->fixed_point_value--;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed new_fixed;
    new_fixed.fixed_point_value = this->fixed_point_value;
    this->fixed_point_value++;
    return new_fixed;
}

Fixed Fixed::operator--(int)
{
    Fixed new_fixed;
    new_fixed.fixed_point_value = this->fixed_point_value;
    this->fixed_point_value--;
    return new_fixed;
}

bool Fixed::operator>(const Fixed &copy)
{
    return this->fixed_point_value > copy.fixed_point_value;
}

bool Fixed::operator<(const Fixed &copy)
{
    return this->fixed_point_value < copy.fixed_point_value;
}

bool Fixed::operator>=(const Fixed &copy)
{
    return this->fixed_point_value >= copy.fixed_point_value;
}

bool Fixed::operator<=(const Fixed &copy)
{
    return this->fixed_point_value <= copy.fixed_point_value;
}

bool Fixed::operator==(const Fixed &copy)
{
    return this->fixed_point_value == copy.fixed_point_value;
}

bool Fixed::operator!=(const Fixed &copy)
{
    return this->fixed_point_value != copy.fixed_point_value;
}

Fixed::Fixed(const int integer)
{
    this->fixed_point_value = integer << this->fractional_bits;
}

int Fixed::toInt(void) const
{
    return this->fixed_point_value >> this->fractional_bits;
}

Fixed::Fixed(const float floating_point)
{
    this->fixed_point_value = roundf(floating_point * (1 << this->fractional_bits));
}

float Fixed::toFloat(void) const
{
    return (float)this->fixed_point_value / (1 << this->fractional_bits);
}

Fixed::~Fixed()
{
    return;
}

int Fixed::getRawBits(void) const
{
    return this->fixed_point_value;
}

void Fixed::setRawBits(int const raw)
{
    this->fixed_point_value = raw;
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
    if (a.getRawBits() < b.getRawBits())
        return a;
    return b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
    if (a.getRawBits() > b.getRawBits())
        return a;
    return b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
    if ( a.getRawBits() > b.getRawBits() )
        return a;
    return b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
    if ( a.getRawBits() < b.getRawBits() )
        return a;
    return b;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}