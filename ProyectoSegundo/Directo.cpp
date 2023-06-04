//#include "Directo.h"
//
//Directo::Directo(string num, Cliente* cli, Componente* com): Factura(num, cli, com){}
//Directo::~Directo(){}
//
//string Directo::getNumFactura() { return numFactura; }
//
//Cliente* Directo::getCliente() { return cliente; }
//
//Destino* Directo::getDestino() { return destino; }
//
//Componente* Directo::getCombo() { return combo; }
//
//void Directo::setNumFactura(string num) { numFactura = num; }
//
//void Directo::setCliente(Cliente* cli) { cliente = cli; }
//
//void Directo::setDestino(Destino* des) { destino = des; }
//
//void Directo::setCombo(Componente* com) { combo = com; }
//
//string Directo::toString() {
//	stringstream show;
//	show << "--------------Factura---------------" << endl
//		<< "| Numero de factura: " << numFactura << endl
//		<< "| Cliente: " << cliente->toString() << endl
//		<< "| Destino: " << destino->toString() << endl
//		<< "-------INFORMACION DE LA COMPRA------" << endl
//		<< combo->toString() << endl
//		<< "-------------------------------------" << endl;
//	return show.str();
//}