#include "Tienda.h"


Tienda::Tienda() {
	Catalogo = new Lista<Componente>();
	Suscriptores = new Lista<Cliente>();
	Ventas = new Lista<Factura>();
	Destinos = new Lista<Destino>();
}

Tienda::~Tienda(){
	if (Catalogo != NULL) delete Catalogo;
	if (Suscriptores != NULL) delete Suscriptores;
	if (Ventas != NULL) delete Ventas;
	if (Destinos != NULL) delete Destinos;
}

Lista<Componente>* Tienda::getCatalago() { return Catalogo; }

Lista<Cliente>* Tienda::getSuscriptores() { return Suscriptores; }

Lista<Factura>* Tienda::getVentas() { return Ventas; }

Lista<Destino>* Tienda::getDestinos() { return Destinos; }

string Tienda::mostrarElCatalogo(){
	return Catalogo->toString();
}
string Tienda::mostrasDestinos() {
	return Destinos->toString();
}
bool Tienda::buscarSuscriptor(string cod)
{
	Nodo<Cliente>* e = Suscriptores->getPrimero();
	while (e != NULL) {
		if (e->getDato() != NULL) {
			if (e->getDato()->getID() == cod)
				return true;
		}
		e = e->getSiguiente();
	}
	return false;
}

bool Tienda::buscarProductoDelCatalogo(string cod){
	Nodo<Componente>* e = Catalogo->getPrimero();
	while (e != NULL) {
		if (e->getDato() != NULL) {
			if (e->getDato()->getID() == cod)
				return true;
		}
		e = e->getSiguiente();
	}
	return false;
}

bool Tienda::buscarComponente(string cod) {
	string tipo;
	Nodo<Componente>* e = Catalogo->getPrimero();
	while (e != NULL) {
		if (e->getDato() != NULL) {
			tipo = typeid(*e->getDato()).name();
			if (tipo != "class Kit") {
				if (e->getDato()->getID() == cod) {
					return true;
				}
			}
		}
		e = e->getSiguiente();
	}
	return false;
}

bool Tienda::buscarKit(string cod) {
	string tipo;
	Nodo<Componente>* e = Catalogo->getPrimero();
	while (e != NULL) {
		if (e->getDato() != NULL) {
			tipo = typeid(*e->getDato()).name();
			if (tipo == "class Kit") {
				if (e->getDato()->getID() == cod) {
					return true;
				}
			}
		}
		e = e->getSiguiente();
	}
	return false;
}

bool Tienda::buscarDestino(string cod) {
	Nodo<Destino>* e = Destinos->getPrimero();
	while (e != NULL) {
		if (e->getDato() != NULL) {
			if (e->getDato()->getCodigo() == cod) {
				return true;
			}
		}
		e = e->getSiguiente();
	}
	return false;
}

Componente* Tienda::retornarSoloComponentes(string cod) {
	string tipo;
	Nodo<Componente>* e = Catalogo->getPrimero();
	while (e != NULL) {
		if (e->getDato() != NULL) {
			tipo = typeid(*e->getDato()).name();
			if (tipo != "class Kit") {
				if (e->getDato()->getCodigo() == cod) {
					if (tipo == "class UnidadCD") {
						return (Componente*)new UnidadCD(*(UnidadCD*)e->getDato());
					}
					if (tipo == "class Tornamesa") {
						return (Componente*)new Tornamesa(*(Tornamesa*)e->getDato());
					}
					if (tipo == "class Radio") {
						return (Componente*)new Radio(*(Radio*)e->getDato());
					}
					if (tipo == "class UnidadBluetooth") {
						return (Componente*)new UnidadBluetooth(*(UnidadBluetooth*)e->getDato());
					}
					if (tipo == "class Microfono") {
						return (Componente*)new Microfono(*(Microfono*)e->getDato());
					}
					if (tipo == "class Amplificador") {
						return (Componente*)new Amplificador(*(Amplificador*)e->getDato());
					}
					if (tipo == "class Mezclador") {
						return (Componente*)new Mezclador(*(Mezclador*)e->getDato());
					}
					if (tipo == "class Altavoz") {
						return (Componente*)new Altavoz(*(Altavoz*)e->getDato());
					}
					if (tipo == "class Audifono") {
						return (Componente*)new Audifono(*(Audifono*)e->getDato());
					}
				}
			}
		}
		e = e->getSiguiente();
	}
	return NULL;
}

string Tienda::mostrarSoloComponentes() {
	stringstream show;
	string tipo;
	Nodo<Componente>* e = Catalogo->getPrimero();
	while (e != NULL) {
		if (e->getDato() != NULL) {
			tipo = typeid(*e->getDato()).name();
			if (tipo != "class Kit" && tipo != "class Dispositivo")
				show << e->getDato()->toString() << endl;
		}
		e = e->getSiguiente();
	}
	return show.str();
}

Componente* Tienda::retornarSoloKits(string cod){
	string tipo;
	Nodo<Componente>* e = Catalogo->getPrimero();
	while (e != NULL) {
		if (e->getDato() != NULL) {
			tipo = typeid(*e->getDato()).name();
			if (tipo == "class Kit") {
				if (e->getDato()->getCodigo() == cod) {
					return (Componente*)new Kit(*(Kit*)e->getDato());
				}
			}
		}
		e = e->getSiguiente();
	}
	return NULL;
}

string Tienda::mostrarSoloKits(){
	stringstream show;
	string tipo;
	Nodo<Componente>* e = Catalogo->getPrimero();
	while (e != NULL) {
		if (e->getDato() != NULL) {
			tipo = typeid(*e->getDato()).name();
			if (tipo == "class Kit")
				show << e->getDato()->toString() << endl;
		}
		e = e->getSiguiente();
	}
	return show.str();
}

