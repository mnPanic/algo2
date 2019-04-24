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
    if(prim_anterior) {
        prim_anterior->prev = _prim;
    }

    // Si no hay ultimo, lo agrego como tal
    if(!_ult) {
        _ult = nuevo;
    }
}

template <typename T>
void Lista<T>::agregarAtras(const T& elem) {
    // Obtengo el ultimo anterior
    Nodo* ult_anterior = _ult;

    // Creo el nuevo nodo que tiene como anterior al anterior previo
    Nodo* nuevo = new Nodo(elem, ult_anterior, NULL);
    // Lo pongo como ultimo
    _ult = nuevo;

    // Si habia ultimo, hago que su siguiente sea el nuevo
    if (ult_anterior) {
        ult_anterior->sig = _ult;
    }

    // Si no hay primero, lo agrego como tal
    if(!_prim) {
        _prim = nuevo;
    }
}

template <typename T>
void Lista<T>::eliminar(Nat i) {
    Nodo* iesimo = _iesimo_nodo(i);
    // Supongo que i esta en rango y iesimo no es NULL

    // Cambio los punteros
    Nodo* prev_de_iesimo = iesimo->prev;
    Nodo* sig_de_iesimo = iesimo->sig;

    if (prev_de_iesimo) {
        prev_de_iesimo->sig = sig_de_iesimo;
    }

    if (sig_de_iesimo) {
        sig_de_iesimo->prev = prev_de_iesimo;
    }

    // Si es el primero, tengo que cambiar el prim
    if (_prim == iesimo) {
        _prim = sig_de_iesimo;
    }
    // Si es el ultimo, tengo que cambiar el ult
    if (_ult == iesimo) {
        _ult = prev_de_iesimo;
    }

    // Lo borro
    delete(iesimo);
}

template <typename T>
int Lista<T>::longitud() const {
    Nodo* actual = _prim;
    int l = 0;
    while(actual){
        l++;
        actual = actual->sig;
    }

    return l;
}

template <typename T>
typename Lista<T>::Nodo* Lista<T>::_iesimo_nodo(Nat i) const {
    int idx_actual = -1;
    Nodo* iesimo = NULL;
    Nodo* nodo_actual = _prim;
    while(nodo_actual){
        idx_actual++;
        if (i == idx_actual) {
            iesimo = nodo_actual;
        }
        nodo_actual = nodo_actual->sig;
    }

    return iesimo;
}

template <typename T>
const T& Lista<T>::iesimo(Nat i) const {
    // Supongo que no puede estar fuera de indice, sino daría nullpointer
    return _iesimo_nodo(i)->valor;

}

template <typename T>
T& Lista<T>::iesimo(Nat i) {
    // Supongo que no puede estar fuera de indice, sino daría nullpointer
    return _iesimo_nodo(i)->valor;
}

template <typename T>
void Lista<T>::mostrar(ostream& o) {
    // Completar
}