#pragma once
#include <iostream>
#include <sstream>

using namespace std;

class Componente {
protected:
	string codigo;
	string caracteristica;
	double precio;
public:
	virtual ~Componente(){}
	
	
	virtual string getNombre() = 0;
	virtual string getCodigo() = 0;
	virtual string getCaracteristica() = 0;
	virtual double getPrecio() = 0;

	
	virtual void setCodigo(string) = 0;
	virtual void setCaracteristica(string) = 0;
	virtual void setPrecio(double) = 0;
	virtual void setNombre(string) = 0;


	virtual void agregar(Componente*) = 0;
	virtual string toString() = 0;
	virtual void guardar(ostream&) = 0;
};
