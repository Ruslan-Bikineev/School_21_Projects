# CMakeLists.txt
cmake_minimum_required(VERSION 3.22)
find_program(VALGRIND_EXECUTABLE valgrind)
project(CPP2_s21_containers-4 CXX)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)

# Define the main executable target
# add_executable(CPP2_s21_containers-4 
#         src/main.cc 

# target_include_directories(CPP2_s21_containers-4 PRIVATE src)
# target_link_libraries(CPP2_s21_containers-4 PRIVATE -lm)

# if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU") #C++
#     target_compile_options(CPP2_s21_containers-4 PRIVATE
#         -Wall
#         -Wextra
#         -Werror
#     )
# endif ()

# Define the test executable target
include_directories(src/tests)
enable_testing()
add_executable(CPP2_s21_containers-4_tests 
    src/tests/list_tests.cc
    src/tests/map_tests.cc
    src/tests/queue_tests.cc    
    src/tests/set_tests.cc
    src/tests/stack_tests.cc
    src/tests/vector_tests.cc
    )

target_link_libraries(CPP2_s21_containers-4_tests PRIVATE gtest gtest_main)
# Include Google Test
include(GoogleTest)
gtest_discover_tests(CPP2_s21_containers-4_tests)