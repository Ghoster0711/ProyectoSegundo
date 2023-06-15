#include "Microfono.h"
#include "Utiles.h"


// Delimitadores para la parte de archivos
#define DELIMITA_CAMPO '\t'
#define DELIMITA_REGISTRO '\n'

// Desarrollo del constructor parametrizado
Microfono::Microfono(string cod, string model, string carac, double pre, int uni) {
	codigo = cod;
	modelo = model;
	caracteristica = carac;
	precio = pre;
	unidades = uni;
}

// Desarrollo del Destructor
Microfono::~Microfono() {}

// Desarrollo de los get's
string Microfono::getID() { return codigo; }
string Microfono::getCodigo() { return codigo; }
string Microfono::getCaracteristica() { return caracteristica; }
double Microfono::getPrecio() { return precio; }
double Microfono::obtenerPrecios() { return precio; }
int Microfono::getUnidades() { return unidades; }




// Desarrollo de los set's
void Microfono::agregar(Componente*) {}
void Microfono::setCodigo(string cod) { codigo = cod; }
void Microfono::setCaracteristica(string carac) { caracteristica = carac; }
void Microfono::setPrecio(double pre) { precio = pre; }
void Microfono::setUnidades(int uni) { unidades = uni; }

// Desarrollo del ToString
string Microfono::toString() {
	stringstream show;
	show << "| Fuente de audio\t " << codigo << "\t\t" << "Microfono" << "\t\t" << modelo << "\t\t" << caracteristica << espaciado(caracteristica) << precio << "\t\t" << unidades;
	return show.str();
}

string Microfono::toStringKits() {
	stringstream show;
	show << "| Fuente de audio\t " << codigo << "\t\t" << "Microfono" << "\t\t" << modelo << "\t\t" << caracteristica << espaciado(caracteristica) << precio;
	return show.str();
}

// Desarrollo del metodo guardar
void Microfono::guardar(ostream& salida) {
	salida << "Microfono" << DELIMITA_CAMPO;
	salida << codigo << DELIMITA_CAMPO;
	salida << modelo << DELIMITA_CAMPO;
	salida << caracteristica << DELIMITA_CAMPO;
	salida << precio << DELIMITA_CAMPO;
	salida << unidades << DELIMITA_REGISTRO;
}

// Desarrollo del metodo recuperar
Componente* Microfono::recuperar(istream& entrada) {
	string cod, model, carac, precio, unidades;
	getline(entrada, cod, DELIMITA_CAMPO);
	getline(entrada, model, DELIMITA_CAMPO);
	getline(entrada, carac, DELIMITA_CAMPO);
	getline(entrada, precio, DELIMITA_CAMPO);
	getline(entrada, unidades, DELIMITA_REGISTRO);

	double valorPrecio = convierteDouble(precio);
	int valorUnidades = convierteInt(unidades);

	return new Microfono(cod, model, carac, valorPrecio, valorUnidades);

}