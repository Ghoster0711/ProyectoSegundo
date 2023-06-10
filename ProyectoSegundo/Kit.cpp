#include "Kit.h"
#include "Utiles.h"
#include "FuenteDeAudio.h"
#include "UnidadCD.h"
#include "Tornamesa.h"
#include "Radio.h"
#include "UnidadBluetooth.h"
#include "Microfono.h"
#include "ProcesadorDeSenal.h"
#include "Amplificador.h"
#include "Mezclador.h"
#include "Parlante.h"
#include "Altavoz.h"
#include "Audifono.h"


// Delimitadores para archivos
#define DELIMITA_CAMPO '\t'
#define DELIMITA_REGISTRO '\n'


// Desarrollo del constructor
Kit::Kit()
{
	nombre = "";
	codigo = "";
	caracteristica = "";
	precio = 0;
}

// Desarrollo del constructor paremetrizado
Kit::Kit(string nom, string cod){
	nombre = nom;
	codigo = cod;
	caracteristica = "";
	precio = 0;
}

// Desarrollo del destructor
Kit::~Kit() {}


// Desarrollo de los get's
string Kit::getID() { return codigo; }
string Kit::getCodigo() { return codigo; }
string Kit::getNombre() { return nombre; }
string Kit::getCaracteristica() { return caracteristica; }
double Kit::getPrecio() { return precio; }

// Desarrollo de los set's
void Kit::setCodigo(string cod) { codigo = cod; }
void Kit::setCaracteristica(string carac) { caracteristica = carac; }
void Kit::setPrecio(double pre) { precio = pre; }
void Kit::setNombre(string nom) { nombre = nom; }


// Desarrollo del ToString
string Kit::toString(){
	stringstream show;
	show << "----------------------------------------------------------------------------------------------" << endl;
	show << "| Nombre del Kit: " << nombre	<< "\tCodigo del kit: " << codigo << endl;
	show << Empaquetado->toString();
	return show.str();
}

// Desarrollo del agregar
void Kit::agregar(Componente* com){ 
	Empaquetado->ingresar(*com);
	cantItems++;
}


// Desarrollo del metodo guardar
void Kit::guardar(ostream& salida) {
	Nodo<Componente>* e = Empaquetado->getPrimero();
	salida << "Kit" << DELIMITA_CAMPO;
	salida << nombre << DELIMITA_CAMPO;
	salida << codigo << DELIMITA_CAMPO;
	while (e != NULL) {
		if (e->getDato() != NULL) {
			e->getDato()->guardar(salida);
		}
		e = e->getSiguiente();
	}
	salida << "finKit" << DELIMITA_CAMPO;
}

// Desarrollo del metodo recuperar
Componente* Kit::recuperar(istream& entrada){
	string op = "g", nombre, codigo;
	Componente* kit = new Kit();
	getline(entrada, nombre, DELIMITA_CAMPO);
	getline(entrada, codigo, DELIMITA_CAMPO);
	kit->setCodigo(codigo);
	kit->setNombre(nombre);
	while (op != "finKit") {
		getline(entrada, op, DELIMITA_CAMPO);
		if (op == "Unidad CD") {
			kit->agregar(UnidadCD::recuperar(entrada));
		}
		if (op == "Tornamesa") {
			kit->agregar(Tornamesa::recuperar(entrada));
		}
		if (op == "Radio") {
			kit->agregar(Radio::recuperar(entrada));
		}
		if (op == "Unidad Bluetooth") {
			kit->agregar(UnidadBluetooth::recuperar(entrada));
		}
		if (op == "Microfono") {
			kit->agregar(Microfono::recuperar(entrada));
		}
		if (op == "Amplificador") {
			kit->agregar(Amplificador::recuperar(entrada));
		}
		if (op == "Mezclador") {
			kit->agregar(Mezclador::recuperar(entrada));
		}
		if (op == "Altavoz") {
			kit->agregar(Altavoz::recuperar(entrada));
		}
		if (op == "Audifono") {
			kit->agregar(Audifono::recuperar(entrada));
		}
	}
	return kit;
}