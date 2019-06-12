
template<class T>
ColaPrior<T>::ColaPrior(): elementos() {}

template<class T>
int ColaPrior<T>::tam() const {
	return int(elementos.size());
}

template<class T>
void ColaPrior<T>::encolar(const T& elem) {
    // Lo agrego en la última posición libre
    elementos.push_back(elem);
    // Le aplico sift up
    sift_up(ultima_pos());
}

template<class T>
const T& ColaPrior<T>::proximo() const {
	return elementos[0];
}

template<class T>
void ColaPrior<T>::desencolar() {
    // Swapeo el último elemento y el primero
    swap(0, ultima_pos());

    // Borro el ultimo elemento
    elementos.pop_back();

    // Lo sifteo para abajo
    sift_down(0);
}

template<class T>
ColaPrior<T>::ColaPrior(const vector<T>& elems) {
    // Algoritmo simple: Agrego todos devuelta
    //for (T elem : elems) {
    //    encolar(elem);
    //}

	// Heapify: Interpreto el arreglo como un heap, y le aplico
	// sift down a todos los elementos, recorriendolos de abajo para arriba.

	// Me copio los elementos
	elementos = elems;
	for (int i = ultima_pos(); i >= 0; i--) {
	    sift_down(i);
	}
}

template <class T>
void ColaPrior<T>::sift_up(int elem_idx) {
    // Si el elemento es mas grande que el padre,
    int p = padre(elem_idx);
    if (valido(p) &&
        elementos[elem_idx] > elementos[p]) {
        swap(elem_idx, p);
        // Sigo sifteando recursivamente
        sift_up(p);
    }
}

template <class T>
void ColaPrior<T>::sift_down(int elem_idx){
    int next = sift_down_next(elem_idx);
    // Si el elemento es mas chico que el maximo de sus hijos
    if (next != -1 &&
        elementos[elem_idx] < elementos[next]) {
        swap(elem_idx, next);
        // Sigo sifteando recursivamente
        sift_down(next);
    }
}

template <class T>
int ColaPrior<T>::sift_down_next(int elem_idx) const {
    int next = -1;

    int i = hijo_izq(elem_idx);
    int d = hijo_der(elem_idx);

    // Si el derecho no es válido
    if (!valido(d)) {
        // Si el izquierdo es válido, sigo por ahí
        if (valido(i)) {
            next = i;
        }
    } else {
        // El derecho es válido
        // Si el izquierdo es inválido, sigo por el derecho
        if (!valido(i)) {
            next = d;
        } else {
            // Ambos son válidos, me quedo con el máximo entre ellos
            next = (elementos[i] > elementos[d])? i : d;
        }
    }

    return next;
}

template <class T>
int ColaPrior<T>::ultima_pos() const {
    return tam() - 1;
}

template <class T>
bool ColaPrior<T>::valido(int idx) const {
    return 0 <= idx && idx < elementos.size();
}

template <class T>
void ColaPrior<T>::swap(int i, int j) {
    T temp = elementos[i];
    elementos[i] = elementos[j];
    elementos[j] = temp;
}

template <class T>
int ColaPrior<T>::hijo_izq(int elem_idx) const {
    return 2 * elem_idx + 1;
}

template <class T>
int ColaPrior<T>::hijo_der(int elem_idx) const {
    return 2 * elem_idx + 2;
}

template <class T>
int ColaPrior<T>::padre(int elem_idx) const {
    return (elem_idx - 1) / 2;
}

