//#include "EnLinea.h"
//
//EnLinea::EnLinea(string num, Cliente* cli, Componente* com, Destino* des) : Factura(num, cli, com), destino(des) {}
//EnLinea::~EnLinea() {
//	if (destino != NULL) delete destino;
//}
//
//string EnLinea::getNumFactura() { return numFactura; }
//
//Cliente* EnLinea::getCliente() { return cliente; }
//
//Destino* EnLinea::getDestino() { return destino; }
//
//Componente* EnLinea::getCombo() { return combo; }
//
//void EnLinea::setNumFactura(string num) { numFactura = num; }
//
//void EnLinea::setCliente(Cliente* cli) { cliente = cli; }
//
//void EnLinea::setDestino(Destino* des) { destino = des; }
//
//void EnLinea::setCombo(Componente* com) { combo = com; }
//
//string EnLinea::toString() {
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