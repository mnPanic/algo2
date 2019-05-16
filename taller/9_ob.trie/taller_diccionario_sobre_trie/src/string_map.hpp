template <typename T>
string_map<T>::string_map()
    : _raiz(nullptr), _size(0){}

template <typename T>
string_map<T>::string_map(const string_map<T>& aCopiar) : string_map() { *this = aCopiar; } // Provisto por la catedra: utiliza el operador asignacion para realizar la copia.

template <typename T>
string_map<T>& string_map<T>::operator=(const string_map<T>& d) {
    // COMPLETAR
}

template <typename T>
string_map<T>::~string_map(){
    // COMPLETAR
}

template <typename T>
T& string_map<T>::operator[](const string& clave){
    // Si ya está definido, retorno su definición
    if (count(clave)) {
        return at(clave);
    }

    return _define_default(clave);
}

template <class T>
T& string_map<T>::_define_default(const string& clave) {
    // Si no hay raiz, la creo
    if (_raiz == nullptr) {
        _raiz = new Nodo();
    }

    Nodo* actual = _raiz;
    for(char c : clave) {
        // Si no tengo siguiente, lo creo
        if (actual->siguientes[int(c)] == nullptr) {
            actual->siguientes[int(c)] = new Nodo();
        }

        actual = actual->siguientes[int(c)];
    }

    // Estoy parado en el nodo que va a tener la definición.
    T* def = new T();
    if (actual->definicion != nullptr) {
        // Si estaba definido, borro la definición anterior
        delete actual->definicion;

    }
    // Le asigno la nueva definición
    actual->definicion = def;

    // Incremento el size
    _size++;

    return *def;
}


template <class T>
bool string_map<T>::_contains(const string& clave) const {
    // Si no tengo raiz, nada va a estar contenido
    if (_raiz == nullptr) {
        return false;
    }
    Nodo* actual = _raiz;
    // Recorro los caracteres de la palabra
    for(char c : clave) {
        actual = actual->siguientes[int(c)];
        if (actual == nullptr) {
            return false;
        }
    }

    return actual->definicion != nullptr;
}

template <typename T>
int string_map<T>::count(const string& clave) const{
    return _contains(clave)? 1 : 0;
}

template <typename T>
const T& string_map<T>::at(const string& clave) const {
    // Como ya se que está definido, simplemente recorro hasta que lo encuentro
    Nodo* actual = _raiz;
    for(char c : clave) {
        actual = actual->siguientes[int(c)];
    }
    return *actual->definicion;
}

template <typename T>
T& string_map<T>::at(const string& clave) {
    // Como ya se que está definido, simplemente recorro hasta que lo encuentro
    Nodo* actual = _raiz;
    for(char c : clave) {
        actual = actual->siguientes[int(c)];
    }
    return *actual->definicion;
}

template <typename T>
void string_map<T>::erase(const string& clave) {
    // COMPLETAR
}

template <typename T>
int string_map<T>::size() const{
    return _size;
}

template <typename T>
bool string_map<T>::empty() const{
    return size() == 0;
}