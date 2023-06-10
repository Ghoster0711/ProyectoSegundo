#pragma once
#include "FuenteDeAudio.h"

class Radio : public FuenteDeAudio {
public:
	// Construtor parmetrizado 
	Radio(string, string, string, double);

	// Destructor
	virtual ~Radio();

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