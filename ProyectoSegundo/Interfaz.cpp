#include "Interfaz.h"


// -----------MENUS-------------
int menu(){
	int op;
	cout << "------------MENU----------" << endl
		<< "| (1) Venta Directa.     |" << endl
		<< "| (2) Venta en linea.    |" << endl
		<< "| (3) Mantenimiento.     |" << endl
		<< "| (4) Reportes.          |" << endl
		<< "| (5) Salir.             |" << endl
		<< "--------------------------" << endl;
	cout << "| Ingrese una opcion -> ";	cin >> op;
	return op;
}

int menudirecto(){
	int op;
	cout << "------------------------------------------------" << endl
		<< "| Que desea ingresar a su carrito de compras   |" << endl
		<< "| (1) Componente.                              |" << endl
		<< "| (2) Sistema Preconfigurado.                  |" << endl
		<< "| (3) Crear Configurado a la medida.           |" << endl
		<< "| (4) Volver.                                  |" << endl
		<< "------------------------------------------------" << endl
		<< "| Ingrese una opcion -> "; cin >> op;
	return op;
}

int menuEnLinea(){
	int op;
	cout << "------------------------------------------------" << endl
		<< "| Que desea ingresar a su carrito de compras   |" << endl
		<< "| (1) Sistema Preconfigurado.                  |" << endl
		<< "| (2) Volver.                                  |" << endl
		<< "------------------------------------------------" << endl
		<< "| Ingrese una opcion -> "; cin >> op;
	return op;
}

int menuMantenimiento(){
	int op;
	cout << "-----------------------------------------" << endl
		<< "| (1) Ver Lista de clientes.             |" << endl
		<< "| (2) Ingreso de nuevos clientes         |" << endl
		<< "| (3) Ver lista del catalogo             |" << endl
		<< "| (4) Ingresar productos al catalogo     |" << endl
		<< "| (5) Eliminar productos del cat�logo    |" << endl
		<< "| (6) Volver.                            |" << endl
		<< "------------------------------------------" << endl
		<< "| Ingrese una opcion -> "; cin >> op;
	return op;

}

int menuReportes() {
	int op;
	cout << "---------------------------------------" << endl
		<< "| (1) Reporte equipos mas vendidos     |" << endl
		<< "| (2) Reportes ventas                  |" << endl
		<< "| (3) Volver.                          |" << endl
		<< "----------------------------------------" << endl
		<< "| Ingrese una opcion -> "; cin >> op;
	return op;
}

// -----------DIRECTO-----------


// -----------EN LINEA----------


// ---------MANTENIMIENTO-------

void mostrarClientes(Tienda* tienda) {
	cout << tienda->mostrarClientes();
}
Cliente* crearCliente(){
	int op;
	cout << "----------------------------------" << endl
		<< "| (1) Empresa.                    |" << endl
		<< "| (2) Persona.                    |" << endl
		<< "-----------------------------------"
		<< "| Que desea ingresar ->"; cin >> op;
	if (op == 1)
		return crearEmpresa();
	if (op == 2)
		return crearPersona();
	return NULL;
}
Cliente* crearPersona() {
	string nom, ced, correo, tel;
	cout << "Ingrese el nombre -> "; cin >> nom;
	cout << "Ingrese la cedula -> "; cin >> ced;
	cout << "Ingrese el correo -> "; cin >> correo;
	cout << "Ingrese el telefono -> "; cin >> tel;
	return new Persona(nom, ced, correo, tel);
}
Cliente* crearEmpresa(){
	string nom, ced, correo, tel;
	cout << "Ingrese el nombre de la empresa -> "; cin >> nom;
	cout << "Ingrese la cedula juridica-> "; cin >> ced;
	cout << "Ingrese el correo de la empresa-> "; cin >> correo;
	cout << "Ingrese el telefono de la empresa-> "; cin >> tel;
	return new Empresa(nom, ced, correo, tel);
}

void verCatalogo(Tienda* tienda) {
	cout << tienda->verCatalogo();
}

