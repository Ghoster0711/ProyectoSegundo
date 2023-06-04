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
	
	
	void guardarCatalogo();
	void recuperarArchivoCatalogo();

	void guardarSuscriptores();
	void recuperarArchivoSuscriptores();

	void guardarFacturas();
	//static Factura* recuperarFacturas(istream&);

};