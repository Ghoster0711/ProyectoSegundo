#pragma once
#include <iostream>
#include <sstream>
#include"Lista.h"
#include "Persona.h"
#include "Empresa.h"
#include "Destino.h"
#include "Fecha.h"
#include "Kit.h"
#include "Dispositivos.h"
#include"FuenteDeAudio.h"
#include"Parlante.h"
#include"ProcesadorDeSenal.h"

class Factura {
protected:
	string codigo;
	Fecha* fecha;
	Cliente* cliente;
	Lista<Componente>* carritoDeCompras;
public:
	Factura();
	Factura(string, Fecha*, Cliente*);
	virtual ~Factura();

	string getCodigo();
	Fecha* getFecha();
	Cliente* getCliente();
	//Lista<Componente>* getCarritoDeCompras();

	void setCodigo(string);
	void setFecha(Fecha*);
	void setCliente(Cliente*);
	void setLista(Lista<Componente>*);

	virtual string toString() = 0;

	Cliente* clonarCliente(Cliente*);
	Componente* clonarComponente(Componente*);
	void ingresarCompra(Componente*);
	
	virtual void guardarDatos(ostream&) = 0;

};

