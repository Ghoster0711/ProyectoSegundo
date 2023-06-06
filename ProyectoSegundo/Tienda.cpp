#include "Tienda.h"


Tienda::Tienda() {
	Catalogo = new Lista<Componente>();
	Suscriptores = new Lista<Cliente>();
	//Ventas = new Lista<Factura>();
}

Tienda::~Tienda(){
	if (Catalogo != NULL) delete Catalogo;
	if (Suscriptores != NULL) delete Suscriptores;
	//if (Ventas != NULL) delete Ventas;
}

Lista<Componente>* Tienda::getCatalago() { return Catalogo; }

Lista<Cliente>* Tienda::getSuscriptores() { return Suscriptores; }

string Tienda::mostrarElCatalogo(){
	return Catalogo->toString();
}

//Lista<Factura>* Tienda::getVentas() { return Ventas; }


bool Tienda::buscarProductoDelCatalogo(string cod){
	Nodo<Componente>* e = Catalogo->getPrimero();
	while (e != NULL) {
		if (e->getDato() != NULL) {
			if (e->getDato()->getCodigo() == cod)
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
			if (tipo != "class Kit" && tipo != "class Dispositivo") {
				if (e->getDato()->getCodigo() == cod) {
					return true;
				}
			}
		}
		e = e->getSiguiente();
	}
	return false;
}

string Tienda::mostrarSoloComponentes() {
	stringstream show;
	string tipo;
	Nodo<Componente>* e = Catalogo->getPrimero();
	while (e != NULL) {
		if (e->getDato() != NULL) {
			tipo = typeid(*e->getDato()).name();
			if (tipo != "class Kit" && tipo != "class Dispositivo")
				show << e->getDato()->toString();
		}
		e = e->getSiguiente();
	}
	return show.str();
}

Componente* Tienda::retornarSoloComponentes(string cod) {
	string tipo;
	Nodo<Componente>* e = Catalogo->getPrimero();
	while (e != NULL) {
		if (e->getDato() != NULL) {
			tipo = typeid(*e->getDato()).name();
			if (tipo != "class Kit" && tipo != "class Dispositivo") {
				if (e->getDato()->getCodigo() == cod) {
					if (tipo == "class FuenteDeAudio") {
						return (Componente*)new FuenteDeAudio(*(FuenteDeAudio*)e->getDato());
					}
					if (tipo == "class Parlante") {
						return (Componente*)new Parlante(*(Parlante*)e->getDato());
					}
					if (tipo == "class ProcesadorDeSenal") {
						return (Componente*)new ProcesadorDeSenal(*(ProcesadorDeSenal*)e->getDato());
					}
				}
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

void Tienda::ingresarCliente(Cliente* cli){
	Suscriptores->ingresar(cli);
}

string Tienda::verCatalogo(){
	stringstream show;
	show << Catalogo->toString();
	return show.str();
}

void Tienda::ingresarProductosAlCatalogo(Componente* compo){
	Catalogo->ingresar(compo);
}

void Tienda::EliminarProducto(string cod) {
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
		if (op == "Fuente de audio")
			Catalogo->ingresar(FuenteDeAudio::recuperar(file));
		if (op == "Procesador de senal")
			Catalogo->ingresar(ProcesadorDeSenal::recuperar(file));
		if (op == "Parlante")
			Catalogo->ingresar(Parlante::recuperar(file));
		if (op == "Kit")
			Catalogo->ingresar(Kit::recuperar(file)); 
		if (op == "Dispositivo")
			Catalogo->ingresar(Dispositivo::recuperar(file));
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
			Suscriptores->ingresar(Empresa::recuperar(file));
		if (op == "Persona")
			Suscriptores->ingresar(Persona::recuperar(file));
	}
	file.close();
}

void Tienda::recuperarDeArchivos(){
	recuperarArchivoCatalogo();
	recuperarArchivoSuscriptores();
}

//void Tienda::guardarFacturas()  {}
//Factura* Tienda::recuperarFacturas(istream& entrada) {}

void mostrarClientes(){
	
}
