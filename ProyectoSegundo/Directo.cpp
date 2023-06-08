#include "Directo.h"

// Desarrollo del constructor
Directo::Directo() {
	codigo = "";
	fecha = NULL;
	cliente = NULL;
	carritoDeCompras = NULL;
}

// Desarrollo del constructor parametrizado
Directo::Directo(string cod, Fecha* fecha, Cliente* cli) {
	codigo = cod;
	fecha = fecha;
	cliente = clonarCliente(cli);
	carritoDeCompras = new Lista<Componente>();
}

// Desarrollo destructor
Directo::~Directo() {}

// Desarrollo de los get's
string Directo::getCodigo() { return codigo; }
Fecha* Directo::getFecha() { return fecha; }
Cliente* Directo::getCliente() { return cliente; }
Lista<Componente>* Directo::getCarrito() { return carritoDeCompras; }
Destino* Directo::getDestino() { return NULL; }

// Desarrollo de los set's
void Directo::setCodigo(string cod) { codigo = cod; }
void Directo::setFecha(Fecha* fec) { fecha = fec; }
void Directo::setCliente(Cliente* clie) { cliente = clie; }
void Directo::setLista(Lista<Componente>* carrito) { carritoDeCompras = carrito; }
void Directo::setDestino(Destino* dest) {}


// Desarrollo de clonar destino
Destino* Directo::clonarDestino(Destino* dest) { 
	return new Destino(*dest); 
}

// Desarrollo de clonar cliente
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

// Desarrollo de clonar componente
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

// Desarrollo de ingresar al componente
void Directo::ingresarCompra(Componente* componente) {
	carritoDeCompras->ingresar(*clonarComponente(componente));
}

// Desarrollo del ToString
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

// Desarrollo del metodo guardar 
void Directo::guardar(ostream& salida) {
	salida << "Factura Directo" << DELIMITA_CAMPO;
	salida << codigo << DELIMITA_CAMPO;
	fecha->guardarDatos(salida);
	cliente->guardar(salida);
	carritoDeCompras->guardarCarritoDeCompras(salida);
	salida << "finCarrito" << DELIMITA_CAMPO;
}


// Desarrollo del metodo recuperar
Factura* Directo::recuperar(istream& entrada) {
	string typeCliente, codigo;
	Factura* factura = new Directo();
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
	recuperarCarrito(entrada, factura);
	factura->setCodigo(codigo);
	factura->setCliente(cliente);
	factura->setFecha(fecha);
	return factura;
}

void Directo::recuperarCarrito(istream& entrada, Factura* fac){
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
