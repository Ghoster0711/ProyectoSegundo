#include"Exepciones.h"


Excepciones::Excepciones() {}
Excepciones:: ~Excepciones() {}

ExcepcionRango::ExcepcionRango() : Excepciones() {}
ExcepcionRango::~ExcepcionRango() {}
string ExcepcionRango::toString() const {
	return "ERROR: La opcion digitada esta fuera de rango. \n";
}

ExcepcionNoExiteModelo::ExcepcionNoExiteModelo(): Excepciones() {}
ExcepcionNoExiteModelo::~ExcepcionNoExiteModelo() {}
string ExcepcionNoExiteModelo::toString() const {
	return "ERROR: El modelo no existe. \n";
}