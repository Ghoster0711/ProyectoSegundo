#include "Altavoz.h"
#include "Utiles.h"


// Delimitadores para la parte de archivos
#define DELIMITA_CAMPO '\t'
#define DELIMITA_REGISTRO '\n'

// Desarrollo del constructor parametrizado
Altavoz::Altavoz(string cod, string model, string carac, double pre, int uni) {
	codigo = cod;
	modelo = model;
	caracteristica = carac;
	precio = pre;
	unidades = uni;
}

// Desarrollo del Destructor
Altavoz::~Altavoz() {}

// Desarrollo de los get's
string Altavoz::getID() { return codigo; }
string Altavoz::getCodigo() { return codigo; }
string Altavoz::getCaracteristica() { return caracteristica; }
double Altavoz::getPrecio() { return precio; }
double Altavoz::obtenerPrecios() { return precio;}
int Altavoz::getUnidades() { return unidades; }


// Desarrollo de los set's
void Altavoz::agregar(Componente*) {}
void Altavoz::setCodigo(string cod) { codigo = cod; }
void Altavoz::setCaracteristica(string carac) { caracteristica = carac; }
void Altavoz::setPrecio(double pre) { precio = pre; }
void Altavoz::setUnidades(int uni) { unidades = uni; }


// Desarrollo del ToString
string Altavoz::toString() {
	stringstream show;
	show << "| Parlante\t\t " << codigo << "\t\t" << "Altavoz" << "\t\t\t" << modelo << "\t\t" << caracteristica << "\t\t\t" << precio << "\t" << unidades;
	return show.str();
}

// Desarrollo del ToString para los kits
string Altavoz::toStringKits() {
	stringstream show;
	show << "| Parlante\t\t " << codigo << "\t\t" << "Altavoz" << "\t\t\t" << modelo << "\t\t" << caracteristica << "\t\t\t" << precio;
	return show.str();
}

// Desarrollo del metodo guardar
void Altavoz::guardar(ostream& salida) {
	salida << "Altavoz" << DELIMITA_CAMPO;
	salida << codigo << DELIMITA_CAMPO;
	salida << modelo << DELIMITA_CAMPO;
	salida << caracteristica << DELIMITA_CAMPO;
	salida << precio << DELIMITA_CAMPO;
	salida << unidades << DELIMITA_REGISTRO;
}

// Desarrollo del metodo recuperar
Componente* Altavoz::recuperar(istream& entrada) {
	string cod, model, carac, precio, unidades;
	getline(entrada, cod, DELIMITA_CAMPO);
	getline(entrada, model, DELIMITA_CAMPO);
	getline(entrada, carac, DELIMITA_CAMPO);
	getline(entrada, precio, DELIMITA_CAMPO);
	getline(entrada, unidades, DELIMITA_REGISTRO);

	double valorPrecio = convierteDouble(precio);
	int valorUnidades = convierteInt(unidades);

	return new Altavoz(cod, model, carac, valorPrecio, valorUnidades);

}