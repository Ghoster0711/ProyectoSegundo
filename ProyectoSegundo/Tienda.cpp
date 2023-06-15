#include "Tienda.h"


Tienda::Tienda() {
	Catalogo = new Lista<Componente>();
	Suscriptores = new Lista<Cliente>();
	Ventas = new Lista<Factura>();
	Destinos = new Lista<Destino>();
}

Tienda::~Tienda(){
	if (Catalogo != NULL) delete Catalogo;
	if (Suscriptores != NULL) delete Suscriptores;
	if (Ventas != NULL) delete Ventas;
	if (Destinos != NULL) delete Destinos;
}

void Tienda::notificar(Componente* c, bool elimina){
	stringstream show;
	Nodo<Cliente>* pExt = Suscriptores->getPrimero();
	ofstream file;
	file.open("../notificaciones.txt", ios::app);
	if (elimina) {
		show << "Se a eliminado el siguiente producto: \n" << c->toString();
	}
	else
		show << "Se a agregado el siguiente producto: \n" << c->toString();
	
	file << "NUEVA NOTIFICACION\n";
	while (pExt != NULL) {
		pExt->getDato()->update(show.str(), file);

		pExt = pExt->getSiguiente();
	}
	file.close();

}

Lista<Componente>* Tienda::getCatalago() { return Catalogo; }

Lista<Cliente>* Tienda::getSuscriptores() { return Suscriptores; }

Lista<Factura>* Tienda::getVentas() { return Ventas; }

Lista<Destino>* Tienda::getDestinos() { return Destinos; }

