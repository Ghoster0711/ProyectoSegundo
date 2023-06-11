#include "Directo.h"

// Desarrollo del constructor
Directo::Directo() {
	codigo = "";
	fecha = NULL;
	cliente = NULL;
	carritoDeCompras = NULL;
}

// Desarrollo del constructor parametrizado
Directo::Directo(string cod, Cliente* cli) {
	codigo = cod;
	fecha = new Fecha();
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

 //Desarrollo de clonar componente
Componente* Directo::clonarComponente(Componente* compo) {
	string tipo;
	tipo = typeid(*compo).name();
	if (tipo == "class Kit") {
		return (Componente*)new Kit(*(Kit*)compo);
	}
	if (tipo == "class UnidadCD") {
		return (Componente*)new UnidadCD(*(UnidadCD*)compo);
	}
	if (tipo == "class Tornamesa") {
		return (Componente*)new Tornamesa(*(Tornamesa*)compo);
	}
	if (tipo == "class Radio") {
		return (Componente*)new Radio(*(Radio*)compo);
	}
	if (tipo == "class UnidadBluetooth") {
		return (Componente*)new UnidadBluetooth(*(UnidadBluetooth*)compo);
	}
	if (tipo == "class Microfono") {
		return (Componente*)new Microfono(*(Microfono*)compo);
	}
	if (tipo == "class Amplificador") {
		return (Componente*)new Amplificador(*(Amplificador*)compo);
	}
	if (tipo == "class Mezclador") {
		return (Componente*)new Mezclador(*(Mezclador*)compo);
	}
	if (tipo == "class Altavoz") {
		return (Componente*)new Altavoz(*(Altavoz*)compo);
	}
	if (tipo == "class Audifono") {
		return (Componente*)new Audifono(*(Audifono*)compo);
	}
	return NULL;
}

// Desarrollo de ingresar al componente
void Directo::ingresarCompra(Componente* componente) {
	if (componente != NULL) {
		carritoDeCompras->ingresar(*componente);
	}
}

// Desarrollo del ToString
string Directo::toString() {
	stringstream show;
	show << "--------------Factura---------------" << endl
		<< "Codigo de factura: " << codigo << endl
		<< "Fecha: " << fecha->toString() << endl
		<< "-------INFORMACION DEL CLIENTE------" << endl
		<< cliente->toString() << endl
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

//Desarrollo del metodo para recuperar el carrito de compras del cliente, del archivo 
void Directo::recuperarCarrito(istream& entrada, Factura* fac){
	string op;
	while (op != "finCarrito") {
		getline(entrada, op, DELIMITA_CAMPO);
		if (op == "Unidad CD") {
			fac->getCarrito()->ingresar(*UnidadCD::recuperar(entrada));
		}
		if (op == "Tornamesa") {
			fac->getCarrito()->ingresar(*Tornamesa::recuperar(entrada));
		}
		if (op == "Radio") {
			fac->getCarrito()->ingresar(*Radio::recuperar(entrada));
		}
		if (op == "Unidad Bluetooth") {
			fac->getCarrito()->ingresar(*UnidadBluetooth::recuperar(entrada));
		}
		if (op == "Microfono") {
			fac->getCarrito()->ingresar(*Microfono::recuperar(entrada));
		}
		if (op == "Amplificador") {
			fac->getCarrito()->ingresar(*Amplificador::recuperar(entrada));
		}
		if (op == "Mezclador") {
			fac->getCarrito()->ingresar(*Mezclador::recuperar(entrada));
		}
		if (op == "Altavoz") {
			fac->getCarrito()->ingresar(*Altavoz::recuperar(entrada));
		}
		if (op == "Audifono") {
			fac->getCarrito()->ingresar(*Audifono::recuperar(entrada));
		}
		if (op == "Kit")
			fac->getCarrito()->ingresar(*Kit::recuperar(entrada));
	}
}
