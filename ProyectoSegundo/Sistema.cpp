#include "Sistema.h"


Sistema::Sistema(){
	Empaquetado = NULL;
	cantItems = 0;
}

Sistema::~Sistema(){
	if (Empaquetado != NULL) delete Empaquetado;
}
