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

	string getCorreo();
	string getNacionalidad();

	void setCorreo(string);
	void setNacionalidad(string);

	string toString();
	void guardarDatos(ostream&);
	static Persona* recuperarDatos(istream&);
};