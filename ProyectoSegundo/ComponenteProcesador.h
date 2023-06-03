#pragma once
#include <iostream>
#include <sstream>

using namespace std;

class ComponenteProcesador {
public:
	virtual ~ComponenteProcesador() {}
	virtual string toString() = 0;
	virtual string getCaracteristica() = 0;
	virtual double getPrecio() = 0;
};