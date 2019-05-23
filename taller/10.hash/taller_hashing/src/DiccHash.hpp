#include "DiccHash.h"
/* Constructor sin parámetros de la clase */
template<class V>
DiccHash<V>::DiccHash() :
	_tabla(vector<list<Asociacion>>(TAM_INICIAL)),
	_tam(TAM_INICIAL),
	_cant_claves(0) {}

/* Destructor */
template<class V>
DiccHash<V>::~DiccHash() {
}

/* Devuelve true si la clave está definida en el diccionario.
 * - clav : clave a buscar
 */
template<class V>
bool DiccHash<V>::definido(const string& clav) const {
	return _obtener(clav) != nullptr;
}

template <class V>
typename DiccHash<V>::Asociacion* DiccHash<V>::_obtener(const string& str) const {
	// Hasheo la clave
	int clav_hash = fn_hash(str);
	// Obtengo la lista de asociaciones para ese hash
	list<Asociacion> asociaciones = _tabla[clav_hash];

	return _buscar_asociacion(str, asociaciones);
}

template <class V>
typename DiccHash<V>::Asociacion* DiccHash<V>::_buscar_asociacion(const string &str, list<Asociacion> asociaciones) const {
	// Busco si mi clave está en esa lista de asociaciones
	// Si no la encuentro, retorno nullptr
	Asociacion* asociacion = nullptr;
	for (Asociacion &a : asociaciones) {
		if (a.clave == str) {
			// Si las claves son iguales, la encontré
			asociacion = &a;
			break;
		}
	}

	return asociacion;
}


/* Agrega una clave y su significado al Diccionario.
 * Si la clave a agregar ya se encuentra definida,
 * redefine su significado.
 * - clav : clave a agregar
 * - sig  : significado de la clave a agregar
 *
 * Nota de implementación:
 *
 * Si el factor de carga supera el valor de UMBRAL_FC, se debe
 * redimensionar la tabla al doble de tamaño.
 *
 * Pasos a seguir para redimensionar la tabla:
 * - Crear una tabla del doble de tamaño de la original.
 * - Insertar todas las claves de la tabla original en la tabla nueva.
 * - Liberar la memoria reservada para la tabla original.
 */
template<class V>
void DiccHash<V>::definir(const string& clav, const V& sig) {
	int clav_hash = fn_hash(clav);
	list<Asociacion> &asociaciones = _tabla[clav_hash];

	Asociacion* asociacion_existente = _buscar_asociacion(clav, asociaciones);

	if (asociacion_existente != nullptr) {
		// La redefino
		asociacion_existente->valor = sig;
	} else {
		// No está definido
		// La tengo que definir
		asociaciones.push_back(Asociacion(clav, sig));
		// Incremento la cantidad de claves
		_cant_claves++;
	}

	if (factorCarga() > UMBRAL_FC) {
		// Tengo que redimensionar la tabla
		_redimensionar();
	}
}

template <class V>
void DiccHash<V>::_redimensionar() {
	// Me guardo las asociaciones
	vector<Asociacion> asociaciones = _asociaciones();
	// Duplico el tamaño
	_tam *= 2;
	// Vacío las asociaciones y reseteo la cantidad de claves
	_tabla.clear();
	_cant_claves = 0;

	// Creo una tabla nueva con el doble de tamaño
	_tabla = vector<list<Asociacion>>(_tam);

	// Inserto las claves de la tabla original
	for (Asociacion a : asociaciones) {
		definir(a.clave, a.valor);
	}
}

/* Busca en el diccionario el significado de la clave clav.
 * - clav : clave a buscar
 * Devuelve el significado de clav.
 */
template<class V>
V& DiccHash<V>::significado(const string& clav) {
	return _obtener(clav)->valor;
}

/* Borra la clave del diccionario
 * - clav : clave a borrar
 *
 * Precondición: clav está definida en el diccionario */
template<class V>
void DiccHash<V>::borrar(const string& clav) {
	int clav_hash = fn_hash(clav);
	list<Asociacion> &asociaciones = _tabla[clav_hash];

	for (auto it=asociaciones.begin(); it!=asociaciones.end(); ++it) {
		if(it->clave == clav) {
			asociaciones.erase(it);
			_cant_claves--;
			break;
		}
	}
}

/* Devuelve la cantidad de claves definidas en el diccionario. */
template<class V>
unsigned int DiccHash<V>::cantClaves() const {
	return _cant_claves;
}

/* Devuelve el conjunto de claves del diccionario. */
template<class V>
set<string> DiccHash<V>::claves() const {
	set<string> claves;

	vector<Asociacion> asociaciones = _asociaciones();

	for (Asociacion asociacion : asociaciones) {
		claves.insert(asociacion.clave);
	}

	return claves;
}

template <class V>
vector<typename DiccHash<V>::Asociacion> DiccHash<V>::_asociaciones() const {
	vector<Asociacion> asociaciones;

	for (list<Asociacion> as : _tabla) {
		for (Asociacion a : as) {
			asociaciones.push_back(a);
		}
	}

	return asociaciones;
}

/* SÓLO PARA TESTING
 *
 * Devuelve el factor de carga de la tabla de hash.
 * Factor de carga : cantidad de claves definidas / tamaño de la tabla.
 */
template<class V>
float DiccHash<V>::factorCarga() const {
	return _cant_claves / _tam;
}

/* SÓLO PARA TESTING
 * Devuelve la cantidad de colisiones que tiene el diccionario.
 *
 * Observación: si en una celda de la tabla conviven n elementos,
 * hay n * (n - 1) / 2 colisiones en esa celda.
 */
template<class V>
unsigned int DiccHash<V>::colisiones() const {
	unsigned int suma = 0;
	for (int i = 0; i < _tam; i++) {
		suma += _tabla[i].size() * (_tabla[i].size() - 1) / 2;
	}
	return suma;
}

/* Función de hash.
 * Recordar usar "hash = hash % _tam".
 * (El operador "%" calcula el resto en la división o "módulo").
 * Devuelve la posición de la tabla asociada a la clave dada.
 */
template<class V>
unsigned int DiccHash<V>::fn_hash(const string& str) const {
	// Función de hash de ejemplo de la clase.
	int hash = 0;
	for (char c : str) {
		hash = hash*131 + int(c);
	}
	return hash % _tam;
}

