#include "Interfaz.h"


// -----------MENUS-------------
int menu(){
	int op = 0;
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
	int op = 0;
	cout << "------------------------------------------------" << endl
		<< "| Que desea ingresar a su carrito de compras   |" << endl
		<< "| (1) Componente.                              |" << endl
		<< "| (2) Sistema Preconfigurado.                  |" << endl
		<< "| (3) Crear Configurado a la medida.           |" << endl
		<< "| (4) Finalizar.                               |" << endl
		<< "------------------------------------------------" << endl
		<< "| Ingrese una opcion -> "; cin >> op;
	return op;
}

int menuEnLinea(){
	int op = 0;
	cout << "------------------------------------------------" << endl
		<< "| Que desea ingresar a su carrito de compras   |" << endl
		<< "| (1) Sistema Preconfigurado.                  |" << endl
		<< "| (2) Finalizar.                                  |" << endl
		<< "------------------------------------------------" << endl
		<< "| Ingrese una opcion -> "; cin >> op;
	return op;
}

int menuMantenimiento(){
	int op = 0;
	cout << "-----------------------------------------" << endl
		<< "| (1) Ver Lista de clientes.             |" << endl
		<< "| (2) Ingreso de nuevos clientes         |" << endl
		<< "| (3) Eliminar Cliente                   |" << endl
		<< "| (4) Ver lista del catalogo             |" << endl
		<< "| (5) Ingresar productos al catalogo     |" << endl
		<< "| (6) Eliminar productos del catálogo    |" << endl
		<< "| (7) Volver.                            |" << endl
		<< "------------------------------------------" << endl
		<< "| Ingrese una opcion -> "; cin >> op;
	return op;

}

int menuReportes() {
	int op = 0;
	cout << "---------------------------------------" << endl
		<< "| (1) Reporte equipos mas vendidos     |" << endl
		<< "| (2) Reportes ventas                  |" << endl
		<< "| (3) Volver.                          |" << endl
		<< "----------------------------------------" << endl
		<< "| Ingrese una opcion -> "; cin >> op;
	return op;
}

// -----------DIRECTO-----------

void generarVentaDirecta(Tienda* tienda){
	int op = 0;
	do {
		system("cls");
		op = menudirecto();
		switch (op) {
		case 1:
			agregarComponente(tienda);
			break;
		case 2:
			agregarSistemaPreconfigurado(tienda);
			break;
		case 3:
			agregarNuevoSistemaAMedida(tienda);
			break;
		case 4:
			// Falta 
			break;
		}
	} while (op != 4);
}

Componente* agregarComponente(Tienda* tienda){
	string cod;
	cout << tienda->mostrarSoloComponentes();
	cout << "--------------------------------------------------------------------------" << endl
		<< "| Seleccione el componente deseado por su codigo -> "; cin >> cod;
	if (tienda->buscarComponente(cod) == true) {
		return tienda->retornarSoloComponentes(cod);
	}
	else {
		cout << "No se pudo agregar el componente!!" << endl;
		system("pause");
	}
	return NULL;
}

Componente* agregarSistemaPreconfigurado(Tienda* tienda){
	string cod;
	cout << tienda->mostrarSoloKits();
	cout << "-----------------------------------------------------------" << endl
		<< "| Seleccione el kit deseado por su codigo -> "; cin >> cod;
	if (tienda->buscarCliente(cod) == true) {
		return tienda->retornarSoloKits(cod);
	}
	else {
		cout << "No se pudo agregar el Sistema Preconfigurado" << endl;
		system("pause");
	}
	return NULL;
}

Componente* agregarNuevoSistemaAMedida(Tienda* tienda){
	// Falta
	return NULL;
}

// -----------EN LINEA----------

void generarVentaEnLinea(Tienda* tienda){
	int op = 0;
	do {
		system("cls");
		op = menuEnLinea();
		switch (op)
		{
		case 1:
			agregarSistemaPreconfigurado(tienda);
			break;
		case 2:
			// Falta
			break;
		}
	} while (op != 2);
}

// ---------MANTENIMIENTO-------

