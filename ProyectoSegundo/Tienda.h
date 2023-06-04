#pragma once
//#include "Lista.h"
//#include "Factura.h"
//#include "Kit.h"
//#include "Dispositivo.h"
//#include "FuenteDeAudio.h"
//#include "Parlante.h"
//#include "ProcesadorDeSenal.h"
//#include "Cliente.h"
//#include <fstream>

#include "Lista.h"
#include "Kit.h"
#include "Dispositivo.h"
#include "FuenteDeAudio.h"
#include "ProcesadorDeSenal.h"
#include "Parlante.h"
#include "Directo.h"
#include "EnLinea.h"
//#include "Utiles.h"
#include <fstream>
#include "Tienda.h"

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

	void recuperarArchivoCatalogo();

	void guardarFacturas();
	static Factura* recuperarFacturas(istream&);

};