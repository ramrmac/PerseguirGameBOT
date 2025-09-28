#ifndef _CTRLMAIN_HPP_
#define _CTRLMAIN_HPP_

#include "PERSONAJE.hpp"
#include "MAPAS.hpp"

class CTRLMAIN{
private:
    MAPAS *M;
    OBJTS *objtctrl;
    OBJTSA*objtactrl;
    PERS *P;
    ENE *E;
public:
    CTRLMAIN(int);
    const virtual ~CTRLMAIN();
    const void accion();
};

#endif // _CTRLMAIN_HPP_
