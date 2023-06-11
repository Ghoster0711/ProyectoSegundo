#pragma once
#include<iostream>
#include<sstream>

using namespace std;

class Excepciones {  //Case abstracta para la creacion de distintos tipos de Excepciones 
public:
	Excepciones();
	virtual ~Excepciones();
	virtual string toString() const = 0;   //Metodo virtual puro 
};

class ExcepcionRango : public Excepciones {    //Clase Derivada: Excepcion de que no se digito una opcion del menu 
public:
	ExcepcionRango();
	virtual ~ExcepcionRango();
	string toString() const;
};

class ExcepcionNoExiteModelo : public Excepciones {  //Clase Derivada: Excepcion de que el modelo del componente digitado no existe 
	ExcepcionNoExiteModelo();
	virtual ~ExcepcionNoExiteModelo();
	string toString() const;
};

class ExcepcionNoExiteSuscriptor : public Excepciones {   //Clase Derivada: Excepcion de que no existe un suscriptor con el numero 
	ExcepcionNoExiteSuscriptor();                         //de cedula digitado 
	virtual ~ExcepcionNoExiteSuscriptor();
	string toString() const;
};