string Tienda::mostrarElCatalogo(){
	return Catalogo->toString();
}
string Tienda::mostrasDestinos() {
	return Destinos->toString();
}
bool Tienda::buscarSuscriptor(string cod)
{
	Nodo<Cliente>* e = Suscriptores->getPrimero();
	while (e != NULL) {
		if (e->getDato() != NULL) {
			if (e->getDato()->getID() == cod)
				return true;
		}
		e = e->getSiguiente();
	}
	return false;
}
bool Tienda::buscarProductoDelCatalogo(string cod){
	Nodo<Componente>* e = Catalogo->getPrimero();
	while (e != NULL) {
		if (e->getDato() != NULL) {
			if (e->getDato()->getID() == cod)
				return true;
		}
		e = e->getSiguiente();
	}
	return false;
}
bool Tienda::buscarComponente(string cod) {
	string tipo;
	Nodo<Componente>* e = Catalogo->getPrimero();
	while (e != NULL) {
		if (e->getDato() != NULL) {
			tipo = typeid(*e->getDato()).name();
			if (tipo != "class Kit") {
				if (e->getDato()->getID() == cod) {
					return true;
				}
			}
		}
		e = e->getSiguiente();
	}
	return false;
}
bool Tienda::buscarKit(string cod) {
	string tipo;
	Nodo<Componente>* e = Catalogo->getPrimero();
	while (e != NULL) {
		if (e->getDato() != NULL) {
			tipo = typeid(*e->getDato()).name();
			if (tipo == "class Kit") {
				if (e->getDato()->getID() == cod) {
					return true;
				}
			}
		}
		e = e->getSiguiente();
	}
	return false;
}
bool Tienda::buscarDestino(string cod) {
	Nodo<Destino>* e = Destinos->getPrimero();
	while (e != NULL) {
		if (e->getDato() != NULL) {
			if (e->getDato()->getCodigo() == cod) {
				return true;
			}
		}
		e = e->getSiguiente();
	}
	return false;
}
Componente* Tienda::retornarProductos(string cod){
	Nodo<Componente>* pExt = Catalogo->getPrimero();
	while (pExt != NULL) {
		if (pExt->getDato()->getID() == cod)
			return pExt->getDato();
		pExt = pExt->getSiguiente();
	}

	return NULL;
}
Componente* Tienda::retornarSoloComponentes(string cod) {
	string tipo;
	Nodo<Componente>* e = Catalogo->getPrimero();
	while (e != NULL) {
		if (e->getDato() != NULL) {
			tipo = typeid(*e->getDato()).name();
			if (tipo != "class Kit") {
				if (e->getDato()->getCodigo() == cod) {
					if (tipo == "class UnidadCD") {
						return (Componente*)new UnidadCD(*(UnidadCD*)e->getDato());
					}
					if (tipo == "class Tornamesa") {
						return (Componente*)new Tornamesa(*(Tornamesa*)e->getDato());
					}
					if (tipo == "class Radio") {
						return (Componente*)new Radio(*(Radio*)e->getDato());
					}
					if (tipo == "class UnidadBluetooth") {
						return (Componente*)new UnidadBluetooth(*(UnidadBluetooth*)e->getDato());
					}
					if (tipo == "class Microfono") {
						return (Componente*)new Microfono(*(Microfono*)e->getDato());
					}
					if (tipo == "class Amplificador") {
						return (Componente*)new Amplificador(*(Amplificador*)e->getDato());
					}
					if (tipo == "class Mezclador") {
						return (Componente*)new Mezclador(*(Mezclador*)e->getDato());
					}
					if (tipo == "class Altavoz") {
						return (Componente*)new Altavoz(*(Altavoz*)e->getDato());
					}
					if (tipo == "class Audifono") {
						return (Componente*)new Audifono(*(Audifono*)e->getDato());
					}
				}
			}
		}
		e = e->getSiguiente();
	}
	return NULL;
}
string Tienda::mostrarSoloComponentes() {
	stringstream show;
	string tipo;
	Nodo<Componente>* e = Catalogo->getPrimero();
	show << "--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	show << "|     Categoria     |    Codigo    |   Tipo de Componente   |      Modelo      |       Caracteristica       |      Precio       |     Unidades   |" << endl;
	while (e != NULL) {
		if (e->getDato() != NULL) {
			tipo = typeid(*e->getDato()).name();
			if (tipo != "class Kit" && tipo != "class Dispositivo")
				show << e->getDato()->toString() << endl;
		}
		e = e->getSiguiente();
	}
	return show.str();
}
Componente* Tienda::retornarSoloKits(string cod){
	string tipo;
	Nodo<Componente>* e = Catalogo->getPrimero();
	while (e != NULL) {
		if (e->getDato() != NULL) {
			tipo = typeid(*e->getDato()).name();
			if (tipo == "class Kit") {
				if (e->getDato()->getCodigo() == cod) {
					return (Componente*)new Kit(*(Kit*)e->getDato());
				}
			}
		}
		e = e->getSiguiente();
	}
	return NULL;
}
string Tienda::mostrarSoloKits(){
	stringstream show;
	string tipo;
	Nodo<Componente>* e = Catalogo->getPrimero();
	show << "--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	show << "|     Categoria     |    Codigo    |   Tipo de Componente   |      Modelo      |       Caracteristica       |      Precio       |     Unidades   |" << endl;
	while (e != NULL) {
		if (e->getDato() != NULL) {
			tipo = typeid(*e->getDato()).name();
			if (tipo == "class Kit")
				show << e->getDato()->toString() << endl;
		}
		e = e->getSiguiente();
	}
	return show.str();
}
Destino* Tienda::retornaDestino(string cod) {
	Nodo<Destino>* e = Destinos->getPrimero();
	while (e != NULL) {
		if (e->getDato() != NULL) {
			if (e->getDato()->getCodigo() == cod) {
				return new Destino(*(e->getDato()));
			}
		}
		e = e->getSiguiente();
	}
	return NULL;
}
Cliente* Tienda::retornaSuscriptor(string cedula) {
	string tipo;
	Nodo<Cliente>* e = Suscriptores->getPrimero();
	while (e != NULL) {
		if (e->getDato() != NULL) {
			if (e->getDato()->getID() == cedula) {
				tipo = typeid(*e->getDato()).name();
				if (tipo == "class Persona")
					return (Cliente*) new Persona(*(Persona*)(e->getDato()));
				if (tipo == "class Empresa")
					return (Cliente*) new Empresa(*(Empresa*)(e->getDato()));
			}
		}
		e = e->getSiguiente();
	}
	return NULL;
}
void Tienda::restarAUnidades(string cod, int cant) {
	int cantaux;
	Nodo<Componente>* e = Catalogo->getPrimero();
	while (e != NULL) {
		if (e->getDato() != NULL) {
			if (e->getDato()->getID() == cod) {
				cantaux = e->getDato()->getUnidades() - cant;
				e->getDato()->setUnidades(cantaux);
			}
		}
		e = e->getSiguiente();
	}e;
}
void Tienda::sumarAUnidades(string cod, int cant) {
	int cantaux;
	Nodo<Componente>* e = Catalogo->getPrimero();
	while (e != NULL) {
		if (e->getDato() != NULL) {
			if (e->getDato()->getID() == cod) {
				cantaux = e->getDato()->getUnidades() + cant;
				e->getDato()->setUnidades(cantaux);
			}
		}
		e = e->getSiguiente();
	}e;
}


