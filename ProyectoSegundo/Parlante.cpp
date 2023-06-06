#include "Parlante.h"
#include "Utiles.h"

#define DELIMITA_CAMPO '\t'
#define DELIMITA_REGISTRO '\n'

Parlante::Parlante(string cod, string tipo, string model, string carac, double pre) {
	codigo = cod;
	tipoComponente = tipo;
	modelo = model;
	caracteristica = carac;
	precio = pre;
}

Parlante::~Parlante() {

}

string Parlante::getID()
{
	return codigo;
}

string Parlante::getCodigo()
{
	return codigo;
}

string Parlante::getCaracteristica() { return caracteristica; }

double Parlante::getPrecio() { return precio; }



void Parlante::setCodigo(string cod)
{
	codigo = cod;
}

void Parlante::setCaracteristica(string carac)
{
	caracteristica = carac;
}

void Parlante::agregar(Componente*) {}

void Parlante::setPrecio(double pre) { precio = pre; }

string Parlante::toString() {
	stringstream show;
	show << "Parlante\t" << codigo << "\t" << tipoComponente << "\t" << modelo << "\t" << caracteristica << "\t" << precio << "\t";
	return show.str();
}

void Parlante::guardar(ostream& salida){
	salida << "Parlante" << DELIMITA_CAMPO;
	salida << codigo << DELIMITA_CAMPO;
	salida << tipoComponente << DELIMITA_CAMPO;
	salida << modelo << DELIMITA_CAMPO;
	salida << caracteristica << DELIMITA_CAMPO;
	salida << precio << DELIMITA_REGISTRO;
}

Componente* Parlante::recuperar(istream& entrada)
{
	string cod, tipo, model, carac, precio;
	getline(entrada, cod, DELIMITA_CAMPO);
	getline(entrada, tipo, DELIMITA_CAMPO);
	getline(entrada, model, DELIMITA_CAMPO);
	getline(entrada, carac, DELIMITA_CAMPO);
	getline(entrada, precio, DELIMITA_REGISTRO);

	double valorPrecio = convierteDouble(precio);

	return new Parlante(cod, tipo, model, carac, valorPrecio);
}
