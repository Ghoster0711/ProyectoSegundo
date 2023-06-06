#pragma once
#include "Nodo.h"
#include"Utiles.h"
#include"Cliente.h"
#include<fstream>

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
	void setCantidad(int);

	void ingresar(T*);

	void guardarDatos(ostream&);
	static Lista<T>* recuperarDatos(istream&);

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
inline void Lista<T>::setCantidad(int c)
{
	cantidad = c;
}

template<class T>
inline void Lista<T>::ingresar(T* dato){
	primero = new Nodo<T>(dato, primero);
	cantidad++;
}

template<class T>
inline void Lista<T>::guardarDatos(ostream& salida){
	Nodo<T>* elemento = primero;
	string tipo;
	salida << cantidad << DELIMITA_REGISTRO;
	while (elemento != NULL) {
		if (elemento->getDato() != NULL) {
			tipo = typeid(*e->getDato()).name();
			salida << tipo << DELIMITA_REGISTRO;
			elemento->getDato()->guardarDatos(salida);
		}
		elemento = elemento->getSiguiente();
	}
	//file.close();
}
/*tipo = typeid(e->getDato()*).name();
if (tipo == "class Dispositivos") {
	e->getDato()->guardar(file);
}
if (tipo == "class Kit") {
    e->getDato()->guardar(file);
}else
	e->getDato()->guardar(file);*/
template<class T>
inline Lista<T>* Lista<T>::recuperarDatos(istream& entrada) {
	Lista<T>* lista = new Lista<T>;
	Cliente* cliente = NULL;
	Componente* componente = NULL;
	Factura* factura = NULL;
	string cantidad, tipo;
	int cant;
	getline(entrada, cantidad, DELIMITA_REGISTRO);
	getline(entrada, tipo, DELIMITA_REGISTRO);
	if (tipo == "class Persona") {
		cliente = Persona::recuperarDatos(entrada);
		lista->ingresar(cliente);
	}
	if (tipo == "class Empresa") {
		cliente = Empresa::recuperarDatos(entrada);
		lista->ingresar(cliente);
	}
	if (tipo == "class Kit") {
		componente = Kit::recuperarDatos(entrada);
		lista->ingresar(componente);
	}
	if (tipo == "class Dispositivos") {
		componente = Dispositivos::recuperarDatos(entrada);
		lista->ingresar(componente);
	}
	if (tipo == "class EnLinea") {
		factura = EnLinea::recuperarDatos(entrada);
		lista->ingresar(factura);
	}
	if (tipo == "class Directo") {
		factura = Directo::recuperarDatos(entrada);
		lista->ingresar(factura);
	}
	cant = convierteInt(cantidad);
	lista->setCantidad(cant);
	return lista;
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