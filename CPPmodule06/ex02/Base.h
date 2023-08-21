#ifndef C__PROJECT_BASE_H
#define C__PROJECT_BASE_H

#include <cstdlib>
#include <iostream>

class Base {
public:
    virtual ~Base();
};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#include "A.h"
#include "B.h"
#include "C.h"

#endif //C__PROJECT_BASE_H
