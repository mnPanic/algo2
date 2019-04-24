#include <gtest/gtest.h>
#include "Mapa.hpp"

using namespace std;

/**
 * Para correr valgrind:
 * - Seleccionar arriba a la derecha la opción "correrValgrind"
 * - Hacer build del proyecto (Ctrl+F9)
 */

#if EJ>=1

TEST(mapa_test, mapa_constructor_vacio) {
    Mapa<int> m(5, 10, 0);
    EXPECT_EQ(m.ancho(), 5);
    EXPECT_EQ(m.alto(), 10);
}

#endif

#if EJ>=2

TEST(mapa_test, mapa_valor) {
    Mapa<int> m(1, 1, 0);
    EXPECT_EQ(m.valor(), 0);
    m.valor()++;
    EXPECT_EQ(m.valor(), 1);
    m.valor()++;
    EXPECT_EQ(m.valor(), 2);
}

TEST(mapa_test, mapa_string) {
    Mapa<string> m(1, 1, "");
    EXPECT_EQ(m.valor(), "");
    m.valor() = "a";
    EXPECT_EQ(m.valor(), "a");
    m.valor() = m.valor() + m.valor();
    EXPECT_EQ(m.valor(), "aa");
}

TEST(mapa_test, mapa_mover_1x1) {
    Mapa<int> m(1, 1, 0);

    EXPECT_EQ(m.valor(), 0);
    m.valor()++;
    EXPECT_EQ(m.valor(), 1);
    m.mover(NORTE);
    EXPECT_EQ(m.valor(), 1);
    m.mover(ESTE);
    EXPECT_EQ(m.valor(), 1);
    m.mover(SUR);
    EXPECT_EQ(m.valor(), 1);
    m.mover(OESTE);
    EXPECT_EQ(m.valor(), 1);
}

TEST(mapa_test, mapa_mover_3x1) {
    Mapa<int> m(3, 1, 0);

    m.mover(ESTE);
    m.valor()++;
    m.mover(ESTE);
    m.valor()++;
    m.valor()++;
    m.mover(OESTE);
    m.mover(OESTE);

    EXPECT_EQ(m.valor(), 0);
    m.mover(ESTE);
    EXPECT_EQ(m.valor(), 1);
    m.mover(ESTE);
    EXPECT_EQ(m.valor(), 2);
    m.mover(OESTE);
    m.mover(OESTE);

    EXPECT_EQ(m.valor(), 0);
    m.mover(ESTE);
    EXPECT_EQ(m.valor(), 1);
    m.mover(ESTE);
    EXPECT_EQ(m.valor(), 2);
    m.mover(ESTE);

    EXPECT_EQ(m.valor(), 0);
    m.mover(ESTE);
    EXPECT_EQ(m.valor(), 1);
    m.mover(ESTE);
    EXPECT_EQ(m.valor(), 2);
    m.mover(ESTE);

    m.mover(SUR);
    EXPECT_EQ(m.valor(), 0);
    m.mover(ESTE);
    EXPECT_EQ(m.valor(), 1);
    m.mover(ESTE);
    EXPECT_EQ(m.valor(), 2);
    m.mover(ESTE);
    EXPECT_EQ(m.valor(), 0);

    m.mover(NORTE);
    EXPECT_EQ(m.valor(), 0);
    m.mover(OESTE);
    EXPECT_EQ(m.valor(), 2);
    m.mover(OESTE);
    EXPECT_EQ(m.valor(), 1);
    m.mover(OESTE);
    EXPECT_EQ(m.valor(), 0);
}

TEST(mapa_test, mapa_mover_1x3) {
    Mapa<int> m(1, 3, 0);

    m.mover(NORTE);
    m.valor()++;
    m.mover(NORTE);
    m.valor()++;
    m.valor()++;
    m.mover(NORTE);

    EXPECT_EQ(m.valor(), 0);
    m.mover(NORTE);
    EXPECT_EQ(m.valor(), 1);
    m.mover(NORTE);
    EXPECT_EQ(m.valor(), 2);
    m.mover(NORTE);

    EXPECT_EQ(m.valor(), 0);
    m.mover(SUR);
    EXPECT_EQ(m.valor(), 2);
    m.mover(SUR);
    EXPECT_EQ(m.valor(), 1);
    m.mover(SUR);

    EXPECT_EQ(m.valor(), 0);
    m.mover(ESTE);
    EXPECT_EQ(m.valor(), 0);
    m.mover(OESTE);
    EXPECT_EQ(m.valor(), 0);
    
    m.mover(NORTE);
    EXPECT_EQ(m.valor(), 1);
    m.mover(ESTE);
    EXPECT_EQ(m.valor(), 1);
    m.mover(OESTE);
    EXPECT_EQ(m.valor(), 1);

    m.mover(NORTE);
    EXPECT_EQ(m.valor(), 2);
    m.mover(ESTE);
    EXPECT_EQ(m.valor(), 2);
    m.mover(OESTE);
    EXPECT_EQ(m.valor(), 2);
}

