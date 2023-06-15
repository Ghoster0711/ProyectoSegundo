/* --------------------------------------------------------------------
*
* EIF204 Programación 2
* Proyecto 2
*
* 6 0483 0349 Joshua Yarit Amador Lara.
* 40 264 0260 Sianny Barrantes Benavides.
*
* -------------------------------------------------------------------
*/

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
#include"Exepciones.h"
using namespace std;



// -------------Menus---------------
int menu();
int menudirecto();
int menuEnLinea();
int menuMantenimiento();
int menuReportes();


// ------------Directo--------------

void generarVentaDirecta(Tienda*);
Componente* agregarComponente(Tienda*);
Componente* agregarSistemaPreconfigurado(Tienda*);
Componente* agregarNuevoSistemaAMedida(Tienda*);

// ------------En linea-------------

void generarVentaEnLinea(Tienda*);

// ---------Mantenimiento-----------

// Realizar todo lo que tiene que ver con la parte de mantenimiento
void mantenimiento(Tienda*);

// Muestra los cliente registrados
void mostrarClientes(Tienda*);

// Realiza la parte de ingresar cliente
void ingresoSuscriptores(Tienda*);

// Realiza la parte de ingresar un cliente
Cliente* crearCliente();

// Crea una persona a ingresar
Cliente* crearPersona();

// Crea una empresa a ingresar
Cliente* crearEmpresa();

// Elimina un cliente
void eliminarCliente(Tienda*);

// Realizar la parte de modificar un cliente
void modificarCliente(Tienda*);

// Se encarga de modificar una persona
void modificarClientePersona(Tienda*,Cliente*);

// Se encarga de modificar una empresa
void modificarClienteEmpresa(Tienda*, Cliente*);


// Muestra el catalogo
void verCatalogo(Tienda*);

// Realiza la parte de ingresar un producto
void ingresoProductos(Tienda*);

// Realiza la parte de crear un producto
Componente* crearProducto(Tienda*);

// Se encarga de crear un componente
Componente* crearComponente();

// Se encarga de crear un sitema 
Componente* crearSistemaPreconfigurado(Tienda*);

// Realiza la parte de modificar la existencia de un producto
void modificarProductos(Tienda*);

// Se encarga de eliminar un producto
void eliminarProducto(Tienda*);


// ------------Reportes-------------

// Realiza la parte de reportes
void reportes(Tienda*);

// Realiza la parte de los dos productos mas vendidos
void reporteEquiposMasVendidos(Tienda*);

// Realiza el reporte de ventas
void reporteVentas(Tienda*);


// Realiza la parte de finalizacion del programa
void salir(Tienda*);

// Se encarga de todo el funcionamiento del programa
void MAIN(Tienda*);


// ------------Extras---------------

// Se encarga de ingresar componentes al kit
bool ingresarAlKit(int&, int&, int&, string&, string, Componente&, Tienda*);