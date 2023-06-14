#include "Mezclador.h"
#include "Utiles.h"


// Delimitadores para la parte de archivos
#define DELIMITA_CAMPO '\t'
#define DELIMITA_REGISTRO '\n'

// Desarrollo del constructor parametrizado
Mezclador::Mezclador(string cod, string model, string carac, double pre, int uni) {
	codigo = cod;
	modelo = model;
	caracteristica = carac;
	precio = pre;
	unidades = uni;
}

// Desarrollo del Destructor
Mezclador::~Mezclador() {}

// Desarrollo de los get's
string Mezclador::getID() { return codigo; }
string Mezclador::getCodigo() { return codigo; }
string Mezclador::getCaracteristica() { return caracteristica; }
double Mezclador::getPrecio() { return precio; }
double Mezclador::obtenerPrecios() { return precio * unidades; }
int Mezclador::getUnidades() { return unidades; }

// Desarrollo de los set's
void Mezclador::agregar(Componente*) {}
void Mezclador::setCodigo(string cod) { codigo = cod; }
void Mezclador::setCaracteristica(string carac) { caracteristica = carac; }
void Mezclador::setPrecio(double pre) { precio = pre; }
void Mezclador::setUnidades(int uni) { unidades = uni; }

// Desarrollo del ToString
string Mezclador::toString() {
	stringstream show;
	show << "| Procesador de senal\t " << codigo << "\t\t" << "Mezclador" << "\t\t" << modelo << "\t\t" << caracteristica << "\t\t\t" << precio << "\t" << unidades;
	return show.str();
}

// Desarrollo del ToString para los kits
string Mezclador::toStringKits() {
	stringstream show;
	show << "| Procesador de senal\t " << codigo << "\t\t" << "Mezclador" << "\t\t" << modelo << "\t\t" << caracteristica << "\t\t\t" << precio;
	return show.str();
}


// Desarrollo del metodo guardar
void Mezclador::guardar(ostream& salida) {
	salida << "Mezclador" << DELIMITA_CAMPO;
	salida << codigo << DELIMITA_CAMPO;
	salida << modelo << DELIMITA_CAMPO;
	salida << caracteristica << DELIMITA_CAMPO;
	salida << precio << DELIMITA_CAMPO;
	salida << unidades << DELIMITA_REGISTRO;
}

// Desarrollo del metodo recuperar
Componente* Mezclador::recuperar(istream& entrada) {
	string cod, model, carac, precio, unidades;
	getline(entrada, cod, DELIMITA_CAMPO);
	getline(entrada, model, DELIMITA_CAMPO);
	getline(entrada, carac, DELIMITA_CAMPO);
	getline(entrada, precio, DELIMITA_CAMPO);
	getline(entrada, unidades, DELIMITA_REGISTRO);

	double valorPrecio = convierteDouble(precio);
	int valorUnidades = convierteInt(unidades);

	return new Mezclador(cod, model, carac, valorPrecio, valorUnidades);

}