#pragma once
#include <fstream>
#include "Componente.h"


// class Parlante hereda de class Componente
class Parlante : public Componente {
private:
	string tipoComponente;
	string modelo;
public:
	// Constructor parametrizado
	Parlante(string, string, string, string, double);
	
	// Destructor
	virtual ~Parlante();

	// Get's
	string getID();
	string getNombre() { return ""; }
	string getCodigo();
	string getCaracteristica();
	double getPrecio();


	// Set's
	void setNombre(string){}
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