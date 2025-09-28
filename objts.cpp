#include "objts.hpp"

volatile int id=0;

BASEOBJTS::BASEOBJTS(){
    this->TIME=new Alarm[5]();
    this->D.pid=id; id++;
    this->sprite=NULL;
    this->D.x=0;
    this->D.y=0;
    this->D.w=0;
    this->D.h=0;
    this->D.fps=0;
    this->D.index=0;
    this->D.dir=0;
    this->D.g=0;
    this->D.e=0;
}

void BASEOBJTS::_INI(const char *n,float x,float y,int w,int h,int fps,int index,int dir,int g,int e){
    this->sprite=load_bitmap(n,NULL);
    this->D.x=x;
    this->D.y=y;
    this->D.w=w;
    this->D.h=h;
    this->D.fps=fps;
    this->D.index=index;
    this->D.dir=dir;
    this->D.g=g;
    this->D.e=e;
}

const BASEOBJTS::~BASEOBJTS(){
    delete this->sprite;
    delete this->TIME;
}

//--------------------------------------------------------
OBJTS::OBJTS(){
}

const OBJTS::~OBJTS(){
}

const void OBJTS::accion(){
    this->draw();
}

//-----------------------------------------------------------
OBJTSA::OBJTSA(){
}

const OBJTSA::~OBJTSA(){
}

const void OBJTSA::accion(){
    this->animar(this->GD());
}
