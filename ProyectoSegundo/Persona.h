#pragma once
#include"Cliente.h"

// class Persona hereda de class Cliente
class Persona : public Cliente {
private:
	string correo;
	string nacionalidad;
public:
	// Constructor
	Persona();

	// Constructor parametrizado
	Persona(string, string, string, string, string, string);
	
	// Destructor
	virtual~Persona();

	// Get's
	string getID();
	string getNombre();
	string getCedula();
	string getNombrePais();
	string getCiudadUbicacion();
	string getCorreo();
	string getNacionalidad();


	// Set's
	void setNombre(string);
	void setCedula(string);
	void setNombrePais(string);
	void setCiudadUbicacion(string);
	void setCorreo(string);
	void setNacionalidad(string);


	// ToString
	string toString();

	// Guardar en archivos
	void guardar(ostream&);

	// Recuperar de archivos
	static Persona* recuperar(istream&);
};