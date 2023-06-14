#pragma once
#include "Nodo.h"
#define DELIMITA_CAMPO '\t'
#define DELIMITA_REGISTRO '\n'


template<class T>
class Lista {
private:
	Nodo<T>* primero;
	int cantidad;
public:
	// Constructor
	Lista();

	// Destructor
	virtual ~Lista();

	// Get's
	Nodo<T>* getPrimero();

	// Set's
	int getCantidad();

	// Metodo para ingresar un elemento a la lista
	void ingresar(T&);

	// Metodo para eliminar un elemento de la lista
	void eliminar(string);

	// Metodos para guardar en los archivos
	void guardarCatalogo();
	void guardarSuscriptores();
	void guardarVentas();
	void guardarCarritoDeCompras(ostream&);
	void guardarDestinos();

	// Metodos para mostrar las listas
	string toString();
	string toStringKit();

	// Metodos para obtener los precios de los elementos que se encuentran en las listas
	double obtenerPrecios();

	double subtotalesDeFacturas();

};


// Desarrollo del Construtor
template<class T>
inline Lista<T>::Lista(){
	cantidad = 0;
	primero = NULL;
}

// Desarrollo del Destructor
template<class T>
inline Lista<T>::~Lista(){
	if (primero != NULL) delete primero;
}

// Desarrollo de los Get's
template<class T>
inline Nodo<T>* Lista<T>::getPrimero()
{
	return primero;
}


// Desarrollo de los Set's
template<class T>
inline int Lista<T>::getCantidad()
{
	return cantidad;
}


// Desarrollo del metodo para ingresar
template<class T>
inline void Lista<T>::ingresar(T& dato){
	primero = new Nodo<T>((T*)&dato, primero); // Ingresa el dato de primero
	cantidad++; // Aumenta el contador de elementos que contiene la lista
}


// Desarrollo del metodo para eliminar
template<class T>
inline void Lista<T>::eliminar(string cod) { // Se ingresa el identificador 

	if (this->primero != NULL) { // Verifica que el primero sea diferente de NULL
	
		// Se crean dos punteros que son los encargados de moverse atravez de la lista
		Nodo<T>* current = this->primero; 
		Nodo<T>* prev;
		
		// Se realiza un primer caso en el que si el dato a eliminar se encuentra de primero
		if (current->getDato()->getID() == cod && this->primero == current) {
			primero = primero->getSiguiente();
			current->setSiguiente(NULL);
			delete current;
			return;
		}
		prev = current;
		current = current->getSiguiente();
		// En el caso de que no se encuentre en el primero, se realiza un recorrido en toda la lista
		while (current) {
			if (current->getDato()->getID() == cod) { // Si el identificador conside con el del elemento
				// Se realizan los procesos necesarios para eliminar el nodo en el que se encuentra el elemento
				prev->setSiguiente(current->getSiguiente());
				current->setSiguiente(NULL);
				delete current;
				return;
			}
			prev = current;
			current = current->getSiguiente();
		}
	}
}

// Desarrollo del metodo para guardar lo que almacena el catalogo
template<class T>
inline void Lista<T>::guardarCatalogo(){
	Nodo<T>* e = primero; // Se crea un nodo que ve al primero
	//string tipo; // Se encarga de ver el tipo
	string rutaCatalogo = "../catalogo.txt"; // Se crear la ruta donde se va a guardar el catalogo
	ofstream file; // Permite crear un archivo
	file.open(rutaCatalogo); // Se le asigna la ruta al archivo y lo abre
	
	// Se realiza el recorrido de la lista
	while (e != NULL) { 
		if (e->getDato() != NULL) {
			e->getDato()->guardar(file); // Ejecuta el metodo guardar de cada elemento
		}
		e = e->getSiguiente();
	}
	file.close(); // Cierra el archivo
}

