#pragma once
#include "Factura.h"

class Directo : public Factura {
public:
	Directo();
	Directo(string, Fecha*, Cliente*);
	virtual ~Directo();

	string getCodigo();
	Fecha* getFecha();
	Cliente* getCliente();
	Lista<Componente>* getCarrito();
	Destino* getDestino();

	void setCodigo(string);
	void setFecha(Fecha*);
	void setCliente(Cliente*);
	void setLista(Lista<Componente>*);
	void setDestino(Destino*);

	Destino* clonarDestino(Destino*);
	Cliente* clonarCliente(Cliente*);
	Componente* clonarComponente(Componente*);
	void ingresarCompra(Componente*);

	string toString();

	void guardarDatos(ostream&);
	static Directo* recuperarDatos(istream&);

};