#pragma once
#include <fstream>
#include "Lista.h"
//Factura
#include "Factura.h"
// Componentes
#include "FuenteDeAudio.h"
#include "ProcesadorDeSenal.h"
#include "Parlante.h"
#include "Kit.h"
// Clientes
#include "Empresa.h"
#include "Persona.h"


class Tienda {
private:
	Lista<Componente>* Catalogo;
	Lista<Cliente>* Suscriptores;
	Lista<Factura>* Ventas;
public:
	Tienda();
	virtual ~Tienda();

	Lista<Componente>* getCatalago();
	Lista<Cliente>* getSuscriptores();
	Lista<Factura>* getVentas();

	string mostrarElCatalogo();
	//string mostrarLosSuscriptores();
	//string mostrarLasVentas();
	
	bool buscarProductoDelCatalogo(string);
	bool buscarComponente(string);
	Componente* retornarSoloComponentes(string);
	string mostrarSoloComponentes();

	bool buscarCliente(string);


// -------------Directo---------------

// -------------En Linea--------------

// -----------Mantenimiento-----------

	string mostrarClientes();
	bool ingresarCliente(Cliente*);
	bool eliminarCliente(string);
	string verCatalogo();
	bool ingresarProductosAlCatalogo(Componente*);
	bool eliminarProducto(string);

	// ------------Reportes---------------

	// ------------Archivos---------------


	void guardarCatalogo();
	void recuperarArchivoCatalogo();

	void guardarSuscriptores();
	void recuperarArchivoSuscriptores();

	void guardarFacturas();
	void recuperarFacturas();

	void recuperarDeArchivos();

};