#include"Interfaz.h"


// -------------------------------------MENUS-----------------------------------------------

//Menu principal de la tienda
int menu() {  
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

//Menu de componentes que el cliente puede comprar en venta directa
int menudirecto() {  
	int op = 0;
	cout << "------------------------------------------------" << endl
		<< "| Que desea ingresar a su carrito de compras   |" << endl
		<< "| (1) Componente.                              |" << endl
		<< "| (2) Sistema Preconfigurado.                  |" << endl
		<< "| (3) Crear Configurado a la medida.           |" << endl
		<< "| (4) Generar Factura.                         |" << endl
		<< "| (5) Cancelar Compra.                         |" << endl
		<< "------------------------------------------------" << endl
		<< "| Ingrese una opcion -> "; cin >> op;
	return op;
}

//Menu de componentes que el cliente puede comprar en venta en linea 
int menuEnLinea() {  
	int op = 0;
	cout << "------------------------------------------------" << endl
		<< "| Que desea ingresar a su carrito de compras   |" << endl
		<< "| (1) Sistema Preconfigurado.                  |" << endl
		<< "| (2) Generar Factura.                         |" << endl
		<< "| (3) Cancelar Compra.                         |" << endl
		<< "------------------------------------------------" << endl
		<< "| Ingrese una opcion -> "; cin >> op;
	return op;
}

//Menu para area de mantenimiento de la tienda
int menuMantenimiento() {  
	int op = 0;
	cout << "MENU ->  (3) Mantenimiento." << endl << endl;
	cout << "-----------------------------------------" << endl
		<< "| (1) Ver Lista de Clientes.             |" << endl
		<< "| (2) Ingreso de Nuevos Clientes         |" << endl
		<< "| (3) Eliminar Cliente                   |" << endl
		<< "| (4) Modificar Cliente                  |" << endl
		<< "| (5) Ver Lista del Catalogo             |" << endl
		<< "| (6) Ingresar Productos al Catalogo     |" << endl
		<< "| (7) Eliminar Productos del Catalogo    |" << endl
		<< "| (8) Modificar cantidad de productos    |" << endl
		<< "| (9) Volver.                            |" << endl
		<< "------------------------------------------" << endl
		<< "| Ingrese una opcion -> "; cin >> op;
	return op;

}

//Menu para el area de reportes de la tienda
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

// --------------------------------------DIRECTO-----------------------------------------------

//Desarrollo del metodo para generar una venta en modalidad directa 
void generarVentaDirecta(Tienda* tienda) {  
	string codigo,cedula; 
	int op = 0;
	//char op2;
	bool acceso = false;
	Cliente* cliente = NULL;
	codigo = to_string(tienda->getVentas()->getCantidad() + 1);
	do {
		try {
			system("cls");
			cout << "MENU ->  (1) Venta Directa." << endl << endl;
			cout << "Posee el cliente una suscripcion en la tienda?" << endl;  
			cout << "| (1) Si" << endl;
			cout << "| (2) No" << endl;
			cout << "| Ingrese una opcion -> "; cin >> op;
			cout << endl;
			if (op != 1 && op != 2) {
				throw(ExcepcionRango());
				acceso = false;
			}
			else
				acceso = true;
		}
		catch (ExcepcionRango& e) {
			cout << e.toString() << endl;
		}
	} while (acceso == false);
	do {
		if (op == 1) {
			cout << "Ingrese la cedula -> "; cin >> cedula;
			cout << endl;
			if (tienda->buscarSuscriptor(cedula) == true) {
				cout << "Cliente suscrito encontrado!! " << endl << endl;
				cliente = tienda->retornaSuscriptor(cedula);
				op = 3;
			}
			else {
				cout << "Cliente no suscrito!! " << endl;
				op = 2;
			}
		}
		if (op == 2) {
			cout << "Por favor ingrese la informacion del cliente" << endl;
			cout << endl;
			cliente = crearCliente();
			cout << "Listo!!" << endl;
			op = 3;
		}
		system("pause");
	} while (op != 3);
	Factura* factura = new Directo(codigo, cliente);
	do {
		system("cls");
		cout << "MENU ->  (1) Venta Directa." << endl << endl;
		cout << "Cliente suscrito encontrado!! " << endl << endl;
		op = menudirecto();
		switch (op) {
		case 1:
			factura->ingresarCompra(agregarComponente(tienda));
			break;
		case 2:
			factura->ingresarCompra(agregarSistemaPreconfigurado(tienda));
			break;
		case 3:
			factura->ingresarCompra(agregarNuevoSistemaAMedida(tienda));
			break;
		case 4:  //Se genera la factura de la compra realizada 
			if (factura->getCarrito()->getPrimero() != NULL) {
				cout << endl;
				cout << "Generando Factura..." << endl;
				tienda->getVentas()->ingresar(*factura);
				cout << factura->toString() << endl;	   //Calcular el precio total de la compra 
				cout << "Muchas Gracias Por Su Compra!!" << endl;
				op = 5;
			}
			else {
				cout << endl;
				cout << "No se ha generado la Factura..." << endl;
				cout << "Aun no se ha ingresado algo al carrito de compras!!" << endl << endl;
			}
			break;
		case 5:
			cout << endl;
			cout << "Cancelando la Compra..." << endl << endl;
			tienda->cancelacionDeCompra(factura);
			break;
		}
		system("pause");
	} while (op != 5);
}

//Desarrollo de metodo para agregar un unico componente, al carrito de compras del cliente 
Componente* agregarComponente(Tienda* tienda){
	int cant;
	string cod;
	Componente* aux = NULL;
	cout << tienda->mostrarSoloComponentes();
	cout << "--------------------------------------------------------------------------" << endl
		<< "| Seleccione el componente deseado por su codigo -> "; cin >> cod;
	if (tienda->buscarComponente(cod) == true) {
		cout << "| Ingrese la cantidad de componentes que desea -> "; cin >> cant;
		aux = tienda->retornarSoloComponentes(cod);
		if ((aux->getUnidades() - cant) > 0) {
			aux->setUnidades(cant);
			tienda->restarAUnidades(cod, cant);
			cout << "Componente encontrado y agregado!!" << endl << endl;
			return aux;
		}
		else
			cout << "No hay suficientes productos para vender" << endl;
	}
	else {
		cout << "Componente no encontrado!!" << endl << endl;
	}
	return NULL;
}

//Desarrollo de metodo para agregar sistema preconfigurado, al carrito de compras del cliente
Componente* agregarSistemaPreconfigurado(Tienda* tienda){
	int cant;
	string cod;
	Componente* aux = NULL;
	cout << tienda->mostrarSoloKits();
	cout << "-----------------------------------------------------------" << endl
		<< "| Seleccione el kit deseado por su codigo -> "; cin >> cod; 
	if (tienda->buscarKit(cod) == true) {
		cout << "| Ingrese la cantidad de componentes que desea -> "; cin >> cant;
		aux = tienda->retornarSoloKits(cod);
		if ((aux->getUnidades() - cant) > 0) {
			aux->setUnidades(cant);
			tienda->restarAUnidades(cod, cant);
			cout << "Sistema Preconfigurado encontrado y agregado!!" << endl << endl;
			return aux;
		}
		else
			cout << "No hay suficientes productos para vender" << endl;
	}
	else {
		cout << "Sistema Preconfigurado no encontrado!!" << endl << endl;
	}
	return NULL;
}

//Desarrollo de metodo para agregar sistema hecho a la medida, al carrito de compras del cliente
Componente* agregarNuevoSistemaAMedida(Tienda* tienda){
	Componente* aux = NULL;
	int cant;
	aux = crearSistemaPreconfigurado(tienda);
	cout << "| Ingrese la cantidad de componentes que desea -> "; cin >> cant;
	aux->setUnidades(cant);
	return aux;
}

// -------------------------------------EN LINEA---------------------------------------------------

//Desarrollo del metodo para generar una venta en modalidad en linea 
void generarVentaEnLinea(Tienda* tienda){
	string codigo, cedula, destino;
	char option;
	int op = 0;
	bool acceso = false;
	Cliente* cliente = NULL;
	Factura* factura = new EnLinea();
	codigo = to_string(tienda->getVentas()->getCantidad() + 1);
	factura->setCodigo(codigo);
	cout << "MENU ->  (2) Venta en Linea." << endl << endl;
	cout << "Ingrese la cedula -> "; cin >> cedula;
	cout << endl;
	if (tienda->buscarSuscriptor(cedula) == true) {
		cliente = tienda->retornaSuscriptor(cedula);
	}
	else {
		cout << "Cliente no suscrito!! " << endl;
		cout << "Desea ingresar un nuevo cliente?  s/n -> "; cin >> option;
		if (option == 's') {
			cout << "Por favor ingrese la informacion del cliente" << endl;
			cout << endl;
			cliente = crearCliente();
			tienda->ingresarCliente(cliente);
			cout << "Listo!!" << endl << endl;
		}
		else return;
	
	}
	factura->setCliente(cliente);
	do {
		system("cls");
		cout << "MENU ->  (2) Venta en Linea." << endl << endl;
		cout << "Cliente suscrito encontrado!! " << endl << endl;
		cout << tienda->mostrasDestinos();
		cout << "Digite el codigo del Destino ->"; cin >> destino;
		if (tienda->buscarDestino(destino) == true) {
			factura->setDestino(tienda->retornaDestino(destino));
			cout << endl;
			cout << "Destino encontrado!!" << endl << endl;
			system("pause");
			acceso = true;
		}
		else {
			cout << "Destino no encontrado!!" << endl << endl;
			cout << "Por favor digite nuevamente el codigo..." << endl;
			system("pause");
		}
	} while (acceso != true);
	do {
		system("cls");
		cout << "MENU ->  (2) Venta en Linea." << endl << endl;
		cout << "Cliente suscrito encontrado!! " << endl << endl;
		cout << "Destino encontrado!!" << endl << endl;
		op = menuEnLinea();
		switch (op)
		{
		case 1:
			factura->ingresarCompra(agregarSistemaPreconfigurado(tienda));
			break;
		case 2:
			if (factura->getCarrito()->getPrimero() != NULL) {
				cout << endl;
				cout << "Generando Factura..." << endl;
				tienda->getVentas()->ingresar(*factura);
				cout << factura->toString() << endl;	   //Calcular el precio total de la compra 
				cout << "Muchas Gracias Por Su Compra!!" << endl;
				op = 3;
			}
			else {
				cout << endl;
				cout << "No se ha generado la Factura..." << endl;
				cout << "Aun no se ha ingresado algo al carrito de compras!!" << endl << endl;
			}
			break;
		case 3:
			cout << endl;
			cout << "Cancelando la Compra..." << endl << endl;
			break;
		}
		system("pause");
	} while (op != 3);

}

// ----------------------------------MANTENIMIENTO-------------------------------------------------

//Desarrollo de metodo que maneja el menu del area de mantenimiento 
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
			cout << "MENU ->  (3) Mantenimiento -> (4) Modificar Cliente" << endl << endl;
			modificarCliente(tienda);
			break;
		case 5:
			system("cls");
			cout << "MENU ->  (3) Mantenimiento -> (5) Ver Lista del Catalogo" << endl << endl;
			verCatalogo(tienda);
			break;
		case 6:
			system("cls");
			cout << "MENU ->  (3) Mantenimiento -> (6) Ingresar Productos al Catalogo" << endl << endl;
			ingresoProductos(tienda);
			break;
		case 7:
			system("cls");
			cout << "MENU ->  (3) Mantenimiento -> (7) Eliminar Productos del Catalogo" << endl << endl;
			eliminarProducto(tienda);
			break;
		case 8:
			system("cls");
			cout << "MENU ->  (3) Mantenimiento -> (8) Modificar cantidad de productos" << endl << endl;
			modificarProductos(tienda);
			break;
		case 9:
			break;
		}
	} while (op != 9);
}

