#pragma once
#include<iostream>
#include<sstream>
#include<string>
#include<fstream>
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
	
	//Get's 
	int getDia();
	int getMes();
	int getAnio();
	
	//Set's 
	void setDia(int);
	void setMes(int);
	void setAnio(int);

	string toString();

	void guardarDatos(ostream&);
	static Fecha* recuperarDatos(istream&);

};