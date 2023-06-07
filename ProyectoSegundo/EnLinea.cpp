#include "EnLinea.h"

// Desarrollo del constructor
EnLinea::EnLinea() {
	codigo = "";
	fecha = NULL;
	cliente = NULL;
	carritoDeCompras = NULL;
	destino = NULL;
}


// Desarrollo del constructor parametrizado
EnLinea::EnLinea(string cod, Fecha* fec, Cliente* cli, Destino* des) {
	codigo = cod;
	fecha = fec;
	cliente = clonarCliente(cli);
	carritoDeCompras = new Lista<Componente>();
	destino = des;
}

// Desarrollo destructor
EnLinea::~EnLinea() {
	if (destino != NULL) delete destino;
}

// Desarrollo de los get's
string EnLinea::getCodigo() { return codigo; }
Fecha* EnLinea::getFecha() { return fecha; }
Cliente* EnLinea::getCliente() { return cliente; }
Lista<Componente>* EnLinea::getCarrito() { return carritoDeCompras; }
Destino* EnLinea::getDestino() { return destino; }

// Desarrollo de los set's
void EnLinea::setCodigo(string cod) { codigo = cod; }
void EnLinea::setFecha(Fecha* fec) { fecha = fec; }
void EnLinea::setCliente(Cliente* clie) { cliente = clie; }
void EnLinea::setLista(Lista<Componente>* carrito) { carritoDeCompras = carrito; }
void EnLinea::setDestino(Destino* dest) { destino = dest; }

// Desarrollo del metodo clonar destino
Destino* EnLinea::clonarDestino(Destino* dest) {
	return (Destino*) new Destino(*(Destino*)dest);
}

// Desarrollo del metodo clonar cliente
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


// Desarrollo del metodo clonar componente
Componente* EnLinea::clonarComponente(Componente* compo) {
	string tipo;
	tipo = typeid(compo).name();
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

// Desarrollo del ingresar compra
void EnLinea::ingresarCompra(Componente* componente) {
	carritoDeCompras->ingresar(*clonarComponente(componente));
}

// Desarrollo del ToString
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


// Desarrollo del metodo guardar
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


Factura* EnLinea::recuperar(istream& entrada) {
	string typeCliente, codigo;
	Factura* factura = new EnLinea();
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
	//Lista<Componente>* ventas = Lista<Componente>::recuperarCarritoDeCompras(entrada);
	Destino* destino = Destino::recuperarDatos(entrada);
	factura->setCodigo(codigo);
	factura->setCliente(cliente);
	factura->setFecha(fecha);
	//factura->setLista(ventas);
	factura->setDestino(destino);
	return factura;
}