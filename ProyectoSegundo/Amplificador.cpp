#include "Amplificador.h"
#include "Utiles.h"


// Delimitadores para la parte de archivos
#define DELIMITA_CAMPO '\t'
#define DELIMITA_REGISTRO '\n'

// Desarrollo del constructor parametrizado
Amplificador::Amplificador(string cod, string model, string carac, double pre, int uni) {
	codigo = cod;
	modelo = model;
	caracteristica = carac;
	precio = pre;
	unidades = uni;
}

// Desarrollo del Destructor
Amplificador::~Amplificador() {}

// Desarrollo de los get's
string Amplificador::getID() { return codigo; }
string Amplificador::getCodigo() { return codigo; }
string Amplificador::getCaracteristica() { return caracteristica; }
double Amplificador::getPrecio() { return precio; }
double Amplificador::obtenerPrecios() {	return precio;}
int Amplificador::getUnidades() { return unidades; }


// Desarrollo de los set's
void Amplificador::agregar(Componente*) {}
void Amplificador::setCodigo(string cod) { codigo = cod; }
void Amplificador::setCaracteristica(string carac) { caracteristica = carac; }
void Amplificador::setPrecio(double pre) { precio = pre; }
void Amplificador::setUnidades(int uni) { unidades = uni; }


// Desarrollo del ToString
string Amplificador::toString() {
	stringstream show;
	show << "| Procesador de senal\t " << codigo << "\t\t" << "Amplificador" << "\t\t" << modelo << "\t\t" << caracteristica << "\t\t\t" << precio << "\t" << unidades;
	return show.str();
}

// Desarrollo del ToString para los kits
string Amplificador::toStringKits() {
	stringstream show;
	show << "| Procesador de senal\t " << codigo << "\t\t" << "Amplificador" << "\t\t" << modelo << "\t\t" << caracteristica << "\t\t\t" << precio;
	return show.str();
}

// Desarrollo del metodo guardar
void Amplificador::guardar(ostream& salida) {
	salida << "Amplificador" << DELIMITA_CAMPO;
	salida << codigo << DELIMITA_CAMPO;
	salida << modelo << DELIMITA_CAMPO;
	salida << caracteristica << DELIMITA_CAMPO;
	salida << precio << DELIMITA_CAMPO;
	salida << unidades << DELIMITA_REGISTRO;
}

// Desarrollo del metodo recuperar
Componente* Amplificador::recuperar(istream& entrada) {
	string cod, model, carac, precio, unidades;
	getline(entrada, cod, DELIMITA_CAMPO);
	getline(entrada, model, DELIMITA_CAMPO);
	getline(entrada, carac, DELIMITA_CAMPO);
	getline(entrada, precio, DELIMITA_CAMPO);
	getline(entrada, unidades, DELIMITA_REGISTRO);

	double valorPrecio = convierteDouble(precio);
	int valorUnidades = convierteInt(unidades);

	return new Amplificador(cod, model, carac, valorPrecio, valorUnidades);

}