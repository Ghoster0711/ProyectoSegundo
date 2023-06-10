#include"Persona.h"

// Desarrollo del constructor
Persona::Persona() : Cliente() {}

// Desarrollo del constructor parametrizado
Persona::Persona(string nom, string ced, string pais, string ciudad, string correo, string nacio)
	: Cliente(nom, ced, pais, ciudad), correo(correo), nacionalidad(nacio) {}

// Desarrollo del destructor
Persona::~Persona() {}


// Desarrollo de los Get's
string Persona::getID(){ return cedula; }
string Persona::getNombre() { return nombre; }
string Persona::getCedula() { return cedula; }
string Persona::getNombrePais() { return nombrePais; }
string Persona::getCiudadUbicacion() { return ciudadUbicacion; }
string Persona::getCorreo() { return correo; }
string Persona::getNacionalidad() { return nacionalidad; }

// Desarrollo de los Set's
void Persona::setNombre(string nom) { nombre = nom; }
void Persona::setCedula(string ced) { cedula = ced; }
void Persona::setNombrePais(string pais) { nombrePais = pais; }
void Persona::setCiudadUbicacion(string cuidad) { ciudadUbicacion = cuidad; }
void Persona::setCorreo(string cor) { correo = cor; }
void Persona::setNacionalidad(string nacio) { nacionalidad; }

// Desarrollo del ToString
string Persona::toString() {
	stringstream s;
	s << "| Nombre: " << nombre << endl
		<< "| Cedula: " << cedula << endl
		<< "| Pais: " << nombrePais << endl
		<< "| Ciudad de Ubicacion: " << ciudadUbicacion << endl
		<< "| Correo: " << correo << endl
		<< "| Nacionalidad: " << nacionalidad;
	return s.str();
}

// Desarrollo del metodo para guardar
void Persona::guardar(ostream& salida) {
	salida << "Persona" << DELIMITA_CAMPO
		   << nombre << DELIMITA_CAMPO
		   << cedula << DELIMITA_CAMPO
		   << nombrePais << DELIMITA_CAMPO
		   << ciudadUbicacion << DELIMITA_CAMPO
		   << correo << DELIMITA_CAMPO
		   << nacionalidad << DELIMITA_REGISTRO;

}

// Desarrollo del metodo para recuperar
Persona* Persona::recuperar(istream& entrada) {
	string nom, ced, pais, ciudad, cor, nacio;
	getline(entrada, nom, DELIMITA_CAMPO);
	getline(entrada, ced, DELIMITA_CAMPO);
	getline(entrada, pais, DELIMITA_CAMPO);
	getline(entrada, ciudad, DELIMITA_CAMPO);
	getline(entrada, cor, DELIMITA_CAMPO);
	getline(entrada, nacio, DELIMITA_REGISTRO);

	return new Persona(nom, ced, pais, ciudad, cor, nacio);
}
