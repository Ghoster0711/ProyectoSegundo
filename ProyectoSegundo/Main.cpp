#include "Tienda.h"












/// Prueba archivos clientes
//int main() {
//	string rutaSuscriptores = "../suscriptores.txt";
//	Cliente* p1 = new Persona("Joshua Amador Lara", "604830349", "josh@gmail.com", "83599692");
//	Cliente* p2 = new Persona("Jefferson Amador Lara", "119310170", "jeff@gmail.com", "83838674");
//	Cliente* e1 = new Empresa("Soporte Real", "2039-1240-123", "sreal@gmail.com", "27734146");
//	Cliente* e2 = new Empresa("Microsoft", "1022-1245-567", "micro@gmail.com", "22118080");
//	Tienda* tienda = new Tienda();
//
//	tienda->getSuscriptores()->ingresar(p1);
//	tienda->getSuscriptores()->ingresar(p2);
//	tienda->getSuscriptores()->ingresar(e1);
//	tienda->getSuscriptores()->ingresar(e2);
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
//	Componente* c1 = new FuenteDeAudio("Tornamesa", "HT59J", "AJLJSDLA", 150);
//	Componente* c2 = new Parlante("Audio", "HT59J", "AJLJSDLA", 150);
//	Componente* c3 = new ProcesadorDeSenal("Parlante", "HT59J", "AJLJSDLA", 150);
//	Componente* c4 = new FuenteDeAudio("Microfono", "HT59J", "AJLJSDLA", 150);
//
//	Componente* c5 = new Kit();
//
//	c5->agregar(new FuenteDeAudio("Tornamesa", "HT59J", "AJLJSDLA", 150));
//	c5->agregar(new Parlante("Audio", "HT59J", "AJLJSDLA", 150));
//	c5->agregar(new ProcesadorDeSenal("Parlante", "HT59J", "AJLJSDLA", 150) );
//	c5->agregar(new FuenteDeAudio("Microfono", "HT59J", "AJLJSDLA", 150));
//
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