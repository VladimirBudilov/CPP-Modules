#include "Zombie.h"

Zombie* ZombieHorde( int N, std::string name);

int main()
{
	int hordeSize = 5;
	Zombie *zombieHorde;
	zombieHorde = ZombieHorde(hordeSize, "zombieHorde");
	for (int i = 0; i < hordeSize; i++)
		zombieHorde[i].announce();
	delete[] zombieHorde;
	//system("leaks MoarBrainz!");
	return 0;
}