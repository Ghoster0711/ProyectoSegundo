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
#include<Windows.h>
#include"Utiles.h"
#define DELIMITA_CAMPO '\t'
#define DELIMITA_REGISTRO '\n'

using namespace std;

class Fecha {
private:
	int dia;
	int mes;
	int anio;
public:

	Fecha();
	Fecha(int, int, int);
	virtual ~Fecha();
	
	// Get's 
	int getDia();
	int getMes();
	int getAnio();
	
	// Set's 
	void setDia(int);
	void setMes(int);
	void setAnio(int);

	// ToString
	string toString();

	// Metodos para recuperar y guardar en archivos
	void guardarDatos(ostream&);
	static Fecha* recuperarDatos(istream&);

};