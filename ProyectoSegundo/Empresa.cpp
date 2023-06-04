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
void Empresa::guardarDatos(ostream& salida) {
	salida << nombre << DELIMITA_CAMPO
		<< cedula << DELIMITA_CAMPO
		<< correo << DELIMITA_CAMPO
		<< telefono << DELIMITA_REGISTRO;
}
Empresa* Empresa::recuperarDatos(istream& entrada) {
	Empresa* empresa = new Empresa();
	string nom, ced, cor, tel;
	getline(entrada, nom, DELIMITA_CAMPO);
	getline(entrada, ced, DELIMITA_CAMPO);
	getline(entrada, cor, DELIMITA_CAMPO);
	getline(entrada, tel, DELIMITA_REGISTRO);
	empresa->setNombre(nom);
	empresa->setCedula(ced);
	empresa->setCorreo(cor);
	empresa->setTelefono(tel);

	return empresa;
}