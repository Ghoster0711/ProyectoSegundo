#pragma once
#include"Cliente.h"

// Class Empresa hereda de class Cliente
class Empresa : public Cliente {
public:
	// Constructor
	Empresa();
	// Constructor parametrizado
	Empresa(string, string, string, string);
	virtual~Empresa();

	// Get's
	string getID();
	string getNombre();
	string getCedula();
	string getNombrePais();
	string getCiudadUbicacion();
	string getCorreo();
	string getNacionalidad();

	// Set´s
	void setNombre(string);
	void setCedula(string);
	void setNombrePais(string);
	void setCiudadUbicacion(string);
	void setCorreo(string);
	void setNacionalidad(string);


	// Tostring
	string toString();

	// Guardar en archivos
	void guardar(ostream&);

	// Para recuperar de archivos
	static Empresa* recuperar(istream&);
};