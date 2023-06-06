#include "Factura.h"


Factura::Factura() {
	codigo = "";
	fecha = NULL;
	cliente = NULL;
	carritoDeCompras = NULL;
}

Factura::Factura(string cod, Fecha* fec, Cliente* cli) {
	codigo = cod;
	fecha = fec;
	cliente = clonarCliente(cli);
	carritoDeCompras = new Lista<Componente>();
}

Factura::~Factura() {
	if (fecha != NULL)delete fecha;
	if (cliente != NULL) delete cliente;
	if (carritoDeCompras != NULL) delete carritoDeCompras;
}

