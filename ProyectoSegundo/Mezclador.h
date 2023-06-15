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
#include "ProcesadorDeSenal.h"

class Mezclador : public ProcesadorDeSenal {
public:
	// Construtor parmetrizado 
	Mezclador(string, string, string, double, int);

	// Destructor
	virtual ~Mezclador();

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