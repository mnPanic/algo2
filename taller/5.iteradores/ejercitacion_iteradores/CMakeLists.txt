cmake_minimum_required(VERSION 3.5)
project(algo2_labo_clase5)

set(CMAKE_CXX_STANDARD 14)

include_directories(src/ tests/google-test)
add_subdirectory(tests/google-test)

foreach(ejN RANGE 1 7)
    add_executable(ej${ejN} tests/algo_tests.cpp)
    target_compile_definitions(ej${ejN} PUBLIC EJ=${ejN})
    target_link_libraries(ej${ejN} gtest gtest_main)
endforeach(ejN)
