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
	Lista();
	virtual ~Lista();
	Nodo<T>* getPrimero();
	int getCantidad();

	void ingresar(T*);
	bool eliminar(string);

	void guardarCatalogo();
	void guardarSuscriptores();
	void guardarVentas();
	void guardarCarritoDeCompras(ostream&);
	//static Lista<Componente>* recuperarCarritoDeCompras(istream&);

	string toString();
};

template<class T>
inline Lista<T>::Lista(){
	cantidad = 0;
	primero = NULL;
}

template<class T>
inline Lista<T>::~Lista(){
	if (primero != NULL) delete primero;
}

template<class T>
inline Nodo<T>* Lista<T>::getPrimero()
{
	return primero;
}

template<class T>
inline int Lista<T>::getCantidad()
{
	return cantidad;
}

template<class T>
inline void Lista<T>::ingresar(T* dato){
	primero = new Nodo<T>(dato, primero);
	cantidad++;
}

template<class T>
inline bool Lista<T>::eliminar(string cod){
	Nodo<T>* nExt = primero;
	Nodo<T>* aux = NULL;
	// Elimina el primero si el que se busca es el primero
	if (nExt != NULL && nExt->getDato() != NULL) {
		if (nExt->getDato()->getID() == cod) {
			primero = primero->getSiguiente();
			delete nExt;
			return true;
		}
	}
	// Se le asigna nExt a aux
	aux = nExt;
	// Empieza el ciclo para buscar el elemento
	while (nExt != NULL) {
		if (nExt->getDato() != NULL) {
			// Si el elemento existe lo elimina
			if (nExt->getDato()->getID() == cod) {
				// Se le setea a aux el siguiente de nExt
				aux->setSiguiente(nExt->getSiguiente());
				// Se elimina nExt
				delete nExt;

				return true;
			}
		}
		// Se le asigna nExt a aux
		aux = nExt;
		// nExt pasa al siguiente nodo
		nExt = nExt->getSiguiente();
	}
	return false;
}

template<class T>
inline void Lista<T>::guardarCatalogo(){
	Nodo<T>* e = primero;
	string tipo;
	string rutaCatalogo = "../catalogo.txt";
	ofstream file;
	file.open(rutaCatalogo);

	while (e != NULL) {
		if (e->getDato() != NULL) {
			tipo = typeid(*e->getDato()).name();
			if (tipo == "class Dispositivo") {
				e->getDato()->guardar(file);
			}
			if (tipo == "class Kit") {
				e->getDato()->guardar(file);
			}else
				e->getDato()->guardar(file);
		}
		e = e->getSiguiente();
	}
	file.close();
}

template<class T>
inline void Lista<T>::guardarSuscriptores(){
	string rutaSuscriptores = "../suscriptores.txt";
	Nodo<T>* e = primero;
	string tipo;
	ofstream file;
	file.open(rutaSuscriptores);
	while (e != NULL) {
		if (e->getDato() != NULL) {
			e->getDato()->guardar(file);
		}
		e = e->getSiguiente();
	}
	file.close();

}
template<class T>
inline void Lista<T>::guardarVentas() {
	string rutaVentas = "../ventas.txt";
	Nodo<T>* e = primero;
	string tipo;
	ofstream salida;
	salida.open(rutaVentas);
	while (e != NULL) {
		if (e->getDato() != NULL) {
			e->getDato()->guardar(salida);
		}
		e = e->getSiguiente();
	}
	salida.close();
}

template<class T>
inline void Lista<T>::guardarCarritoDeCompras(ostream& salida) {
	Nodo<T>* e = primero;
	while (e != NULL) {
		if (e->getDato() != NULL) {
			e->getDato()->guardar(salida);
		}
		e = e->getSiguiente();
	}
}

//template<class T>
//inline Lista<Componente>* Lista<T>::recuperarCarritoDeCompras(istream& entrada) {
// Pedir Ayuda 
//}


template<class T>
inline string Lista<T>::toString(){
	stringstream show;
	Nodo<T>* pExt = primero;
	while (pExt != NULL) {
		if (pExt->getDato() != NULL) {
			show << pExt->getDato()->toString() << endl;
		}
		pExt = pExt->getSiguiente();
	}
	return show.str();
}
