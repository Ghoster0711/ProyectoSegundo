#include "Audifono.h"
#include "Utiles.h"


// Delimitadores para la parte de archivos
#define DELIMITA_CAMPO '\t'
#define DELIMITA_REGISTRO '\n'

// Desarrollo del constructor parametrizado
Audifono::Audifono(string cod, string model, string carac, double pre, int uni) {
	codigo = cod;
	modelo = model;
	caracteristica = carac;
	precio = pre;
	unidades = uni;
}

// Desarrollo del Destructor
Audifono::~Audifono() {}

// Desarrollo de los get's
string Audifono::getID() { return codigo; }
string Audifono::getCodigo() { return codigo; }
string Audifono::getCaracteristica() { return caracteristica; }
double Audifono::getPrecio() { return precio; }
double Audifono::obtenerPrecios() {	return precio; }
int Audifono::getUnidades() { return unidades; }



// Desarrollo de los set's
void Audifono::agregar(Componente*) {}
void Audifono::setCodigo(string cod) { codigo = cod; }
void Audifono::setCaracteristica(string carac) { caracteristica = carac; }
void Audifono::setPrecio(double pre) { precio = pre; }
void Audifono::setUnidades(int uni) { unidades = uni; }

// Desarrollo del ToString
string Audifono::toString() {
	stringstream show;
	show << "| Parlante\t\t " << codigo << "\t\t" << "Audifono" << "\t\t" << modelo << "\t\t" << caracteristica << "\t\t\t" << precio << "\t" << unidades;
	return show.str();
}

// Desarrollo del ToString para los kits
string Audifono::toStringKits() {
	stringstream show;
	show << "| Parlante\t\t " << codigo << "\t\t" << "Audifono" << "\t\t" << modelo << "\t" << caracteristica << "\t\t\t" << precio;
	return show.str();
}

// Desarrollo del metodo guardar
void Audifono::guardar(ostream& salida) {
	salida << "Audifono" << DELIMITA_CAMPO;
	salida << codigo << DELIMITA_CAMPO;
	salida << modelo << DELIMITA_CAMPO;
	salida << caracteristica << DELIMITA_CAMPO;
	salida << precio << DELIMITA_CAMPO;
	salida << unidades << DELIMITA_REGISTRO;
}

// Desarrollo del metodo recuperar
Componente* Audifono::recuperar(istream& entrada) {
	string cod, model, carac, precio, unidades;
	getline(entrada, cod, DELIMITA_CAMPO);
	getline(entrada, model, DELIMITA_CAMPO);
	getline(entrada, carac, DELIMITA_CAMPO);
	getline(entrada, precio, DELIMITA_CAMPO);
	getline(entrada, unidades, DELIMITA_REGISTRO);

	double valorPrecio = convierteDouble(precio);
	int valorUnidades = convierteInt(unidades);

	return new Audifono(cod, model, carac, valorPrecio, valorUnidades);

}