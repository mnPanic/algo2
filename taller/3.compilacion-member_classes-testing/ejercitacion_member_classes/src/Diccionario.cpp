#include "Diccionario.h"

Diccionario::Diccionario() :
    _asociaciones(){}   // Lista de inicialización con un vector vacío

// Obtiene un puntero a la asociación que matchea la clave.
// Si no hay ninguna, retorna nullpointer.
int Diccionario::index_of(Clave k) const {
    int index = -1;
    for (int i = 0; i < _asociaciones.size() && index == -1; i++) {
        if (_asociaciones[i].clave == k) {
            index = i;
        }
    }

    return index;
}

void Diccionario::definir(Clave k, Valor v) {
    int index_existente = index_of(k);

    if (index_existente != -1) {
        // Ya está definida la clave, sobreescribo el valor
        _asociaciones[index_existente].valor = v;
    } else {
        // No está definida, la defino
        _asociaciones.push_back(Asociacion{k, v});
    }
}

bool Diccionario::def(Clave k) const {
    return index_of(k) != -1;
}

Valor Diccionario::obtener(Clave k) const {
    // Supongo que está definida
    return _asociaciones[index_of(k)].valor;
}