TEST(mapa_test, mapa_mover_2x2) {
    Mapa<int> m(2, 2, 0);

    m.valor()++;
    m.mover(NORTE);
    m.valor()++;
    m.valor()++;
    m.mover(ESTE);
    m.valor()++;
    m.valor()++;
    m.valor()++;
    m.mover(SUR);
    m.valor()++;
    m.valor()++;
    m.valor()++;
    m.valor()++;
    m.mover(OESTE);

    EXPECT_EQ(m.valor(), 1);
    m.mover(OESTE);
    EXPECT_EQ(m.valor(), 4);
    m.mover(SUR);
    EXPECT_EQ(m.valor(), 3);
    m.mover(ESTE);
    EXPECT_EQ(m.valor(), 2);
    m.mover(NORTE);

    EXPECT_EQ(m.valor(), 1);
    m.mover(SUR);
    EXPECT_EQ(m.valor(), 2);
    m.mover(OESTE);
    EXPECT_EQ(m.valor(), 3);
    m.mover(NORTE);
    EXPECT_EQ(m.valor(), 4);
    m.mover(ESTE);

    EXPECT_EQ(m.valor(), 1);
}

#endif

#if EJ>=3

TEST(mapa_test, test_destructor) {
    Mapa<int> m(100, 100, 0);
    // Si se ejecuta con valgrind, no debería reportar
    // pérdida de memoria.
}

#endif

#if EJ>=4

TEST(mapa_test, mapa_copiar) {
    Mapa<int> m(3, 2, 0);

    m.valor() = 11;
    m.mover(ESTE);
    m.valor() = 21;
    m.mover(ESTE);
    m.valor() = 31;
    m.mover(OESTE);
    m.mover(OESTE);

    m.mover(NORTE);
    m.valor() = 12;
    m.mover(ESTE);
    m.valor() = 22;
    m.mover(ESTE);
    m.valor() = 32;

    Mapa<int> mm(m);
    ASSERT_EQ(mm.ancho(), m.ancho());
    ASSERT_EQ(mm.alto(), m.alto());
    ASSERT_EQ(mm.valor(), 32);
    mm.valor() = 42;
    ASSERT_EQ(m.valor(), 32);
    ASSERT_EQ(mm.valor(), 42);
    mm.mover(SUR);
    mm.mover(ESTE);
    ASSERT_EQ(mm.valor(), 11);
    ASSERT_EQ(m.valor(), 32);

    mm.mover(ESTE);
    ASSERT_EQ(mm.valor(), 21);
    mm.mover(ESTE);
    ASSERT_EQ(mm.valor(), 31);
    mm.mover(SUR);
    ASSERT_EQ(mm.valor(), 42);
    mm.mover(ESTE);
    ASSERT_EQ(mm.valor(), 12);
    mm.mover(ESTE);
    ASSERT_EQ(mm.valor(), 22);
}

#endif

#if EJ>=5

TEST(mapa_test, mapa_asignar) {
    Mapa<int> m(3, 2, 0);

    m.valor() = 11;
    m.mover(ESTE);
    m.valor() = 21;
    m.mover(ESTE);
    m.valor() = 31;
    m.mover(OESTE);
    m.mover(OESTE);

    m.mover(NORTE);
    m.valor() = 12;
    m.mover(ESTE);
    m.valor() = 22;
    m.mover(ESTE);
    m.valor() = 32;

    Mapa<int> mm(10, 10, 0);

    mm = m;
    ASSERT_EQ(mm.ancho(), m.ancho());
    ASSERT_EQ(mm.alto(), m.alto());
    ASSERT_EQ(mm.valor(), 32);
    mm.valor() = 42;
    ASSERT_EQ(m.valor(), 32);
    ASSERT_EQ(mm.valor(), 42);
    mm.mover(SUR);
    mm.mover(ESTE);
    ASSERT_EQ(mm.valor(), 11);
    ASSERT_EQ(m.valor(), 32);

    mm.mover(ESTE);
    ASSERT_EQ(mm.valor(), 21);
    mm.mover(ESTE);
    ASSERT_EQ(mm.valor(), 31);
    mm.mover(SUR);
    ASSERT_EQ(mm.valor(), 42);
    mm.mover(ESTE);
    ASSERT_EQ(mm.valor(), 12);
    mm.mover(ESTE);
    ASSERT_EQ(mm.valor(), 22);
}

#endif

