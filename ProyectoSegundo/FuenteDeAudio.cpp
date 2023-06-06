#include "FuenteDeAudio.h"
#include "Utiles.h"


#define DELIMITA_CAMPO '\t'
#define DELIMITA_REGISTRO '\n'

FuenteDeAudio::FuenteDeAudio(string tipo, string mod,string carac, double pre) {
	tipoComponente = tipo;
	modelo = mod;
	caracteristica = carac;
	precio = pre;
}

FuenteDeAudio::~FuenteDeAudio(){}

string FuenteDeAudio::getTipoComponente() { return tipoComponente; }

string FuenteDeAudio::getModelo() { return modelo; }

string FuenteDeAudio::getCaracteristica() { return caracteristica; }

double FuenteDeAudio::getPrecio() { return precio; }

void FuenteDeAudio::setTipoComponente(string tipo) { tipoComponente = tipo; }

void FuenteDeAudio::setModelo(string mod) { modelo = mod; }

void FuenteDeAudio::setCaracteristica(string carac) { caracteristica = carac; }

void FuenteDeAudio::setPrecio(double pre) { precio = pre; }

void FuenteDeAudio::agregar(Componente*){}

string FuenteDeAudio::toString() {
	stringstream show;
	show << tipoComponente << "\t"	<< modelo << "\t" << caracteristica << "\t" << precio << "\t";
	return show.str();
}

void agregar(Componente*) {}

void FuenteDeAudio::guardarDatos(ostream& salida) {
	salida << "Fuente de audio" << DELIMITA_CAMPO;
	salida << tipoComponente << DELIMITA_CAMPO;
	salida << modelo << DELIMITA_CAMPO;
	salida << caracteristica << DELIMITA_CAMPO;
	salida << precio << DELIMITA_REGISTRO;
}

Componente* FuenteDeAudio::recuperarDatos(istream& entrada){
	string clase, tipo, model, carac, precio;
	getline(entrada, clase, DELIMITA_CAMPO);
	getline(entrada, tipo, DELIMITA_CAMPO);
	getline(entrada, model, DELIMITA_CAMPO);
	getline(entrada, carac, DELIMITA_CAMPO);
	getline(entrada, precio, DELIMITA_REGISTRO);

	double valorPrecio = convierteDouble(precio);

	return new FuenteDeAudio(tipo, model, carac, valorPrecio);

}