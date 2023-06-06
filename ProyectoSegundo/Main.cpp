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
	c5->agregar(new ProcesadorDeSenal("Parlante", "HT59J", "AJLJSDLA", 150));


	tienda->getCatalago()->ingresar(c5);
	tienda->getCatalago()->ingresar(c1);
	tienda->getCatalago()->ingresar(c2);
	tienda->getCatalago()->ingresar(c3);
	tienda->getCatalago()->ingresar(c4);


	Cliente* cliente = new Persona("Sia", "1111", "sia.com", "61319120", "cfcewf", "vrefe");
	Destino* destino = new Destino("010", "Brasil", "Brasilia", 17500);
	Factura* factura = new EnLinea("14141", new Fecha(), cliente, destino);

	factura->ingresarCompra(c5);
	cout << factura->toString() << endl;
	tienda->getVentas()->ingresar(factura);
	cout << tienda->getVentas()->toString();

	cout << endl;
	cout << "Guardar Datos" << endl;
	tienda->guardarFacturas();


	//delete tienda;

	/*tienda = new Tienda();*/

	//tienda->recuperarArchivoCatalogo();

	/*cout << endl << endl << endl;
	cout << "Imprimiendo con datos recuperados" << endl 
		<<	tienda->getCatalago()->toString();*/
	


	system("pause");
	return 0;
}