/* --------------------------------------------------------------------
*
* EIF204 Programación 2
* Proyecto 2
*
* 6 0483 0349 Joshua Yarit Amador Lara.
* 4 0264 0260 Sianny Barrantes Benavides.
*
* -------------------------------------------------------------------
*/

#pragma once
#include <iostream>
#include<sstream>
#include<string.h>

using namespace std;

// Convierte de string a numero
int convierteInt(std::string);  //Metodo para convertir un string a un int 
double convierteDouble(std::string);  //Metodo para convertir un string a un double 

// Se encarga del espaciodo entre datos
string espaciado(string);

void ignorar();
string recibirGetline();
int entradaInt();
double entradaDouble();
char entradaSN();

