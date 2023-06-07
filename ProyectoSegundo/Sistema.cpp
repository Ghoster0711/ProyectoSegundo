#include "Sistema.h"

// Desarrollo del constructor
Sistema::Sistema(){
	empaquetado = new Lista<Componente>();
	cantItems = 0;
}

// Desarrollo del destructor
Sistema::~Sistema(){
	if (Empaquetado != NULL) delete Empaquetado;
}
