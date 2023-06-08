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
EnLinea::EnLinea(string cod, Cliente* cli, Destino* des) {
	codigo = cod;
	fecha = new Fecha();
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
	salida << "Factura En Linea" << DELIMITA_CAMPO;
	salida	<< codigo << DELIMITA_CAMPO;
	fecha->guardarDatos(salida);
	cliente->guardar(salida);
	destino->guardar(salida);
	carritoDeCompras->guardarCarritoDeCompras(salida);
}


Factura* EnLinea::recuperar(istream& entrada) {
	string typeCliente, codigo;
	Factura* factura = new EnLinea();
	Cliente* cliente = NULL;
	getline(entrada, codigo, DELIMITA_CAMPO);
	Fecha* fecha = Fecha::recuperarDatos(entrada);
	getline(entrada, typeCliente, DELIMITA_CAMPO);
	if (typeCliente == "Persona") {
		cliente = Persona::recuperar(entrada);
	}
	if (typeCliente == "Empresa") {
		cliente = Empresa::recuperar(entrada);
	}
	Destino* destino = Destino::recuperar(entrada);
	recuperarCarrito(entrada, factura);
	factura->setCodigo(codigo);
	factura->setCliente(cliente);
	factura->setFecha(fecha);
	factura->setDestino(destino);
	return factura;
}

void EnLinea::recuperarCarrito(istream& entrada, Factura* fac) {
	string op;
	while (op != "finCarrito") {
		getline(entrada, op, DELIMITA_CAMPO);
		if (op == "Fuente de audio")
			fac->getCarrito()->ingresar(*FuenteDeAudio::recuperar(entrada));
		if (op == "Procesador de senal")
			fac->getCarrito()->ingresar(*ProcesadorDeSenal::recuperar(entrada));
		if (op == "Parlante")
			fac->getCarrito()->ingresar(*Parlante::recuperar(entrada));
		if (op == "Kit")
			fac->getCarrito()->ingresar(*Kit::recuperar(entrada));
	}
}