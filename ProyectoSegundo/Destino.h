#pragma once
#include<iostream>
#include<sstream>
#include<string>
#include<fstream>
#include"Utiles.h"
#define DELIMITA_CAMPO '\t'
#define DELIMITA_REGISTRO '\n'

using namespace std;

class Destino {
private:
	string codigo;
	string pais;
	string ciudad;
	double costoTraslado;
public:
	Destino();
	Destino(string, string, string, double);
	virtual ~Destino();

	//Get's
	string getCodigo();
	string getPais();
	string getCiudad();
	double getCostoTraslado();

	//Set's 
	void setCodigo(string);
	void setPais(string);
	void setCiudad(string);
	void setCostoTraslado(double);

	string toString();
	void guardarDatos(ostream&); 
	static Destino* recuperarDatos(istream&);
};
