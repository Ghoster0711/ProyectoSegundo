#pragma once
#include"Cliente.h"


class Empresa : public Cliente {
public:
	Empresa();
	Empresa(string, string, string, string);
	virtual~Empresa();
	string toString();
	void guardarDatos(ostream&);
	static Empresa* recuperarDatos(istream&);
};