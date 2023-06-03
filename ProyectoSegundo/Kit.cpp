#include "Kit.h"

Kit::Kit(){
	caracteristica = "";
	precio = 0;
}

Kit::~Kit(){

}

string Kit::getCaracteristica() { return caracteristica; }

double Kit::getPrecio() { return precio; }

void Kit::agregar(Componente* com){ 
	empaquetado->ingresar(com);
	cantItems++;
}

void Kit::setPrecio(double pre) { precio = pre; }

string Kit::toString(){
	stringstream show;
	show << empaquetado->toString();
	return show.str();
}