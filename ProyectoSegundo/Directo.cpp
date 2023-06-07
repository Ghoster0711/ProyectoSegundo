#include "Directo.h"

Directo::Directo() {
	codigo = "";
	fecha = NULL;
	cliente = NULL;
	carritoDeCompras = NULL;
}
Directo::Directo(string cod, Fecha* fec, Cliente* cli) {
	codigo = cod;
	fecha = fec;
	cliente = clonarCliente(cli);
	carritoDeCompras = new Lista<Componente>();
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

Destino* Directo::clonarDestino(Destino*) {
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
	carritoDeCompras->ingresar(*clonarComponente(componente));
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
	salida << "Factura Directo" << DELIMITA_CAMPO;
	salida << codigo << DELIMITA_CAMPO;
	fecha->guardarDatos(salida);
	salida << type << DELIMITA_CAMPO;
	cliente->guardar(salida);
	carritoDeCompras->guardarCarritoDeCompras(salida);
}

Factura* Directo::recuperar(istream& entrada) {
	string typeCliente, codigo;
	Factura* factura = new Directo();
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
	Lista<Componente>* ventas = Lista<Componente>::recuperarCarritoDeCompras(entrada);
	factura->setCodigo(codigo);
	factura->setCliente(cliente);
	factura->setFecha(fecha);
	factura->setLista(ventas);
	return factura;
}