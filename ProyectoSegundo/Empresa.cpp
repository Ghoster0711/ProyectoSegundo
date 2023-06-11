#include"Empresa.h"

// Desarrollo del constructor
Empresa::Empresa() : Cliente() {}

// Desarrollo del constructor parametrizado
Empresa::Empresa(string nom, string ced, string pais, string ciudad) : Cliente(nom, ced, pais, ciudad) {}

// Desarroolo del destructor
Empresa::~Empresa() {}


// Desarrollo de los get's
string Empresa::getID() { return cedula; }
string Empresa::getNombre() { return nombre; }
string Empresa::getCedula() { return cedula; }
string Empresa::getNombrePais() { return nombrePais; }
string Empresa::getCiudadUbicacion() { return ciudadUbicacion; }
string Empresa::getCorreo() { return ""; }
string Empresa::getNacionalidad() { return ""; }

// Desarrollo de los set's
void Empresa::setNombre(string nom) { nombre = nom; }
void Empresa::setCedula(string ced) { cedula = ced; }
void Empresa::setNombrePais(string pais) { nombrePais = pais; }
void Empresa::setCiudadUbicacion(string cuidad) { ciudadUbicacion = cuidad; }
void Empresa::setCorreo(string){}
void Empresa::setNacionalidad(string){}

// Desarrollo del ToString
string Empresa::toString() {
	stringstream s;
	 s  << "| Nombre: " << nombre << endl
		<< "| Cedula: " << cedula << endl
		<< "| Pais: " << nombrePais << endl
		<< "| Ciudad de Ubicacion: " << ciudadUbicacion;
	return s.str();
}

// Desarrollo del metodo para guardar
void Empresa::guardar(ostream& salida) {
	salida << "Empresa" << DELIMITA_CAMPO
		<< nombre << DELIMITA_CAMPO
		<< cedula << DELIMITA_CAMPO
		<< nombrePais << DELIMITA_CAMPO
		<< ciudadUbicacion << DELIMITA_REGISTRO;
}

// Desarrollo del metodo para recuperar
Empresa* Empresa::recuperar(istream& entrada) {
	string nom, ced, pais, ciudad;
	getline(entrada, nom, DELIMITA_CAMPO);
	getline(entrada, ced, DELIMITA_CAMPO);
	getline(entrada, pais, DELIMITA_CAMPO);
	getline(entrada, ciudad, DELIMITA_REGISTRO);

	return new Empresa(nom, ced, pais, ciudad);
}