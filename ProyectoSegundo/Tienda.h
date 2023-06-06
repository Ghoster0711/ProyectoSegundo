#pragma once
#include <fstream>
#include "Lista.h"
//#include "Cliente.h"
//#include "Factura.h"
// Componentes
#include "FuenteDeAudio.h"
#include "ProcesadorDeSenal.h"
#include "Parlante.h"
#include "Kit.h"
#include "Dispositivo.h"
// Clientes
#include "Empresa.h"
#include "Persona.h"


class Tienda {
private:
	Lista<Componente>* Catalogo;
	Lista<Cliente>* Suscriptores;
	//Lista<Factura>* Ventas;
public:
	Tienda();
	virtual ~Tienda();

	Lista<Componente>* getCatalago();
	Lista<Cliente>* getSuscriptores();
	//Lista<Factura>* getVentas();

	string mostrarElCatalogo();
	//string mostrarLosSuscriptores();
	//string mostrarLasVentas();
	
	bool buscarProductoDelCatalogo(string);
	bool buscarComponente(string);
	Componente* retornarSoloComponentes(string);
	string mostrarSoloComponentes();

// -------------Directo---------------

// -------------En Linea--------------

// -----------Mantenimiento-----------

	string mostrarClientes();
	void ingresarCliente(Cliente*);
	string verCatalogo();
	void ingresarProductosAlCatalogo(Componente*);
	void EliminarProducto(string);

	// ------------Reportes---------------

	// ------------Archivos---------------


	void guardarCatalogo();
	void recuperarArchivoCatalogo();

	void guardarSuscriptores();
	void recuperarArchivoSuscriptores();

	void guardarFacturas();
	//static Factura* recuperarFacturas(istream&);

	void recuperarDeArchivos();

};