Componente* crearProducto(Tienda* tienda) {
	int op;
	cout << "-------------------------------------" << endl
		<< "| (1) Componente.                    |" << endl
		<< "| (2) Sistema Preconfigurado.        |" << endl
		<< "--------------------------------------" << endl
		<< "| Que desea ingresar ->"; cin >> op;
	if (op == 1)
		if (crearComponente() != NULL)
			return crearComponente();
	if (op == 2)
		if (crearSistemaPreconfigurado(tienda) != NULL)
			return crearSistemaPreconfigurado(tienda);
	return NULL;
}
Componente* crearComponente() {
	string tipo, model, carac, cod;
	double precio;
	int op;
	do {
		system("cls");
		cout << "------------------------------------" << endl
			<< "| (1) Fuente de audio               |" << endl
			<< "| (2) Procesador de senal           |" << endl
			<< "| (3) Parlante                      |" << endl
			<< "-------------------------------------" << endl
			<< "| Que desea agregar al sistema -> "; cin >> op;

		if (op == 1) {
			cout << "| Ingrese el codigo del componente -> "; cin >> cod;
			cout << "| Ingrese el tipo de componente -> "; cin >> tipo;
			cout << "| Ingrese el modelo del componente -> "; cin >> model;
			cout << "| Ingrese la caracteristica del componente -> "; cin >> carac;
			cout << "| Ingresel el precio del componente -> "; cin >> precio;
			return new FuenteDeAudio(cod,tipo, model, carac, precio);
		}
		if (op == 2) {
			cout << "| Ingrese el codigo del componente -> "; cin >> cod;
			cout << "| Ingrese el tipo de componente -> "; cin >> tipo;
			cout << "| Ingrese el modelo del componente -> "; cin >> model;
			cout << "| Ingrese la caracteristica del componente -> "; cin >> carac;
			cout << "| Ingresel el precio del componente -> "; cin >> precio;
			return new ProcesadorDeSenal(cod, tipo, model, carac, precio);
		}
		if (op == 3) {
			cout << "| Ingrese el codigo del componente -> "; cin >> cod;
			cout << "| Ingrese el tipo de componente -> "; cin >> tipo;
			cout << "| Ingrese el modelo del componente -> "; cin >> model;
			cout << "| Ingrese la caracteristica del componente -> "; cin >> carac;
			cout << "| Ingresel el precio del componente -> "; cin >> precio;
			return new Parlante(cod, tipo, model, carac, precio);
		}
	} while (op > 3);
	
	return NULL;
}
Componente* crearSistemaPreconfigurado(Tienda* tienda) {
	// Comodines
	Componente* kit = new Kit();
	string codK, cod, nom;
	char op;
	// Ingreso del nombre y codigo del kit
	cout << "--------------------------------------------" << endl;
	cout << "| Ingrese el nombre del Kit -> "; cin >> nom;
	cout << "--------------------------------------------" << endl;
	cout << "| Ingrese el codigo del Kit -> "; cin >> codK;
	// Ciclo para agregar componentes al kit
	do {
		// Muestra los componente con los que cuenta el catalogo
		tienda->mostrarSoloComponentes();
		// Muesta opciones por si no quiere hacer nada
		cout << "------------------------------------------------------" << endl
			<< "| (s) Volver.                                         |" << endl
			<< "-------------------------------------------------------" << endl
			<< "| Ingrese el codigo del producto a agregar -> "; cin >> cod; // Solicita que ingrese el codigo del componente
		// Verifica que cod se diferente a la opcion de para volver
		if (cod != "s") {
			// Verifica que el componente exista en el sistema
			if (tienda->buscarComponente(cod) == true) {
				// Pregunta que si quiere agregarlo al kit
				cout << "Se encontro el Componente desea agregarlo (s/n) "; cin >> op;
				// Si lo quiere agregar se encargar de agregarlo
				if (op == 's') {
					kit->agregar(tienda->retornarSoloComponentes(cod));
				}
			}
			else
				cout << "!! El Componente no existe en el catalogo." << endl;
		}
	} while (cod != "s");
	// Pregunta si lo quiere agregar y lo agrega
	cout << "Agregar el kit al catalogo? s/n "; cin >> op;
	if (op == 's') {
		kit->setCodigo(codK);
		kit->setNombre(nom);
		return (Componente*)new Kit(*(Kit*)kit);
	}
	delete kit;

	return NULL;
}

void eliminarProducto(Tienda* tienda) {
	string cod;
	cout << tienda->mostrarElCatalogo();
	cout << "-------------------------------------------------------" << endl
		<< "| Ingrese el codigo del producto a eliminar -> "; cin >> cod;
	if (tienda->buscarProductoDelCatalogo(cod) == true) {
		tienda->EliminarProducto(cod);
		cout << "El producto se elimino con exito!!" << endl;
	}
	else
		cout << "El codigo que se ingreso no coincide con ningun con los que se encuentran en el catalogo!!" << endl;
		system("pause");
}


// ----------REPORTES-----------



void salir(Tienda* tienda){
	cout << "Muchas Gracias por visitarnos" << endl;

}
