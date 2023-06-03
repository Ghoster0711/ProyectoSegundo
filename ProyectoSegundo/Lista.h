#pragma once
#include "Nodo.h"

template<class T>
class Lista {
private:
	Nodo<T>* primero;
	int cantidad;
public:
	Lista();
	virtual ~Lista();

	void ingresar(T*);

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
inline void Lista<T>::ingresar(T* dato){
	primero = new Nodo<T>(dato, primero);
	cantidad++;
}

template<class T>
inline string Lista<T>::toString(){
	stringstream show;
	Nodo<T>* pExt = primero;
	while (pExt != NULL) {
		if (pExt->getDato() != NULL) {
			show << pExt->getDato()->toString();
		}
		pExt = pExt->getSiguiente();
	}
	return show.str();
}
