#include "Factura.h"

Factura::Factura(string cod, Cliente* cli, Destino* des, Componente* com){
	codigo = cod;
	cliente = cli;
	destino = des;
	combo = com;
}

Factura::~Factura(){
	if (cliente != NULL) delete cliente;
	if (destino != NULL) delete destino;
	if (combo != NULL) delete combo;
}

string Factura::getCodigo() { return codigo; }

Cliente* Factura::getCliente() { return cliente; }

Destino* Factura::getDestino() { return destino; }

Componente* Factura::getCombo() { return combo; }

void Factura::setCodigo(string cod){ codigo = cod; }

void Factura::setCliente(Cliente* cli){ cliente = cli; }

void Factura::setDestino(Destino* des){ destino = des; }

void Factura::setCombo(Componente* com){ combo = com; }

string Factura::toString() {
	stringstream show;
	show << "--------------FACTURA---------------" << endl
		<< "| Numero de Factura: " << codigo << endl
		<< "| Cliente: " /*<< cliente.toString()*/ << endl
		<< "| Destino: " /*<< destino.toString()*/ << endl
		<< "-------INFORMACION DE LA COMPRA------" << endl
		<< combo->toString() << endl
		<< "-------------------------------------" << endl;
	return show.str();
}
