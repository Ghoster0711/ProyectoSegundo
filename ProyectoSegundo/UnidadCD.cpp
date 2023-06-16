#include "UnidadCD.h"
#include "Utiles.h"


// Delimitadores para la parte de archivos
#define DELIMITA_CAMPO '\t'
#define DELIMITA_REGISTRO '\n'

// Desarrollo del constructor parametrizado
UnidadCD::UnidadCD(string cod, string model, string carac, double pre, int uni) {
	codigo = cod;
	modelo = model;
	caracteristica = carac;
	precio = pre;
	unidades = uni;
}

// Desarrollo del Destructor
UnidadCD::~UnidadCD() {}

// Desarrollo de los get's
string UnidadCD::getID() { return codigo; }
string UnidadCD::getCodigo() { return codigo; }
string UnidadCD::getCaracteristica() { return caracteristica; }
double UnidadCD::getPrecio() { return precio; }
double UnidadCD::obtenerPrecios() { return precio; }
int UnidadCD::getUnidades(){ return unidades; }

// Desarrollo de los set's
void UnidadCD::agregar(Componente*) {}
void UnidadCD::setCodigo(string cod) { codigo = cod; }
void UnidadCD::setCaracteristica(string carac) { caracteristica = carac; }
void UnidadCD::setPrecio(double pre) { precio = pre; }
void UnidadCD::setUnidades(int uni) { unidades = uni; }

// Desarrollo del ToString
string UnidadCD::toString() {
	stringstream show;
	show << "| Fuente de audio\t " << codigo << "\t\t" << "Unidad CD" << "\t\t" << modelo << "\t\t" << caracteristica << espaciado(caracteristica) << precio << "\t\t" << unidades;
	return show.str();
}

// Desarrollo del ToString para los kits
string UnidadCD::toStringKits() {
	stringstream show;
	show << "| Fuente de audio\t " << codigo << "\t\t" << "Unidad CD" << "\t\t" << modelo << "\t\t" << caracteristica << espaciado(caracteristica) << precio;
	return show.str();
}

// Desarrollo del metodo guardar
void UnidadCD::guardar(ostream& salida) {
	salida << "Unidad CD" << DELIMITA_CAMPO;
	salida << codigo << DELIMITA_CAMPO;
	salida << modelo << DELIMITA_CAMPO;
	salida << caracteristica << DELIMITA_CAMPO;
	salida << precio << DELIMITA_CAMPO;
	salida << unidades << DELIMITA_REGISTRO;
}

// Desarrollo del metodo recuperar
Componente* UnidadCD::recuperar(istream& entrada) {
	string cod, model, carac, precio, unidades;
	getline(entrada, cod, DELIMITA_CAMPO);
	getline(entrada, model, DELIMITA_CAMPO);
	getline(entrada, carac, DELIMITA_CAMPO);
	getline(entrada, precio, DELIMITA_CAMPO);
	getline(entrada, unidades, DELIMITA_REGISTRO);

	double valorPrecio = convierteDouble(precio);
	int valorUnidades = convierteInt(unidades);

	return new UnidadCD(cod, model, carac, valorPrecio, valorUnidades);

}