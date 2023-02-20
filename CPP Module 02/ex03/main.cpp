
#include "Fixed.hpp"
#include "Point.hpp"
#include "Bsp.hpp"

int main( void ) 
{
    if ( bsp(Point(0, 0), Point(10, 30), Point(20, 0), Point(30, 15) ) == true )    
        std::cout << "Point is in the triangle" << std::endl;    
    else 
        std::cout << "Point is not in the triangle" << std::endl;
    if ( bsp(Point(1, 1), Point(10, 30), Point(20, 1), Point(15, 15) ) == true )    
        std::cout << "Point is in the triangle" << std::endl;    
    else 
        std::cout << "Point is not in the triangle" << std::endl;
    return 0;
}