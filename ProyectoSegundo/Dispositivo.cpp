#include "Dispositivo.h"
#include "Utiles.h"
#include "FuenteDeAudio.h"
#include "ProcesadorDeSenal.h"
#include "Parlante.h"

#define DELIMITA_CAMPO '\t'
#define DELIMITA_REGISTRO '\n'

Dispositivo::Dispositivo()
{
nombre = "Sistema a la medida";
codigo = "";
caracteristica = "";
precio = 0;
}

Dispositivo::Dispositivo(string nom, string cod) {
	nombre = nom;
	codigo = cod;
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

void Dispositivo::setNombre(string nom)
{
	nombre = nom;
}

void Dispositivo::setCodigo(string cod)
{
	codigo = cod;
}

void Dispositivo::setCaracteristica(string carac)
{
	caracteristica = carac;
}

void Dispositivo::setPrecio(double pre) { precio = pre; }

string Dispositivo::toString() {
	stringstream show;
	show << "Nombre : " << nombre 
		<< "\tCodigo: " << codigo << endl;
	show << empaquetado->toString();
	return show.str();
}

string Dispositivo::getNombre()
{
	return nombre;
}

string Dispositivo::getCodigo()
{
	return codigo;
}

void Dispositivo::guardar(ostream& salida) {
	Nodo<Componente>* e = empaquetado->getPrimero();
	salida << "Dispositivo" << DELIMITA_CAMPO;
	salida << nombre << DELIMITA_CAMPO;
	salida << codigo << DELIMITA_CAMPO;
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
	string findispositivo, nombre, codigo;
	Componente* dispositivo = new Dispositivo();
	getline(entrada, nombre, DELIMITA_CAMPO);
	getline(entrada, codigo, DELIMITA_CAMPO);
	dispositivo->setCodigo(codigo);
	dispositivo->setNombre(nombre);
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