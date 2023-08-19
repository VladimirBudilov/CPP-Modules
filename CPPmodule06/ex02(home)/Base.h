#ifndef C__PROJECT_BASE_H
#define C__PROJECT_BASE_H

#include <cstdlib>
#include <iostream>
#include "A.h"
#include "B.h"
#include "C.h"

class Base {
public:
    virtual ~Base();
};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif //C__PROJECT_BASE_H
