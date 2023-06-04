#pragma once
#include <iostream>
#include <sstream>

using namespace std;

class Componente {
protected:
	string caracteristica;
	double precio;
public:
	virtual ~Componente(){}
	virtual string toString() = 0;
	virtual string getCaracteristica() = 0;
	virtual double getPrecio() = 0;
	virtual void agregar(Componente*) = 0;
	virtual void setPrecio(double) = 0;

	virtual void guardar(ostream&) = 0;
};
