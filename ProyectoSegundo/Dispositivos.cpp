#include "Dispositivos.h"
#include "Utiles.h"
#include "FuenteDeAudio.h"
#include "ProcesadorDeSenal.h"
#include "Parlante.h"

#define DELIMITA_CAMPO '\t'
#define DELIMITA_REGISTRO '\n'

Dispositivos::Dispositivos() {
	precio = 0;
}

Dispositivos::~Dispositivos() {}

Lista<Componente>* Dispositivos::getEmpaquetado() { return empaquetado; }

int Dispositivos::getCantItems() { return cantItems; }

double Dispositivos::getPrecio() { return precio; }

string Dispositivos::getTipoComponente() { return ""; }

string Dispositivos::getModelo() { return ""; }

string Dispositivos::getCaracteristica() { return ""; }

void Dispositivos::setPrecio(double pre) { precio = pre; }

void Dispositivos::setTipoComponente(string){}

void Dispositivos::setModelo(string){}

void Dispositivos::setCaracteristica(string carac) {}

string Dispositivos::toString() {
	stringstream show;
	show << "Dispositivos" << endl;
	show << empaquetado->toString();
	return show.str();
}

void Dispositivos::agregar(Componente* com) {
	empaquetado->ingresar(com);
	cantItems++;
}

void Dispositivos::guardarDatos(ostream& salida) {
	Nodo<Componente>* e = empaquetado->getPrimero();
	salida << "Dispositivos" << DELIMITA_CAMPO;
	while (e != NULL) {
		if (e->getDato() != NULL) {
			e->getDato()->guardarDatos(salida);
		}
		e = e->getSiguiente();
	}
	salida << "finDispositivos" << DELIMITA_CAMPO;
}

Componente* Dispositivos::recuperarDatos(istream& entrada)
{
	string finDispositivos;
	Componente* dispositivos = new Dispositivos();
	while (finDispositivos != "finDispositivos") {
		getline(entrada, finDispositivos, DELIMITA_REGISTRO);
		if (finDispositivos == "Fuente de audio") {
			dispositivos->agregar(FuenteDeAudio::recuperarDatos(entrada));
		}
		if (finDispositivos == "Procesador de senal") {
			dispositivos->agregar(ProcesadorDeSenal::recuperarDatos(entrada));
		}
		if (finDispositivos == "Parlante") {
			dispositivos->agregar(Parlante::recuperarDatos(entrada));
		}
	}
	return dispositivos;
}