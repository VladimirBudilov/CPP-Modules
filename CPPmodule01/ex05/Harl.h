#ifndef C__CIRCLE_HARL_H
#define C__CIRCLE_HARL_H

#include "iostream"

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
};


#endif //C__CIRCLE_HARL_H
