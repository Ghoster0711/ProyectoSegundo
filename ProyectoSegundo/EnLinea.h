#pragma once
#include "Factura.h"
#include "Destino.h"

class EnLinea : public Factura {
private:
	Destino* destino;
public:
	EnLinea();
	EnLinea(string, Fecha*, Cliente*, Destino*);
	virtual ~EnLinea();

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

	void guardar(ostream&);
	static EnLinea* recuperar(istream&);
};