#pragma once
#include "Factura.h"
#include "Destino.h"

// class EnLinea hereda de class Factura
class EnLinea : public Factura {
private:
	Destino* destino;
public:
	// Construtor
	EnLinea();
	
	// Construtor parametrizado
	EnLinea(string, Cliente*, Destino*);
	
	// Destructor
	virtual ~EnLinea();

	// Get's
	string getCodigo();
	Fecha* getFecha();
	Cliente* getCliente();
	Lista<Componente>* getCarrito();
	Destino* getDestino();

	// Set's
	void setCodigo(string);
	void setFecha(Fecha*);
	void setCliente(Cliente*);
	void setLista(Lista<Componente>*);
	void setDestino(Destino*);

	// Clonaciones
	Destino* clonarDestino(Destino*); // Clonar un destino
	Cliente* clonarCliente(Cliente*); // Clonar un cliente
	Componente* clonarComponente(Componente*); // Clonar un componente

	// Metodo que se encarga de agregar un componente al carrito
	void ingresarCompra(Componente*); // 

	// ToString
	string toString();

	// Metodo que se encarga de guardar en archivo
	void guardar(ostream&);

	// Metodo que se encarga de recuperar de archivo
	static Factura* recuperar(istream&);
	static void recuperarCarrito(istream&, Factura*);
};