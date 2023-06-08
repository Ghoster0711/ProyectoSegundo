#include "Sistema.h"

// Desarrollo del constructor
Sistema::Sistema(){
	Empaquetado = new Lista<Componente>();
	cantItems = 0;
}

// Desarrollo del destructor
Sistema::~Sistema(){
	if (Empaquetado != NULL) delete Empaquetado;
}
