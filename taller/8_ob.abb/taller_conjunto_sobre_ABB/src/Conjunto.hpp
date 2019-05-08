template <class T>
Conjunto<T>::Conjunto() : _raiz(NULL) {}

template <class T>
Conjunto<T>::~Conjunto() { 
    // Completar
}

template <class T>
bool Conjunto<T>::pertenece(const T& clave) const {
    Conjunto<T>::Nodo* resultado = _recorrer_nodos(_raiz, clave);
    return (resultado != NULL) && (resultado->valor == clave);
}

template <class T>
typename Conjunto<T>::Nodo* Conjunto<T>::_recorrer_nodos(Conjunto<T>::Nodo* n, const T& clave) const {
    if (n == NULL) {
        return NULL;
    } else {
        if (n->valor == clave) {
            return n;
        } else {
            // Si la clave es mayor voy por el subarbol derecho,
            // sino por el izquierdo.
            Conjunto<T>::Nodo* siguiente = (n->valor < clave)? n->der : n->izq;
            // Busco en el siguiente
            return _recorrer_nodos(siguiente, clave);
        }

    }
}


template <class T>
void Conjunto<T>::insertar(const T& clave) {
}

template <class T>
void Conjunto<T>::remover(const T&) {
}

template <class T>
const T& Conjunto<T>::siguiente(const T& clave) {
}

template <class T>
const T& Conjunto<T>::minimo() const {
}

template <class T>
const T& Conjunto<T>::maximo() const {
}

template <class T>
unsigned int Conjunto<T>::cardinal() const {
    return 0;
}

template <class T>
void Conjunto<T>::mostrar(std::ostream&) const {
}

