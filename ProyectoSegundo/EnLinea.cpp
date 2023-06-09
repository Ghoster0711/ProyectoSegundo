#include "EnLinea.h"

// Desarrollo del constructor
EnLinea::EnLinea() {
	codigo = "";
	fecha = new Fecha();
	cliente = NULL;
	carritoDeCompras = new Lista<Componente>();
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
	if (fecha != NULL) delete fecha;
	if (cliente != NULL) delete cliente;
	if (destino != NULL) delete destino;
	delete carritoDeCompras;
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

// Desarrollo del ingresar compra
void EnLinea::ingresarCompra(Componente* componente) {
	if (componente != NULL) {
		carritoDeCompras->ingresar(*componente);
	}
	//carritoDeCompras->ingresar(*clonarComponente(componente));
}

// Desarrollo del ToString
string EnLinea::toString() {
	double subtotal = carritoDeCompras->obtenerPrecios();
	double adicional = subtotal * 0.35;
	double total = subtotal + adicional + destino->getCostoTraslado();
	stringstream show;
	show << "--------------------------------------------------Factura----------------------------------------------------------" << endl
		<< "| Codigo de factura: " << codigo << endl
		<< "| Fecha: " << fecha->toString() << endl
		<< "-------------------------------------------INFORMACION DEL CLIENTE-------------------------------------------------" << endl
		<< cliente->toString() << endl
		<< "-------------------------------------------INFORMACION DEL DESTINO-------------------------------------------------" << endl
		<< destino->toString() << endl
		<< "-------------------------------------------INFORMACION DE LA COMPRA------------------------------------------------" << endl
		<< carritoDeCompras->toString() << endl
		<< "-------------------------------------------------------------------------------------------------------------------" << endl
		<< "| Subtotal a Pagar: " << subtotal << endl
		<< "| Adicional: " << adicional << endl
		<< "| Precio de envio: " << destino->getCostoTraslado() << endl
		<< "-------------------------------------------------------------------------------------------------------------------" << endl
		<< "| Total a pagar: " << total << endl
		<< "-------------------------------------------------------------------------------------------------------------------" << endl;		

	return show.str();
}


// Desarrollo del metodo guardar
void EnLinea::guardar(ostream& salida) {
	salida << "EnLinea" << DELIMITA_CAMPO;
	salida	<< codigo << DELIMITA_CAMPO;
	fecha->guardarDatos(salida);
	cliente->guardar(salida);
	destino->guardar(salida);
	carritoDeCompras->guardarCarritoDeCompras(salida);
	salida << "finCarrito" << DELIMITA_CAMPO;
}

//Desarrollo del metodo para recuperar datos del archivo 
Factura* EnLinea::recuperar(istream& entrada) {
	string typeCliente, codigo;
	Factura* factura = new EnLinea();
	Cliente* cliente = NULL;
	Fecha* fecha = NULL;
	Destino* destino = NULL;

	getline(entrada, codigo, DELIMITA_CAMPO);
	fecha = Fecha::recuperarDatos(entrada);
	getline(entrada, typeCliente, DELIMITA_CAMPO);
	if (typeCliente == "Persona") {
		cliente = Persona::recuperar(entrada);
	}
	if (typeCliente == "Empresa") {
		cliente = Empresa::recuperar(entrada);
	}
	destino = Destino::recuperar(entrada);
	recuperarCarrito(entrada, factura);
	factura->setCodigo(codigo);
	factura->setCliente(cliente);
	factura->setFecha(fecha);
	factura->setDestino(destino);
	return factura;
}

//Desarrollo del metodo para recuperar el carrito de compras del cliente, del archivo 
void EnLinea::recuperarCarrito(istream& entrada, Factura* fac) {
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



double EnLinea::precioBrutoDeLaFactura() {
	double subtotal = carritoDeCompras->obtenerPrecios();
	double adicional = subtotal * 0.35;
	double total = subtotal + adicional + destino->getCostoTraslado();
	return total;
}

double EnLinea::precioNetoDeLaFactura() {
	double subtotal = carritoDeCompras->obtenerPrecios();
	double adicional = subtotal * 0.35;
	double total = subtotal;
	return total;
}

double EnLinea::ganaciasDeLaFactura() {
	double subtotal = carritoDeCompras->obtenerPrecios();
	double total = subtotal - precioBrutoDeLaFactura();
	return abs(total);
}



bool EnLinea::existenciaDeProducto(string cod) {
	Nodo<Componente>* pExt = carritoDeCompras->getPrimero();
	while (pExt != NULL) {
		if (pExt != NULL) {
			if (pExt->getDato()->getID() == cod) {
				cout << cod << endl << endl;
				cout << pExt->getDato()->getUnidades() << endl;
				return true;
			}
		}
		pExt = pExt->getSiguiente();
	}
	return false;
}


int EnLinea::obtenerUnidadesDeProductoBuscado(string cod) {
	Nodo<Componente>* pExt = carritoDeCompras->getPrimero();
	while (pExt != NULL) {
		if (pExt != NULL) {
			if (pExt->getDato()->getID() == cod)
				return pExt->getDato()->getUnidades();
		}
		pExt = pExt->getSiguiente();
	}
	return 0;
}