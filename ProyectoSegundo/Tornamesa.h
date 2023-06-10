#pragma once
#include "FuenteDeAudio.h"

class Tornamesa : public FuenteDeAudio {
public:
	// Construtor parmetrizado 
	Tornamesa(string, string, string, double);

	// Destructor
	virtual ~Tornamesa();

	// Get's
	string getID();
	string getNombre() { return ""; }
	string getCodigo();
	string getCaracteristica();
	double getPrecio();

	// Set's
	void setNombre(string) {}
	void setCodigo(string);
	void setCaracteristica(string);
	void setPrecio(double);

	// ToString
	string toString();

	// Metodo para agregar
	void agregar(Componente*);

	// Metodo para guardar en archivo
	void guardar(ostream&);

	// Metodo para recuperar de archivo
	static Componente* recuperar(istream&);

};