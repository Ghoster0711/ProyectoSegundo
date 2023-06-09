#include"Fecha.h"


//Constructor por defecto que toma la fecha actual
Fecha::Fecha() {   
	SYSTEMTIME fecha;
	GetLocalTime(&fecha);
	dia = fecha.wDay;
	mes = fecha.wMonth;
	anio = fecha.wYear;
}

//Constructor parametrizado 
Fecha::Fecha(int d, int m, int a) {  
	dia = d;
	mes = m;
	anio = a;
}

//Destrcutor 
Fecha::~Fecha() {}

int Fecha::getDia() { return dia; }
int Fecha::getMes() { return mes; }
int Fecha::getAnio() { return anio; }

void Fecha::setDia(int d) { dia = d; }
void Fecha::setMes(int m) { mes = m; }
void Fecha::setAnio(int a) { anio = a; }

string Fecha::toString() {
	stringstream s;
	s << dia << "/" << mes << "/" << anio;
	return s.str();
}

//Guardar datos al archivo 
void Fecha::guardarDatos(ostream& salida) {
	salida << dia << DELIMITA_CAMPO
		<< mes << DELIMITA_CAMPO
		<< anio << DELIMITA_REGISTRO;
}

//Recuperar datos del archivo 
Fecha* Fecha::recuperarDatos(istream& entrada) {
	string d, m, a;
	int dia, mes, anio;
	getline(entrada, d, DELIMITA_CAMPO);
	getline(entrada, m, DELIMITA_CAMPO);
	getline(entrada, a, DELIMITA_REGISTRO);
	dia = convierteInt(d);
	mes = convierteInt(m);
	anio = convierteInt(a);
	return new Fecha(dia, mes, anio);
}