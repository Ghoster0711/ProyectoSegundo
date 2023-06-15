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
	
	// algo
	void notificar(Componente*, bool = false );


	// Get's
	Lista<Componente>* getCatalago();
	Lista<Cliente>* getSuscriptores();
	Lista<Factura>* getVentas();
	Lista<Destino>* getDestinos();

	//Desarrollo de metodos para mostrar contenedores 
	string mostrarElCatalogo();
	string mostrasDestinos();
	string mostrarSoloComponentes();
	
	//Desarrollo de metodos para buscar objetos 
	bool buscarSuscriptor(string);
	bool buscarProductoDelCatalogo(string);
	bool buscarComponente(string);
	bool buscarKit(string);
	bool buscarDestino(string);

	//Desarrollo de metodos que retornan objetos 
	Componente* retornarProductos(string);
	Componente* retornarSoloComponentes(string);
	Componente* retornarSoloKits(string);
	string mostrarSoloKits();
	Destino* retornaDestino(string);
	Cliente* retornaSuscriptor(string);
	Cliente* retornaCliente(string);
	void restarAUnidades(string, int);
	void sumarAUnidades(string, int);
	void cancelacionDeCompra(Factura*);

// -----------Mantenimiento-----------

	string mostrarClientes();
	bool ingresarCliente(Cliente*);
	void eliminarCliente(string);


	string verCatalogo();
	bool ingresarProductosAlCatalogo(Componente*);
	void eliminarProducto(string);

	// ------------Reportes---------------


	string reporteTotalesBrutos();
	string reporteTotalesNetos();
	string reporteDeGanancias();
	string primeroYsegundoMasVendios();

	// ------------Archivos---------------

	//Desarrollo de metodos para guardar y recuperar el catalago de componentes del archivo 
	void guardarCatalogo();
	void recuperarArchivoCatalogo();

	//Desarrollo de metodos para guardar y recuperar los suscriptores del archivo 
	void guardarSuscriptores();
	void recuperarArchivoSuscriptores();

	//Desarrollo de metodos para guardar y recuperar las facturas del archivo
	void guardarFacturas();
	void recuperarFacturas();

	//Desarrollo de metodos para guardar y recuperar los destinos del archivo
	void guardaDestinos();
	void recuperarArchivoDestinos();

	//Desarrollo de metodos para guardar y recuperar todos los archivos en general de la tienda 
	void guardarArchivos();
	void recuperarDeArchivos();

};