#pragma once
#include <fstream>
#include "Sistema.h"

class Kit : public Sistema {
private:
	string nombre;
public:
	Kit();
	Kit(string, string);
	virtual ~Kit();

	string getID();
	string getNombre();
	string getCodigo();
	string getCaracteristica();
	double getPrecio();

	void setNombre(string);
	void setCodigo(string);
	void setCaracteristica(string);
	void setPrecio(double);
	
	void agregar(Componente*);

	string toString();

	void guardar(ostream&);

	static Componente* recuperar(istream&);
};