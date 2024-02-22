# CMakeLists.txt
cmake_minimum_required(VERSION 3.22)
find_program(VALGRIND_EXECUTABLE valgrind)
project(CPP1_s21_matrixplus-1 CXX)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)

# Define the main executable target
# add_executable(CPP1_s21_matrixplus-1 
#         src/main.cc 
#         src/s21_matrix_oop.cc)

# target_include_directories(CPP1_s21_matrixplus-1 PRIVATE src)
# target_link_libraries(CPP1_s21_matrixplus-1 PRIVATE -lm)

# if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU") #C++
#     target_compile_options(CPP1_s21_matrixplus-1 PRIVATE
#         -Wall
#         -Wextra
#         -Werror
#     )
# endif ()

# Define the test executable target
include_directories(src/tests)
enable_testing()
add_executable(CPP1_s21_matrixplus-1_tests 
    src/tests/set_get_tests.cc
    src/tests/mul_matrix_tests.cc
    src/tests/calc_complements_tests.cc    
    src/tests/sum_tests.cc
    src/tests/transpose_tests.cc
    src/tests/constructor_tests.cc
    src/tests/inverse_matrix_tests.cc
    src/tests/eq_tests.cc
    src/tests/sub_tests.cc
    src/tests/determinant_tests.cc
    src/tests/mul_number_tests.cc
    src/tests/move_copy_tests.cc
    src/s21_matrix_oop.cc
    )

target_link_libraries(CPP1_s21_matrixplus-1_tests PRIVATE gtest gtest_main)
# Include Google Test
include(GoogleTest)
gtest_discover_tests(CPP1_s21_matrixplus-1_tests)