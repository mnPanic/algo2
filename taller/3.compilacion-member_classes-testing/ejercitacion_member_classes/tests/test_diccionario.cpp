#include "gtest-1.8.1/gtest.h"
#include "../src/Diccionario.h"

#if EJ >= 4
TEST(diccionario, ej4_def) {
	Diccionario d;
	ASSERT_FALSE(d.def(1));
	ASSERT_FALSE(d.def(2));
	ASSERT_FALSE(d.def(3));
	d.definir(1, 10);
	ASSERT_TRUE(d.def(1));
	ASSERT_FALSE(d.def(2));
	ASSERT_FALSE(d.def(3));
	d.definir(2, 20);
	ASSERT_TRUE(d.def(1));
	ASSERT_TRUE(d.def(2));
	ASSERT_FALSE(d.def(3));
}

TEST(diccionario, ej4_obtener) {
	Diccionario d;
	d.definir(1, 4);
	ASSERT_EQ(d.obtener(1), 4);
	d.definir(1, 44);
	ASSERT_EQ(d.obtener(1), 44);
	d.definir(2, 5);
	ASSERT_EQ(d.obtener(1), 44);
	ASSERT_EQ(d.obtener(2), 5);
	d.definir(1, 444);
	ASSERT_EQ(d.obtener(1), 444);
	ASSERT_EQ(d.obtener(2), 5);
	d.definir(2, 55);
	ASSERT_EQ(d.obtener(1), 444);
	ASSERT_EQ(d.obtener(2), 55);
}
#endif

#if EJ >= 5

TEST(diccionario, ej5_borrar) {
	Diccionario d;

	d.definir(1, 4);
	d.definir(2, 5);
	d.definir(6, 11);

	// Borro una clave existente y verifico que:
	// - NO siga existiendo
	// - El resto si
	d.borrar(1);
	ASSERT_FALSE(d.def(1));
	ASSERT_EQ(d.obtener(2), 5);
	ASSERT_EQ(d.obtener(6), 11);

	// Borro una clave inexistente y me aseguro que siga igual
	d.borrar(12312312);
	ASSERT_EQ(d.obtener(2), 5);
	ASSERT_EQ(d.obtener(6), 11);
}

#endif

#if EJ >= 6


TEST(diccionario, ej6_claves) {
	// Voy a hacer un test sobreespecificado que tenga el orden normal.
	Diccionario d;

	d.definir(1, 4);
	d.definir(2, 5);
	d.definir(6, 11);

	ASSERT_EQ(d.claves(), std::vector<Clave>({1, 2, 6}));
}

#endif

#if EJ >= 7

TEST(diccionario, ej7_claves) {
	Diccionario d1;
	d1.definir(2, 4);
	d1.definir(5, 6);
	d1.definir(1, 123);

	Diccionario d2;
	d2.definir(5, 6);
	d2.definir(1, 1234);

	// No deberían ser iguales
	ASSERT_FALSE(d1 == d2);

	d1.borrar(2);
	// Todavía tampoco
	ASSERT_FALSE(d1 == d2);

	d1.definir(1, 1234);
	// Deberían ser iguales
	ASSERT_TRUE(d1 == d2);
}

#endif

#if EJ >= 8

#endif

