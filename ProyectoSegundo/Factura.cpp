#include "Factura.h"


Factura::Factura() {
	codigo = "";
	fecha = NULL;
	cliente = NULL;
	carritoDeCompras = NULL;
}

Factura::Factura(string cod, Fecha* fec, Cliente* cli){
	codigo = cod;
	fecha = fec;
	cliente = clonarCliente(cli);
	carritoDeCompras = new Lista<Componente>();
}

Factura::~Factura(){
	if (fecha != NULL)delete fecha;
	if (cliente != NULL) delete cliente;
	//Eliminar el carrito de compras 
}

string Factura::getCodigo() { return codigo; }

Fecha* Factura::getFecha() { return fecha; }

Cliente* Factura::getCliente() { return cliente; }

void Factura::setCodigo(string cod){ codigo = cod; }

void Factura::setFecha(Fecha* fec) { fecha = fec; }

void Factura::setCliente(Cliente* cli){ cliente = cli; }

void Factura::setLista(Lista<Componente>* carrito) {
	carritoDeCompras = carrito;
}

Cliente* Factura::clonarCliente(Cliente* client) {
	string type, nom, ced, pais, ciudad, correo, naciona;
	type= typeid(*(client)).name();
	nom = client->getNombre();
	ced = client->getCedula();
	pais = client->getNombrePais();
	ciudad = client->getCiudadUbicacion();
	if (type == "class Persona") {
		Persona* persona = dynamic_cast<Persona*>(client);
		if (persona != NULL) {
			correo = persona->getCorreo();
			naciona = persona->getNacionalidad();
			return new Persona(nom, ced, pais, ciudad, correo, naciona);
		}
	}
	if (type == "class Empresa") {
		return new Empresa(nom, ced, pais, ciudad);
	}
}

Componente* Factura::clonarComponente(Componente* componente) {
	string type, tipo, modelo, caracteristica;
	double precio;
	Componente* componenteClonado = NULL;
	type = typeid(*(componente)).name();
	tipo = componente->getTipoComponente();
	modelo = componente->getModelo();
	caracteristica = componente->getCaracteristica();
	precio = componente->getPrecio();
	if (type == "class FuenteDeAudio") {
		componenteClonado = new FuenteDeAudio(tipo, modelo, caracteristica, precio);
	}
	if (type == "class ProcesadorDeSenal") {
		componenteClonado = new ProcesadorDeSenal(tipo, modelo, caracteristica, precio);
	}
	if (type == "class Parlante") {
		componenteClonado = new Parlante(tipo, modelo, caracteristica, precio);
	}
	return componenteClonado;
}

void Factura::ingresarCompra(Componente* compra) {
	Componente* compraClonada = NULL;
	string type = typeid(*(compra)).name();
	Nodo<Componente>* aux = NULL;
	if (type == "class Kit") {
		Kit* kit = dynamic_cast<Kit*>(compra);
		if (kit != NULL) {
			compraClonada = new Kit();
			aux = kit->getEmpaquetado()->getPrimero();
			while (aux != NULL) {
				compraClonada->agregar(clonarComponente(aux->getDato()));
				carritoDeCompras->ingresar(compraClonada);
				aux->getSiguiente();
			}
		}
	}
	if (type == "class Dispositivos") {
		Dispositivos* dispositivos = dynamic_cast<Dispositivos*>(compra);
		if (dispositivos != NULL) {
			compraClonada = new Dispositivos();
			aux = dispositivos->getEmpaquetado()->getPrimero();
			while (aux != NULL) {
				compraClonada->agregar(clonarComponente(aux->getDato()));
				carritoDeCompras->ingresar(compraClonada);
				aux->getSiguiente();
			}
		}
	}
}

//Factura* Factura::recuperarDatos(istream& entrada) {
//	Factura* factura = NULL;
//	string cod, type, nom, ced, cor, tel;
//	getline(entrada, cod, DELIMITA_REGISTRO);
//	getline(entrada, type, DELIMITA_REGISTRO);
//	if (type == "class Persona") {
//		Cliente* cliente = Persona::recuperarDatos(entrada);
//		factura->setCliente(cliente);
//	}
//	if (type == "class Empresa") {
//		Cliente* cliente = Empresa::recuperarDatos(entrada);
//		factura->setCliente(cliente);
//	}
//	Fecha* fec = Fecha::recuperarDatos(entrada);
//	Destino* destino = Destino::recuperarDatos(entrada);
//	factura->setCodigo(cod);
//	factura->setFecha(fec);
//	factura->setDestino(destino);
//	
//	//Recuperar el combo 
//	return factura;
//}

