#include "Tornamesa.h"
#include "Utiles.h"


// Delimitadores para la parte de archivos
#define DELIMITA_CAMPO '\t'
#define DELIMITA_REGISTRO '\n'

// Desarrollo del constructor parametrizado
Tornamesa::Tornamesa(string cod, string model, string carac, double pre) {
	codigo = cod;
	modelo = model;
	caracteristica = carac;
	precio = pre;
}

// Desarrollo del Destructor
Tornamesa::~Tornamesa() {}

// Desarrollo de los get's
string Tornamesa::getID() { return codigo; }
string Tornamesa::getCodigo() { return codigo; }
string Tornamesa::getCaracteristica() { return caracteristica; }
double Tornamesa::getPrecio() { return precio; }

// Desarrollo de los set's
void Tornamesa::agregar(Componente*) {}
void Tornamesa::setCodigo(string cod) { codigo = cod; }
void Tornamesa::setCaracteristica(string carac) { caracteristica = carac; }
void Tornamesa::setPrecio(double pre) { precio = pre; }

// Desarrollo del ToString
string Tornamesa::toString() {
	stringstream show;
	show << "----------------------------------------------------------------------------------------------" << endl;
	show << "| Fuente de audio\t" << codigo << "\t" << "Tornamesa" << "\t\t" << modelo << "\t" << caracteristica << "\t" << precio << "\t";
	return show.str();
}

// Desarrollo del metodo guardar
void Tornamesa::guardar(ostream& salida) {
	salida << "Tornamesa" << DELIMITA_CAMPO;
	salida << codigo << DELIMITA_CAMPO;
	salida << modelo << DELIMITA_CAMPO;
	salida << caracteristica << DELIMITA_CAMPO;
	salida << precio << DELIMITA_REGISTRO;
}

// Desarrollo del metodo recuperar
Componente* Tornamesa::recuperar(istream& entrada) {
	string cod, model, carac, precio;
	getline(entrada, cod, DELIMITA_CAMPO);
	getline(entrada, model, DELIMITA_CAMPO);
	getline(entrada, carac, DELIMITA_CAMPO);
	getline(entrada, precio, DELIMITA_REGISTRO);

	double valorPrecio = convierteDouble(precio);

	return new Tornamesa(cod, model, carac, valorPrecio);

}