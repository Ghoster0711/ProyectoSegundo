#include"Persona.h"

Persona::Persona(): Cliente() {}

Persona::Persona(string nom, string ced, string correo, string tel) : Cliente(nom,ced,correo,tel){}
Persona::~Persona(){}
string Persona::toString() {
	stringstream s;
	s << "-----------------------------------------" << endl;
	s << "| Nombre: " << nombre << endl
	  << "| Cedula: " << cedula << endl
	  << "| Correo: " << correo << endl
	  << "| Telefono: " << telefono << endl;
	return s.str();
}

void Persona::guardar(ostream& salida) {
	salida << "Persona" << DELIMITA_CAMPO
		<< nombre << DELIMITA_CAMPO
		<< cedula << DELIMITA_CAMPO
		<< correo << DELIMITA_CAMPO
		<< telefono << DELIMITA_REGISTRO;
}
Persona* Persona::recuperar(istream& entrada){
	Persona* per = new Persona();
	string nom, ced, cor, tel;
	getline(entrada, nom, DELIMITA_CAMPO);
	getline(entrada, ced, DELIMITA_CAMPO);
	getline(entrada, cor, DELIMITA_CAMPO);
	getline(entrada, tel, DELIMITA_REGISTRO);
	per->setNombre(nom);
	per->setCedula(ced);
	per->setCorreo(cor);
	per->setTelefono(tel);
	return per;
}
