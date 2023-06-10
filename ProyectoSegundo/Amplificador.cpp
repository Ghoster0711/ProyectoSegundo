#include "Amplificador.h"
#include "Utiles.h"


// Delimitadores para la parte de archivos
#define DELIMITA_CAMPO '\t'
#define DELIMITA_REGISTRO '\n'

// Desarrollo del constructor parametrizado
Amplificador::Amplificador(string cod, string model, string carac, double pre) {
	codigo = cod;
	modelo = model;
	caracteristica = carac;
	precio = pre;
}

// Desarrollo del Destructor
Amplificador::~Amplificador() {}

// Desarrollo de los get's
string Amplificador::getID() { return codigo; }
string Amplificador::getCodigo() { return codigo; }
string Amplificador::getCaracteristica() { return caracteristica; }
double Amplificador::getPrecio() { return precio; }

// Desarrollo de los set's
void Amplificador::agregar(Componente*) {}
void Amplificador::setCodigo(string cod) { codigo = cod; }
void Amplificador::setCaracteristica(string carac) { caracteristica = carac; }
void Amplificador::setPrecio(double pre) { precio = pre; }

// Desarrollo del ToString
string Amplificador::toString() {
	stringstream show;
	show << "----------------------------------------------------------------------------------------------" << endl;
	show << "| Procesador de senal\t" << codigo << "\t" << "Amplificador" << "\t\t" << modelo << "\t" << caracteristica << "\t" << precio << "\t";
	return show.str();
}

// Desarrollo del metodo guardar
void Amplificador::guardar(ostream& salida) {
	salida << "Amplificador" << DELIMITA_CAMPO;
	salida << codigo << DELIMITA_CAMPO;
	salida << modelo << DELIMITA_CAMPO;
	salida << caracteristica << DELIMITA_CAMPO;
	salida << precio << DELIMITA_REGISTRO;
}

// Desarrollo del metodo recuperar
Componente* Amplificador::recuperar(istream& entrada) {
	string cod, model, carac, precio;
	getline(entrada, cod, DELIMITA_CAMPO);
	getline(entrada, model, DELIMITA_CAMPO);
	getline(entrada, carac, DELIMITA_CAMPO);
	getline(entrada, precio, DELIMITA_REGISTRO);

	double valorPrecio = convierteDouble(precio);

	return new Amplificador(cod, model, carac, valorPrecio);

}