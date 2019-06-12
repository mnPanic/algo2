#ifndef _COLAPRIOR_H_
#define _COLAPRIOR_H_

#include <vector>

using namespace std;

/* La clase T debe tener definido un operator<
 * que implemente una relación de orden total. */
template<class T>
class ColaPrior {
public:
	ColaPrior();

	// Cantidad de elementos en la cola.
	int tam() const;

	// Encola un elemento.
	//
	// Nota: si se implementa usando un vector, es O(n) en peor caso.
	//
	void encolar(const T& elem);

	// Devuelve el elemento de mayor prioridad.
	// Pre: tam() > 0
	const T& proximo() const;

	// Saca el elemento de mayor prioridad.
	//
	// Nota: si se implementa usando un vector, es O(n) en peor caso.
	//
	// Pre: tam() > 0
	void desencolar();

	// Constructor que hace heapify.
	ColaPrior(const vector<T>& elems);

private:
	vector<T> elementos;

	// Siftea el elemento hacia arriba hasta que está bien ubicado
	void sift_up(int elem_idx);
	// Siftea el elemento hacia abajo hasta que está bien ubicado
	void sift_down(int elem_idx);

	// Da el indice del elemento con el cual swapear.
	// Devuelve -1 si no hay ninguno.
	int sift_down_next(int elem_idx) const;

	// Dice si un indice es válido en el arreglo.
	bool valido(int idx) const;

	// Retorna la última posición del vector de elementos.
	int ultima_pos() const;

	// Swapea los elementos de los indices i y j.
	// Pre: están en rango.
	void swap(int i, int j);

	// Devuelve el padre del elemento que está en el indice provisto
	// O(1)
	int padre(int elem_idx) const;

	// Devuelve el hijo izquierdo del elemento que está en el indice provisto
	// O(1)
	int hijo_izq(int elem_idx) const;

	// Devuelve el hijo derecho del elemento que está en el indice provisto
	// O(1)
	int hijo_der(int elem_idx) const;
};

#include "ColaPrior.hpp"

#endif /*_COLAPRIOR_H_*/
