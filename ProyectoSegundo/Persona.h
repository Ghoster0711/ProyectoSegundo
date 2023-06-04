#pragma once
#include"Cliente.h"


class Persona : public Cliente {
public:
	Persona();
	Persona(string, string, string, string);
	virtual~Persona();
	string toString();
	void guardarDatos(ostream&);
	static Persona* recuperarDatos(istream&);
};