//Desarrollo de metodo que despliega la lista de clientes 
void mostrarClientes(Tienda* tienda) {
	cout << "Listado de clientes suscritos" << endl;
	cout << tienda->mostrarClientes();
	system("pause");
}

//Desarrollo de metodo para suscribir un nuevo cliente 
void ingresoSuscriptores(Tienda* tienda) {
	if (tienda->ingresarCliente(crearCliente()) == true)
		cout << "Se ingreso con exito!!" << endl;
	else
		cout << "No se pudo ingresar por favor intentelo de nuevo" << endl;
	system("pause");
}

//Desarrollo de metodos para ingresar los datos del nuevo cliente a suscribir 
Cliente* crearCliente(){
	int op;
	bool acceso = false;
	do {
		system("cls");
		try {
			cout << "Tipo de Cliente?" << endl;
			cout << "----------------------------------" << endl
			<< "| (1) Empresa.                    |" << endl
			<< "| (2) Persona.                    |" << endl
			<< "-----------------------------------" << endl
			<< "| Que desea ingresar -> "; cin >> op;
			cout << endl;
			if (op != 1 && op != 2) {
				throw(ExcepcionRango());
				acceso = false;
			}
			else
				acceso = true;
		}
		catch (ExcepcionRango& e) {
			cout << e.toString() << endl;
		}
	} while (acceso == false);
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

//Desarrollo de metodo para desescribir un cliente de la tienda 
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

void modificarCliente(Tienda* tienda) {
	string cedula,tipo;
	Cliente* cliente = NULL;
	cout << "Ingrese la cedula -> "; cin >> cedula;
	if (tienda->buscarSuscriptor(cedula) == true) {
		cliente = tienda->retornaCliente(cedula);
		tipo = typeid(*tienda->retornaCliente(cedula)).name();
		if (tipo == "class Persona")
			modificarClientePersona(tienda, cliente);
		if (tipo == "class Empresa")
			modificarClienteEmpresa(tienda, cliente);
		cliente = NULL;
	}
	else {
		cout << "Cliente no encontrado!!" << endl;
		system("pause");
	}
}

void modificarClientePersona(Tienda* tienda, Cliente* cliente) {
	int op;
	string dato;
	do {
		system("cls");
		cout << "MENU ->  (3) Mantenimiento -> (4) Modificar Cliente" << endl << endl;
		cout << cliente->toString() << endl << endl;
		cout << "(1) Modificar Nombre" << endl;
		cout << "(2) Modificar Pais" << endl;
		cout << "(3) Modificar Ciudad" << endl;
		cout << "(4) Modificar Correo" << endl;
		cout << "(5) Modificar Nacionalidad" << endl;
		cout << "(6) Volver" << endl;
		cout << "| Ingrese una opcion -> "; cin >> op;
		cout << endl;
		switch (op) {
		case 1:
			cout << "Digite el nuevo nombre ->"; cin >> dato;
			cliente->setNombre(dato);
			break;
		case 2:
			cout << "Digite el nuevo pais ->"; cin >> dato;
			cliente->setNombrePais(dato);
			break;
		case 3:
			cout << "Digite la nueva ciudad ->"; cin >> dato;
			cliente->setCiudadUbicacion(dato);
			break;
		case 4:
			cout << "Digite el nuevo correo ->"; cin >> dato;
			cliente->setCorreo(dato);
			break;
		case 5:
			cout << "Digite el nueva nacionalidad ->"; cin >> dato;
			cliente->setNacionalidad(dato);
			break;
		case 6:
			break;
		}
	} while (op != 6);
	
}

void modificarClienteEmpresa(Tienda* tienda,Cliente* cliente) {
	int op;
	string dato;
	do {
		system("cls");
		cout << "MENU ->  (3) Mantenimiento -> (4) Modificar Cliente" << endl << endl;
		cout << cliente->toString() << endl << endl;
		cout << "(1) Modificar Nombre" << endl;
		cout << "(2) Modificar Pais" << endl;
		cout << "(3) Modificar Ciudad" << endl;
		cout << "(4) Volver" << endl;
		cout << "| Ingrese una opcion -> "; cin >> op;
		cout << endl;
		switch (op) {
		case 1:
			cout << "Digite el nuevo nombre ->"; cin >> dato;
			cliente->setNombre(dato);
			break;
		case 2:
			cout << "Digite el nuevo pais ->"; cin >> dato;
			cliente->setNombrePais(dato);
			break;
		case 3:
			cout << "Digite la nueva ciudad ->"; cin >> dato;
			cliente->setCiudadUbicacion(dato);
			break;
		case 4:
			break;
		default:
			cout << "Opcion digitada fuera de rango" << endl;
			system("pause");
		}
	} while (op != 4);
}

//Desarrollo de metodo que despliega la lista de componentes que existen en la tienda 
void verCatalogo(Tienda* tienda) {
	cout << tienda->verCatalogo();
	system("pause");
}

//Desarrollo de metodo para ingresar un nuevo componente a la tienda 
void ingresoProductos(Tienda* tienda){

	if (tienda->ingresarProductosAlCatalogo(crearProducto(tienda)) == true)
		cout << "Se ingreso con exito!!" << endl;
	else
		cout << "No se pudo ingresar por favor intentelo de nuevo!!" << endl;
}

//Desarrollo de metodos para ingresar los datos del nuevo componente en la tienda 
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
	string model, carac, cod;
	double precio;
	int op = 0, cant = 0;
	do {
		system("cls");
		cout << "-------------------------------------------" << endl
			<< "| (1) Unidad CD (Fuente de audio)         |" << endl
			<< "| (2) Tornamesa (Fuente de audio)         |" << endl
			<< "| (3) Radio (Fuente de audio)             |" << endl
			<< "| (4) Unidad Bluetooth (Fuente de audio)  |" << endl
			<< "| (5) Microfono (Procesador de senal)     |" << endl
			<< "| (6) Amplificador (Procesador de senal)  |" << endl
			<< "| (7) Mezclador (Procesador de senal)     |" << endl
			<< "| (8) Altavoz (Parlante)                  |" << endl
			<< "| (9) Audifonos (Parlante)                |" << endl
			<< "| (10) Volver                             |" << endl
			<< "-------------------------------------------" << endl
			<< "| Que desea agregar al sistema -> "; cin >> op;
		cout << "-------------------------------------------" << endl;
		cout << "| Ingrese el codigo del componente -> "; cin >> cod;
		cout << "| Ingrese el modelo del componente -> "; cin >> model;
		cout << "| Ingrese la caracteristica del componente -> "; cin >> carac;
		cout << "| Ingrese el precio del componente -> "; cin >> precio;
		cout << "| Ingrese la cantidad -> "; cin >> cant;
		switch (op) {
		case 1:
			return new UnidadCD(cod, model, carac, precio, cant);
			break;
		case 2:
			return new Tornamesa(cod, model, carac, precio, cant);
			break;
		case 3:
			return new Radio(cod, model, carac, precio, cant);
			break;
		case 4:
			return new UnidadBluetooth(cod, model, carac, precio, cant);
			break;
		case 5:
			return new Microfono(cod, model, carac, precio, cant);
			break;
		case 6:
			return new Amplificador(cod, model, carac, precio, cant);
			break;
		case 7:
			return new Mezclador(cod, model, carac, precio, cant);
			break;
		case 8:
			return new Altavoz(cod, model, carac, precio, cant);
			break;
		case 9:
			return new Audifono(cod, model, carac, precio, cant);
			break;
		}
	} while (op != 10);
	return NULL;
}
Componente* crearSistemaPreconfigurado(Tienda* tienda) { // Falta corregir
	// Comodines
	Componente* kit = new Kit();
	string codK, cod, nom;
	int contadorA = 0, contadorM = 0, contadorP = 0, cant;
	string type;
	char op;
	// Ingreso del nombre y codigo del kit
	cout << "--------------------------------------------" << endl;
	cout << "| Ingrese el nombre del Kit -> "; cin >> nom;
	cout << "--------------------------------------------" << endl;
	cout << "| Ingrese el codigo del Kit -> "; cin >> codK;
	cout << "--------------------------------------------" << endl;
	cout << "| Ingrese la cantidad de kits -> "; cin >> cant;
	// Ciclo para agregar componentes al kit
	do {
		system("cls");
		// Muestra los componente con los que cuenta el catalogo
		tienda->mostrarSoloComponentes();
		// Muesta opciones por si no quiere hacer nada
		cout << tienda->mostrarSoloComponentes() << endl
			<< "-------------------------------------------------------" << endl
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
				type = typeid(*tienda->retornarSoloComponentes(cod)).name();
				if (op == 's') {
					if (ingresarAlKit(contadorP, contadorM, contadorA, type, cod, *kit, tienda) == true) {
						cout << "Se ingreso correctamente " << endl;
						system("pause");
					}
					else { 
						cout << "No se puede ingresar mas " << type << endl; 
						system("pause");
					}
					//kit->agregar(tienda->retornarSoloComponentes(cod));
				}
			}
			else
				cout << "!! El Componente no existe en el catalogo." << endl;
		}
	} while (cod != "s");
	// Pregunta si lo quiere agregar y lo agrega
	cout << "Agregar el kit? s/n "; cin >> op;
	if (op == 's') {
		kit->setCodigo(codK);
		kit->setNombre(nom);
		kit->setUnidades(cant);
		return (Componente*)new Kit(*(Kit*)kit);
	}
	delete kit;

	return NULL;
}
bool ingresarAlKit(int& contadorP, int& contadorM, int& contadorA, string& type, string cod, Componente& kit, Tienda* tienda) {
	if (type == "class Mezclador" && contadorM == 0) {
		type = "mezcladores";
		kit.agregar(tienda->retornarSoloComponentes(cod));
		contadorM = 1;
		return true;
	}
	if (type == "class Amplificador" && contadorA == 0) {
		type = "amplificadores";
		kit.agregar(tienda->retornarSoloComponentes(cod));
		contadorA = 1;
		return true;
	}
	if (type == "class Altavoz" || type == "class Audifono" && contadorP == 0) {
		kit.agregar(tienda->retornarSoloComponentes(cod));
		contadorP = 1;
		return true;
	}
	if (type != "class Mezclador" && type != "class Amplificador" && type != "class Altavoz" && type != "class Audifono") {
		kit.agregar(tienda->retornarSoloComponentes(cod));
		return true;
	}
	if(type == "class Audifono" || type == "class Altavoz")
		type = "altavoces o audifonos.";
	if (type == "class Mezclador")
		type = "mezcladores.";
	if (type == "class Amplificador")
		type = "amplificadores";

	return false;
}

