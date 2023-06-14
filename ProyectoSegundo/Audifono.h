#pragma once
#include "Parlante.h"

class Audifono : public Parlante {
public:
	// Construtor parmetrizado 
	Audifono(string, string, string, double, int);

	// Destructor
	virtual ~Audifono();

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