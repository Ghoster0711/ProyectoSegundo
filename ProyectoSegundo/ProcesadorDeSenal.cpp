#include "ProcesadorDeSenal.h"
#include "Utiles.h"

// Delimitadores que se utilizaran en archivos
#define DELIMITA_CAMPO '\t'
#define DELIMITA_REGISTRO '\n'

// Desarrollo del constructor
ProcesadorDeSenal::ProcesadorDeSenal(string cod, string tipo, string model, string carac, double pre) {
	codigo = cod;
	tipoComponente = tipo;
	modelo = model;
	caracteristica = carac;
	precio = pre;
}

// Desarrollo del destructor
ProcesadorDeSenal::~ProcesadorDeSenal() {

}

// Desarrollo de los get's
string ProcesadorDeSenal::getID() { return codigo; }
string ProcesadorDeSenal::getNombre() { return ""; }
string ProcesadorDeSenal::getCodigo() {	return codigo; }
string ProcesadorDeSenal::getCaracteristica() { return caracteristica; }
double ProcesadorDeSenal::getPrecio() { return precio; }


// Desarrollo de los set's
void ProcesadorDeSenal::setCodigo(string cod) {	codigo = cod; }
void ProcesadorDeSenal::setCaracteristica(string carac) { caracteristica = carac; }
void ProcesadorDeSenal::setPrecio(double pre) { precio = pre; }

// Desarrollo del metodo agregar
void ProcesadorDeSenal::agregar(Componente*) {}


// Desarrollo del metodo ToString
string ProcesadorDeSenal::toString() {
	stringstream show;
	show << "Procesador de senal\t" << codigo << "\t" << tipoComponente << "\t" << modelo << "\t" << caracteristica << "\t" << precio << "\t";
	return show.str();
}

// Desarrollo del metodo para guardar
void ProcesadorDeSenal::guardar(ostream& salida) {
	salida << "Procesador de senal" << DELIMITA_CAMPO;
	salida << codigo << DELIMITA_CAMPO;
	salida << tipoComponente << DELIMITA_CAMPO;
	salida << modelo << DELIMITA_CAMPO;
	salida << caracteristica << DELIMITA_CAMPO;
	salida << precio << DELIMITA_REGISTRO;
}

// Desarrollo del metodo para recuperar
Componente* ProcesadorDeSenal::recuperar(istream& entrada)
{
	string  cod, tipo, model, carac, precio;
	getline(entrada, cod, DELIMITA_CAMPO);
	getline(entrada, tipo, DELIMITA_CAMPO);
	getline(entrada, model, DELIMITA_CAMPO);
	getline(entrada, carac, DELIMITA_CAMPO);
	getline(entrada, precio, DELIMITA_REGISTRO);

	double valorPrecio = convierteDouble(precio);

	return new ProcesadorDeSenal(cod, tipo, model, carac, valorPrecio);
}
