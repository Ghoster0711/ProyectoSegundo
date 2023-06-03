#pragma once
#include <iostream>
#include <sstream>
//#include "Persona.h"
//#include "Empresa.h"
//#include "Destino.h"
#include "Kit.h"
#include "Dispositivo.h"

class Persona;
class Empresa;
class Cliente;
class Destino;

class Factura {
private:
	// Fecha* fecha;
	string codigo;
	Cliente* cliente;
	Destino* destino;
	Componente* combo;
public:
	Factura(string, Cliente*, Destino*, Componente*);
	virtual ~Factura();

	string getCodigo();
	Cliente* getCliente();
	Destino* getDestino();
	Componente* getCombo();

	void setCodigo(string);
	void setCliente(Cliente*);
	void setDestino(Destino*);
	void setCombo(Componente*);

	string toString();

};

