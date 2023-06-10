#include "Microfono.h"
#include "Utiles.h"


// Delimitadores para la parte de archivos
#define DELIMITA_CAMPO '\t'
#define DELIMITA_REGISTRO '\n'

// Desarrollo del constructor parametrizado
Microfono::Microfono(string cod, string model, string carac, double pre) {
	codigo = cod;
	modelo = model;
	caracteristica = carac;
	precio = pre;
}

// Desarrollo del Destructor
Microfono::~Microfono() {}

// Desarrollo de los get's
string Microfono::getID() { return codigo; }
string Microfono::getCodigo() { return codigo; }
string Microfono::getCaracteristica() { return caracteristica; }
double Microfono::getPrecio() { return precio; }

// Desarrollo de los set's
void Microfono::agregar(Componente*) {}
void Microfono::setCodigo(string cod) { codigo = cod; }
void Microfono::setCaracteristica(string carac) { caracteristica = carac; }
void Microfono::setPrecio(double pre) { precio = pre; }

// Desarrollo del ToString
string Microfono::toString() {
	stringstream show;
	show << "| Fuente de audio\t" << codigo << "\t" << "Microfono" << "\t\t" << modelo << "\t" << caracteristica << "\t" << precio << "\t";
	return show.str();
}

// Desarrollo del metodo guardar
void Microfono::guardar(ostream& salida) {
	salida << "Microfono" << DELIMITA_CAMPO;
	salida << codigo << DELIMITA_CAMPO;
	salida << modelo << DELIMITA_CAMPO;
	salida << caracteristica << DELIMITA_CAMPO;
	salida << precio << DELIMITA_REGISTRO;
}

// Desarrollo del metodo recuperar
Componente* Microfono::recuperar(istream& entrada) {
	string cod, model, carac, precio;
	getline(entrada, cod, DELIMITA_CAMPO);
	getline(entrada, model, DELIMITA_CAMPO);
	getline(entrada, carac, DELIMITA_CAMPO);
	getline(entrada, precio, DELIMITA_REGISTRO);

	double valorPrecio = convierteDouble(precio);

	return new Microfono(cod, model, carac, valorPrecio);

}