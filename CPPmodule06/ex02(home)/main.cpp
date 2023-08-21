#include <cstdlib>
#include "Base.h"

int main( void ) {

    srand(time(NULL));
    Base *base = generate();
    identify(base);
    identify(*base);
    delete base;

	return 0;
}
