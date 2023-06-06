#include "Kit.h"
#include "Utiles.h"
#include "FuenteDeAudio.h"
#include "ProcesadorDeSenal.h"
#include "Parlante.h"

#define DELIMITA_CAMPO '\t'
#define DELIMITA_REGISTRO '\n'

Kit::Kit(){
	precio = 0;
}

Kit::~Kit(){}

Lista<Componente>* Kit::getEmpaquetado() { return empaquetado; }

int Kit::getCantItems() { return cantItems; }

double Kit::getPrecio() { return precio; }

string Kit::getTipoComponente() { return ""; }

string Kit::getModelo() { return ""; }

string Kit::getCaracteristica() { return ""; }

void Kit::setPrecio(double pre) { precio = pre; }

void Kit::setTipoComponente(string){}

void Kit::setModelo(string){}

void Kit::setCaracteristica(string) {}

string Kit::toString(){
	stringstream show;
	show << "Kit" << endl;
	show << empaquetado->toString();
	return show.str();
}

void Kit::agregar(Componente* com) {
	empaquetado->ingresar(com);
	cantItems++;
}

void Kit::guardarDatos(ostream& salida) {
	Nodo<Componente>* e = empaquetado->getPrimero();
	salida << "Kit" << DELIMITA_CAMPO;
	while (e != NULL) {
		if (e->getDato() != NULL) {
			e->getDato()->guardarDatos(salida);
		}
		e = e->getSiguiente();
	}
	salida << "finKit" << DELIMITA_CAMPO;
}

Componente* Kit::recuperarDatos(istream& entrada){
	string finkit;
	Componente* kit = new Kit();
	while (finkit != "finKit") {
		getline(entrada, finkit, DELIMITA_CAMPO);
		if (finkit == "Fuente de audio") {
			kit->agregar(FuenteDeAudio::recuperarDatos(entrada));
		}
		if (finkit == "Procesador de senal") {
			kit->agregar(ProcesadorDeSenal::recuperarDatos(entrada));
		}
		if (finkit == "Parlante") {
			kit->agregar(Parlante::recuperarDatos(entrada));
		}
	}
	return kit;
}