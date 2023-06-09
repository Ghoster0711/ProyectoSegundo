#include"Interfaz.h"


// -----------MENUS-------------
int menu(){
	int op = 0;
	cout << "------------MENU----------" << endl
		<< "| (1) Venta Directa.     |" << endl
		<< "| (2) Venta en Linea.    |" << endl
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
		<< "| (2) Finalizar.                               |" << endl
		<< "------------------------------------------------" << endl
		<< "| Ingrese una opcion -> "; cin >> op;
	return op;
}

int menuMantenimiento(){
	int op = 0;
	cout << "MENU ->  (3) Mantenimiento." << endl << endl;
	cout << "-----------------------------------------" << endl
		<< "| (1) Ver Lista de Clientes.             |" << endl
		<< "| (2) Ingreso de Nuevos Clientes         |" << endl
		<< "| (3) Eliminar Cliente                   |" << endl
		<< "| (4) Ver Lista del Catalogo             |" << endl
		<< "| (5) Ingresar Productos al Catalogo     |" << endl
		<< "| (6) Eliminar Productos del Catalogo    |" << endl
		<< "| (7) Volver.                            |" << endl
		<< "------------------------------------------" << endl
		<< "| Ingrese una opcion -> "; cin >> op;
	return op;

}

int menuReportes() {
	int op = 0;
	cout << "MENU ->  (4) Reportes." << endl << endl;
	cout << "---------------------------------------" << endl
		<< "| (1) Reporte Equipos mas Vendidos     |" << endl
		<< "| (2) Reportes Ventas                  |" << endl
		<< "| (3) Volver.                          |" << endl
		<< "----------------------------------------" << endl
		<< "| Ingrese una opcion -> "; cin >> op;
	return op;
}

// -----------DIRECTO-----------

void generarVentaDirecta(Tienda* tienda) {
	string codigo,cedula;
	int op = 0;
	Cliente* cliente = NULL;
	codigo = to_string(tienda->getVentas()->getCantidad() + 1);
	cout << "MENU ->  (1) Venta Directa." << endl << endl;
	cout << "Ingrese la informacion del cliente" << endl;
	cout << "Posee el cliente una suscripcion en la tienda?" << endl;
	cout << "| (1) Si" << endl;
	cout << "| (2) No" << endl;
	cout << "| Ingrese una opcion -> "; cin >> op;
	cout << endl;
	do {
		if (op == 1) {
			cout << "Ingrese la cedula -> "; cin >> cedula;
			cout << endl;
			if (tienda->buscarSuscriptor(cedula) == true) {
				cout << "Cliente suscrito encontrado!!" << endl << endl;
				cliente = tienda->retornaSuscriptor(cedula);
				op = 3;
			}
			else {
				cout << "Cliente no suscrito!!" << endl;
				op = 2;
			}
		}
		if (op == 2) {
			cout << "Por favor ingrese la informacion del cliente" << endl;
			cout << endl;
			cliente = crearCliente();
			cout << "Liso!!" << endl;
			op = 3;
		}
		system("pause");
	} while (op != 3);
	Factura* factura = new Directo(codigo, cliente);
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
			cout << "Generando Factura..." << endl;
			tienda->getVentas()->ingresar(*factura);
			cout << factura->toString() << endl;				//Calcular el precio total de la compra 
			cout << "Muchas Gracias Por Su Compra!!" << endl;
			break;
		}
		system("pause");
	} while (op != 4);
	//delete cliente;
	//delete factura;
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
	string codigo, cedula, destino;
	int op = 0;
	Cliente* cliente = NULL;
	codigo = tienda->getVentas()->getCantidad() + 1;
	cout << "MENU ->  (2) Venta en Linea." << endl << endl;
	cout << "Ingrese la cedula -> "; cin >> cedula;
	cout << endl;
	if (tienda->buscarSuscriptor(cedula) == true) {
		cout << "Cliente suscrito encontrado!" << endl << endl;
		cliente = tienda->retornaSuscriptor(cedula);
	}
	else {
		cout << "Cliente no suscrito!" << endl;
		cout << "Por favor ingrese la informacion del cliente" << endl;
		cout << endl;
		cliente = crearCliente();
		tienda->ingresarCliente(cliente);
		cout << "Liso!!" << endl << endl;
	
	}
	system("pause");
	Factura* factura = new Directo(codigo, cliente);
	cout << tienda->mostrasDestinos();
	cout << "Digite el codigo del Destino ->"; cin >> destino;
	if (tienda->buscarDestino(destino) == true) {
		factura->setDestino(tienda->retornaDestino(destino));
		cout << "Liso!!" << endl;
	}
	else {
		cout << "Ese codigo no existe en el menu de destinos" << endl;
	}
	do {
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
			system("cls");
			cout << "MENU ->  (3) Mantenimiento -> (1) Ver Lista de Clientes" << endl << endl;
			mostrarClientes(tienda);
			break;
		case 2:
			system("cls");
			cout << "MENU ->  (3) Mantenimiento -> (2) Ingreso de Nuevos Clientes" << endl << endl;
			ingresoSuscriptores(tienda);
			break;
		case 3:
			system("cls");
			cout << "MENU ->  (3) Mantenimiento -> (3) Eliminar Cliente" << endl << endl;
			eliminarCliente(tienda);
			break;
		case 4:
			system("cls");
			cout << "MENU ->  (3) Mantenimiento -> (4) Ver Lista del Catalogo" << endl << endl;
			verCatalogo(tienda);
			break;
		case 5:
			system("cls");
			cout << "MENU ->  (3) Mantenimiento -> (5) Ingresar Productos al Catalogo" << endl << endl;
			ingresoProductos(tienda);
			break;
		case 6:
			system("cls");
			cout << "MENU ->  (3) Mantenimiento -> (6) Eliminar Productos del Catalogo" << endl << endl;
			eliminarProducto(tienda);
			break;
		case 7:
			break;
		}
	} while (op != 7);
}

void mostrarClientes(Tienda* tienda) {
	cout << "Listado de clientes suscritos" << endl;
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
	cout << "Que tipo de Cliente desea ingresar?" << endl;
	cout << "----------------------------------" << endl
		<< "| (1) Empresa.                    |" << endl
		<< "| (2) Persona.                    |" << endl
		<< "-----------------------------------" << endl
		<< "| Que desea ingresar -> "; cin >> op;
	cout << endl;
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
	cout << "Ingrese la Ciudad de Ubicacion ->"; cin >> ciudadUbicacion;
	cout << "Ingrese el Correo ->"; cin >> correo;
	cout << "Ingrese la Nacionalidad ->"; cin >> nacionalidad;
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
	//Componente* kit = new Kit();
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
					//kit->agregar(tienda->retornarSoloComponentes(cod));
				}
			}
			else
				cout << "!! El Componente no existe en el catalogo." << endl;
		}
	} while (cod != "s");
	// Pregunta si lo quiere agregar y lo agrega
	cout << "Agregar el kit al catalogo? s/n "; cin >> op;
	if (op == 's') {
		//kit->setCodigo(codK);
		//kit->setNombre(nom);
		//return (Componente*)new Kit(*(Kit*)kit);
	}
	//delete kit;

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


