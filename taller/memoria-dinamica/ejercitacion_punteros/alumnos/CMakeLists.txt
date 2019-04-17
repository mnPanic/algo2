cmake_minimum_required(VERSION 3.5)
project(algo2_labo_clase4)

set(CMAKE_CXX_STANDARD 11)

include_directories(src/ tests/google-test)
add_subdirectory(tests/google-test)

# Ejercicios
add_executable(ej1 tests/mapa_tests.cpp)
add_executable(ej2 tests/mapa_tests.cpp)
add_executable(ej3 tests/mapa_tests.cpp)
add_executable(ej4 tests/mapa_tests.cpp)
add_executable(ej5 tests/mapa_tests.cpp)

# Definiciones por target
target_compile_definitions(ej1 PUBLIC EJ=1)
target_compile_definitions(ej2 PUBLIC EJ=2)
target_compile_definitions(ej3 PUBLIC EJ=3)
target_compile_definitions(ej4 PUBLIC EJ=4)
target_compile_definitions(ej5 PUBLIC EJ=5)

# Necesitamos asociar los archivos del framework de testing
target_link_libraries(ej1 gtest gtest_main)
target_link_libraries(ej2 gtest gtest_main)
target_link_libraries(ej3 gtest gtest_main)
target_link_libraries(ej4 gtest gtest_main)
target_link_libraries(ej5 gtest gtest_main)

# Targets para correr valgrind

add_custom_target(ej3_correrValgrind
        valgrind --leak-check=full -v ./ej3 2>&1
        DEPENDS ej3)

add_custom_target(ej4_correrValgrind
        valgrind --leak-check=full -v ./ej4 2>&1
        DEPENDS ej4)

add_custom_target(ej5_correrValgrind
        valgrind --leak-check=full -v ./ej5 2>&1
        DEPENDS ej5)

