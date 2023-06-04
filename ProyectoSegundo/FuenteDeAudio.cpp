#include "FuenteDeAudio.h"
#include "Utiles.h"


#define DELIMITA_CAMPO '\t'
#define DELIMITA_REGISTRO '\n'

FuenteDeAudio::FuenteDeAudio(string tipo, string model, string carac, double pre) {
	tipoComponente = tipo;
	modelo = model;
	caracteristica = carac;
	precio = pre;
}

FuenteDeAudio::~FuenteDeAudio(){

}

string FuenteDeAudio::getCaracteristica() { return caracteristica; }

double FuenteDeAudio::getPrecio() { return precio; }

void FuenteDeAudio::agregar(Componente*){}

void FuenteDeAudio::setPrecio(double pre) { precio = pre; }

string FuenteDeAudio::toString() {
	stringstream show;
	show << tipoComponente << "\t"	<< modelo << "\t" << caracteristica << "\t" << precio << "\t";
	return show.str();
}

void FuenteDeAudio::guardar(ostream& salida) {
	salida << "Fuente de audio" << DELIMITA_CAMPO;
	salida << tipoComponente << DELIMITA_CAMPO;
	salida << modelo << DELIMITA_CAMPO;
	salida << caracteristica << DELIMITA_CAMPO;
	salida << precio << DELIMITA_REGISTRO;
}

Componente* FuenteDeAudio::recuperar(istream& entrada){
	string tipo, model, carac, precio;
	getline(entrada, tipo, DELIMITA_CAMPO);
	getline(entrada, model, DELIMITA_CAMPO);
	getline(entrada, carac, DELIMITA_CAMPO);
	getline(entrada, precio, DELIMITA_REGISTRO);

	double valorPrecio = convierteDouble(precio);

	return new FuenteDeAudio(tipo, model, carac, valorPrecio);

}