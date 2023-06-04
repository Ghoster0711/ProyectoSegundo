#pragma once
#include <fstream>
#include "Componente.h"




class Parlante : public Componente {
private:
	string tipoComponente;
	string modelo;
public:
	Parlante(string, string, string, double);
	virtual ~Parlante();
	string getCaracteristica();
	double getPrecio();
	void agregar(Componente*);
	void setPrecio(double);
	string toString();
	
	void guardar(ostream&);
	static Componente* recuperar(istream&);
};