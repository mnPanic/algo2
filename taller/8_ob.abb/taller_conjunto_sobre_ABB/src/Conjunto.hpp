template <class T>
Conjunto<T>::Conjunto() : _raiz(NULL), _cardinal(0) {}

template <class T>
Conjunto<T>::~Conjunto() { 
    // Completar
}

template <class T>
bool Conjunto<T>::pertenece(const T& clave) const {
    return _pertenece_recorriendo_nodos(_raiz, clave);
}

template <class T>
bool Conjunto<T>::_pertenece_recorriendo_nodos(Conjunto<T>::Nodo* n, const T& clave) const {
    if (n == nullptr) {
        return false;
    } else {
        if (n->valor == clave) {
            return true;
        } else {
            // Si la clave es mayor voy por el subarbol derecho,
            // sino por el izquierdo.
            Conjunto<T>::Nodo* siguiente = (n->valor < clave)? n->der : n->izq;
            // Busco en el siguiente
            return _pertenece_recorriendo_nodos(siguiente, clave);
        }
    }
}


template <class T>
void Conjunto<T>::insertar(const T& clave) {
    if (!pertenece(clave)) {
        // Si no pertenece, lo inserto recorriendo los nodos
        _insertar_recorriendo_nodos(_raiz, clave);
    }
}

template <class T>
void Conjunto<T>::_insertar_recorriendo_nodos(Conjunto<T>::Nodo* &n, const T& clave) {
    // Supongo que nodo no es null
    if (n == nullptr) {
        // Si el nodo es null, lo inserto allí
        n = new Conjunto<T>::Nodo(clave);
        _cardinal++;
    } else {
        // Sino, veo si lo debo insertar a izquierda o derecha
        if (n->valor > clave) {
            _insertar_recorriendo_nodos(n->izq, clave);
        } else {
            _insertar_recorriendo_nodos(n->der, clave);
        }
    }
}

template <class T>
void Conjunto<T>::remover(const T& clave) {
    _remover_recorriendo(_raiz, nullptr, clave);
}

template <class T>
void Conjunto<T>::_remover_recorriendo(Conjunto<T>::Nodo* &n, Conjunto<T>::Nodo** padre, const T& clave) {
    if (n == nullptr) {
        // El nodo que estoy buscando no existe.
        return;
    }

    if (n->valor == clave) {
        // Encontré el nodo, lo borro.
        _remover_nodo(n, padre);
    } else {
        // Sigo recorriendo hasta encontrarlo.
        Conjunto<T>::Nodo** sig = (n->valor > clave)? &(n->izq) : &(n->der);
        _remover_recorriendo(*sig, &n, clave);
    }
}

template <class T>
void Conjunto<T>::_remover_nodo(Conjunto<T>::Nodo* &n, Conjunto<T>::Nodo** padre) {
    // Supone que n no es null
    vector<typename Conjunto<T>::Nodo*> hijos = _hijos(n);
    Conjunto<T>::Nodo* reemplazo = nullptr;
    switch (hijos.size()) {
        case 1:
            // El hijo pasa a ocupar el lugar del padre (n es el padre de hijos)
            reemplazo = hijos[0];
            break;
        case 2:
            reemplazo = *_inmediato_sucesor(n);
            break;
        default:
            // No es posible
            break;
    }

    // Si tenía padre, lo cambio por su reemplazo
    if (padre != nullptr) {
        if (n->valor < (*padre)->valor) {
            (*padre)->izq = reemplazo;
        } else {
            (*padre)->der = reemplazo;
        }
    } else {
        // El unico momento en el que no tiene padre es la raiz.
        // n es la raiz.
        // La reinicio.
        _raiz = nullptr;
    }

    // Borro a n
    delete(n);

    // Decremento el cardinal
    _cardinal--;

}

template <class T>
typename Conjunto<T>::Nodo** Conjunto<T>::_inmediato_sucesor(Conjunto<T>::Nodo* &n) {
    // Es el mas chico de los mas grandes
    if (n->der == nullptr) {
        return nullptr;
    }
    return _mas_chico(n->der);
}

template <class T>
typename Conjunto<T>::Nodo** Conjunto<T>::_mas_chico(Conjunto<T>::Nodo* &n) {
    return (n->izq == nullptr)? &n : _mas_chico(n->izq);
}

template <class T>
vector<typename Conjunto<T>::Nodo*> Conjunto<T>::_hijos(Conjunto<T>::Nodo* &n) {
    // Supone que n no es null
    vector<Conjunto<T>::Nodo*> hijos;
    if (n->izq != nullptr) {
        hijos.push_back(n->izq);
    }
    if (n->der != nullptr) {
        hijos.push_back(n->der);
    }
    return hijos;
}

template <class T>
const T& Conjunto<T>::siguiente(const T& clave) {
}

template <class T>
const T& Conjunto<T>::minimo() const {
    // Asumo que el conjunto no es vacío
    assert(cardinal() > 0);

    return _minimo_recorriendo(_raiz)->valor;
}

template <class T>
typename Conjunto<T>::Nodo* Conjunto<T>::_minimo_recorriendo(Conjunto<T>::Nodo* n) const {
    if (n == nullptr) {
        return nullptr;
    }

    // Hago que el minimo sea la "raiz"
    Conjunto<T>::Nodo* min = n;

    Conjunto<T>::Nodo* min_izq = _minimo_recorriendo(n->izq);
    Conjunto<T>::Nodo* min_der = _minimo_recorriendo(n->der);

    if (min_izq != nullptr) {
        min = (min->valor < min_izq->valor)? min : min_izq;
    }
    if (min_der != nullptr) {
        min = (min->valor < min_der->valor)? min : min_der;
    }

    return min;
}


template <class T>
const T& Conjunto<T>::maximo() const {
    // Asumo que el conjunto no es vacío
    assert(cardinal() > 0);

    return _maximo_recorriendo(_raiz)->valor;
}


template <class T>
typename Conjunto<T>::Nodo* Conjunto<T>::_maximo_recorriendo(Conjunto<T>::Nodo* n) const {
    if (n == nullptr) {
        return nullptr;
    }

    // Hago que el maximo sea la "raiz"
    Conjunto<T>::Nodo* max = n;

    Conjunto<T>::Nodo* max_izq = _maximo_recorriendo(n->izq);
    Conjunto<T>::Nodo* max_der = _maximo_recorriendo(n->der);

    if (max_izq != nullptr) {
        max = (max->valor > max_izq->valor)? max : max_izq;
    }
    if (max_der != nullptr) {
        max = (max->valor > max_der->valor)? max : max_der;
    }

    return max;
}

template <class T>
unsigned int Conjunto<T>::cardinal() const {
    return _cardinal;
}

template <class T>
void Conjunto<T>::mostrar(std::ostream&) const {
}

