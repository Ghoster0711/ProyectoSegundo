#include"Empresa.h"

Empresa::Empresa() : Cliente() {}
Empresa::Empresa(string nom, string ced, string pais, string ciudad) : Cliente(nom, ced, pais, ciudad) {}

Empresa::~Empresa() {}

string Empresa::getID()
{
	return cedula;
}

string Empresa::getNombre() { return nombre; }

string Empresa::getCedula() { return cedula; }

string Empresa::getNombrePais() { return nombrePais; }

string Empresa::getCiudadUbicacion() { return ciudadUbicacion; }

string Empresa::getCorreo() { return ""; }

string Empresa::getNacionalidad() { return ""; }

void Empresa::setNombre(string nom) { nombre = nom; }

void Empresa::setCedula(string ced) { cedula = ced; }

void Empresa::setNombrePais(string pais) { nombrePais = pais; }

void Empresa::setCiudadUbicacion(string cuidad) { ciudadUbicacion = cuidad; }

void Empresa::setCorreo(string){}
void Empresa::setNacionalidad(string){}


string Empresa::toString() {
	stringstream s;
	 s  << "Nombre: " << nombre << endl
		<< "Cedula: " << cedula << endl
		<< "Pais: " << nombrePais << endl
		<< "Ciudad de Ubicacion: " << ciudadUbicacion << endl;
	return s.str();
}
void Empresa::guardar(ostream& salida) {
	salida << "Empresa" << DELIMITA_CAMPO
		<< nombre << DELIMITA_CAMPO
		<< cedula << DELIMITA_CAMPO
		<< nombrePais << DELIMITA_CAMPO
		<< ciudadUbicacion << DELIMITA_REGISTRO;
}
Empresa* Empresa::recuperar(istream& entrada) {
	string nom, ced, pais, ciudad;
	getline(entrada, nom, DELIMITA_CAMPO);
	getline(entrada, ced, DELIMITA_CAMPO);
	getline(entrada, pais, DELIMITA_CAMPO);
	getline(entrada, ciudad, DELIMITA_REGISTRO);

	return new Empresa(nom, ced, pais, ciudad);
}