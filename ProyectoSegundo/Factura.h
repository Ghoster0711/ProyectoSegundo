#pragma once
#include <iostream>
#include <sstream>
#include "Persona.h"
#include "Empresa.h"
#include "Destino.h"
#include "Fecha.h"
#include "Kit.h"
#include "Dispositivo.h"



class Factura {
protected:
	Fecha* fecha;
	string numFactura;
	Cliente* cliente;
	Destino* destino;
	Componente* combo;
public:
	Factura(string, Cliente*, Componente*);
	virtual ~Factura();

	virtual string getNumFactura() = 0;
	virtual Cliente* getCliente() = 0;
	virtual Componente* getCombo() = 0;
	virtual void setNumFactura(string) = 0;
	virtual void setCliente(Cliente*) = 0;
	virtual void setCombo(Componente*) = 0;

	virtual Destino* getDestino() = 0;
	virtual void setDestino(Destino*) = 0;
	virtual string toString() = 0;

};

