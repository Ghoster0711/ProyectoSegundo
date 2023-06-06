#pragma once
#include <fstream>
#include "Componente.h"

class FuenteDeAudio : public Componente {
private:
	string tipoComponente;
	string modelo;
	string caracteristica;
public:
	FuenteDeAudio(string, string, string, double);
	virtual ~FuenteDeAudio();

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