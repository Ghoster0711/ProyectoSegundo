#pragma once
#include "Composite.h"

class Dispositivo : public Composite {
protected:

public:
	Dispositivo();
	virtual ~Dispositivo();
	string toString();
	string getCaracteristica();
	double getPrecio();
	void agregar(Componente*);
	void setPrecio(double);
};