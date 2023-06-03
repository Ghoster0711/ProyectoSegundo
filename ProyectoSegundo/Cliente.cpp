#include"Cliente.h"


Cliente::Cliente() {
	nombre = "";
	cedula = "";
	correo = "";
	telefono = "";
}
Cliente::Cliente(string nom, string ced, string cor, string tel) {
	nombre = nom;
	cedula = ced;
	correo = cor;
	telefono = tel;
}
Cliente::~Cliente() {}

//Get's 
string Cliente::getNombre() { return nombre; }
string Cliente::getCedula() { return cedula; }
string Cliente::getCorreo() { return correo; }
string Cliente::getTelefono() { return telefono; }

//Set's 
void Cliente::setNombre(string nom) { nombre = nom; }
void Cliente::setCedula(string ced) { cedula = ced; }
void Cliente::setCorreo(string cor) { correo = cor; }
void Cliente::setTelefono(string tel) { telefono = tel; }

