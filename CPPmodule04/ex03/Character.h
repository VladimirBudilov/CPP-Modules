#ifndef C__CIRCLE_CHARACTER_H
#define C__CIRCLE_CHARACTER_H

#include "ICharacter.h"

class Character : public ICharacter{
private:
	std::string _name;
	AMateria *_inventory[4];
	int _inventoryCount;
public:
	Character();
	Character(std::string name);
	Character(const Character &copy);
	Character &operator=(const Character &copy);
	virtual ~Character();

	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};


#endif //C__CIRCLE_CHARACTER_H
