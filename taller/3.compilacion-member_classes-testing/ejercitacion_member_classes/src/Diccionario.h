#ifndef __DICCIONARIO_H__
#define __DICCIONARIO_H__

#include <vector>

typedef int Clave;
typedef int Valor;

class Diccionario {
public:
	Diccionario();
	void definir(Clave k, Valor v);
	bool def(Clave k) const;
	Valor obtener(Clave k) const;
	
private:
	struct Asociacion {
		Clave clave;
		Valor valor;
	};

	int index_of(Clave k) const;

	std::vector<Asociacion> _asociaciones;
};

#endif /*__DICCIONARIO_H__*/
