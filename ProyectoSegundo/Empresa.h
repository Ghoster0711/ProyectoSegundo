#pragma once
#include"Cliente.h"


class Empresa : public Cliente {
public:
	Empresa();
	Empresa(string, string, string, string);
	virtual~Empresa();
	string toString();
	virtual void guardarDatos(ofstream&);
	static Cliente* recuperarDatos(string,string,string,string);
};