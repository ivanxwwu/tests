cmake_minimum_required(VERSION 3.7)
project(test_ossl)

set(CMAKE_CXX_STANDARD 11)

add_executable(server server.cpp)
add_executable(client client.cpp)
target_link_libraries(server -lssl)
target_link_libraries(client -lssl)

macro(add_example_target EXAMPLE_TARGET)
    add_executable("example_${EXAMPLE_TARGET}" "example_${EXAMPLE_TARGET}.cpp")
    target_link_libraries("example_${EXAMPLE_TARGET}" ssl)
    target_link_libraries("example_${EXAMPLE_TARGET}" crypto)
endmacro()

add_example_target(base64)
add_example_target(hash)
add_example_target(test)