void modificarProductos(Tienda* tienda) {
	string cod;
	int cant;
	Componente* aux = NULL;
	cout << tienda->mostrarElCatalogo();
	cout << "------------------------------------------------------------" << endl;
	cout << "| Ingrese el codigo del producto a modificar -> "; cin >> cod;
	cout << "------------------------------------------------------------" << endl;
	if (tienda->buscarProductoDelCatalogo(cod) == true) {
		aux = tienda->retornarProductos(cod);
		cout << "Ingrese la cantidad de existencia del producto -> "; cin >> cant;
		aux->setUnidades(cant);
	}
	else { 
		cout << "El codigo ingresado no coincide con los de la tienda!!" << endl; 
		system("pause");
	}
}

//Desarrollo de metodo para eliminar un componente de la tienda 
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


// ---------------------------------------REPORTES---------------------------------------------------

//Desarrollo de metodo que maneja el menu del area de reportes 
void reportes(Tienda* tienda) {
	int op = 0;
	do {
		system("cls");
		op = menuReportes();
		switch (op) {
		case 1:
			system("cls");
			cout << "MENU ->  (4) Reportes -> (1) Reporte Equipos mas Vendidos" << endl << endl;
			reporteEquiposMasVendidos(tienda);
			system("pause");
			break;
		case 2:
			system("cls");
			cout << "MENU ->  (4) Reportes -> (2) Reportes Ventas " << endl << endl;
			reporteVentas(tienda);
			system("pause");
			break;
		case 3:
			break;
		}
	} while (op != 3);
}

