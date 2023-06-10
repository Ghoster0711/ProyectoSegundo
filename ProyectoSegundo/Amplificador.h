#pragma once
#include "ProcesadorDeSenal.h"

class Amplificador : public ProcesadorDeSenal {
public:
	// Construtor parmetrizado 
	Amplificador(string, string, string, double);

	// Destructor
	virtual ~Amplificador();

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