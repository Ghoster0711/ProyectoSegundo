#include "Composite.h"


Sistema::Sistema(){
	empaquetado = new Lista<Componente>();
	cantItems = 0;
}

Sistema::~Sistema(){
	if (empaquetado != NULL) delete empaquetado;
}
