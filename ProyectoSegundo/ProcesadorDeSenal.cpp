#include "ProcesadorDeSenal.h"
#include "Utiles.h"

#define DELIMITA_CAMPO '\t'
#define DELIMITA_REGISTRO '\n'

ProcesadorDeSenal::ProcesadorDeSenal(string tipo, string model, string carac, double pre) {
	tipoComponente = tipo;
	modelo = model;
	caracteristica = carac;
	precio = pre;
}

ProcesadorDeSenal::~ProcesadorDeSenal() {}

string ProcesadorDeSenal::getTipoComponente() { return tipoComponente; }

string ProcesadorDeSenal::getModelo() { return modelo; }

string ProcesadorDeSenal::getCaracteristica() { return caracteristica; }

double ProcesadorDeSenal::getPrecio() { return precio; }

void ProcesadorDeSenal::setTipoComponente(string tipo) { tipoComponente = tipo; }

void ProcesadorDeSenal::setModelo(string mod) { modelo = mod; }

void ProcesadorDeSenal::setCaracteristica(string carac) { caracteristica = carac; }

void ProcesadorDeSenal::setPrecio(double pre) { precio = pre; }

void ProcesadorDeSenal::agregar(Componente*){}

string ProcesadorDeSenal::toString() {
	stringstream show;
	show << tipoComponente << "\t" << modelo << "\t" << caracteristica << "\t" << precio << "\t";
	return show.str();
}

void agregar(Componente*) {}

void ProcesadorDeSenal::guardarDatos(ostream& salida) {
	salida << "Procesador de senal" << DELIMITA_CAMPO;
	salida << tipoComponente << DELIMITA_CAMPO;
	salida << modelo << DELIMITA_CAMPO;
	salida << caracteristica << DELIMITA_CAMPO;
	salida << precio << DELIMITA_REGISTRO;
}

Componente* ProcesadorDeSenal::recuperarDatos(istream& entrada)
{
	string clase, tipo, model, carac, precio;
	//getline(entrada, clase, DELIMITA_CAMPO);
	getline(entrada, tipo, DELIMITA_CAMPO);
	getline(entrada, model, DELIMITA_CAMPO);
	getline(entrada, carac, DELIMITA_CAMPO);
	getline(entrada, precio, DELIMITA_REGISTRO);

	double valorPrecio = convierteDouble(precio);

	return new ProcesadorDeSenal(tipo, model, carac, valorPrecio);
}
