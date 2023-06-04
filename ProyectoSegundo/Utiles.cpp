#include "Utiles.h"

double convertirDouble(string s) {
	stringstream r(s);
	double v;
	r >> v;
	return v;
}