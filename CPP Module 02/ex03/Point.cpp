
#include "Point.hpp"
#include "Fixed.hpp"


Point& Point::operator=(const Point &copy)
{
    if (this != &copy)
    {
        (Fixed) this->x = copy.getX();
        (Fixed) this->y = copy.getY();
    }
    return *this;
}

Point::Point() : x(0), y(0)
{
    return;
}

Point::Point(const Point &copy) : x(copy.getX()), y(copy.getY())
{
    return;
}

Point::Point(const float x, const float y) : x(x), y(y)
{
    return;
}

Point::~Point()
{
    return;
}

Fixed Point::getX(void) const
{
    return this->x;
}

Fixed Point::getY(void) const
{
    return this->y;
}