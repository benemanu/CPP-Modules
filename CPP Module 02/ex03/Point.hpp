#pragma once

#include "Fixed.hpp"

class Point
{
    private:
        const Fixed x;
        const Fixed y;
    
    public:
        Point();
        Point(const Point &copy);
        Point(const float x, const float y);
        ~Point();
        Point& operator=(const Point &copy);
        Fixed getX(void) const;
        Fixed getY(void) const;
};