void mantenimiento(Tienda* tienda) {
	int op = 0;
	do {
		system("cls");
		op = menuMantenimiento();
		switch (op) {
		case 1:
			mostrarClientes(tienda);
			break;
		case 2:
			ingresoSuscriptores(tienda);
			break;
		case 3:
			eliminarCliente(tienda);
			break;
		case 4:
			verCatalogo(tienda);
			break;
		case 5:
			ingresoProductos(tienda);
			break;
		case 6:
			eliminarProducto(tienda);
			break;
		case 7:
			break;
		}
	} while (op != 7);
}

void mostrarClientes(Tienda* tienda) {
	cout << tienda->mostrarClientes();
	system("pause");
}

void ingresoSuscriptores(Tienda* tienda) {
	if (tienda->ingresarCliente(crearCliente()) == true)
		cout << "Se ingreso con exito!!" << endl;
	else
		cout << "No se pudo ingresar por favor intentelo de nuevo" << endl;
}

Cliente* crearCliente(){
	int op;
	cout << "----------------------------------" << endl
		<< "| (1) Empresa.                    |" << endl
		<< "| (2) Persona.                    |" << endl
		<< "-----------------------------------" << endl
		<< "| Que desea ingresar ->"; cin >> op;
	if (op == 1)
		return crearEmpresa();
	if (op == 2)
		return crearPersona();
	return NULL;
}
Cliente* crearPersona() {
	string nom, ced, correo, ciudadUbicacion, nacionalidad, pais;
	cout << "Ingrese el nombre -> "; cin >> nom;
	cout << "Ingrese la cedula -> "; cin >> ced;
	cout << "Ingrese el Pais -> "; cin >> pais;
	cout << "Ingrese la Ciudad de Ubicacion: "; cin >> ciudadUbicacion;
	cout << "Ingrese el Correo: "; cin >> correo;
	cout << "Ingrese la Nacionalidad: "; cin >> nacionalidad;
	return new Persona(nom, ced, pais, ciudadUbicacion, correo, nacionalidad);
}
Cliente* crearEmpresa(){
	string nom, ced, pais, ciudad;
	cout << "Ingrese el nombre de la empresa -> "; cin >> nom;
	cout << "Ingrese la cedula juridica-> "; cin >> ced;
	cout << "Ingrese el pais de la empresa-> "; cin >> pais;
	cout << "Ingrese la ciudad de ubicacion-> "; cin >> ciudad;
	return new Empresa(nom, ced, pais, ciudad);
}

void eliminarCliente(Tienda* tienda) {
	string cod;
	cout << tienda->mostrarClientes();
	cout << "-------------------------------------------------------" << endl
		<< "| Ingrese la cedula del cliente a eliminar -> "; cin >> cod;
	if (tienda->buscarSuscriptor(cod) == true) {
		tienda->eliminarCliente(cod);
		cout << "El cliente se elimino con exito!!" << endl;
	}
	else
		cout << "La cedula que se ingreso no coincide con ningun con los que se encuentran!!" << endl;
	system("pause");
}


void verCatalogo(Tienda* tienda) {
	cout << tienda->verCatalogo();
	system("pause");
}

void ingresoProductos(Tienda* tienda){

	if (tienda->ingresarProductosAlCatalogo(crearProducto(tienda)) == true)
		cout << "Se ingreso con exito!!" << endl;
	else
		cout << "No se pudo ingresar por favor intentelo de nuevo!!" << endl;
}

Componente* crearProducto(Tienda* tienda) {
	int op;
	cout << "-------------------------------------" << endl
		<< "| (1) Componente.                    |" << endl
		<< "| (2) Sistema Preconfigurado.        |" << endl
		<< "--------------------------------------" << endl
		<< "| Que desea ingresar ->"; cin >> op;
	if (op == 1)
			return crearComponente();
	if (op == 2)
			return crearSistemaPreconfigurado(tienda);
	return NULL;
}
Componente* crearComponente() {
	string tipo, model, carac, cod;
	double precio;
	int op;
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
	
	return NULL;
}
Componente* crearSistemaPreconfigurado(Tienda* tienda) { // Falta corregir
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
			<< tienda->mostrarSoloComponentes() << endl
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
		tienda->eliminarProducto(cod);
		cout << "El producto se elimino con exito!!" << endl;
	}
	else
		cout << "El codigo que se ingreso no coincide con ningun con los que se encuentran en el catalogo!!" << endl;
		system("pause");
}


// ----------REPORTES-----------



void salir(Tienda* tienda){
	cout << "Muchas Gracias por visitarnos" << endl;
	tienda->guardarArchivos();
	delete tienda;
}


