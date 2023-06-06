#pragma once
#include "Factura.h"

class Directo : public Factura {
public:
	Directo();
	Directo(string, Fecha*, Cliente*);
	virtual ~Directo();

	string toString();

	void guardarDatos(ostream&);
	static Directo* recuperarDatos(istream&);
};