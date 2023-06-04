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