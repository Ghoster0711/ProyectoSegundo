#pragma once
#include "Sistema.h"

class Kit : public Sistema {
protected:

public:
	Kit();
	virtual ~Kit();
	string toString();
	string getCaracteristica();
	double getPrecio();
	void agregar(Componente*);
	void setPrecio(double);
};