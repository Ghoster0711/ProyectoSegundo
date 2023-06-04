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
	string correo;
	string telefono;
public:
	Cliente();
	Cliente(string, string, string, string);
	virtual ~Cliente();

	//Get's 
	string getNombre();
	string getCedula();
	string getCorreo();
	string getTelefono();

	//Set's 
	void setNombre(string);
	void setCedula(string);
	void setCorreo(string);
	void setTelefono(string);

	virtual string toString() = 0;

	virtual void guardarDatos(ostream&) = 0;
};