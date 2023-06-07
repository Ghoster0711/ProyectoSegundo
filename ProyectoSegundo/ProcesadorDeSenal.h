#pragma once
#include <fstream>
#include "Componente.h"


// class ProcesadorDeSenal hereda de class Componente
class ProcesadorDeSenal : public Componente {
private:
	string tipoComponente;
	string modelo;
public:
	// Constructor parametrizado
	ProcesadorDeSenal(string, string, string, string, double);
	
	// Destructor
	virtual ~ProcesadorDeSenal();
	
	// Get's
	string getID();
	string getNombre();
	string getCodigo();
	string getCaracteristica();
	double getPrecio();

	// Set's
	void setNombre(string){}
	void setCodigo(string);
	void setCaracteristica(string);
	void setPrecio(double);
	
	// ToString
	string toString();

	// Metodo para agregar
	void agregar(Componente*);

	// Metodo para guardar en archivo
	void guardar(ostream&);
	
	// Metodo para recuperar de archivo
	static Componente* recuperar(istream&);
};