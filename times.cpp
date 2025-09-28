#include "times.hpp"


Alarm::Alarm(){
	this->cont = 0;
}

bool Alarm::alarm(int secons){

	if(secons == 0) return false;

	if(cont >= secons){
		cont = 0;
		return true;
	}

	cont++;

	return false;
}

