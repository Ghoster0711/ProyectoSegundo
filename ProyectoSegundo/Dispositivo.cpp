#include "Dispositivo.h"
#include "Utiles.h"
#include "FuenteDeAudio.h"
#include "ProcesadorDeSenal.h"
#include "Parlante.h"

#define DELIMITA_CAMPO '\t'
#define DELIMITA_REGISTRO '\n'

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
	show << "Kit" << endl;
	show << empaquetado->toString();
	return show.str();
}

void Dispositivo::guardar(ostream& salida) {
	Nodo<Componente>* e = empaquetado->getPrimero();
	salida << "Dispositivo" << DELIMITA_CAMPO;
	while (e != NULL) {
		if (e->getDato() != NULL) {
			e->getDato()->guardar(salida);
		}
		e = e->getSiguiente();
	}
	salida << "findispositivo" << DELIMITA_CAMPO;
}

Componente* Dispositivo::recuperar(istream& entrada)
{
	string findispositivo;
	Componente* dispositivo = new Dispositivo();
	while (findispositivo != "findispositivo") {
		getline(entrada, findispositivo, DELIMITA_REGISTRO);
		if (findispositivo == "Fuente de audio") {
			dispositivo->agregar(FuenteDeAudio::recuperar(entrada));
		}
		if (findispositivo == "Procesador de senal") {
			dispositivo->agregar(ProcesadorDeSenal::recuperar(entrada));
		}
		if (findispositivo == "Parlante") {
			dispositivo->agregar(Parlante::recuperar(entrada));
		}
	}
	return dispositivo;
}