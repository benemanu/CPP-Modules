
#include "Zombie.hpp"

int main()
{
    Zombie *zombie = newZombie("RALF");
    zombie->announce();
    delete zombie;
    randomChump("Randie");
    return (0);
}