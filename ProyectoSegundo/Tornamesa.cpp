#include "Tornamesa.h"
#include "Utiles.h"


// Delimitadores para la parte de archivos
#define DELIMITA_CAMPO '\t'
#define DELIMITA_REGISTRO '\n'

// Desarrollo del constructor parametrizado
Tornamesa::Tornamesa(string cod, string model, string carac, double pre, int uni) {
	codigo = cod;
	modelo = model;
	caracteristica = carac;
	precio = pre;
	unidades = uni;
}

// Desarrollo del Destructor
Tornamesa::~Tornamesa() {}

// Desarrollo de los get's
string Tornamesa::getID() { return codigo; }
string Tornamesa::getCodigo() { return codigo; }
string Tornamesa::getCaracteristica() { return caracteristica; }
double Tornamesa::getPrecio() { return precio; }
double Tornamesa::obtenerPrecios() { return precio; }
int Tornamesa::getUnidades() { return unidades; }


// Desarrollo de los set's
void Tornamesa::agregar(Componente*) {}
void Tornamesa::setCodigo(string cod) { codigo = cod; }
void Tornamesa::setCaracteristica(string carac) { caracteristica = carac; }
void Tornamesa::setPrecio(double pre) { precio = pre; }
void Tornamesa::setUnidades(int uni) { unidades = uni; }

// Desarrollo del ToString
string Tornamesa::toString() {
	stringstream show;
	show << "| Fuente de audio\t " << codigo << "\t\t" << "Tornamesa" << "\t\t" << modelo << "\t\t" << caracteristica << espaciado(caracteristica) << precio << "\t\t" << unidades;
	return show.str();
}

// Desarrollo del ToString para los kits
string Tornamesa::toStringKits() {
	stringstream show;
	show << "| Fuente de audio\t " << codigo << "\t\t" << "Tornamesa" << "\t\t" << modelo << "\t\t" << caracteristica << espaciado(caracteristica) << precio;
	return show.str();
}

// Desarrollo del metodo guardar
void Tornamesa::guardar(ostream& salida) {
	salida << "Tornamesa" << DELIMITA_CAMPO;
	salida << codigo << DELIMITA_CAMPO;
	salida << modelo << DELIMITA_CAMPO;
	salida << caracteristica << DELIMITA_CAMPO;
	salida << precio << DELIMITA_CAMPO;
	salida << unidades << DELIMITA_REGISTRO;
}

// Desarrollo del metodo recuperar
Componente* Tornamesa::recuperar(istream& entrada) {
	string cod, model, carac, precio, unidades;
	getline(entrada, cod, DELIMITA_CAMPO);
	getline(entrada, model, DELIMITA_CAMPO);
	getline(entrada, carac, DELIMITA_CAMPO);
	getline(entrada, precio, DELIMITA_CAMPO);
	getline(entrada, unidades, DELIMITA_REGISTRO);

	double valorPrecio = convierteDouble(precio);
	int valorUnidades = convierteInt(unidades);

	return new Tornamesa(cod, model, carac, valorPrecio, valorUnidades);

}