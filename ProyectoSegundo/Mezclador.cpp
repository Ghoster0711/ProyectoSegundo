#include "Mezclador.h"
#include "Utiles.h"


// Delimitadores para la parte de archivos
#define DELIMITA_CAMPO '\t'
#define DELIMITA_REGISTRO '\n'

// Desarrollo del constructor parametrizado
Mezclador::Mezclador(string cod, string model, string carac, double pre) {
	codigo = cod;
	modelo = model;
	caracteristica = carac;
	precio = pre;
}

// Desarrollo del Destructor
Mezclador::~Mezclador() {}

// Desarrollo de los get's
string Mezclador::getID() { return codigo; }
string Mezclador::getCodigo() { return codigo; }
string Mezclador::getCaracteristica() { return caracteristica; }
double Mezclador::getPrecio() { return precio; }

// Desarrollo de los set's
void Mezclador::agregar(Componente*) {}
void Mezclador::setCodigo(string cod) { codigo = cod; }
void Mezclador::setCaracteristica(string carac) { caracteristica = carac; }
void Mezclador::setPrecio(double pre) { precio = pre; }

// Desarrollo del ToString
string Mezclador::toString() {
	stringstream show;
	show << "Procesador de senal\t" << codigo << "\t" << "Mezclador" << "\t" << modelo << "\t" << caracteristica << "\t" << precio << "\t";
	return show.str();
}

// Desarrollo del metodo guardar
void Mezclador::guardar(ostream& salida) {
	salida << "Mezclador" << DELIMITA_CAMPO;
	salida << codigo << DELIMITA_CAMPO;
	salida << modelo << DELIMITA_CAMPO;
	salida << caracteristica << DELIMITA_CAMPO;
	salida << precio << DELIMITA_REGISTRO;
}

// Desarrollo del metodo recuperar
Componente* Mezclador::recuperar(istream& entrada) {
	string cod, model, carac, precio;
	getline(entrada, cod, DELIMITA_CAMPO);
	getline(entrada, model, DELIMITA_CAMPO);
	getline(entrada, carac, DELIMITA_CAMPO);
	getline(entrada, precio, DELIMITA_REGISTRO);

	double valorPrecio = convierteDouble(precio);

	return new Mezclador(cod, model, carac, valorPrecio);

}