Destino* Tienda::retornaDestino(string cod) {
	Nodo<Destino>* e = Destinos->getPrimero();
	while (e != NULL) {
		if (e->getDato() != NULL) {
			if (e->getDato()->getCodigo() == cod) {
				return new Destino(*(e->getDato()));
			}
		}
		e = e->getSiguiente();
	}
	return NULL;
}
Cliente* Tienda::retornaSuscriptor(string cedula) {
	string tipo;
	Nodo<Cliente>* e = Suscriptores->getPrimero();
	while (e != NULL) {
		if (e->getDato() != NULL) {
			if (e->getDato()->getID() == cedula) {
				tipo = typeid(*e->getDato()).name();
				if (tipo == "class Persona")
					return (Cliente*) new Persona(*(Persona*)(e->getDato()));
				if (tipo == "class Empresa")
					return (Cliente*) new Empresa(*(Empresa*)(e->getDato()));
			}
		}
		e = e->getSiguiente();
	}
	return NULL;
}

// -------------Directo---------------

// -------------En Linea--------------

// -----------Mantenimiento-----------

string Tienda::mostrarClientes(){
	stringstream show;
	show << Suscriptores->toString();
	return show.str();;
}

bool Tienda::ingresarCliente(Cliente* cli){
	if (cli != NULL) {
		Suscriptores->ingresar(*cli);
		return true;
	}
	return false;
}

void Tienda::eliminarCliente(string cod)
{
	Suscriptores->eliminar(cod);
}

string Tienda::verCatalogo(){
	stringstream show;
	show << Catalogo->toString();
	return show.str();
}

bool Tienda::ingresarProductosAlCatalogo(Componente* compo){
	if (compo != NULL) {
		Catalogo->ingresar(*compo);
		return true;
	}
	return false;
}

void Tienda::eliminarProducto(string cod) {
	Catalogo->eliminar(cod);
}

// ------------Reportes---------------

// ------------Archivos---------------
void Tienda::guardarCatalogo()
{
	Catalogo->guardarCatalogo();
}

void Tienda::recuperarArchivoCatalogo(){
	string rutaCatalogo = "../catalogo.txt";
	ifstream file;
	string op;
	file.open(rutaCatalogo);
	while (file.good()) {
		
		getline(file, op, DELIMITA_CAMPO);
		if (op == "Unidad CD") {
			Catalogo->ingresar(*UnidadCD::recuperar(file));
		}
		if (op == "Tornamesa") {
			Catalogo->ingresar(*Tornamesa::recuperar(file));
		}
		if (op == "Radio") {
			Catalogo->ingresar(*Radio::recuperar(file));
		}
		if (op == "Unidad Bluetooth") {
			Catalogo->ingresar(*UnidadBluetooth::recuperar(file));
		}
		if (op == "Microfono") {
			Catalogo->ingresar(*Microfono::recuperar(file));
		}
		if (op == "Amplificador") {
			Catalogo->ingresar(*Amplificador::recuperar(file));
		}
		if (op == "Mezclador") {
			Catalogo->ingresar(*Mezclador::recuperar(file));
		}
		if (op == "Altavoz") {
			Catalogo->ingresar(*Altavoz::recuperar(file));
		}
		if (op == "Audifono") {
			Catalogo->ingresar(*Audifono::recuperar(file));
		}
		if (op == "Kit") {
			Catalogo->ingresar(*Kit::recuperar(file));
		}
	}
	file.close();
}

void Tienda::guardarSuscriptores()
{
	Suscriptores->guardarSuscriptores();
}

void Tienda::recuperarArchivoSuscriptores(){
	string rutaSuscriptores = "../suscriptores.txt";
	ifstream file;
	string op;
	file.open(rutaSuscriptores);
	while (file.good()) {
		getline(file, op, DELIMITA_CAMPO);
		if (op == "Empresa")
			Suscriptores->ingresar(*Empresa::recuperar(file));
		if (op == "Persona")
			Suscriptores->ingresar(*Persona::recuperar(file));
	}
	file.close();
}

void Tienda::guardarFacturas() {
	Ventas->guardarVentas();
}
void Tienda::recuperarFacturas() {
	string rutaVentas = "../ventas.txt";
	ifstream entrada;
	string tipo;
	entrada.open(rutaVentas);
	while (entrada.good()) {
		getline(entrada, tipo, DELIMITA_CAMPO);
		if (tipo == "EnLinea") {
			Ventas->ingresar(*EnLinea::recuperar(entrada));
		}
		if (tipo == "Directo") {
			Ventas->ingresar(*Directo::recuperar(entrada));
		}
	}
	entrada.close();
}

void Tienda::guardaDestinos() {
	Destinos->guardarDestinos();
}

void Tienda::recuperarArchivoDestinos() {
	string rutaDestinos = "../traslados.txt";
	ifstream entrada;
	entrada.open(rutaDestinos);
	while (entrada.good()) {
		if (entrada.good()) {
			Destinos->ingresar(*Destino::recuperar(entrada));
		}
	}
	entrada.close();
}

void Tienda::guardarArchivos(){
	guardarCatalogo();
	guardarSuscriptores();
	guardarFacturas();
	guardaDestinos();
}

void Tienda::recuperarDeArchivos(){
	recuperarArchivoCatalogo();
	recuperarArchivoSuscriptores();
	recuperarFacturas();
	recuperarArchivoDestinos();
	cout << Catalogo->toString() << endl << endl
		<< Suscriptores->toString() << endl << endl
		<< Ventas->toString() << endl << endl
		<< Destinos->toString() << endl << endl;
	system("pause");

}
