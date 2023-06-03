#include"Persona.h"

Persona::Persona(): Cliente() {}

Persona::Persona(string nom, string ced, string correo, string tel) : Cliente(nom,ced,correo,tel){}
Persona::~Persona(){}
string Persona::toString() {
	stringstream s;
	s << "Nombre: " << nombre << endl
		<< "Cedula: " << cedula << endl
		<< "Correo: " << correo << endl
		<< "Telefono: " << telefono << endl;
	return s.str();
}

void Persona::guardarDatos(ofstream& salida) {
	string clase = "Persona";
	salida << clase << DELIMITA_REGISTRO
		<< nombre << DELIMITA_CAMPO
		<< cedula << DELIMITA_CAMPO
		<< correo << DELIMITA_CAMPO
		<< telefono << DELIMITA_REGISTRO;
}
static Cliente* recuperarDatos(string nom,string ced,string correo,string tel) {
	return new Persona(nom, ced, correo, tel);
}