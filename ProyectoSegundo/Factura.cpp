#include "Factura.h"

Factura::Factura(string cod, Cliente* cli, Componente* com){
	numFactura = cod;
	cliente = cli;
	combo = com;
}

Factura::~Factura(){
	if (cliente != NULL) delete cliente;
	if (destino != NULL) delete destino;
	if (combo != NULL) delete combo;
}


