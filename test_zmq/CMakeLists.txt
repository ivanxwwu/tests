cmake_minimum_required(VERSION 3.7)
project(test_zmq)

set(CMAKE_CXX_STANDARD 11)
find_library(LIBZMQ
        PATH /usr/local/lib
        NAMES zmq)

macro(add_cxx_example_target EXAMPLE_TARGET)
    add_executable("example_${EXAMPLE_TARGET}" "example_${EXAMPLE_TARGET}.cpp")
    target_link_libraries("example_${EXAMPLE_TARGET}" ${LIBZMQ})
endmacro(add_cxx_example_target)

macro(add_c_example_target EXAMPLE_TARGET)
    add_executable("example_${EXAMPLE_TARGET}" "example_${EXAMPLE_TARGET}.c")
    target_link_libraries("example_${EXAMPLE_TARGET}" ${LIBZMQ})
endmacro(add_c_example_target)

add_c_example_target(hwserver)
add_cxx_example_target(hwserver2)
add_c_example_target(hwclient)
add_c_example_target(version)
add_c_example_target(wuserver)
add_c_example_target(wuclient)

