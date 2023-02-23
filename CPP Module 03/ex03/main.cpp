
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main( void )
{
    DiamondTrap ash( "Ash" );
    DiamondTrap ash2( ash );
    DiamondTrap ash3("ashette");

    ash.whoAmI();
    ash2.whoAmI();
    ash3.whoAmI();
    ash.attack( "the air" );
    ash.takeDamage( 49 );
    ash.beRepaired( 10 );

    return (0);
}