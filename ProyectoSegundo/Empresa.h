#pragma once
#include"Cliente.h"


class Empresa : public Cliente {
public:
	Empresa();
	Empresa(string, string, string, string);
	virtual~Empresa();
	string toString();
	void guardar(ostream&);
	static Empresa* recuperar(istream&);
};