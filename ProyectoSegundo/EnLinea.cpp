#include "EnLinea.h"

EnLinea::EnLinea() {
	codigo = "";
	fecha = NULL;
	cliente = NULL;
	carritoDeCompras = NULL;
	destino = NULL;
}
EnLinea::EnLinea(string cod, Fecha* fecha, Cliente* cli,  Destino* des) : Factura(cod, fecha, cli), destino(des) {}
EnLinea::~EnLinea() {
	if (destino != NULL) delete destino;
}

Destino* EnLinea::getDestino() { return destino; }

void EnLinea::setDestino(Destino* des) { destino = des; }

string EnLinea::toString() {
	stringstream show;
	show << "--------------Factura---------------" << endl
		<< "| Codigo de factura: " << codigo << endl
		<< "| Fecha: " << fecha->toString() << endl
		<< "| Cliente: " << cliente->toString() << endl
		<< "| Destino: " << destino->toString() << endl
		<< "-------INFORMACION DE LA COMPRA------" << endl
		<< carritoDeCompras->toString() << endl
		<< "-------------------------------------" << endl;
	return show.str();
}

Destino* EnLinea::clonarDestino(Destino* dest) {
	string cod, pais, ciud;
	double cost;
	cod = dest->getCodigo();
	pais = dest->getPais();
	ciud = dest->getCiudad();
	cost = dest->getCostoTraslado();
	return new Destino(cod, pais, ciud, cost);
}

void EnLinea::guardarDatos(ostream& salida) {
	string typeCliente;
	typeCliente = typeid((cliente)).name();
	salida << codigo << DELIMITA_REGISTRO
		   << typeCliente << DELIMITA_REGISTRO;
	cliente->guardarDatos(salida);
	fecha->guardarDatos(salida);
	carritoDeCompras->guardarDatos(salida);
	destino->guardarDatos(salida);
}

EnLinea* EnLinea::recuperarDatos(istream& entrada) {
	string typeCliente, codigo;
	EnLinea* factura = new EnLinea();
	Cliente* cliente = NULL;
	getline(entrada, codigo, DELIMITA_REGISTRO);
	getline(entrada, typeCliente, DELIMITA_REGISTRO);
	if (typeCliente == "class Persona") {
		cliente = Persona::recuperarDatos(entrada);
	}
	if (typeCliente == "class Empresa") {
		cliente = Empresa::recuperarDatos(entrada);
	}
	Fecha* fecha = Fecha::recuperarDatos(entrada);
	Lista<Componente>* ventas = Lista<Componente>::recuperarDatos(entrada);
	Destino* destino = Destino::recuperarDatos(entrada);
	factura->setCodigo(codigo);
	factura->setCliente(cliente);
	factura->setFecha(fecha);
	factura->setLista(ventas);
	factura->setDestino(destino);
	return factura;
}