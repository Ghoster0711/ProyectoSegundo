#pragma once
#include "Componente.h"
#include "FuenteDeAudio.h"
#include "ProcesadorDeSenal.h"
#include "Parlante.h"
#include "Kit.h"
#include"Lista.h"

class Sistema : public Componente {
protected:
	Lista<Componente>* Empaquetado;
	int cantItems;
public:
	Sistema();
	virtual ~Sistema();

	virtual string getID() = 0;
	virtual string getCodigo() = 0;
	virtual string getNombre() = 0;
	virtual string getCaracteristica() = 0;
	virtual double getPrecio() = 0;

	virtual void setNombre(string) = 0;
	virtual void setCodigo(string) = 0;
	virtual void setCaracteristica(string) = 0;
	virtual void setPrecio(double) = 0;

	virtual string toString() = 0;
	virtual void agregar(Componente*) = 0;
	virtual void guardar(ostream&) = 0;
};