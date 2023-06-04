#include "Factura.h"

Factura::Factura() {
	codigo = "";
	fecha = NULL;
	cliente = NULL;
	destino = NULL;
	combo = NULL;
}

Factura::Factura(string cod, Fecha* fec, Cliente* cli, Destino* des, Componente* com){
	codigo = cod;
	fecha = fec;
	cliente = clonarCliente(cli);
	destino = clonarDestino(des);
	combo = com;
}

Factura::~Factura(){
	if (fecha != NULL)delete fecha;
	if (cliente != NULL) delete cliente;
	if (destino != NULL) delete destino;
	if (combo != NULL) delete combo;
}

string Factura::getCodigo() { return codigo; }

Fecha* Factura::getFecha() { return fecha; }

Cliente* Factura::getCliente() { return cliente; }

Destino* Factura::getDestino() { return destino; }

Componente* Factura::getCombo() { return combo; }

void Factura::setCodigo(string cod){ codigo = cod; }

void Factura::setFecha(Fecha* fec) { fecha = fec; }

void Factura::setCliente(Cliente* cli){ cliente = cli; }

void Factura::setDestino(Destino* des){ destino = des; }

void Factura::setCombo(Componente* com){ combo = com; }

string Factura::toString() {
	stringstream show;
	show << "--------------FACTURA---------------" << endl
		<< "| Numero de Factura: " << codigo << endl << endl
		<< "| Fecha: "<< fecha->toString() << endl << endl
		<< "| Cliente: " << endl << cliente->toString() << endl << endl
		<< "| Destino: " << endl << destino->toString() << endl << endl
		<< "-------INFORMACION DE LA COMPRA------" << endl
		//<< combo->toString() << endl
		<< "-------------------------------------" << endl;
	return show.str();
}

Cliente* Factura::clonarCliente(Cliente* client) {
	string type,nom, ced, cor, tel;
	type= typeid(*(client)).name();
	nom = client->getNombre();
	ced = client->getCedula();
	cor = client->getCorreo();
	tel = client->getTelefono();
	if (type == "class Persona") {
		return new Persona(nom, ced, cor, tel);
	}
	if (type == "class Empresa") {
		return new Empresa(nom, ced, cor, tel);
	}
}
Destino* Factura::clonarDestino(Destino* dest) {
	string cod, pais, ciud;
	double cost;
	cod = dest->getCodigo();
	pais = dest->getPais();
	ciud = dest->getCiudad();
	cost = dest->getCostoTraslado();
	return new Destino(cod, pais, ciud, cost);
}

void Factura::guardarDatos(ostream& salida) {
	string type = typeid(*(cliente)).name();
	salida << codigo << DELIMITA_REGISTRO
		<< type << DELIMITA_REGISTRO;
	cliente->guardarDatos(salida);
	fecha->guardarDatos(salida);
	destino->guardarDatos(salida);
	//Guardar el combo 

}
Factura* Factura::recuperarDatos(istream& entrada) {
	Factura* factura = new Factura();
	string cod, type, nom, ced, cor, tel;
	getline(entrada, cod, DELIMITA_REGISTRO);
	getline(entrada, type, DELIMITA_REGISTRO);
	if (type == "class Persona") {
		Cliente* cliente = Persona::recuperarDatos(entrada);
		factura->setCliente(cliente);
	}
	if (type == "class Empresa") {
		Cliente* cliente = Empresa::recuperarDatos(entrada);
		factura->setCliente(cliente);
	}
	Fecha* fec = Fecha::recuperarDatos(entrada);
	Destino* destino = Destino::recuperarDatos(entrada);
	factura->setCodigo(cod);
	factura->setFecha(fec);
	factura->setDestino(destino);
	
	//Recuperar el combo 
	return factura;
}
