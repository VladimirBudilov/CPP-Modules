#include "Character.h"
#include "Cure.h"
#include "Ice.h"
#include "MateriaSource.h"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	Character a;
	{
		Character b("b");
		a = b;
	}
	{
		Character c(a);
	}
	{
		Character d("d");
		a = d;
	}

	system("leaks ex03");
	return 0;
}
