#pragma once
#include <iostream>
#include <sstream>
#include<string.h>

using namespace std;


// Abstract Class
class Componente {
protected:
	string codigo;
	string caracteristica;
	double precio;
public:
	// Destructor 
	virtual ~Componente(){}
	
	// Los siguientes son metodos virtuales puros (M.V.P)

	// Get's
	virtual string getID() = 0; // Este metodo va a devolver el atributo con el que se identifica cada objeto
	virtual string getNombre() = 0;
	virtual string getCodigo() = 0;
	virtual string getCaracteristica() = 0;
	virtual double getPrecio() = 0;


	// Set's
	virtual void setCodigo(string) = 0;
	virtual void setCaracteristica(string) = 0;
	virtual void setPrecio(double) = 0;
	virtual void setNombre(string) = 0;


	// ToString
	virtual string toString() = 0;
	
	// Para agregar al composite
	virtual void agregar(Componente*) = 0;
	
	// Para guardar en guardar en archivos
	virtual void guardar(ostream&) = 0;
};
