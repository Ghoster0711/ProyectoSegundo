#include "Directo.h"

Directo::Directo() {
	codigo = "";
	fecha = NULL;
	cliente = NULL;
	carritoDeCompras = NULL;
}
Directo::Directo(string cod, Fecha* fecha, Cliente* cli): Factura(cod, fecha, cli){}
Directo::~Directo(){}

string Directo::toString() {
	stringstream show;
	show << "--------------Factura---------------" << endl
		<< "| Codigo de factura: " << codigo << endl
		<< "| Fecha: " << fecha->toString() << endl
		<< "| Cliente: " << cliente->toString() << endl
		<< "-------INFORMACION DE LA COMPRA------" << endl
		<< carritoDeCompras->toString() << endl
		<< "-------------------------------------" << endl;
	return show.str();
}

void Directo::guardarDatos(ostream& salida) {
	string typeCliente;
	typeCliente = typeid((cliente)).name();
	salida << codigo << DELIMITA_REGISTRO
		<< typeCliente << DELIMITA_REGISTRO;
	cliente->guardarDatos(salida);
	fecha->guardarDatos(salida);
	carritoDeCompras->guardarDatos(salida);
}

Directo* Directo::recuperarDatos(istream& entrada) {
	string typeCliente, codigo;
	Directo* factura = new Directo();
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
	Lista<Factura>* ventas = Lista<Factura>::recuperarDatos(entrada);
	factura->setCodigo(codigo);
	factura->setCliente(cliente);
	factura->setFecha(fecha);
	factura->setLista(ventas);
	return factura;
}