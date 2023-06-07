#pragma once
#include "Componente.h"
#include"Lista.h"


// Abstract class Sistema hereda de Componente 
class Sistema : public Componente {
protected:
	Lista<Componente>* Empaquetado;
	int cantItems;
public:
	// Constructor
	Sistema();

	// Destructor
	virtual ~Sistema();

	// Los siguiente son metodos virtuales puros (M.V.P)

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

	// Metodo para agregar componente
	virtual void agregar(Componente*) = 0;

	// Metodo para guardar en archivo
	virtual void guardar(ostream&) = 0;
};