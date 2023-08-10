#include "Zombie.h"

Zombie *newZombie(std::string name);
void randomChump(std::string name);

int main()
{
	Zombie zombieDefault;
	zombieDefault.announce();
	Zombie *zombieOnHeap = newZombie("zombieOnHeap");;
	randomChump("zombieOnStack");
	(*zombieOnHeap).announce();

	delete zombieOnHeap;
	//system("leaks BraiiiiiiinnnzzzZ");
	return 0;
}