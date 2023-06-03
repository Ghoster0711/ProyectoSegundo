#pragma once
#include "Componente.h"

class ProcesadorDeSenal : public Componente {
private:
	string tipoComponente;
	string modelo;
public:
	ProcesadorDeSenal(string, string, string, double);
	virtual ~ProcesadorDeSenal();
	string getCaracteristica();
	double getPrecio();
	void agregar(Componente*);
	void setPrecio(double);
	string toString();
};