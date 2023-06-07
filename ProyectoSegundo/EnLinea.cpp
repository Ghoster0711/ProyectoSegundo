#include "EnLinea.h"

EnLinea::EnLinea() {
	codigo = "";
	fecha = NULL;
	cliente = NULL;
	carritoDeCompras = NULL;
	destino = NULL;
}
EnLinea::EnLinea(string cod, Fecha* fecha, Cliente* cli, Destino* des) : Factura(cod, fecha, cli), destino(des) {}
EnLinea::~EnLinea() {
	if (destino != NULL) delete destino;
}

string EnLinea::getCodigo() { return codigo; }

Fecha* EnLinea::getFecha() { return fecha; }

Cliente* EnLinea::getCliente() { return cliente; }

Lista<Componente>* EnLinea::getCarrito() { return carritoDeCompras; }

Destino* EnLinea::getDestino() { return destino; }

void EnLinea::setCodigo(string cod) { codigo = cod; }

void EnLinea::setFecha(Fecha* fec) { fecha = fec; }

void EnLinea::setCliente(Cliente* clie) { cliente = clie; }

void EnLinea::setLista(Lista<Componente>* carrito) { carritoDeCompras = carrito; }

void EnLinea::setDestino(Destino* dest) { destino = dest; }

Destino* EnLinea::clonarDestino(Destino* dest) {
	string cod, pais, ciud;
	double cost;
	cod = dest->getCodigo();
	pais = dest->getPais();
	ciud = dest->getCiudad();
	cost = dest->getCostoTraslado();
	return new Destino(cod, pais, ciud, cost);
}

Cliente* EnLinea::clonarCliente(Cliente* cliente) {
	string tipo;
	tipo = typeid(*cliente).name();
	if (tipo == "class Empresa") {
		return (Cliente*)new Empresa(*(Empresa*)cliente);
	}
	if (tipo == "class Persona") {
		return (Cliente*)new Persona(*(Persona*)cliente);
	}
	return NULL;
}
Componente* EnLinea::clonarComponente(Componente* compo) {
	string tipo;
	tipo = typeid(*compo).name();
	if (tipo == "class Kit") {
		return (Componente*)new Kit(*(Kit*)compo);
	}
	if (tipo == "class FuenteDeAudio") {
		return (Componente*)new FuenteDeAudio(*(FuenteDeAudio*)compo);
	}
	if (tipo == "class ProcesadorDeSenal") {
		return (Componente*)new ProcesadorDeSenal(*(ProcesadorDeSenal*)compo);
	}
	if (tipo == "class Parlante") {
		return (Componente*)new Parlante(*(Parlante*)compo);
	}
	return NULL;
}
void EnLinea::ingresarCompra(Componente* componente) {
	carritoDeCompras->ingresar(*clonarComponente(componente));
}


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

void EnLinea::guardar(ostream& salida) {
	string type = typeid((cliente)).name();
	salida << "Factura En Linea" << DELIMITA_CAMPO;
	salida	<< codigo << DELIMITA_CAMPO;
	fecha->guardarDatos(salida);
	salida << type << DELIMITA_CAMPO;
	cliente->guardar(salida);
	carritoDeCompras->guardarCarritoDeCompras(salida);
	destino->guardarDatos(salida);
}

EnLinea* EnLinea::recuperar(istream& entrada) {
	string typeCliente, codigo;
	EnLinea* factura = new EnLinea();
	Cliente* cliente = NULL;
	getline(entrada, codigo, DELIMITA_CAMPO);
	getline(entrada, typeCliente, DELIMITA_CAMPO);
	if (typeCliente == "class Persona") {
		cliente = Persona::recuperar(entrada);
	}
	if (typeCliente == "class Empresa") {
		cliente = Empresa::recuperar(entrada);
	}
	Fecha* fecha = Fecha::recuperarDatos(entrada);
	//Lista<Componente>* ventas = Lista<Componente>::recuperar(entrada);
	Destino* destino = Destino::recuperarDatos(entrada);
	factura->setCodigo(codigo);
	factura->setCliente(cliente);
	factura->setFecha(fecha);
	//factura->setLista(ventas);
	factura->setDestino(destino);
	return factura;
}