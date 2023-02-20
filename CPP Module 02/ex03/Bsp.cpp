
#include "Point.hpp"
#include "Fixed.hpp"

static Fixed abs(Fixed x);
static Fixed area (Point const a, Point const b, Point const c);

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed abcArea = abs(area(a, b, c));
    Fixed abpArea = abs(area(a, b, point));
    Fixed bcpArea = abs(area(b, c, point));
    Fixed capArea = abs(area(c, a, point));
    return (abcArea == abpArea + bcpArea + capArea);
    
}

static Fixed abs(Fixed x)
{
    if (x < 0 )
        return x * -1;
    return x;
}

static Fixed area (Point const a, Point const b, Point const c)
{
    return ( ( ( a.getX() * ( b.getY() - c.getY() ) ) +
             ( b.getX() * ( c.getY() - a.getY() ) ) +
             ( c.getX() * ( a.getY() - b.getY() ) ) ) / 2 );   
}