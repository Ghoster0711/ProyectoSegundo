#include "Directo.h"

Directo::Directo() {
	codigo = "";
	fecha = NULL;
	cliente = NULL;
	carritoDeCompras = NULL;
}
Directo::Directo(string cod, Fecha* fecha, Cliente* cli) {
	codigo = cod;
	this->fecha = fecha;
	cliente = clonarCliente(cli);
}
Directo::~Directo() {}

string Directo::getCodigo() { return codigo; }

Fecha* Directo::getFecha() { return fecha; }

Cliente* Directo::getCliente() { return cliente; }

Lista<Componente>* Directo::getCarrito() { return carritoDeCompras; }

Destino* Directo::getDestino() { return NULL; }

void Directo::setCodigo(string cod) { codigo = cod; }

void Directo::setFecha(Fecha* fec) { fecha = fec; }

void Directo::setCliente(Cliente* clie) { cliente = clie; }

void Directo::setLista(Lista<Componente>* carrito) { carritoDeCompras = carrito; }

void Directo::setDestino(Destino* dest) {}

Destino* Directo::clonarDestino(Destino* dest) {
	return NULL;
}

Cliente* Directo::clonarCliente(Cliente* cliente) {
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
Componente* Directo::clonarComponente(Componente* compo) {
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
void Directo::ingresarCompra(Componente* componente) {
	carritoDeCompras->ingresar(clonarComponente(componente));
}

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

void Directo::guardar(ostream& salida) {
	string type = typeid((cliente)).name();
	salida << "Factura En Linea" << DELIMITA_CAMPO;
	salida << codigo << DELIMITA_CAMPO;
	fecha->guardarDatos(salida);
	salida << type << DELIMITA_CAMPO;
	cliente->guardar(salida);
	carritoDeCompras->guardarCarritoDeCompras(salida);
}

//Directo* Directo::recuperarDatos(istream&);