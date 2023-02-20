#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <fstream>

class Fixed
{
    private: 
        int fixed_point_value;
        static const int fractional_bits = 8;

    public:
        Fixed();
        Fixed(const Fixed &copy);
        Fixed(const int integer);
        Fixed(const float floating_point);
        ~Fixed();

        bool operator>(const Fixed &copy);
        bool operator<(const Fixed &copy);
        bool operator>=(const Fixed &copy);
        bool operator<=(const Fixed &copy);
        bool operator==(const Fixed &copy);
        bool operator!=(const Fixed &copy);
        
        Fixed& operator=(const Fixed &copy);
        Fixed operator+(const Fixed &copy);
        Fixed operator-(const Fixed &copy);
        Fixed operator*(const Fixed &copy);
        Fixed operator/(const Fixed &copy);
        Fixed operator++(void);
        Fixed operator++(int);
        Fixed operator--(void);
        Fixed operator--(int);

        static  Fixed& min(Fixed &a, Fixed &b);
        static  Fixed& max(Fixed &a, Fixed &b);
        static  const Fixed& min(const Fixed &a, const Fixed &b);
        static  const Fixed& max(const Fixed &a, const Fixed &b);
        
        friend std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
        {
            os << fixed.toFloat();
            return os;
        }

        float toFloat(void) const;
        int toInt(void) const;        
        int getRawBits(void) const;
        void setRawBits(int const raw);
};

#endif