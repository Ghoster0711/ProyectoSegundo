#include "Kit.h"
#include "Utiles.h"
#include "FuenteDeAudio.h"
#include "ProcesadorDeSenal.h"
#include "Parlante.h"


#define DELIMITA_CAMPO '\t'
#define DELIMITA_REGISTRO '\n'

Kit::Kit(){
	caracteristica = "";
	precio = 0;
}

Kit::~Kit(){

}

string Kit::getCaracteristica() { return caracteristica; }

double Kit::getPrecio() { return precio; }

void Kit::agregar(Componente* com){ 
	empaquetado->ingresar(com);
	cantItems++;
}

void Kit::setPrecio(double pre) { precio = pre; }

string Kit::toString(){
	stringstream show;
	show << "Kit" << endl;
	show << empaquetado->toString();
	return show.str();
}

void Kit::guardar(ostream& salida) {
	Nodo<Componente>* e = empaquetado->getPrimero();
	salida << "Kit" << DELIMITA_CAMPO;
	while (e != NULL) {
		if (e->getDato() != NULL) {
			e->getDato()->guardar(salida);
		}
		e = e->getSiguiente();
	}
	salida << "finKit" << DELIMITA_CAMPO;
}

Componente* Kit::recuperar(istream& entrada){
	string finkit;
	Componente* kit = new Kit();
	while (finkit != "finKit") {
		getline(entrada, finkit, DELIMITA_CAMPO);
		if (finkit == "Fuente de audio") {
			kit->agregar(FuenteDeAudio::recuperar(entrada));
		}
		if (finkit == "Procesador de senal") {
			kit->agregar(ProcesadorDeSenal::recuperar(entrada));
		}
		if (finkit == "Parlante") {
			kit->agregar(Parlante::recuperar(entrada));
		}
	}
	return kit;
}