#pragma once
#include<sstream>
#include<string>

using namespace std;

double convertirDouble(string s) {
	stringstream r(s);
	double v;
	r >> v;
	return v;
}
void ignorar();

