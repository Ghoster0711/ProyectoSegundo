/* --------------------------------------------------------------------
*
* EIF204 Programación 2
* Proyecto 2
*
* 6 0483 0349 Joshua Yarit Amador Lara.
* 40 264 0260 Sianny Barrantes Benavides.
*
* -------------------------------------------------------------------
*/

#pragma once
#include <iostream>
#include <sstream>

using namespace std;

template <class T>
class Nodo {
private:
	T* dato;
	Nodo* siguiente;
public:
	Nodo(T*, Nodo*);
	virtual ~Nodo();

	T* getDato();
	Nodo<T>* getSiguiente();

	void setDato(T*);
	void setSiguiente(Nodo*);

};

template<class T>
inline Nodo<T>::Nodo(T* dato, Nodo* siguiente){
	this->dato = dato;
	this->siguiente = siguiente;
}

template<class T>
inline Nodo<T>::~Nodo(){
	if (dato != NULL) delete dato;
	if (siguiente != NULL) delete siguiente;
}

template<class T>
inline T* Nodo<T>::getDato()
{
	return dato;
}

template<class T>
inline Nodo<T>* Nodo<T>::getSiguiente()
{
	return siguiente;
}

template<class T>
inline void Nodo<T>::setDato(T* dato){
	this->dato = dato;
}

template<class T>
inline void Nodo<T>::setSiguiente(Nodo* siguiente){
	this->siguiente = siguiente;
}


