#pragma once
#include <fstream>
#include "Componente.h"

class ProcesadorDeSenal : public Componente {
private:
	string tipoComponente;
	string modelo;
public:
	ProcesadorDeSenal(string, string, string, string, double);
	virtual ~ProcesadorDeSenal();
	
	string getNombre() { return ""; }
	string getCodigo();
	string getCaracteristica();
	double getPrecio();

	void setNombre(string){}
	void setCodigo(string);
	void setCaracteristica(string);
	void setPrecio(double);
	
	string toString();
	void agregar(Componente*);
	void guardar(ostream&);
	static Componente* recuperar(istream&);
};