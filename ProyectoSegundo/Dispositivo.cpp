#include "Dispositivo.h"

Dispositivo::Dispositivo() {
	caracteristica = "";
	precio = 0;
}

Dispositivo::~Dispositivo() {

}

string Dispositivo::getCaracteristica() { return caracteristica; }

double Dispositivo::getPrecio() { return precio; }

void Dispositivo::agregar(Componente* com) {
	empaquetado->ingresar(com);
	cantItems++;
}

void Dispositivo::setPrecio(double pre) { precio = pre; }

string Dispositivo::toString() {
	stringstream show;
	show << empaquetado->toString();
	return show.str();
}