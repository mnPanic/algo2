template <class T>
Conjunto<T>::Conjunto() : _raiz(NULL), _cardinal(0) {}

template <class T>
Conjunto<T>::~Conjunto() { 
    _destruir(_raiz);
}

template <class T>
void Conjunto<T>::_destruir(Conjunto<T>::Nodo* n) {
    if (n != nullptr) {
        _destruir(n->izq);
        _destruir(n->der);
        delete(n);
    }
    _cardinal = 0;
    _raiz = nullptr;
}

template <class T>
typename Conjunto<T>::Nodo* Conjunto<T>::_buscar_con_pila(const T &clave, Conjunto::Nodo* actual, stack<Conjunto::Nodo*> &recorrido) const{
    if (actual == nullptr) {
        return nullptr;
    }

    if (actual->valor == clave) {
        // Lo encontré
        return actual;
    }

    // Agrego el actual al recorrido
    recorrido.push(actual);

    // Veo por donde seguir buscando
    if (actual->valor > clave) {
        // Busco por la izquierda
        return _buscar_con_pila(clave, actual->izq, recorrido);
    } else {
        // Busco por la derecha
        return _buscar_con_pila(clave, actual->der, recorrido);
    }
}

template <class T>
typename Conjunto<T>::Nodo* Conjunto<T>::_buscar(const T &clave, Conjunto::Nodo* actual) const {
    stack<Conjunto::Nodo*> s;
    return _buscar_con_pila(clave, actual, s);
}

template <class T>
bool Conjunto<T>::pertenece(const T& clave) const {
    Conjunto::Nodo* res = _buscar(clave, _raiz);
    return (res != nullptr);
}

template <class T>
void Conjunto<T>::insertar(const T& clave) {
    stack<Conjunto::Nodo*> recorrido;
    Conjunto::Nodo* res = _buscar_con_pila(clave, _raiz, recorrido);
    if (res != nullptr) {
        // Ya está en el conjunto,
        // no hago nada.
        return;
    }

    if (recorrido.empty()) {
        // Como no hubo recorrido, no tengo ni raiz.
        // Lo agrego allí.
        _raiz = new Conjunto<T>::Nodo(clave);
    } else {
        // Tengo al menos un elemento

        // Agrego al nodo nuevo como hijo del último nodo de la búsqueda
        Conjunto::Nodo* padre = recorrido.top();
        if (padre->valor > clave) {
            // Si el padre es mayor, entonces agrego res como hijo izquierdo.
            padre->izq = new Conjunto<T>::Nodo(clave);
        } else {
            // Sino, el padre es menor, entonces agrego res como hijo derecho.
            padre->der = new Conjunto<T>::Nodo(clave);
        }
    }

    // Incremento el cardinal
    _cardinal++;
}

template <class T>
void Conjunto<T>::remover(const T& clave) {
    stack<Conjunto::Nodo*> recorrido;
    Conjunto::Nodo* n = _buscar_con_pila(clave, _raiz, recorrido);

    if (n == nullptr) {
        // La clave no está en el conjunto,
        // no hago nada
        return;
    }

    // Lo borro
    Conjunto::Nodo* padre = nullptr;
    if (!recorrido.empty()) {
        padre = recorrido.top();
    }

    _remover_nodo(n, padre);
}

template <class T>
void Conjunto<T>::_remover_nodo(Conjunto::Nodo* &n, Conjunto::Nodo* &padre) {
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
        if (n->valor < padre->valor) {
            padre->izq = reemplazo;
        } else {
            padre->der = reemplazo;
        }
    } else {
        // El unico momento en el que no tiene padre es la raiz.
        // n es la raiz.
        // La reinicio.
        _raiz = reemplazo;
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
    stack<Conjunto::Nodo*> recorrido;
    Conjunto::Nodo* n = _buscar_con_pila(clave, _raiz, recorrido);

    if (n->der != nullptr) {
        // Caso A: Si tiene subarbol derecho,
        // devuelvo el mínimo de ese subarbol
        // (el sucesor inmediato)
        Conjunto::Nodo** sucesor = _inmediato_sucesor(n);
        return (*sucesor)->valor;
    } else {
        // Caso B: Tengo que subir en el arbol
        Conjunto::Nodo* padre = recorrido.top();
        if (n->valor < padre->valor) {
            // Caso B.1: Es hijo izquierdo
            // Devuelvo el elemento del padre
            return padre->valor;
        } else {
            // Caso B.2: Es hijo derecho
            // Subo en el arbol hasta que llego a un nodo que es hijo izquierdo
            // El padre de ese nodo es el sucesor que busco.

            Conjunto::Nodo* actual = n;
            // Mientras que es un hijo derecho
            while(padre->der == actual) {
                recorrido.pop();
                // Subo con el padre
                actual = padre;
                padre = recorrido.top();
            }
            // Retorno el valor del padre del nodo que es hijo izquierdo
            return padre->valor;
        }
    }
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
void Conjunto<T>::mostrar(std::ostream& out) const {
    out << std::endl;
    print(out, "", _raiz, false);
}

template <class T>
void Conjunto<T>::print(std::ostream& out, const std::string& prefix, const Conjunto::Nodo* n, bool isLeft) const{
    if(n != nullptr) {
        out << prefix;

        out << (isLeft ? "├──" : "└──" );

        // print the value of the node
        out << n->valor << std::endl;

        // enter the next tree level - left and right branch
        print(out, prefix + (isLeft ? "│   " : "    "), n->izq, true);
        print(out, prefix + (isLeft ? "│   " : "    "), n->der, false);
    }
}
