#pragma once
#include "Composite.h"

class Kit : public Composite {
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