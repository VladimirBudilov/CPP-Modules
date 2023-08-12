#ifndef C__CIRCLE_FRAGTRAP_H
#define C__CIRCLE_FRAGTRAP_H

#include "ClapTrap.h"

class FragTrap : public virtual ClapTrap {
public:
	FragTrap();
	FragTrap(const std::string &name);
	FragTrap(const FragTrap &copy);
	FragTrap &operator=(const FragTrap &copy);
	~FragTrap();

	void highFivesGuys( void );
};


#endif //C__CIRCLE_FRAGTRAP_H
