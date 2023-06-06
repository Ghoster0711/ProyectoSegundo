#include"Persona.h"

Persona::Persona(): Cliente() {}

Persona::Persona(string nom, string ced, string pais, string ciudad,string correo,string nacio) 
	: Cliente(nom,ced,pais,ciudad) {}
Persona::~Persona(){}

string Persona::getCorreo() { return correo; }
string Persona::getNacionalidad() { return nacionalidad; }

void Persona::setCorreo(string cor) { correo = cor; }
void Persona::setNacionalidad(string nacio) { nacionalidad = nacio; }

string Persona::toString() {
	stringstream s;
	s << "Nombre: " << nombre << endl
		<< "Cedula: " << cedula << endl
		<< "Pais: " << nombrePais << endl
		<< "Ciudad de Ubicacion: " << ciudadUbicacion << endl
		<< "Correo: " << correo << endl
		<< "Nacionalidad: " << nacionalidad << endl;
	return s.str();
}

void Persona::guardarDatos(ostream& salida) {
	salida << nombre << DELIMITA_CAMPO
		<< cedula << DELIMITA_CAMPO
		<< nombrePais << DELIMITA_CAMPO
		<< ciudadUbicacion << DELIMITA_CAMPO
		<< correo << DELIMITA_CAMPO
		<< nacionalidad << DELIMITA_REGISTRO;
		
}
Persona* Persona::recuperarDatos(istream& entrada){
	Cliente* persona = new Persona();
	Persona* per = dynamic_cast<Persona*>(persona);
	string nom, ced, pais, ciudad, cor, nacio;
	getline(entrada, nom, DELIMITA_CAMPO);
	getline(entrada, ced, DELIMITA_CAMPO);
	getline(entrada, ciudad, DELIMITA_CAMPO);
	getline(entrada, cor, DELIMITA_CAMPO);
	getline(entrada, nacio, DELIMITA_REGISTRO);
	per->setNombre(nom);
	per->setCedula(ced);
	per->setNombrePais(pais);
	per->setCiudadUbicacion(ciudad);
	per->setCorreo(cor);
	per->setNacionalidad(nacio);

	return per;
}
