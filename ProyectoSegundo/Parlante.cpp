#include "Parlante.h"

Parlante::Parlante(string tipo, string model, string carac, double pre) {
	tipoComponente = tipo;
	modelo = model;
	caracteristica = carac;
	precio = pre;
}

Parlante::~Parlante() {

}

string Parlante::getCaracteristica() { return caracteristica; }

double Parlante::getPrecio() { return precio; }

void Parlante::agregar(Componente*) {}

void Parlante::setPrecio(double pre) { precio = pre; }

string Parlante::toString() {
	stringstream show;
	show << tipoComponente << "\t" << modelo << "\t" << caracteristica << "\t" << precio << "\t";
	return show.str();
}
