#pragma once
#include <fstream>
#include "Sistema.h"

class Dispositivo : public Sistema {
private:
	string nombre;
public:
	Dispositivo();
	Dispositivo(string, string);
	virtual ~Dispositivo();
	string toString();
	string getNombre();
	string getCodigo();
	string getCaracteristica();
	double getPrecio();
	void agregar(Componente*);
	void setNombre(string);
	void setCodigo(string);
	void setCaracteristica(string);
	void setPrecio(double);


	void guardar(ostream&);
	static Componente* recuperar(istream&);
};