#ifndef C__CIRCLE_HARL_H
#define C__CIRCLE_HARL_H

#include "iostream"
#include "map"

class Harl {
private:
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
public:
	Harl();
	~Harl();
	void complain( std::string level );
	void Filter(std::string command, int lvl);
	int CompareCommandAndLvl(int lvl, std::string &command);
};

#endif //C__CIRCLE_HARL_H
