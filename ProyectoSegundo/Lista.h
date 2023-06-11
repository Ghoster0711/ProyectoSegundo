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

	void ingresar(T&);
	void eliminar(string);

	void guardarCatalogo();
	void guardarSuscriptores();
	void guardarVentas();
	void guardarCarritoDeCompras(ostream&);
	void guardarDestinos();

	string toString();
	string toStringKit();
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
inline void Lista<T>::ingresar(T& dato){
	primero = new Nodo<T>((T*)&dato, primero);
	cantidad++;
}

template<class T>
inline void Lista<T>::eliminar(string cod) {
	if (this->primero != NULL) {
		Nodo<T>* current = this->primero;
		Nodo<T>* prev;
		if (current->getDato()->getID() == cod && this->primero == current) {
			primero = primero->getSiguiente();
			current->setSiguiente(NULL);
			delete current;
			return;
		}
		prev = current;
		current = current->getSiguiente();
		while (current) {
			if (current->getDato()->getID() == cod) {
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

template<class T>
inline void Lista<T>::guardarCatalogo(){
	Nodo<T>* e = primero;
	string tipo;
	string rutaCatalogo = "../CatalogoS.txt";
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

template<class T>
inline void Lista<T>::guardarDestinos() {
	string rutaDestinos = "../traslados.txt";
	Nodo<T>* e = primero;
	ofstream salida;
	salida.open(rutaDestinos);
	while (e != NULL) {
		if (e->getDato() != NULL) {
			e->getDato()->guardar(salida);
		}
		e = e->getSiguiente();
	}
	salida.close();
}


template<class T>
inline string Lista<T>::toString(){
	stringstream show;
	Nodo<T>* pExt = primero;
	while (pExt != NULL) {
		if (pExt->getDato() != NULL) {
			show << "-------------------------------------------------------------------------------------------------------------------" << endl;
			show << pExt->getDato()->toString() << endl;
		}
		pExt = pExt->getSiguiente();
	}
	show << "-------------------------------------------------------------------------------------------------------------------" << endl;
	return show.str();
}

template<class T>
inline string Lista<T>::toStringKit() {
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