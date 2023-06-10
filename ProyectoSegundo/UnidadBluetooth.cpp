#include "UnidadBluetooth.h"
#include "Utiles.h"


// Delimitadores para la parte de archivos
#define DELIMITA_CAMPO '\t'
#define DELIMITA_REGISTRO '\n'

// Desarrollo del constructor parametrizado
UnidadBluetooth::UnidadBluetooth(string cod, string model, string carac, double pre) {
	codigo = cod;
	modelo = model;
	caracteristica = carac;
	precio = pre;
}

// Desarrollo del Destructor
UnidadBluetooth::~UnidadBluetooth() {}

// Desarrollo de los get's
string UnidadBluetooth::getID() { return codigo; }
string UnidadBluetooth::getCodigo() { return codigo; }
string UnidadBluetooth::getCaracteristica() { return caracteristica; }
double UnidadBluetooth::getPrecio() { return precio; }

// Desarrollo de los set's
void UnidadBluetooth::agregar(Componente*) {}
void UnidadBluetooth::setCodigo(string cod) { codigo = cod; }
void UnidadBluetooth::setCaracteristica(string carac) { caracteristica = carac; }
void UnidadBluetooth::setPrecio(double pre) { precio = pre; }

// Desarrollo del ToString
string UnidadBluetooth::toString() {
	stringstream show;
	show << "----------------------------------------------------------------------------------------------" << endl;
	show << "| Fuente de audio\t" << codigo << "\t" << "Unidad Bluetooth" << "\t" << modelo << "\t" << caracteristica << "\t" << precio << "\t";
	return show.str();
}

// Desarrollo del metodo guardar
void UnidadBluetooth::guardar(ostream& salida) {
	salida << "Unidad Bluetooth" << DELIMITA_CAMPO;
	salida << codigo << DELIMITA_CAMPO;
	salida << modelo << DELIMITA_CAMPO;
	salida << caracteristica << DELIMITA_CAMPO;
	salida << precio << DELIMITA_REGISTRO;
}

// Desarrollo del metodo recuperar
Componente* UnidadBluetooth::recuperar(istream& entrada) {
	string cod, model, carac, precio;
	getline(entrada, cod, DELIMITA_CAMPO);
	getline(entrada, model, DELIMITA_CAMPO);
	getline(entrada, carac, DELIMITA_CAMPO);
	getline(entrada, precio, DELIMITA_REGISTRO);

	double valorPrecio = convierteDouble(precio);

	return new UnidadBluetooth(cod, model, carac, valorPrecio);

}