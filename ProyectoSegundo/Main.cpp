#include "Tienda.h"
#include "Interfaz.h"
#include"Factura.h"
#include"fstream"


//int main() {
//	Tienda* tienda = new Tienda();
//	int op, op5;
//	tienda->recuperarDeArchivos();
//	do {
//		system("cls");
//		op = menu();
//		switch (op) {
//		case 1:
//			generarVentaDirecta(tienda);
//			break;
//		case 2:
//			generarVentaEnLinea(tienda);
//			break;
//		case 3:
//			mantenimiento(tienda);
//			break;
//		case 4:
//			do {
//				system("cls");
//				op5 = menuReportes();
//				switch (op5) {
//				case 1:
//					
//					break;
//				case 2:
//					break;
//				case 3:
//					break;
//				}
//			} while (op5 != 3);
//			break;
//		case 5:
//			salir(tienda);
//			break;
//		}
//	} while (op != 5);
//
//
//
//
//	system("pause");
//	return 0;
//}

/// Prueba Archivos Facturas
int main() {
	string prueba = "C:/Users/barra/OneDrive - Universidad Nacional de Costa Rica/2023/Ciclo I 2023/Progra II/Proyectos/PROYECTO_SEGUNDO/pruebaFacturas.txt";
	Cliente* p1 = new Persona("Joshua Amador Lara", "604830349", "Costa Rica", "Heredia", "josh@gmail.com", "Costarricense");
	//Cliente* p2 = new Empresa("Microsoft", "1022-1245-567", "Rusia", "Tokyo");
	Cliente* p2 = new Empresa("Microsoft", "1022-1245-567", "Rusia", "Tokyo");


	Componente* c1 = new FuenteDeAudio("1010", "Tornamesa", "HT59J", "AJLJSDLA", 150);
	Componente* c2 = new Parlante("1010", "Audio", "HT59J", "AJLJSDLA", 150);
	Componente* c3 = new ProcesadorDeSenal("1010", "Parlante", "HT59J", "AJLJSDLA", 150);
	Componente* c4 = new FuenteDeAudio("1010", "Microfono", "HT59J", "AJLJSDLA", 150);


	Destino* destino = new Destino("010", "Argentina", "Buenos Aires", 17520);

	Fecha* f1 = new Fecha();
	//Fecha* f2 = new Fecha();

	Factura* fac1 = new EnLinea("1111", f1, p1, destino);
	//Factura* fac2 = new Directo("2222", f2, p2);
	fac1->ingresarCompra(c1);
	fac1->ingresarCompra(c2);

	Fecha* fec1 = new Fecha();
	Fecha* fec2 = new Fecha();

	Factura* fac1 = new EnLinea("1111", fec1, p1, destino);
	Factura* fac2 = new Directo("2222", fec2, p2);


	cout << fac1->toString() << endl;
	cout << endl;

	system("pause");

	cout << "Guardando archivos..." << endl;
	ofstream salida;
	salida.open(prueba);
	fac1->guardar(salida);

	salida.close();
	
	



	system("pause");
	return 0;
}





/// Prueba archivos clientes
//int main() {
//	string rutaSuscriptores = "../suscriptores.txt";
//	Cliente* p1 = new Persona("Joshua Amador Lara", "604830349", "Costa Rica", "Heredia", "josh@gmail.com", "Costarricense");
//	Cliente* p2 = new Persona("Jefferson Amador Lara", "119310170", "Costa Rica", "Heredia", "jeff@gmail.com", "Costarricense");
//	//Cliente* p2 = new Persona("Jefferson Amador Lara", "119310170", "jeff@gmail.com", "83838674");
//	Cliente* e1 = new Empresa("Soporte Real", "2039-1240-123", "USA", "New York");
//	Cliente* e2 = new Empresa("Microsoft", "1022-1245-567", "Rusia", "Tokyo");
//	Tienda* tienda = new Tienda();
//
//	tienda->getSuscriptores()->ingresar(*p1);
//	tienda->getSuscriptores()->ingresar(*p2);
//	tienda->getSuscriptores()->ingresar(*e1);
//	tienda->getSuscriptores()->ingresar(*e2);
//
//	cout << tienda->getSuscriptores()->toString();
//	cout << endl << endl << endl;
//	system("pause");
//	system("cls");
//
//	cout << "Guardando en archivos" << endl;
//	tienda->guardarSuscriptores();
//
//	cout << endl << endl << endl;
//	system("pause");
//	system("cls");
//
//	delete tienda;
//	tienda = new Tienda();
//	
//	cout << "Recuperando de Archivos" << endl; 
//	tienda->recuperarArchivoSuscriptores();
//
//	cout << endl << endl << endl;
//	system("pause");
//	system("cls");
//
//	
//
//	cout << "Mostrar archivos recuperados" << endl;
//	cout << tienda->getSuscriptores()->toString();
//
//	system("pause");
//	return 0;
//}




///Prueba archivos catalogo
//int main() {
//	Tienda* tienda = new Tienda();
//	Lista<Componente>* catalogo = new Lista<Componente>();
//
//	Componente* c1 = new FuenteDeAudio("1010", "Tornamesa", "HT59J", "AJLJSDLA", 150);
//	Componente* c2 = new Parlante("1010", "Audio", "HT59J", "AJLJSDLA", 150);
//	Componente* c3 = new ProcesadorDeSenal("1010", "Parlante", "HT59J", "AJLJSDLA", 150);
//	Componente* c4 = new FuenteDeAudio("1010", "Microfono", "HT59J", "AJLJSDLA", 150);
//
//	Componente* c5 = new Kit();
//
//	c5->agregar(new FuenteDeAudio("1010", "Tornamesa", "HT59J", "AJLJSDLA", 150));
//	c5->agregar(new Parlante("1010", "Audio", "HT59J", "AJLJSDLA", 150));
//	c5->agregar(new ProcesadorDeSenal("1010", "Parlante", "HT59J", "AJLJSDLA", 150) );
//	c5->agregar(new FuenteDeAudio("1010", "Microfono", "HT59J", "AJLJSDLA", 150));
//
//	c5->setCodigo("30303");
//	c5->setNombre("Pro");
//
//	system("pause");
//	system("cls");
//
//	tienda->getCatalago()->ingresar(c5);
//	tienda->getCatalago()->ingresar(c1);
//	tienda->getCatalago()->ingresar(c2);
//	tienda->getCatalago()->ingresar(c3);
//	tienda->getCatalago()->ingresar(c4);
//
//
//
//	cout << endl << endl << endl;
//	cout << tienda->getCatalago()->toString();
//
//	system("pause");
//	cout << "guardando en archivos" << endl;
//	tienda->getCatalago()->guardarCatalogo();
//
//	delete tienda;
//
//	tienda = new Tienda();
//
//	tienda->recuperarArchivoCatalogo();
//
//	cout << endl << endl << endl;
//	cout << "Imprimiendo con datos recuperados" << endl 
//		<<	tienda->getCatalago()->toString();
//	
//
//
//	system("pause");
//	return 0;
//}


