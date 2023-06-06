#pragma once
#include "Factura.h"
#include "Destino.h"

class EnLinea : public Factura {
private:
	Destino* destino;
public:
	EnLinea();
	EnLinea(string, Fecha*, Cliente*, Destino*);
	virtual ~EnLinea();

	Destino* getDestino();
	void setDestino(Destino*);

	string toString();

	Destino* clonarDestino(Destino*);

	void guardarDatos(ostream&);
	static EnLinea* recuperarDatos(istream&);
};
