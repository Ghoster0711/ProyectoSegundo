#pragma once
#include "Componente.h"
#include "Lista.h"

class Sistema : public Componente {
protected:
	Lista<Componente>* empaquetado;
	int cantItems;
public:
	Sistema();
	virtual ~Sistema();
	virtual string toString() = 0;
	virtual string getCaracteristica() = 0;
	virtual double getPrecio() = 0;
	virtual void agregar(Componente*) = 0;
	virtual void setPrecio(double) = 0;
};