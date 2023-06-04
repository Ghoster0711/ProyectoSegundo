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

	void guardarCatalogo();

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
