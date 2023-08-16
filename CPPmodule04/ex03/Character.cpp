#include "Character.h"

AMateria *GROUND[100];
int GROUND_COUNT = 0;
void PutOnGround(AMateria *materia)
{
	GROUND[GROUND_COUNT] = materia;
	GROUND_COUNT++;
}

Character::Character() : ICharacter()
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = nullptr;
	_name = "default";
	_inventoryCount = 0;
}

Character::Character(std::string name) : ICharacter(), _name(name)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = nullptr;
	_inventoryCount = 0;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		if (_inventory[i])
			delete _inventory[i];
}

Character::Character(const Character &copy)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = nullptr;
	*this = copy;
}

Character &Character::operator=(const Character &copy)
{
	if (this == &copy)
		return *this;
	_name = copy._name;
	for (int i = 0; i < copy._inventoryCount; i++)
	{
		if (_inventory[i]) {
			delete _inventory[i];
			_inventory[i] = nullptr;
		}
		_inventory[i] = copy._inventory[i]->clone();
	}
	return *this;
}

std::string const &Character::getName() const
{
	return _name;
}

void Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!_inventory[i])
		{
			_inventory[i] = m;
			++_inventoryCount;
			return;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3 || !_inventoryCount || !_inventory[idx])
		return;
	--_inventoryCount;
	PutOnGround(_inventory[idx]);
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > 3|| !_inventoryCount || !_inventory[idx])
		return;
	_inventory[idx]->use(target);
}





