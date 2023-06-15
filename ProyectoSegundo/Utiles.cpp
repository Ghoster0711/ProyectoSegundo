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