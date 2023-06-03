#include "FuenteDeAudio.h"

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
