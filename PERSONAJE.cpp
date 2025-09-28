#include "PERSONAJE.hpp"

PERS::PERS(){
}

const PERS::~PERS(){
}

const void PERS::WALK(){
    if(key[KEY_W]){this->SY(this->GY()-3); this->SD(2); SFPS(60);} else
    if(key[KEY_S]){this->SY(this->GY()+3); this->SD(3); SFPS(60);} else
    if(key[KEY_A]){this->SX(this->GX()-3); this->SD(1); SFPS(60);} else
    if(key[KEY_D]){this->SX(this->GX()+3); this->SD(0); SFPS(60);} else {
        SIDX(0);
        SFPS(0);
    }

}

const void PERS::accion(){
    switch(this->GE()){
        case 0: this->WALK(); break;
    }

    this->animar(this->GD());
}
