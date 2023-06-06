#pragma once
#include<iostream>
#include<sstream>
#include<string>
#include<fstream>
#define DELIMITA_CAMPO '\t'
#define DELIMITA_REGISTRO '\n'

using namespace std;

class Cliente {
protected:
	string nombre;
	string cedula;
	string nombrePais;
	string ciudadUbicacion;
public:
	Cliente();
	Cliente(string, string, string, string);
	virtual ~Cliente();

	//Get's 
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

	virtual string toString() = 0;

	virtual void guardar(ostream&) = 0;
};