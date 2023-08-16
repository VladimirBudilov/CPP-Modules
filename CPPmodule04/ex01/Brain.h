#ifndef C__CIRCLE_BRAIN_H
#define C__CIRCLE_BRAIN_H

#include "iostream"

class Brain {
public:
	Brain();
	~Brain();
	Brain(const Brain &copy);
	Brain &operator=(const Brain &copy);
private:
	std::string *_ideas;
};


#endif //C__CIRCLE_BRAIN_H
