cmake_minimum_required(VERSION 3.10)

# set the project name
project(gc-bas)

set(MY_SOURCES  test_garbling-scheme.cpp)

add_subdirectory(emp-tool)
find_package(OpenSSL REQUIRED)
include_directories(${OPENSSL_INCLUDE_DIR})


# add the executable
add_executable(test_garbling-scheme ${MY_SOURCES})


target_link_libraries(test_garbling-scheme ${OPENSSL_LIBRARIES})
target_link_libraries(test_garbling-scheme emp-tool)

target_include_directories(test_garbling-scheme PUBLIC . emp-tool)

set(CMAKE_FOLDER emp-tool/)
include(emp-tool/cmake/emp-base.cmake)
set(CMAKE_FOLDER .)


