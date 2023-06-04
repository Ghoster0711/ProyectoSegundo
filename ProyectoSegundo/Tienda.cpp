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

//void Tienda::guardarFacturas()  {}
//Factura* Tienda::recuperarFacturas(istream& entrada) {}

