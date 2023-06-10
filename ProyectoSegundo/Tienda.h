#pragma once
#include <fstream>
#include "Lista.h"
//Factura
#include"Factura.h"
#include"EnLinea.h"
#include"Directo.h"
// Componentes
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
// Clientes
#include "Empresa.h"
#include "Persona.h"
//Destino
#include"Destino.h"


class Tienda {
private:
	Lista<Componente>* Catalogo;
	Lista<Cliente>* Suscriptores;
	Lista<Factura>* Ventas;
	Lista<Destino>* Destinos;
public:
	// Constructor
	Tienda();

	// Destructor
	virtual ~Tienda();
	
	
	// Get's
	Lista<Componente>* getCatalago();
	Lista<Cliente>* getSuscriptores();
	Lista<Factura>* getVentas();
	Lista<Destino>* getDestinos();

	// Mostrar contenedores 
	string mostrarElCatalogo();
	string mostrasDestinos();
	
	bool buscarSuscriptor(string);
	bool buscarProductoDelCatalogo(string);
	bool buscarComponente(string);
	bool buscarKit(string);
	bool buscarDestino(string);

	Componente* retornarSoloComponentes(string);
	string mostrarSoloComponentes();
	Componente* retornarSoloKits(string);
	string mostrarSoloKits();
	Destino* retornaDestino(string);
	Cliente* retornaSuscriptor(string);


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

	void guardaDestinos();
	void recuperarArchivoDestinos();

	void guardarArchivos();
	void recuperarDeArchivos();

};