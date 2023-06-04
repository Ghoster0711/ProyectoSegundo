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

void Tienda::guardarFacturas()  {}
Factura* Tienda::recuperarFacturas(istream& entrada) {}