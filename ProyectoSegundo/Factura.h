//#pragma once
//#include <iostream>
//#include <sstream>
//#include "Persona.h"
//#include "Empresa.h"
//#include "Destino.h"
//#include "Fecha.h"
//#include "Kit.h"
//#include "Dispositivo.h"
//
//class Factura {
//protected:
//	string codigo;
//	Fecha* fecha;
//	Cliente* cliente;
//	Destino* destino;
//	Componente* combo;
//public:
//	Factura();
//	Factura(string, Fecha*, Cliente*, Destino*, Componente*);
//	virtual ~Factura();
//
//	string getCodigo();
//	Fecha* getFecha();
//	Cliente* getCliente();
//	Destino* getDestino();
//	Componente* getCombo();
//
//	void setCodigo(string);
//	void setFecha(Fecha*);
//	void setCliente(Cliente*);
//	void setDestino(Destino*);
//	void setCombo(Componente*);
//
//	string toString();
//
//
//	Cliente* clonarCliente(Cliente*);
//	Destino* clonarDestino(Destino*);
//
//	void guardarDatos(ostream&);
//	static Factura* recuperarDatos(istream&);
//
//};
//
