#include "Lista.h"

template <typename T>
Lista<T>::Lista() :
    _prim(NULL), _ult(NULL){}

template <typename T>
Lista<T>::Lista(const Lista<T>& l) : Lista() {
    //Inicializa una lista vacía y luego utiliza operator= para no duplicar el código de la copia de una lista.
    *this = l;
}

template <typename T>
Lista<T>::~Lista() {
    // Completar
}

template <typename T>
Lista<T>& Lista<T>::operator=(const Lista<T>& aCopiar) {
    // Completar
    return *this;
}

template <typename T>
void Lista<T>::agregarAdelante(const T& elem) {
    // Obtengo el primero anterior
    Nodo* prim_anterior = _prim;

    // Creo el nodo nuevo que tiene como siguiente al que solia ser el primero
    Nodo* nuevo = new Nodo(elem, NULL, prim_anterior);
    // Lo pongo como primero
    _prim = nuevo;

    // Si habia primero, hago que su previo sea el nuevo
    if(prim_anterior != NULL) {
        prim_anterior->prev = _prim;
    }
}

template <typename T>
void Lista<T>::agregarAtras(const T& elem) {
    // Completar
}

template <typename T>
void Lista<T>::eliminar(Nat i) {
    // Completar
}

template <typename T>
int Lista<T>::longitud() const {
    Nodo* actual = _prim;
    int l = 0;
    while(actual != NULL){
        l++;
        actual = actual->sig;
    }

    return l;
}

template <typename T>
const T& Lista<T>::iesimo(Nat i) const {
    // Completar
    assert(false);
}

template <typename T>
T& Lista<T>::iesimo(Nat i) {
    // Completar (hint: es igual a la anterior...)
    assert(false);
}

template <typename T>
void Lista<T>::mostrar(ostream& o) {
    // Completar
}