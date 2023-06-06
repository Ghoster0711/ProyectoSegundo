#pragma once
#include <iostream>
#include <sstream>
#include"Lista.h"

using namespace std;

class Componente {
protected:
	double precio;
public:
	virtual ~Componente(){}

	virtual double getPrecio() = 0;
	virtual string getTipoComponente() = 0;
	virtual string getModelo() = 0;
	virtual string getCaracteristica() = 0;
	
	virtual void setPrecio(double) = 0;
	virtual void setTipoComponente(string) = 0;
	virtual void setModelo(string) = 0;
	virtual void setCaracteristica(string) = 0;

	virtual string toString() = 0;

	virtual void agregar(Componente*) = 0;

	virtual void guardarDatos(ostream&) = 0;
};
