#include"Cliente.h"


Cliente::Cliente() {
	nombre = "";
	cedula = "";
	nombrePais = "";
	ciudadUbicacion = "";
}
Cliente::Cliente(string nom, string ced, string pais, string ciudad) {
	nombre = nom;
	cedula = ced;
	nombrePais = pais;
	ciudadUbicacion = ciudad;
}
Cliente::~Cliente() {}

//Get's 
string Cliente::getNombre() { return nombre; }
string Cliente::getCedula() { return cedula; }
string Cliente::getNombrePais() { return nombrePais; }
string Cliente::getCiudadUbicacion() { return ciudadUbicacion; }

//Set's 
void Cliente::setNombre(string nom) { nombre = nom; }
void Cliente::setCedula(string ced) { cedula = ced; }
void Cliente::setNombrePais(string pais) { nombrePais = pais; }
void Cliente::setCiudadUbicacion(string ciudad) { ciudadUbicacion = ciudad; }

