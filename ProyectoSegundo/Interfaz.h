#pragma once
#include <iostream>
#include <sstream>
#include "Tienda.h"
#include "Persona.h"
#include "Empresa.h"
#include "FuenteDeAudio.h"
#include "ProcesadorDeSenal.h"
#include "Parlante.h"
#include "Kit.h"
#include "Dispositivo.h"
using namespace std;



// -------------Menus---------------
int menu();
int menudirecto();
int menuEnLinea();
int menuMantenimiento();
int menuReportes();


// ------------Directo--------------

// ------------En linea-------------

// ---------Mantenimiento-----------

void mostrarClientes(Tienda*);

Cliente* crearCliente();
Cliente* crearPersona();
Cliente* crearEmpresa();

void verCatalogo(Tienda*);

Componente* crearProducto(Tienda*);
Componente* crearComponente();
Componente* crearSistemaPreconfigurado(Tienda*);

void eliminarProducto(Tienda*);


// ------------Reportes-------------

void salir(Tienda*);