#include"Destino.h"

Destino::Destino() {
	codigo = "";
	pais = "";
	ciudad = "";
	costoTraslado = 0;
}
Destino::Destino(string cod, string pai, string ciud, double costo) {
	codigo = cod;
	pais = pai;
	ciudad = ciud;
	costoTraslado = costo;
}
Destino:: ~Destino(){}
string Destino::getCodigo() { return codigo; }
string Destino::getPais() { return pais; }
string Destino::getCiudad() { return ciudad; }
double Destino::getCostoTraslado() { return costoTraslado; }
void Destino::setCodigo(string cod) { codigo = cod; }
void Destino::setPais(string pa) { pais = pa; }
void Destino::setCiudad(string ciud) { ciudad = ciud; }
void Destino::setCostoTraslado(double cost) { costoTraslado = cost; }
string Destino::toString() {
	stringstream s;
	s << "----Informacion del Destino----" << endl
		<< "Codigo: " << codigo << endl
		<< "Pais: " << pais << endl
		<< "Ciudad: " << ciudad << endl
		<< "Costo de Traslado: " << costoTraslado << endl;
	return s.str();
}
void Destino::guardarDatos(ofstream& salida) {
	salida << codigo << DELIMITA_CAMPO 
		<< pais << DELIMITA_CAMPO 
		<< ciudad << DELIMITA_CAMPO 
		<< costoTraslado << DELIMITA_REGISTRO;
}
Destino* Destino::recuperarDatos(ifstream& entrada) {
	Destino* destino = new Destino();
	string cod, pais, ciudad, costo;
	getline(entrada, cod, DELIMITA_CAMPO);
	getline(entrada, pais, DELIMITA_CAMPO);
	getline(entrada, ciudad, DELIMITA_CAMPO);
	getline(entrada, costo, DELIMITA_REGISTRO);
	double cost = convertirDouble(costo);
	destino->setCodigo(cod);
	destino->setPais(pais);
	destino->setCiudad(ciudad);
	destino->setCostoTraslado(cost);
	return destino;
}