#include "Radio.h"
#include "Utiles.h"


// Delimitadores para la parte de archivos
#define DELIMITA_CAMPO '\t'
#define DELIMITA_REGISTRO '\n'

// Desarrollo del constructor parametrizado
Radio::Radio(string cod, string model, string carac, double pre, int uni) {
	codigo = cod;
	modelo = model;
	caracteristica = carac;
	precio = pre;
	unidades = uni;
}

// Desarrollo del Destructor
Radio::~Radio() {}

// Desarrollo de los get's
string Radio::getID() { return codigo; }
string Radio::getCodigo() { return codigo; }
string Radio::getCaracteristica() { return caracteristica; }
double Radio::getPrecio() { return precio; }
double Radio::obtenerPrecios() { return precio * unidades; }
int Radio::getUnidades() { return unidades; }


// Desarrollo de los set's
void Radio::agregar(Componente*) {}
void Radio::setCodigo(string cod) { codigo = cod; }
void Radio::setCaracteristica(string carac) { caracteristica = carac; }
void Radio::setPrecio(double pre) { precio = pre; }
void Radio::setUnidades(int uni) { unidades = uni; }

// Desarrollo del ToString
string Radio::toString() {
	stringstream show;
	show << "| Fuente de audio\t " << codigo << "\t\t" << "Radio" << "\t\t\t" << modelo << "\t\t" << caracteristica << "\t\t\t" << precio << "\t" << unidades;
	return show.str();
}

// Desarrollo del ToString para los kits
string Radio::toStringKits() {
	stringstream show;
	show << "| Fuente de audio\t " << codigo << "\t\t" << "Radio" << "\t\t\t" << modelo << "\t\t" << caracteristica << "\t\t\t" << precio;
	return show.str();
}

// Desarrollo del metodo guardar
void Radio::guardar(ostream& salida) {
	salida << "Radio" << DELIMITA_CAMPO;
	salida << codigo << DELIMITA_CAMPO;
	salida << modelo << DELIMITA_CAMPO;
	salida << caracteristica << DELIMITA_CAMPO;
	salida << precio << DELIMITA_CAMPO;
	salida << unidades << DELIMITA_REGISTRO;
}

// Desarrollo del metodo recuperar
Componente* Radio::recuperar(istream& entrada) {
	string cod, model, carac, precio, unidades;
	getline(entrada, cod, DELIMITA_CAMPO);
	getline(entrada, model, DELIMITA_CAMPO);
	getline(entrada, carac, DELIMITA_CAMPO);
	getline(entrada, precio, DELIMITA_CAMPO);
	getline(entrada, unidades, DELIMITA_REGISTRO);

	double valorPrecio = convierteDouble(precio);
	int valorUnidades = convierteInt(unidades);

	return new Radio(cod, model, carac, valorPrecio, valorUnidades);

}