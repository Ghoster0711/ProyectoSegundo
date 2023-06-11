#pragma once
#include "Parlante.h"

class Altavoz : public Parlante {
public:
	// Construtor parmetrizado 
	Altavoz(string, string, string, double);

	// Destructor
	virtual ~Altavoz();

	// Get's
	string getID();
	string getNombre() { return ""; }
	string getCodigo();
	string getCaracteristica();
	double getPrecio();
	double obtenerPrecios();

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