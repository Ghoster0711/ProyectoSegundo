#include "Parlante.h"
#include "Utiles.h"

// Delimitadores para la parte de archivos
#define DELIMITA_CAMPO '\t'
#define DELIMITA_REGISTRO '\n'

// Desarrollo del constructor parametrizado
Parlante::Parlante(string cod, string tipo, string model, string carac, double pre) {
	codigo = cod;
	tipoComponente = tipo;
	modelo = model;
	caracteristica = carac;
	precio = pre;
}

// Desarrollo del destructor
Parlante::~Parlante() {

}

// Desarrollo de los get's
string Parlante::getID() { return codigo; }
string Parlante::getCodigo() { return codigo; }
string Parlante::getCaracteristica() { return caracteristica; }
double Parlante::getPrecio() { return precio; }

// Desarrollo de los set's
void Parlante::setCodigo(string cod) { codigo = cod; }
void Parlante::setCaracteristica(string carac) { caracteristica = carac; }
void Parlante::agregar(Componente*) {}
void Parlante::setPrecio(double pre) { precio = pre; }


// Desarrollo del ToString
string Parlante::toString() {
	stringstream show;
	show << "Parlante\t\t" << codigo << "\t" << tipoComponente << "\t" << modelo << "\t" << caracteristica << "\t" << precio << "\t";
	return show.str();
}

// Desarrollo del metodo de guardar
void Parlante::guardar(ostream& salida){
	salida << "Parlante" << DELIMITA_CAMPO;
	salida << codigo << DELIMITA_CAMPO;
	salida << tipoComponente << DELIMITA_CAMPO;
	salida << modelo << DELIMITA_CAMPO;
	salida << caracteristica << DELIMITA_CAMPO;
	salida << precio << DELIMITA_REGISTRO;
}

// Desarrollo del metodo de recuperar
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
