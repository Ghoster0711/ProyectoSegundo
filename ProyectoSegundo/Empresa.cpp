#include"Empresa.h"

Empresa::Empresa() : Cliente() {}

Empresa::Empresa(string nom, string ced, string correo, string tel) : Cliente(nom, ced, correo, tel) {}
Empresa::~Empresa() {}
string Empresa::toString() {
	stringstream s;
	s << "Nombre: " << nombre << endl
		<< "Cedula: " << cedula << endl
		<< "Correo: " << correo << endl
		<< "Telefono: " << telefono << endl;
	return s.str();
}
void Empresa::guardarDatos(ofstream& salida) {
	string clase = "Empresa";
	salida << clase << DELIMITA_REGISTRO
		<< nombre << DELIMITA_CAMPO
		<< cedula << DELIMITA_CAMPO
		<< correo << DELIMITA_CAMPO
		<< telefono << DELIMITA_REGISTRO;
}
static Cliente* recuperarDatos(string nom, string ced, string correo, string tel) {
	return new Empresa(nom, ced, correo, tel);
}