void Tienda::cancelacionDeCompra(Factura* factura) {
	Nodo<Componente>* pCarrito = NULL;
	string id;
	int unidades;
	if (factura->getCarrito()->getPrimero() != NULL) {
		pCarrito = factura->getCarrito()->getPrimero();
		while (pCarrito != NULL) {
			if (pCarrito->getDato() != NULL) {
				id = pCarrito->getDato()->getID();
				unidades = pCarrito->getDato()->getUnidades();
				sumarAUnidades(id, unidades);
				pCarrito = pCarrito->getSiguiente();
			}
		}
	}
}


Cliente* Tienda::retornaCliente(string cedula) {
	Nodo<Cliente>* e = Suscriptores->getPrimero();
	while (e != NULL) {
		if (e->getDato() != NULL) {
			if (e->getDato()->getID() == cedula) {
				return e->getDato();
			}
		}
		e = e->getSiguiente();
	}
	return NULL;
}
// -------------Directo---------------

// -------------En Linea--------------

// -----------Mantenimiento-----------

string Tienda::mostrarClientes(){
	stringstream show;
	show << Suscriptores->toString();
	return show.str();;
}

bool Tienda::ingresarCliente(Cliente* cli){
	if (cli != NULL) {
		Suscriptores->ingresar(*cli);
		cli->setModel(Catalogo);
		return true;
	}
	return false;
}

void Tienda::eliminarCliente(string cod){
	Suscriptores->eliminar(cod);
}

string Tienda::verCatalogo(){
	stringstream show;
	show << "--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	show << "|     Categoria     |    Codigo    |   Tipo de Componente   |      Modelo      |       Caracteristica       |      Precio       |     Unidades   |" << endl;
	show << Catalogo->toString();
	return show.str();
}

bool Tienda::ingresarProductosAlCatalogo(Componente* compo){
	if (compo != NULL) {
		Catalogo->ingresar(*compo);
		notificar(compo);
		return true;
	}
	return false;
}

void Tienda::eliminarProducto(string cod) {
	notificar(retornarProductos(cod), true);
	Catalogo->eliminar(cod);

}

// ------------Reportes---------------

string Tienda::reporteTotalesBrutos() {
	stringstream s;
	s << "Total Bruto: " << Ventas->totalBruto() << endl;
	return s.str();
}
string Tienda::reporteTotalesNetos() {
	stringstream s;
	s << "Totales Netos: " << Ventas->totalNeto() << endl;
	return s.str();
}

string Tienda::reporteDeGanancias() {
	stringstream s;
	s << "Total de Ganancias: " << Ventas->ganacias() << endl;
	return s.str();
}
string Tienda::primeroYsegundoMasVendios(){
	// Comodines
	string first, second, id;
	int contador1 = 0, contador2 = 0, contadorAux = 0;
	
	// Donde se va a guardar la informacion
	stringstream show;

	// Punteros a los primeros de cada lista
	Nodo<Componente>* aux1 = Catalogo->getPrimero();
	Nodo<Factura>* aux2 = Ventas->getPrimero();

	// Una verificacion de que ambos punteros sean diferentes de NULL
	if (aux1 && aux2 != NULL) {
		
		// Inicia el ciclo para aux1
		while (aux1 != NULL) {
			// Se le asigna el id del elemento de aux1
			id = aux1->getDato()->getID();

			// Inicia el ciclo para aux2
			while (aux2 != NULL) {
				if (aux2->getDato()->existenciaDeProducto(id) == true) {
					contadorAux = contadorAux + aux2->getDato()->obtenerUnidadesDeProductoBuscado(id);
				}

				aux2 = aux2->getSiguiente();
			}
			aux2 = Ventas->getPrimero();
			if (contador1 == 0) {
				contador1 = contadorAux;
				first = id;
				second = id;
			}
			if (contadorAux > contador1) {
				contador2 = contador1;
				contador1 = contadorAux;
				second = first;
				first = id;
			}
			if (contadorAux < contador1 && contadorAux > contador2) {
				contador2 = contadorAux;
				second = id;
			}
			contadorAux = 0;
			aux1 = aux1->getSiguiente();
		}
	}



	show << "----------------Los dos mas Vendidos---------------------" << endl;
	if(retornarProductos(first) != NULL)
		show << retornarProductos(first)->toStringKits() << endl;
	show << "---------------------------------------------------------" << endl;
	if (retornarProductos(second) != NULL)
		show << retornarProductos(second)->toStringKits() << endl;
	show << "---------------------------------------------------------" << endl;

	
	return show.str();;
}

