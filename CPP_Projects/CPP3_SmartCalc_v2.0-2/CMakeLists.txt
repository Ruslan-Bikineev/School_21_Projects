# CMakeLists.txt
cmake_minimum_required(VERSION 3.22)
find_program(VALGRIND_EXECUTABLE valgrind)
project(CPP3_SmartCalc_v2.0-2 CXX)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)

# Define the main executable target
add_executable(CPP3_SmartCalc_v2.0-2 
src/main.cc 
src/mvc/controller.cc 
src/mvc/model.cc 
src/mvc/view.cc 
)
target_include_directories(CPP3_SmartCalc_v2.0-2 PRIVATE src)
target_link_libraries(CPP3_SmartCalc_v2.0-2 PRIVATE -lm)

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU") #C++
target_compile_options(CPP3_SmartCalc_v2.0-2 PRIVATE
-Wall
-Wextra
-Werror
)
endif ()

# Define the test executable target
include_directories(src/tests)
enable_testing()
add_executable(CPP3_SmartCalc_v2.0-2_tests 
src/tests/calc_tests.cc
src/mvc/controller.cc 
src/mvc/model.cc 
src/mvc/view.cc 
)

target_link_libraries(CPP3_SmartCalc_v2.0-2_tests PRIVATE gtest gtest_main)
# Include Google Test
include(GoogleTest)
gtest_discover_tests(CPP3_SmartCalc_v2.0-2_tests)