#include "Tienda.h"

Tienda::Tienda() {
	Catalogo = new Lista<Componente>();
	Suscriptores = new Lista<Cliente>();
	Ventas = new Lista<Factura>();
}

Tienda::~Tienda(){
	if (Catalogo != NULL) delete Catalogo;
	if (Suscriptores != NULL) delete Suscriptores;
	if (Ventas != NULL) delete Ventas;
}

Lista<Componente>* Tienda::getCatalago() { return Catalogo; }

Lista<Cliente>* Tienda::getSuscriptores() { return Suscriptores; }

Lista<Factura>* Tienda::getVentas() { return Ventas; }

void Tienda::guardarCatalogo() {
	string rutaCatalogo = "../catalogo.txt";
	ofstream salida;
	salida.open(rutaCatalogo);
	Catalogo->guardarDatos(salida);
}
void Tienda::recuperarArchivoCatalogo(){
	string rutaCatalogo = "../catalogo.txt";
	ifstream file;
	string op;
	file.open(rutaCatalogo);
	while (file.good()) {
		Catalogo->recuperarDatos(file);
		/*getline(file, op, DELIMITA_CAMPO);
		if (op == "Fuente de audio")
			Catalogo->ingresar(FuenteDeAudio::recuperarDatos(file));
		if (op == "Procesador de senal")
			Catalogo->ingresar(ProcesadorDeSenal::recuperarDatos(file));
		if (op == "Parlante")
			Catalogo->ingresar(Parlante::recuperarDatos(file));
		if (op == "Kit")
			Catalogo->ingresar(Kit::recuperarDatos(file)); 
		if (op == "Dispositivos")
			Catalogo->ingresar(Dispositivos::recuperarDatos(file));*/
	}
	file.close();
}

void Tienda::guardarFacturas()  {
	string rutaFacturas = "../facturas.txt";
	ofstream salida;
	salida.open(rutaFacturas);
	Ventas->guardarDatos(salida);
	salida.close();
}
void Tienda::recuperarArchivoFacturas() {
	string rutaFacturas = "../facturas.txt";
	ifstream entrada;
	entrada.open(rutaFacturas);
	while (entrada.good()) {
		Ventas->recuperarDatos(entrada);
	}
	entrada.close();
}

