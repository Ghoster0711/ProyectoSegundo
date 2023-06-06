#include"Empresa.h"

Empresa::Empresa() : Cliente() {}

Empresa::Empresa(string nom, string ced, string pais, string ciudad) : Cliente(nom, ced, pais, ciudad) {}
Empresa::~Empresa() {}
string Empresa::toString() {
	stringstream s;
	s   << "Nombre: " << nombre << endl
		<< "Cedula: " << cedula << endl
		<< "Pais: " << nombrePais << endl
		<< "Ciudad de Ubicacion: " << ciudadUbicacion << endl;
	return s.str();
}
void Empresa::guardarDatos(ostream& salida) {
	salida << nombre << DELIMITA_CAMPO
		<< cedula << DELIMITA_CAMPO
		<< nombrePais << DELIMITA_CAMPO
		<< ciudadUbicacion << DELIMITA_REGISTRO;
}
Empresa* Empresa::recuperarDatos(istream& entrada) {
	Empresa* empresa = new Empresa();
	string nom, ced, pais, ciudad;
	getline(entrada, nom, DELIMITA_CAMPO);
	getline(entrada, ced, DELIMITA_CAMPO);
	getline(entrada, pais, DELIMITA_CAMPO);
	getline(entrada, ciudad, DELIMITA_REGISTRO);
	empresa->setNombre(nom);
	empresa->setCedula(ced);
	empresa->setNombrePais(pais);
	empresa->setCiudadUbicacion(ciudad);

	return empresa;
}