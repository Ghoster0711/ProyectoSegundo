#include "Lista.h"
#include "Kit.h"
#include "Dispositivo.h"
#include "Persona.h"
#include "Empresa.h"
#include "Destino.h"
#include"Factura.h"
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<stdlib.h>
#include<Windows.h>

using namespace std;


int main() {
	int k = 0;
	string ruta = "C:/Users/barra/OneDrive - Universidad Nacional de Costa Rica/2023/Ciclo I 2023/Progra II/Proyectos/PROYECTO_2/facturas.txt";
	//Factura 1 
	Fecha* fec1 = new Fecha();
	Cliente* c1 = new Persona("Jime", "4444", "jimen.com", "88738");
	Destino* des1 = new Destino("1212", "Costa Rica", "GAM", 12000);
	Componente* com1 = NULL;
	Factura* fac1 = new Factura("1111", fec1, c1, des1, com1);


	Fecha* fec2 = new Fecha();
	Cliente* c2 = new Persona("Sia", "3333", "sia.com", "89892");
	Destino* des2 = new Destino("1313", "Colombia", "Bogota", 25000);
	Componente* com2 = NULL;
	Factura* fac2 = new Factura("2222", fec2, c2, des2, com2);


	Factura** vec = new Factura * [2];

	vec[0] = fac1;
	vec[1] = fac2;

	for (int i = 0; i < 2; i++) {
		cout << vec[i]->toString() << endl;
	}
	ofstream salida;
	salida.open(ruta.c_str());

	for (int i = 0; i < 2; i++) {
		vec[i]->guardarDatos(salida);
	}
	salida.close();

	for (int i = 0; i < 2; i++) {
		delete vec[i];
	}
	delete[] vec;
	cout << endl;
	cout << "---Recuperar Facturas---" << endl;
	Factura** vec1 = new Factura * [2];
	ifstream entrada;
	entrada.open(ruta.c_str());
	while (entrada.good()) {
		Factura* f = Factura::recuperarDatos(entrada);
		vec1[k] = f;
		k++;
	}
	entrada.close();
	for (int i = 0; i < 2; i++) {
		cout << vec1[i]->toString() << endl;
	}
	
	system("pause");
	return 0;
}