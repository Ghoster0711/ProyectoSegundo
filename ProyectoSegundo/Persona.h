#pragma once
#include"Cliente.h"


class Persona : public Cliente {
private:
	string correo;
	string nacionalidad;
public:
	Persona();
	Persona(string, string, string, string, string, string);
	virtual~Persona();

	string getNombre();
	string getCedula();
	string getNombrePais();
	string getCiudadUbicacion();
	string getCorreo();
	string getNacionalidad();

	void setNombre(string);
	void setCedula(string);
	void setNombrePais(string);
	void setCiudadUbicacion(string);
	void setCorreo(string);
	void setNacionalidad(string);

	string toString();
	void guardar(ostream&);
	static Persona* recuperar(istream&);
};