//Desarrollo de metodo que despliega la lista de los equipos mas vendidos de la tienda 
void reporteEquiposMasVendidos(Tienda* tienda){
	cout << tienda->primeroYsegundoMasVendios();
}

//Desarrollo de metodo de reportes de totales brutos, netos y ganancias de la tienda 
void reporteVentas(Tienda* tienda){
	cout << "------------------Reporte de Ventas--------------------" << endl;
	cout << tienda->reporteTotalesBrutos() << endl;
	cout << tienda->reporteTotalesNetos() << endl;
	cout << tienda->reporteDeGanancias() << endl;
	system("pause");
}



// -------------------------------------Salir--------------------------------------------------
//Desarrollo de metodo para dar la despedida del programa 
void salir(Tienda* tienda){
	cout << "Muchas Gracias por visitarnos" << endl;
	tienda->guardarArchivos();
	delete tienda;
}


// -------------------------------------Extras--------------------------------------------------

//Desarrollo de metodo que maneja el menu principal de la tienda 
void MAIN(Tienda* tienda) {
	int op;
	tienda->recuperarDeArchivos();
	do {
		system("cls");
		op = menu();
		switch (op) {
		case 1:
			system("cls");
			generarVentaDirecta(tienda);
			break;
		case 2:
			system("cls");
			generarVentaEnLinea(tienda);
			break;
		case 3:
			mantenimiento(tienda);
			break;
		case 4:
			reportes(tienda);
			break;
		case 5:
			salir(tienda);
			break;
		}
	} while (op != 5);
	system("pause");
}

