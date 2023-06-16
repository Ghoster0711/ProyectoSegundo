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
#include"Cliente.h"

// class Persona hereda de class Cliente
class Persona : public Cliente {
private:
	string correo;
	string nacionalidad;
public:
	// Constructor
	Persona();

	// Constructor parametrizado
	Persona(string, string, string, string, string, string);
	
	// Destructor
	virtual~Persona();

	// Get's
	string getID();
	string getNombre();
	string getCedula();
	string getNombrePais();
	string getCiudadUbicacion();
	string getCorreo();
	string getNacionalidad();


	// Set's
	void setNombre(string);
	void setCedula(string);
	void setNombrePais(string);
	void setCiudadUbicacion(string);
	void setCorreo(string);
	void setNacionalidad(string);


	// ToString
	string toString();

	// Observer
	void update(string, ofstream&);
	void setModel(Lista<Componente>*);

	// Guardar en archivos
	void guardar(ostream&);

	// Recuperar de archivos
	static Persona* recuperar(istream&);
};