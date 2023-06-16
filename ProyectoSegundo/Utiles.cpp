#include"Utiles.h"

int convierteInt(string s) {
	stringstream r(s);
	int v;
	r >> v;
	return v;
}

double convierteDouble(string s) {
	stringstream r(s);
	double v;
	r >> v;
	return v;
}

string espaciado(string dato) {
	stringstream show;
	int cant = dato.length();
	if (cant > 30)
		show << "\t";
	if (cant <= 29 && cant >= 24)
		show << "\t\t";
	if (cant <= 23 && cant >= 19)
		show << "\t\t\t";
	if (cant <= 18 && cant >= 15)
		show << "\t\t\t";
	if (cant <= 14 && cant >= 10)
		show << "\t\t\t\t";
	if (cant <= 9 && cant >= 7)
		show << "\t\t\t\t";
	if (cant <= 6)
		show << "\t\t\t\t\t";


	return show.str();
}


void ignorar() {
	cin.ignore();
}
string recibirGetline() {
	string s;
	cin.ignore();
	getline(cin, s);
	return s;
}
int entradaInt() {
	int num;
	bool acceso = true;
	do {
		try {
			cin >> num;
			if (cin.fail()) {
				cin.clear();
				cin.ignore();
				acceso = false;
				throw "Error: entrada no válida, la entrada debe ser un numero, vuelva a ingresar";
			}
			else
				acceso = true;

		}
		catch (const char* error) {
			cerr << error << endl;
		}
	} while (acceso != true);
	return num;
}
double entradaDouble() {
	double num;
	bool acceso = true;
	do {
		try {
			cin >> num;
			if (cin.fail()) {
				cin.clear();
				cin.ignore();
				acceso = false;
				throw "Error: entrada no válida, la entrada debe ser un numero vuelva a ingresar";
			}
			else
				acceso = true;
		}
		catch (const char* error) {
			cerr << error << endl;
		}
	} while (acceso != true);
	return num;
}
char entradaSN() {
	char input;
	bool acceso = true;
	do {
		try {
			cin >> input;
			if (input != 's' && input != 'n') {
				acceso = false;
				throw "Error: entrada no válida debe ser s o n, vuelva a ingresar";
			}
			else
				acceso = true;
		}
		catch (const char* error) {
			cerr << error << endl;
		}
	} while (acceso != true);
	return input;
}