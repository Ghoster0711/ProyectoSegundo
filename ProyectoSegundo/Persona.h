#pragma once
#include"Cliente.h"


class Persona : public Cliente {
public:
	Persona();
	Persona(string, string, string, string);
	virtual~Persona();
	string toString();
	virtual void guardarDatos(ofstream&);
	static Cliente* recuperarDatos(string, string, string, string);
};