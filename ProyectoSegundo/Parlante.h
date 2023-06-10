#pragma once
#include <fstream>
#include "Componente.h"


// class Parlante hereda de class Componente
class Parlante : public Componente {
protected:
	string modelo;
public:	
	// Destructor
	virtual ~Parlante(){}

	// Get's
	virtual string getID() = 0;
	virtual string getNombre() = 0;
	virtual string getCodigo() = 0;
	virtual string getCaracteristica() = 0;
	virtual double getPrecio() = 0;

	// Set's
	virtual void setNombre(string) = 0;
	virtual void setCodigo(string) = 0;
	virtual void setCaracteristica(string) = 0;
	virtual void setPrecio(double) = 0;

	// ToString
	virtual string toString() = 0;

	// Metodo para agregar
	virtual void agregar(Componente*) = 0;

	// Metodo para guardar en archivo
	virtual void guardar(ostream&) = 0;
};