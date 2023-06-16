/* --------------------------------------------------------------------
*
* EIF204 Programación 2
* Proyecto 2
*
* 6 0483 0349 Joshua Yarit Amador Lara.
* 4 0264 0260 Sianny Barrantes Benavides.
*
* -------------------------------------------------------------------
*/

#pragma once
#include<iostream>
#include<sstream>
#include<string>
#include<fstream>
#include"Utiles.h"

// Delimitadores para la parte de archivos
#define DELIMITA_CAMPO '\t'
#define DELIMITA_REGISTRO '\n'

using namespace std;

// class Destino
class Destino {
private:
	string codigo;
	string pais;
	string ciudad;
	double costoTraslado;
public:
	// Constructor
	Destino();

	// Constructor Parametrizado
	Destino(string, string, string, double);

	// Destructor
	virtual ~Destino();

	// Get's
	string getCodigo();
	string getPais();
	string getCiudad();
	double getCostoTraslado();

	// Set's 
	void setCodigo(string);
	void setPais(string);
	void setCiudad(string);
	void setCostoTraslado(double);


	// ToString
	string toString();


	// Metodo para guardar en archivo
	void guardar(ostream&); 

	// Metodo para recuperar de archivo
	static Destino* recuperar(istream&);
};
