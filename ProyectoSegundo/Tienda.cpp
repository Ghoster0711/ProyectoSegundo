#include "Tienda.h"

Tienda::Tienda() {
	Catalogo = new Lista<Componente>();
	Envios = new Lista<Destino>();
	Suscriptores = new Lista<Cliente>();
	Ventas = new Lista<Factura>();
}

Tienda::~Tienda(){
	if (Catalogo != NULL) delete Catalogo;
	if (Envios != NULL) delete Envios;
	if (Suscriptores != NULL) delete Suscriptores;
	if (Ventas != NULL) delete Ventas;
}

Lista<Componente>* Tienda::getCatalago() { return Catalogo; }

Lista<Destino>* Tienda::getEnvios() { return Envios; }

Lista<Cliente>* Tienda::getSuscriptores() { return Suscriptores; }

Lista<Factura>* Tienda::getVentas() { return Ventas; }
