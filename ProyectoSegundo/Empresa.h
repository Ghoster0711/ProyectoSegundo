#pragma once
#include"Cliente.h"


class Empresa : public Cliente {
public:
	Empresa();
	Empresa(string, string, string, string);
	virtual~Empresa();

	string getID();
	string getNombre();
	string getCedula();
	string getNombrePais();
	string getCiudadUbicacion();
	string getCorreo();
	string getNacionalidad();

	void setNombre(string);
	void setCedula(string);
	void setNombrePais(string);
	void setCiudadUbicacion(string);
	void setCorreo(string);
	void setNacionalidad(string);

	string toString();
	void guardar(ostream&);
	static Empresa* recuperar(istream&);
};