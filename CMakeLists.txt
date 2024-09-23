cmake_minimum_required(VERSION 3.23)
project(1)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)

add_executable(1
        main.cpp
        main.h
        dialog.cpp
        dialog.h
        functions.cpp
        functions.h
        overloading.cpp
        additional.cpp
        additional.h)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip
)

# Для быстрее собираемых тестов можно включить опцию gtest_force_shared_crt, если используется Windows.
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(main_app
        main.cpp
        main.h
        dialog.cpp
        dialog.h
        functions.cpp
        functions.h
        overloading.cpp
        additional.cpp
        additional.h)

add_executable(tests
        testfile.cpp
        functions.cpp
        functions.h
        dialog.cpp
        dialog.h
        overloading.cpp
        additional.cpp
        additional.h)

target_link_libraries(tests gtest gtest_main)

add_test(NAME all_tests COMMAND tests)


