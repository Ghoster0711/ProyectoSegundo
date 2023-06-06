#pragma once
#include "Componente.h"
#include "Lista.h"

//Composite 
class Sistema : public Componente {
protected:
	Lista<Componente>* empaquetado;
	int cantItems;
public:
	Sistema();
	virtual ~Sistema();
	
	virtual Lista<Componente>* getEmpaquetado() = 0;
	virtual int getCantItems() = 0;
	virtual double getPrecio() = 0;
	virtual string getTipoComponente() = 0;
	virtual string getModelo() = 0;
	virtual string getCaracteristica() = 0;

	virtual void setPrecio(double) = 0;
	virtual void setTipoComponente(string) = 0;
	virtual void setModelo(string) = 0;
	virtual void setCaracteristica(string) = 0;

	virtual void agregar(Componente*) = 0;

	virtual string toString() = 0;

	virtual void guardarDatos(ostream&) = 0;
};