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
	string toString();
	string getNombre();
	void setNombre(string);
	string getCodigo();
	string getCaracteristica();
	double getPrecio();
	void agregar(Componente*);
	void setCodigo(string);
	void setCaracteristica(string);
	void setPrecio(double);


	void guardar(ostream&);
	static Componente* recuperar(istream&);
};