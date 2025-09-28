#ifndef _PERSONAJE_HPP_
#define _PERSONAJE_HPP_

#include "objts.hpp"

class PERS:public BASEOBJTS{
private:
public:
    PERS();
    const virtual ~PERS();
    const void WALK();
    const void accion();
};

class ENE:public BASEOBJTS{
private:
public:
    BASEOBJTS *RAS;
    ENE();
    const virtual ~ENE();
    const void WALK();
    const void accion();
};


#endif // _PERSONAJE_HPP_