// ------------Archivos---------------


void Tienda::guardarCatalogo()
{
	Catalogo->guardarCatalogo();
}

void Tienda::recuperarArchivoCatalogo(){
	string rutaCatalogo = "../catalogo.txt";
	ifstream file;
	string op;
	file.open(rutaCatalogo);
	while (file.good()) {
		
		getline(file, op, DELIMITA_CAMPO);
		if (op == "Unidad CD") {
			Catalogo->ingresar(*UnidadCD::recuperar(file));
		}
		if (op == "Tornamesa") {
			Catalogo->ingresar(*Tornamesa::recuperar(file));
		}
		if (op == "Radio") {
			Catalogo->ingresar(*Radio::recuperar(file));
		}
		if (op == "Unidad Bluetooth") {
			Catalogo->ingresar(*UnidadBluetooth::recuperar(file));
		}
		if (op == "Microfono") {
			Catalogo->ingresar(*Microfono::recuperar(file));
		}
		if (op == "Amplificador") {
			Catalogo->ingresar(*Amplificador::recuperar(file));
		}
		if (op == "Mezclador") {
			Catalogo->ingresar(*Mezclador::recuperar(file));
		}
		if (op == "Altavoz") {
			Catalogo->ingresar(*Altavoz::recuperar(file));
		}
		if (op == "Audifono") {
			Catalogo->ingresar(*Audifono::recuperar(file));
		}
		if (op == "Kit") {
			Catalogo->ingresar(*Kit::recuperar(file));
		}
	}
	file.close();
}

void Tienda::guardarSuscriptores()
{
	Suscriptores->guardarSuscriptores();
}

void Tienda::recuperarArchivoSuscriptores(){
	string rutaSuscriptores = "../suscriptores.txt";
	ifstream file;
	string op;
	Cliente* c = NULL;
	file.open(rutaSuscriptores);
	while (file.good()) {
		getline(file, op, DELIMITA_CAMPO);
		if (op == "Empresa") {
			c = Empresa::recuperar(file);
			c->setModel(Catalogo);
			Suscriptores->ingresar(*c);
		}
		if (op == "Persona") {
			c = Persona::recuperar(file);
			c->setModel(Catalogo);
			Suscriptores->ingresar(*c);
		}
	}
	file.close();
}

void Tienda::guardarFacturas() {
	Ventas->guardarVentas();
}
void Tienda::recuperarFacturas() {
	string rutaVentas = "../ventas.txt";
	ifstream entrada;
	string tipo;
	entrada.open(rutaVentas);
	while (entrada.good()) {
		getline(entrada, tipo, DELIMITA_CAMPO);
		if (tipo == "EnLinea") {
			Ventas->ingresar(*EnLinea::recuperar(entrada));
		}
		if (tipo == "Directo") {
			Ventas->ingresar(*Directo::recuperar(entrada));
		}
	}
	entrada.close();
}

void Tienda::guardaDestinos() {
	Destinos->guardarDestinos();
}

void Tienda::recuperarArchivoDestinos() {
	string rutaDestinos = "../traslados.txt";
	ifstream entrada;
	entrada.open(rutaDestinos);
	while (entrada.good()) {
		string op;
		getline(entrada, op, DELIMITA_CAMPO);
		if(op == "Destino")
			Destinos->ingresar(*Destino::recuperar(entrada));
	}
	entrada.close();
}

void Tienda::guardarArchivos(){
	guardarCatalogo();
	guardarSuscriptores();
	guardarFacturas();
	guardaDestinos();
}

void Tienda::recuperarDeArchivos(){
	recuperarArchivoCatalogo();
	recuperarArchivoSuscriptores();
	recuperarFacturas();
	recuperarArchivoDestinos();
}
