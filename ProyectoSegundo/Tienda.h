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
	// Constructor
	Tienda();

	// Destructor
	virtual ~Tienda();
	
	
	// Get's
	Lista<Componente>* getCatalago();
	Lista<Cliente>* getSuscriptores();
	Lista<Factura>* getVentas();

	// Mostrar contenedores 
	string mostrarElCatalogo();
	//string mostrarLosSuscriptores();
	//string mostrarLasVentas();
	
	bool buscarSuscriptor(string);
	bool buscarProductoDelCatalogo(string);
	bool buscarComponente(string);
	bool buscarKit(string);
	Componente* retornarSoloComponentes(string);
	string mostrarSoloComponentes();
	Componente* retornarSoloKits(string);
	string mostrarSoloKits();

	bool buscarCliente(string);


// -------------Directo---------------

// -------------En Linea--------------

// -----------Mantenimiento-----------

	string mostrarClientes();
	bool ingresarCliente(Cliente*);
	void eliminarCliente(string);
	string verCatalogo();
	bool ingresarProductosAlCatalogo(Componente*);
	void eliminarProducto(string);

	// ------------Reportes---------------

	// ------------Archivos---------------


	void guardarCatalogo();
	void recuperarArchivoCatalogo();

	void guardarSuscriptores();
	void recuperarArchivoSuscriptores();

	void guardarFacturas();
	void recuperarFacturas();


	void guardarArchivos();
	void recuperarDeArchivos();



};