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

using namespace std;


int main() {

	string ruta = "C:/Users/barra/OneDrive - Universidad Nacional de Costa Rica/2023/Ciclo I 2023/Progra II/Proyectos/PROYECTO_2/facturas.txt";

	Fecha* fec = new Fecha(12, 06, 2023);
	Cliente* c1 = new Persona("Jime", "4444", "jimen.com", "88738");
	Destino* des = new Destino("1212", "Costa Rica", "GAM", 12000);
	Componente* com = NULL;
	Factura* fac = new Factura("1111", fec, c1, des, com);
	
	cout << fac->toString() << endl;

	ofstream salida;
	salida.open(ruta.c_str());
	fac->guardarDatos(salida);
	salida.close();
	cout << endl;
	delete fac;
	cout << "---Recuperar Factura---" << endl;
	ifstream entrada;
	entrada.open(ruta.c_str());
	while (entrada.good()) {
		Factura* f = Factura::recuperarDatos(entrada);
		if (entrada.good()) {
			cout << "--------------------Factura Recuperada------------------" << endl;
			cout << f->toString();
		}
		system("pause");
	}
	entrada.close();

	
	system("pause");
	return 0;
}