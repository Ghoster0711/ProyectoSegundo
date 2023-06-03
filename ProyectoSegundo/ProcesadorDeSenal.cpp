#include "ProcesadorDeSenal.h"

ProcesadorDeSenal::ProcesadorDeSenal(string tipo, string model, string carac, double pre) {
	tipoComponente = tipo;
	modelo = model;
	caracteristica = carac;
	precio = pre;
}

ProcesadorDeSenal::~ProcesadorDeSenal() {

}

string ProcesadorDeSenal::getCaracteristica() { return caracteristica; }

double ProcesadorDeSenal::getPrecio() { return precio; }

void ProcesadorDeSenal::agregar(Componente*) {}

void ProcesadorDeSenal::setPrecio(double pre) { precio = pre; }

string ProcesadorDeSenal::toString() {
	stringstream show;
	show << tipoComponente << "\t" << modelo << "\t" << caracteristica << "\t" << precio << "\t";
	return show.str();
}
