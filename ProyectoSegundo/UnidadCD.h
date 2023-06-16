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
#include "FuenteDeAudio.h"

class UnidadCD : public FuenteDeAudio {
public:
	// Construtor parmetrizado 
	UnidadCD(string, string, string, double, int);

	// Destructor
	virtual ~UnidadCD();

	// Get's
	string getID();
	string getNombre() { return ""; }
	string getCodigo();
	string getCaracteristica();
	double getPrecio();
	double obtenerPrecios();
	int getUnidades();

	// Set's
	void setNombre(string) {}
	void setCodigo(string);
	void setCaracteristica(string);
	void setPrecio(double);
	void setUnidades(int);

	// ToString
	string toString();
	string toStringKits();

	// Metodo para agregar
	void agregar(Componente*);

	// Metodo para guardar en archivo
	void guardar(ostream&);

	// Metodo para recuperar de archivo
	static Componente* recuperar(istream&);

};