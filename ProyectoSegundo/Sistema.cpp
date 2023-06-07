#include "Sistema.h"


Sistema::Sistema() {}
Sistema::~Sistema(){
	if (Empaquetado != NULL) delete Empaquetado;
}
