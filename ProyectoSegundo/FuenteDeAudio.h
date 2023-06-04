#pragma 
#include <fstream>
#include "Componente.h"

class FuenteDeAudio : public Componente {
private:
	string tipoComponente;
	string modelo;
public:
	FuenteDeAudio(string, string, string, double);
	virtual ~FuenteDeAudio();
	string getCaracteristica();
	double getPrecio();
	void agregar(Componente*);
	void setPrecio(double);
	string toString();

	void guardar(ostream&);
	static Componente* recuperar(istream&);
};