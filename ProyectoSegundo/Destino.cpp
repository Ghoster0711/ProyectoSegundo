#include"Destino.h"

// Desarrollo del constructor
Destino::Destino() {
	codigo = "";
	pais = "";
	ciudad = "";
	costoTraslado = 0;
}

// Desarrollo del constructor parametrizado
Destino::Destino(string cod, string pai, string ciud, double costo) {
	codigo = cod;
	pais = pai;
	ciudad = ciud;
	costoTraslado = costo;
}

// Desarrollo del destructor
Destino:: ~Destino(){}

// Desarrollo de los get's
string Destino::getCodigo() { return codigo; }
string Destino::getPais() { return pais; }
string Destino::getCiudad() { return ciudad; }
double Destino::getCostoTraslado() { return costoTraslado; }

// Desarrollo de los set's
void Destino::setCodigo(string cod) { codigo = cod; }
void Destino::setPais(string pa) { pais = pa; }
void Destino::setCiudad(string ciud) { ciudad = ciud; }
void Destino::setCostoTraslado(double cost) { costoTraslado = cost; }

// Desarrollo del ToString
string Destino::toString() {
	stringstream s;
	s   << "| Codigo: " << codigo << endl
		<< "| Pais: " << pais << endl
		<< "| Ciudad: " << ciudad << endl
		<< "| Costo de Traslado: " << costoTraslado << endl;
	return s.str();
}

// Desarrollo del metodo guardar
void Destino::guardar(ostream& salida) {
	salida << codigo << DELIMITA_CAMPO 
		<< pais << DELIMITA_CAMPO 
		<< ciudad << DELIMITA_CAMPO 
		<< costoTraslado << DELIMITA_REGISTRO;
}

// Desarrollo del metodo recuperar
Destino* Destino::recuperar(istream& entrada) {
	Destino* destino = new Destino();
	string cod, pais, ciudad, costo;
	getline(entrada, cod, DELIMITA_CAMPO);
	getline(entrada, pais, DELIMITA_CAMPO);
	getline(entrada, ciudad, DELIMITA_CAMPO);
	getline(entrada, costo, DELIMITA_REGISTRO);

	return new Destino(cod, pais, ciudad, convierteDouble(costo));
}