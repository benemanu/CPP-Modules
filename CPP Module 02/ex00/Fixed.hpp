#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private: 
        int fixed_point_value;
        static const int fractional_bits = 8;

    public:
        Fixed();
        Fixed(const Fixed &copy);
        Fixed& operator=(const Fixed &copy);
        ~Fixed();
        
        int getRawBits(void) const;
        void setRawBits(int const raw);
};

#endif