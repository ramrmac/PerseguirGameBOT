#ifndef _OBJTS_HPP_
#define _OBJTS_HPP_

#include "visual.hpp"
#include "times.hpp"

struct DATA{
    int pid;
    float x,y;
    int w,h,fps,index,dir;
    int g;//grupo
    int e;
};

class BASEOBJTS{
private:
    BITMAP*sprite;
    DATA D;
    Alarm *TIME;
public:
    BASEOBJTS();
    const virtual ~BASEOBJTS();
    void _INI(const char*,float,float,int,int,int,int,int,int,int);
    //------
    void SIDX(int index){this->D.index=index;}
    void SFPS(int fps){this->D.fps=fps;}
    void SD(int dir){this->D.dir=dir;}
    void SX(int x){this->D.x=x;}
    void SY(int y){this->D.y=y;}
    //------
    const int GID(){return this->D.pid;}
    const int GD(){return this->D.dir;}
    const int GE(){return this->D.e;}
    const int GX(){return this->D.x;}
    const int GY(){return this->D.y;}
    //----
    void animar(int);
    const void draw();
    //-----
    const virtual void accion()=0;
};
BASEOBJTS *ROBJT(int);

class OBJTS:public BASEOBJTS{
private:
public:
    OBJTS();
    const virtual ~OBJTS();
    const void accion();
};

class OBJTSA:public BASEOBJTS{
private:
public:
    OBJTSA();
    const virtual ~OBJTSA();
    const void accion();
};
/*
class PERSONAJE: public OBJTSA{
};
*/

#endif // _OBJTS_HPP_
