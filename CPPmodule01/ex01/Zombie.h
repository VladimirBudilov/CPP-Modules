#ifndef C__CIRCLE_ZOMBIE_H
#define C__CIRCLE_ZOMBIE_H

#include "iostream"

class Zombie {
private:
	std::string _name;
public:
	Zombie();
	~Zombie();
	void announce();
	void setName(std::string name);
	std::string getName();
};

#endif //C__CIRCLE_ZOMBIE_H
