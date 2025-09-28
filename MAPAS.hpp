#ifndef _MAPAS_HPP_
#define _MAPAS_HPP_

#include "visual.hpp"

class BLOQUES{
private:
public:
    BITMAP *sprite[3];
    BLOQUES();
    const virtual ~BLOQUES();
};

class MAPAS{
private:
    BLOQUES *BLOCK;
    int **M;
    int TX,TY;
public:
    MAPAS();
    const virtual ~MAPAS();
    void RM();
    const void accion();
};

#endif // _MAPAS_HPP_
