#include "Tienda.h"


int main() {
	Tienda* tienda = new Tienda();
	Lista<Componente>* catalogo = new Lista<Componente>();

	Componente* c1 = new FuenteDeAudio("Tornamesa", "HT59J", "AJLJSDLA", 150);
	Componente* c2 = new Parlante("Audio", "HT59J", "AJLJSDLA", 150);
	Componente* c3 = new ProcesadorDeSenal("Parlante", "HT59J", "AJLJSDLA", 150);
	Componente* c4 = new FuenteDeAudio("Microfono", "HT59J", "AJLJSDLA", 150);

	Componente* c5 = new Kit();

	c5->agregar(new FuenteDeAudio("Tornamesa", "HT59J", "AJLJSDLA", 150));
	c5->agregar(new Parlante("Audio", "HT59J", "AJLJSDLA", 150));
	c5->agregar(new ProcesadorDeSenal("Parlante", "HT59J", "AJLJSDLA", 150) );
	c5->agregar(new FuenteDeAudio("Microfono", "HT59J", "AJLJSDLA", 150));

	
	system("pause");
	system("cls");

	tienda->getCatalago()->ingresar(c5);
	tienda->getCatalago()->ingresar(c1);
	tienda->getCatalago()->ingresar(c2);
	tienda->getCatalago()->ingresar(c3);
	tienda->getCatalago()->ingresar(c4);



	cout << endl << endl << endl;
	cout << tienda->getCatalago()->toString();

	system("pause");
	cout << "guardando en archivos" << endl;
	tienda->getCatalago()->guardarCatalogo();

	delete tienda;

	tienda = new Tienda();

	tienda->recuperarArchivoCatalogo();

	cout << endl << endl << endl;
	cout << "Imprimiendo con datos recuperados" << endl 
		<<	tienda->getCatalago()->toString();
	


	system("pause");
	return 0;
}