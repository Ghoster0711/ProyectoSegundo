#include "Parlante.h"
#include "Utiles.h"

#define DELIMITA_CAMPO '\t'
#define DELIMITA_REGISTRO '\n'

Parlante::Parlante(string tipo, string model, string carac, double pre) {
	tipoComponente = tipo;
	modelo = model;
	caracteristica = carac;
	precio = pre;
}

Parlante::~Parlante() {}

string Parlante::getTipoComponente() { return tipoComponente; }

string Parlante::getModelo() { return modelo; }

string Parlante::getCaracteristica() { return caracteristica; }

double Parlante::getPrecio() { return precio; }

void Parlante::setTipoComponente(string tipo) { tipoComponente = tipo; }

void Parlante::setModelo(string mod) { modelo = mod; }

void Parlante::setCaracteristica(string carac) { caracteristica = carac; }

void Parlante::setPrecio(double pre) { precio = pre; }

void Parlante::agregar(Componente*) {}

string Parlante::toString() {
	stringstream show;
	show << tipoComponente << "\t" << modelo << "\t" << caracteristica << "\t" << precio << "\t";
	return show.str();
}

void agregar(Componente*) {}

void Parlante::guardarDatos(ostream& salida){
	salida << "Parlante" << DELIMITA_CAMPO;
	salida << tipoComponente << DELIMITA_CAMPO;
	salida << modelo << DELIMITA_CAMPO;
	salida << caracteristica << DELIMITA_CAMPO;
	salida << precio << DELIMITA_REGISTRO;
}

Componente* Parlante::recuperarDatos(istream& entrada)
{
	string clase, tipo, model, carac, precio;
	//(entrada, clase, DELIMITA_CAMPO);
	getline(entrada, tipo, DELIMITA_CAMPO);
	getline(entrada, model, DELIMITA_CAMPO);
	getline(entrada, carac, DELIMITA_CAMPO);
	getline(entrada, precio, DELIMITA_REGISTRO);

	double valorPrecio = convierteDouble(precio);

	return new Parlante(tipo, model, carac, valorPrecio);
}
