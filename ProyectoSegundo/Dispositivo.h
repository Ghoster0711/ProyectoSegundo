#pragma once
#include "Sistema.h"

class Dispositivo : public Sistema {
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