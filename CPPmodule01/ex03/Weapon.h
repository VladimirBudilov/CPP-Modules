#ifndef C__CIRCLE_WEAPON_H
#define C__CIRCLE_WEAPON_H

#include "iostream"

class Weapon {
private:
	std::string _type;
public:
	Weapon();
	Weapon(std::string type);
	~Weapon();
	const std::string &getType();
	void setType(std::string type);
};

#endif //C__CIRCLE_WEAPON_H
