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
#include<iostream>
#include<sstream>
#include<string>
#include<fstream>
#include"Componente.h"
#include"Lista.h"


// Delimitadores para guardar en los archivos
#define DELIMITA_CAMPO '\t'
#define DELIMITA_REGISTRO '\n'

using namespace std;



// Abstract class
class Cliente {
protected:
	string nombre;
	string cedula;
	string nombrePais;
	string ciudadUbicacion;
	Lista<Componente>* model;
public:
	// Constructor
	Cliente();

	// Constructor parametrizado
	Cliente(string, string, string, string);

	// Destructor
	virtual ~Cliente();

	//Get's 
	virtual string getID() = 0; // Este metodo va a devolver el atributo con el que se identifica cada objeto
	virtual string getNombre() = 0;
	virtual string getCedula() = 0;
	virtual string getNombrePais() = 0;
	virtual string getCiudadUbicacion() = 0;
	virtual string getCorreo() = 0;
	virtual string getNacionalidad() = 0;

	//Set's 
	virtual void setNombre(string) = 0;
	virtual void setCedula(string) = 0;
	virtual void setNombrePais(string) = 0;
	virtual void setCiudadUbicacion(string) = 0;
	virtual void setCorreo(string) = 0;
	virtual void setNacionalidad(string) = 0;

	// ToString
	virtual string toString() = 0;

	// Observer
	virtual void update(string, ofstream&) = 0;
	virtual void setModel(Lista<Componente>*) = 0;
	
	// Guardar en archivos
	virtual void guardar(ostream&) = 0;
};