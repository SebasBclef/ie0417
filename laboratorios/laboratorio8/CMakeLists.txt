cmake_minimum_required(VERSION 3.10)
project(AuthenticationTests)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/release-1.11.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Ejecutable para tests de autenticación
add_executable(test_authentication
  test_authentication.cpp
)

target_link_libraries(test_authentication
  gtest
  gtest_main
  gmock
)

# Ejecutable para tests de calculadora (ajusta los archivos según tu código)
add_executable(test_calculator
  test_calculator.cpp
  # otros archivos fuente necesarios aquí
)

target_link_libraries(test_calculator
  gtest
  gtest_main
  gmock
)

enable_testing()

add_test(NAME test_authentication COMMAND test_authentication)
add_test(NAME test_calculator COMMAND test_calculator)
