
#include "Zombie.hpp"

int main()
{
    int amount = 10;
    Zombie *horde = zombieHorde(amount, "JIM");
    for (int i = 0; i < amount; i++)
        horde[i].announce();
    delete[] horde;
    return 0;
}