// Desarrollo del metodo para guardar lo que almacena los suscriptores
template<class T>
inline void Lista<T>::guardarSuscriptores(){
	Nodo<T>* e = primero; // Se crea un nodo que ve al primero
	string rutaSuscriptores = "../suscriptores.txt"; // Se crea la ruta del archivo donde se va a guardar los suscriptores
	//string tipo;
	ofstream file; // Permite crear el archivo
	file.open(rutaSuscriptores);  // Se le asigna la ruta al archivo y lo abre

	// Se realiza el recorrido de la lista
	while (e != NULL) {
		if (e->getDato() != NULL) {
			e->getDato()->guardar(file); // Ejecuta el metodo guardar de cada elemento
		}
		e = e->getSiguiente();
	}
	file.close(); // Cierra el archivo

}

// Desarrollo del metodo para guardar lo que almacena las ventas
template<class T>
inline void Lista<T>::guardarVentas() {
	Nodo<T>* e = primero; // Se crea un nodo que ve al primero
	string rutaVentas = "../ventas.txt"; // Se crea la ruta del archivo donde se va a guardar las ventas
	ofstream file; // Permite crear el archivo
	file.open(rutaVentas); // Se le asigna la ruta al archivo y lo abre

	// Se realiza el recorrido de la lista
	while (e != NULL) {
		if (e->getDato() != NULL) {
			e->getDato()->guardar(file); // Ejecuta el metodo guardar de cada elemento
		}
		e = e->getSiguiente();
	}
	file.close(); // Cierra el archivo
}

// Desarrollo del metodo para guardar lo que almacena el carrito de compras
template<class T>
inline void Lista<T>::guardarCarritoDeCompras(ostream& salida) { // Ingresa donde se va guardar la informacion del carrito
	Nodo<T>* e = primero; // Se crea un nodo que ve al primero

	// Se realiza el recorrido de la lista
	while (e != NULL) {
		if (e->getDato() != NULL) {
			e->getDato()->guardar(salida); // Ejecuta el metodo guardar de cada elemento
		}
		e = e->getSiguiente();
	}
}

// Desarrollo del metodo para guardar lo que almacena los destinos
template<class T>
inline void Lista<T>::guardarDestinos() {
	Nodo<T>* e = primero; // Se crea un nodo que ve al primero
	string rutaDestinos = "../traslados.txt"; // Se crea la ruta del archivo donde se va a guardar los translados
	ofstream file; // Permite crear el archivo
	file.open(rutaDestinos);; // Se le asigna la ruta al archivo y lo abre
	while (e != NULL) {
		if (e->getDato() != NULL) {
			e->getDato()->guardar(file); // Ejecuta el metodo guardar de cada elemento
		}
		e = e->getSiguiente();
	}
	file.close(); // Cierra el archivo
}


template<class T>
inline string Lista<T>::toString(){
	stringstream show;
	Nodo<T>* pExt = primero;
	while (pExt != NULL) {
		if (pExt->getDato() != NULL) {
			show << "--------------------------------------------------------------------------------------------------------------------------------" << endl;
			show << pExt->getDato()->toString() << endl;
		}
		pExt = pExt->getSiguiente();
	}
	show << "--------------------------------------------------------------------------------------------------------------------------------" << endl;
	return show.str();
}

template<class T>
inline string Lista<T>::toStringKit() {
	stringstream show;
	Nodo<T>* pExt = primero;
	while (pExt != NULL) {
		if (pExt->getDato() != NULL) {
			show << pExt->getDato()->toStringKits() << endl;
		}
		pExt = pExt->getSiguiente();
	}
	return show.str();
}

template<class T>
inline double Lista<T>::obtenerPrecios()
{
	double precios = 0;
	Nodo<T>* pExt = primero;
	while (pExt != NULL) {
		if (pExt->getDato() != NULL) {
			precios = precios + pExt->getDato()->obtenerPrecios();
		}
		pExt = pExt->getSiguiente();
	}
	return precios;
}

//template<class T>
//inline double subtotalesDeFacturas() {
//	double suma = 0;
//	Nodo<T>* pExt = primero;
//	while (pExt != NULL) {
//		if (pExt->getDato() != NULL) {
//			suma = suma + pExt->getDato()->precioBrutoDeLaFactura();
//		}
//		pExt = pExt->getSiguiente();
//	}
//	return suma;
//}