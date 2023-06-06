#pragma once
#include <fstream>
#include "Sistema.h"


class Dispositivos : public Sistema {
public:
	Dispositivos();
	virtual ~Dispositivos();

	Lista<Componente>* getEmpaquetado();
	int getCantItems();
	double getPrecio();
	string getTipoComponente();
	string getModelo();
	string getCaracteristica();

	void setPrecio(double);
	void setTipoComponente(string);
	void setModelo(string);
	void setCaracteristica(string);

	string toString();

	void agregar(Componente*);

	void guardarDatos(ostream&);
	static Componente* recuperarDatos(istream&);
};