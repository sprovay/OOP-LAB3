cmake_minimum_required(VERSION 3.10)
project(Lab3)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(main
    src/main.cpp
    src/point.cpp
    src/figure.cpp
    src/trapezoid.cpp
    src/rhombus.cpp
    src/pentagon.cpp
    src/array.cpp
)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.15.0
  TLS_VERIFY OFF
)

FetchContent_MakeAvailable(googletest)

add_executable(test
    test/test.cpp
    src/point.cpp
    src/figure.cpp
    src/trapezoid.cpp
    src/rhombus.cpp
    src/pentagon.cpp
    src/array.cpp
)

target_link_libraries(test gtest_main)