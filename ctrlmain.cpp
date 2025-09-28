#include "ctrlmain.hpp"

#include <list>
using std::list;
list<BASEOBJTS*>listobjts;

VISUAL VS;

CTRLMAIN::CTRLMAIN(int c){
    M=new MAPAS();/*
    for(int i=0;i<c;i++){
        this->objtctrl=new OBJTS();
        this->objtctrl->_INI("nave.bmp",100*i,10,40,48,10,0,0,1,0);
        listobjts.push_back(this->objtctrl);
    }*/
    this->objtactrl=new OBJTSA();
    this->objtactrl->_INI("fuente.bmp",100,200,192,180,30,0,0,0,0);
    listobjts.push_back(this->objtactrl);

    this->P=new PERS();
    this->P->_INI("Personaje.bmp",100,100,32,44,90,0,0,0,0);
    listobjts.push_back(this->P);

    for(int i=0;i<c;i++){
        this->E=new ENE();
        this->E->_INI("nave.bmp",100*i,10,40,48,10,0,0,0,0);
        this->E->RAS=ROBJT(P->GID());
        listobjts.push_back(this->E);
    }
}

const void CTRLMAIN::accion(){
    M->accion();
    for(list<BASEOBJTS*>::iterator it=listobjts.begin();it!=listobjts.end();it++){
        BASEOBJTS *other=*it;
        other->accion();
    }
    VS.accion();
}

const CTRLMAIN::~CTRLMAIN(){
    for(list<BASEOBJTS*>::iterator it=listobjts.begin();it!=listobjts.end();it++){
        BASEOBJTS *other=*it;
        listobjts.remove(other);
        delete other;
    }
    delete this->objtctrl;
    delete this->objtactrl;
    delete this->P;
    delete this->E;
    delete this->M;
}

//----------------------------------------------------------

BASEOBJTS *ROBJT(int d){

    for(list<BASEOBJTS*>::iterator it=listobjts.begin();it!=listobjts.end();it++){
        BASEOBJTS *other=*it;
        if(other->GID() == d) return other;
    }
    return NULL;
}

const void BASEOBJTS::draw(){
    draw_sprite(VS.LIENZO,this->sprite,this->D.x,this->D.y);
}

void BASEOBJTS::animar(int seccion){
	if(this->TIME[0].alarm(this->D.fps)){
         D.index >= (this->sprite->w/this->D.w)-1 ? this->D.index = 0 : this->D.index++;
	}
	masked_blit(this->sprite,VS.LIENZO, this->D.index *  this->D.w, seccion * this->D.h, this->D.x, this->D.y, this->D.w, this->D.h);
}

//----------------------------------------------------------

const void MAPAS::accion(){
    for(int i=0;i<TX;i++){
        for(int j=0;j<TY;j++){
            draw_sprite(VS.LIENZO,BLOCK->sprite[1],i*30,j*30);
        }
    }
}
