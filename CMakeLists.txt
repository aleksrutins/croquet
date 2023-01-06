cmake_minimum_required(VERSION 3.20)

project(crutches VERSION 0.0.1 LANGUAGES C)
include(FetchContent)

FetchContent_Declare(
    metalang99
    URL https://github.com/Hirrolot/metalang99/archive/refs/tags/v1.13.2.tar.gz
)

FetchContent_MakeAvailable(metalang99)


FetchContent_Declare(
    interface99
    URL https://github.com/Hirrolot/interface99/archive/refs/tags/v1.0.0.tar.gz # v1.2.3
)

FetchContent_MakeAvailable(interface99)

add_library(crutches SHARED
    src/main.c
)

target_include_directories(crutches PUBLIC include)


target_link_libraries(crutches metalang99)

target_link_libraries(crutches interface99)

# Disable full macro expansion backtraces for Metalang99.
if(CMAKE_C_COMPILER_ID STREQUAL "Clang")
  target_compile_options(crutches PRIVATE -fmacro-backtrace-limit=1)
elseif(CMAKE_C_COMPILER_ID STREQUAL "GNU")
  target_compile_options(crutches PRIVATE -ftrack-macro-expansion=0)
endif()

add_executable(crutches-test
    test/main.c
)

target_link_libraries(crutches-test crutches)