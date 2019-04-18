#ifndef MAPA_H
#define MAPA_H

typedef int Direccion;

#define NORTE   0
#define ESTE    1
#define SUR     2
#define OESTE   3

template <class T>
class Mapa {
public:
	// Constructor:
	// Crea un mapa de las dimensiones indicadas.
	// Cada coordenada del mapa almacena un valor de tipo T.
	// Cada coordenada del mapa se inicializa utilizando el constructor
	// por defecto de T.
	//
	// Las coordenadas son de la forma (x, y)
	// donde 0 <= x < ancho
	//       0 <= y < alto.
	//
	// El cursor empieza ubicado sobre la coordenada (0, 0).
	//
	// Precondición: ancho > 0 && alto > 0
	Mapa(int ancho, int alto, const T& def);

	// Devuelve el ancho del mapa.
	int ancho() const;

	// Devuelve el alto del mapa.
	int alto() const;

	// Devuelve una referencia al valor ubicado en la
	// posición del cursor.
	T& valor();

	// Mueve el cursor hacia la dirección indicada.
	// El resultado es el de aplicar el siguiente desplazamiento
	// a la posición actual del cursor:
	//   norte --> (0, +1)
	//   este  --> (+1, 0)
	//   sur   --> (0, -1)
	//   oeste --> (-1, 0)
	// Si la coordenada queda fuera de los límites del mapa, se
	// ajusta utilizando aritmética modular.
	//
	// P.ej. si el tablero es de 100x100
	// la coordenada al este de (99, 3) es (0, 3).
	void mover(Direccion direccion);

	// Constructor por copia
	Mapa(const Mapa& otro);

	// Destructor
	~Mapa();

	// Operador de asignación
	Mapa& operator=(const Mapa& otro);
private:
	// NOTA:
	// En este ejercicio no está permitido usar vector ni
	// otras clases de la STL. El objetivo es hacerlo a mano
	// usando punteros.

	struct _Coordenada {
		int x;
		int y;
	};

	_Coordenada _obtener_desplazamiento(Direccion d);
	_Coordenada _make_coord(int x, int y);
	T** _grilla;
	int _ancho;
	int _alto;

	_Coordenada _cursor;
};

template <class T>
typename Mapa<T>::_Coordenada Mapa<T>::_make_coord(int x, int y) {
	_Coordenada c;
	c.x = x;
	c.y = y;

	return c;
}

template <class T>
Mapa<T>::Mapa(int ancho, int alto, const T& def) {

	// El cursor comienza en (0, 0)
	_cursor = _make_coord(0, 0);

	_ancho = ancho;
	_alto = alto;

	_grilla = new T*[ancho];

	for (int i = 0; i < ancho; i++) {
		_grilla[i] = new T[alto];

		for (int j = 0; j < alto; j++) {
			_grilla[i][j] = def;
		}
	}
}

template <class T>
int Mapa<T>::ancho() const {
	return _ancho;
}

template <class T>
int Mapa<T>::alto() const {
	return _alto;
}

template <class T>
T& Mapa<T>::valor() {
	return _grilla[_cursor.x][_cursor.y];
}

template <class T>
typename Mapa<T>::_Coordenada Mapa<T>::_obtener_desplazamiento(Direccion direccion) {
	_Coordenada desplazamiento;
	// Si pudiese usar std usaría un mapa.
	switch(direccion){
		case NORTE:
			desplazamiento = _make_coord(0, 1);
			break;
		case SUR:
			desplazamiento = _make_coord(0, -1);
			break;
		case ESTE:
			desplazamiento = _make_coord(1, 0);
			break;
		case OESTE:
			desplazamiento = _make_coord(-1, 0);
			break;
		default:
			desplazamiento = _make_coord(0, 0);
	}

	return desplazamiento;
}

int mod(int a, int b) {
	if (a < 0) {
		while (a <= b) {
			a += b;
		}
	}
	if (a >= 0) {
		while (a >= b) {
			a -= b;
		}
	}

	return a;
}

template <class T>
void Mapa<T>::mover(Direccion direccion) {
	_Coordenada desp = _obtener_desplazamiento(direccion);

	_cursor.x = mod((_cursor.x + desp.x), _ancho);
	_cursor.y = mod((_cursor.y + desp.y), _alto);
}


template <class T>
Mapa<T>::Mapa(const Mapa<T>& otro) :
	Mapa(otro._ancho, otro._alto, otro._grilla[otro._cursor.x][otro._cursor.y]){
	for(int i = 0; i < _ancho; i++) {
		for (int j = 0; j < _alto; j++) {
			_grilla[i][j] = otro._grilla[i][j];
		}
	}
	_cursor = otro._cursor;
}

template <class T>
Mapa<T>::~Mapa() {
	for (int i = 0; i < _ancho; i++) {
		delete[] _grilla[i];
	}
	delete[] _grilla;
}

// Otra forma sería definir el operador= y crear un constructor vacío privado, y así se usaría en el constructor por copia.
template <class T>
Mapa<T>& Mapa<T>::operator=(const Mapa<T>& otro) {

	T** tmp = nullptr;
	if (_ancho != otro._ancho) {
		tmp = _grilla;
		_grilla = new T*[otro._ancho];
	}

	for(int i = 0; i < _ancho; i++) {
		for (int j = 0; j < _alto; j++) {
			if (_alto != otro._alto) {
				delete[] _grilla[i];
				_grilla[i] = new T[_alto];
			}
			_grilla[i][j] = otro._grilla[i][j];
		}
	}
	_cursor = otro._cursor;

	if (tmp != nullptr) {
		delete[] tmp;
	}
	return *this;
}

#endif
