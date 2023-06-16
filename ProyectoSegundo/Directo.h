/* --------------------------------------------------------------------
*
* EIF204 Programación 2
* Proyecto 2
*
* 6 0483 0349 Joshua Yarit Amador Lara.
* 4 0264 0260 Sianny Barrantes Benavides.
*
* -------------------------------------------------------------------
*/

#pragma once
#include "Factura.h"


// class Directo hereda de class Factura
class Directo : public Factura {
public:
	// Constructor
	Directo();

	// Constructor parametrizado
	Directo(string, Cliente*);

	// Destructor
	virtual ~Directo();

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
	Destino* clonarDestino(Destino*); // Clona el destino
	Cliente* clonarCliente(Cliente*); // Clona un cliente
	Componente* clonarComponente(Componente*); // Clona un componente
	
	// Metodo que se encarga de agregar un componente al carrito
	void ingresarCompra(Componente*);

	// Tostring
	string toString();

	// Metodo que se encarga de guardar en archivo
	void guardar(ostream&);
  
	// Metodo que se encarga de recuperar de archivo !Revisar si se usa!
	static Factura* recuperar(istream&);
	static void recuperarCarrito(istream&, Factura*);


	// Metodos para la parte de reportes
	double precioBrutoDeLaFactura();
	double precioNetoDeLaFactura();
	double ganaciasDeLaFactura();
	bool existenciaDeProducto(string);
	int obtenerUnidadesDeProductoBuscado(string);
};