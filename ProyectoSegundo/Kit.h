#pragma once
#include <fstream>
#include "Sistema.h"


// class Kit hereda de class Sistema
class Kit : public Sistema {
private:
	string nombre;
public:
	// Constructor
	Kit();

	// Constructor parametrizado
	Kit(string, string);

	// Destructor
	virtual ~Kit();

	// Get's
	string getID();
	string getNombre();
	string getCodigo();
	string getCaracteristica();
	double getPrecio();
	double obtenerPrecios();
	int getUnidades();

	// Set's
	void setNombre(string);
	void setCodigo(string);
	void setCaracteristica(string);
	void setPrecio(double);
	void setUnidades(int);
	
	// Metodo para agregar componente
	void agregar(Componente*);

	// ToString
	string toString();
	string toStringKits();

	// Metodo para guardar en archivo
	void guardar(ostream&);

  // Metodo para recuperar de archivo
	static Componente* recuperar(istream&);
};