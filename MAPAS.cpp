#include "MAPAS.hpp"

BLOQUES::BLOQUES(){
    this->sprite[0]=load_bitmap("Madera.bmp",NULL);
    this->sprite[1]=load_bitmap("Tierra.bmp",NULL);
    this->sprite[2]=load_bitmap("tiles.bmp",NULL);
}

const BLOQUES::~BLOQUES(){
    delete this->sprite[0];
    delete this->sprite[1];
    delete this->sprite[2];
}

//---------------------------------------------------

MAPAS::MAPAS(){
    TX=22;
    TY=16;
    BLOCK=new BLOQUES();
    M=new int*[TX];
    for(int i=0;i<TX;i++){
        M[i]=new int[TY];
    }
}

void MAPAS::RM(){
    for(int i=0;i<TX;i++){
        for(int j=0;j<TY;j++){
            M[j][i]=1;
        }
    }
}

const MAPAS::~MAPAS(){
    delete this->M;
    delete this->BLOCK;
}
