#include "Radio.h"
#include "Utiles.h"


// Delimitadores para la parte de archivos
#define DELIMITA_CAMPO '\t'
#define DELIMITA_REGISTRO '\n'

// Desarrollo del constructor parametrizado
Radio::Radio(string cod, string model, string carac, double pre) {
	codigo = cod;
	modelo = model;
	caracteristica = carac;
	precio = pre;
}

// Desarrollo del Destructor
Radio::~Radio() {}

// Desarrollo de los get's
string Radio::getID() { return codigo; }
string Radio::getCodigo() { return codigo; }
string Radio::getCaracteristica() { return caracteristica; }
double Radio::getPrecio() { return precio; }

// Desarrollo de los set's
void Radio::agregar(Componente*) {}
void Radio::setCodigo(string cod) { codigo = cod; }
void Radio::setCaracteristica(string carac) { caracteristica = carac; }
void Radio::setPrecio(double pre) { precio = pre; }

// Desarrollo del ToString
string Radio::toString() {
	stringstream show;
	show << "----------------------------------------------------------------------------------------------" << endl;
	show << "| Fuente de audio\t" << codigo << "\t" << "Radio" << "\t\t\t" << modelo << "\t" << caracteristica << "\t" << precio << "\t";
	return show.str();
}

// Desarrollo del metodo guardar
void Radio::guardar(ostream& salida) {
	salida << "Radio" << DELIMITA_CAMPO;
	salida << codigo << DELIMITA_CAMPO;
	salida << modelo << DELIMITA_CAMPO;
	salida << caracteristica << DELIMITA_CAMPO;
	salida << precio << DELIMITA_REGISTRO;
}

// Desarrollo del metodo recuperar
Componente* Radio::recuperar(istream& entrada) {
	string cod, model, carac, precio;
	getline(entrada, cod, DELIMITA_CAMPO);
	getline(entrada, model, DELIMITA_CAMPO);
	getline(entrada, carac, DELIMITA_CAMPO);
	getline(entrada, precio, DELIMITA_REGISTRO);

	double valorPrecio = convierteDouble(precio);

	return new Radio(cod, model, carac, valorPrecio);

}