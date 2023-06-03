#pragma once
#include "Lista.h"
#include "Factura.h"
#include "FacBasico.h"
#include "FacProfesional.h"
#include "FacSemiPro.h"
#include "Kit.h"
#include "Dispositivo.h"
#include "FuenteDeAudio.h"
#include "Parlante.h"
#include "ProcesadorDeSenal.h"
//#include "Cliente.h"
//#include "Destino.h"

class Destino;
class Cliente;

class Tienda {
private:
	Lista<Componente>* Catalogo;
	Lista<Destino>* Envios;
	Lista<Cliente>* Suscriptores;
	Lista<Factura>* Ventas;
public:
	Tienda();
	virtual ~Tienda();

	Lista<Componente>* getCatalago();
	Lista<Destino>* getEnvios();
	Lista<Cliente>* getSuscriptores();
	Lista<Factura>* getVentas();

};