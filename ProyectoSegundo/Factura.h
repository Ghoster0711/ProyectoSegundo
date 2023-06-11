#pragma once
#include <iostream>
#include <sstream>
#include"Lista.h"
#include "Persona.h"
#include "Empresa.h"
#include "Destino.h"
#include "Fecha.h"
#include "FuenteDeAudio.h"
#include "UnidadCD.h"
#include "Tornamesa.h"
#include "Radio.h"
#include "UnidadBluetooth.h"
#include "Microfono.h"
#include "ProcesadorDeSenal.h"
#include "Amplificador.h"
#include "Mezclador.h"
#include "Parlante.h"
#include "Altavoz.h"
#include "Audifono.h"
#include "Kit.h"

class Factura {   //Clase Abstracta 
protected:
	string codigo;   //Codigo de la factura 
	Fecha* fecha;
	Cliente* cliente;
	Lista<Componente>* carritoDeCompras;   //Lista de componentes que el cliente desea comprar 
public:
	//Factura();
	//virtual ~Factura();

	virtual string getCodigo() = 0;
	virtual Fecha* getFecha() = 0;
	virtual Cliente* getCliente() = 0;
	virtual Lista<Componente>* getCarrito() = 0;
	virtual Destino* getDestino() = 0;

	virtual void setCodigo(string) = 0;
	virtual void setFecha(Fecha*) = 0;
	virtual void setCliente(Cliente*) = 0;
	virtual void setLista(Lista<Componente>*) = 0;
	virtual void setDestino(Destino*) = 0;

	virtual Destino* clonarDestino(Destino*) = 0;
	virtual Cliente* clonarCliente(Cliente*) = 0;
	virtual Componente* clonarComponente(Componente*) = 0;
	virtual void ingresarCompra(Componente*) = 0;

	virtual string toString() = 0;

	virtual void guardar(ostream&) = 0;

};

