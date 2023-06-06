#pragma once
#include <fstream>
#include "Sistema.h"

class Kit : public Sistema {
public:
	Kit();
	virtual ~Kit();
	
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

	void agregar(Componente*);

	string toString();

	void guardarDatos(ostream&);
	static Componente* recuperarDatos(istream&);
};