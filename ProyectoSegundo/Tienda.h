#pragma once

#include "Lista.h"
#include "Kit.h"
#include "Dispositivos.h"
#include "FuenteDeAudio.h"
#include "ProcesadorDeSenal.h"
#include "Parlante.h"
#include "Directo.h"
#include "EnLinea.h"
#include <fstream>

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

	void guardarCatalogo();
	void recuperarArchivoCatalogo();

	void guardarFacturas();
	void recuperarArchivoFacturas();

};