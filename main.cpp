#include "ctrlmain.hpp"

CTRLMAIN *CM;

int main(){
    CM=new CTRLMAIN(5);

    while(!key[KEY_ESC]){
        if(rsp()>0){
            CM->accion();
        }
    }

    delete CM;
    return 0;
}
END_OF_MAIN()
