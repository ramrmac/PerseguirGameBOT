#include "PERSONAJE.hpp"

ENE::ENE(){
}

const void ENE::WALK(){
    //((RAS->GX() < this->GX()+100) && (RAS->GX() > this->GX()-100)) || ((RAS->GY() < this->GY()+100) (RAS->GY() > this->GY()-100))
    if(((RAS->GX() < this->GX()+100) && (RAS->GX() > this->GX()-100)) && ((RAS->GY() < this->GY()+100) && (RAS->GY() > this->GY()-100))){
        if(this->GX() > RAS->GX()) SX(GX()-1);
        if(this->GX() < RAS->GX()) SX(GX()+1);
        if(this->GY() > RAS->GY()) SY(GY()-1);
        if(this->GY() < RAS->GY()) SY(GY()+1);
    }
}

const void ENE::accion(){
    switch(this->GE()){
        case 0: this->WALK(); break;
    }

    this->draw();
}

const ENE::~ENE(){
    delete this->RAS;
}
