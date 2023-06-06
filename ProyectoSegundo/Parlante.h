#pragma once
#include <fstream>
#include "Componente.h"


class Parlante : public Componente {
private:
	string tipoComponente;
	string modelo;
	string caracteristica;
public:
	Parlante(string, string, string, double);
	virtual ~Parlante();

	string getTipoComponente();
	string getModelo();
	string getCaracteristica();
	double getPrecio();

	void setTipoComponente(string);
	void setModelo(string);
	void setCaracteristica(string);
	void setPrecio(double);
	
	void agregar(Componente*);

	string toString();

	void guardarDatos(ostream&);
	static Componente* recuperarDatos(istream&);
};