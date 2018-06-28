cmake_minimum_required(VERSION 3.2.2)

project(satvistool_test VERSION 1.0.0)

set(SOURCE test.cpp)
set(SRC_COMMON ../common/SatTimestamp.cpp ../common/SatTimestamp.h)
set(SRC_UTILS ../utils/FileHelper.cpp ../utils/FileHelper.h ../utils/AlgoHelper.cpp ../utils/AlgoHelper.h)

set(CMAKE_CXX11_EXTENSION_COMPILE_OPTION "-std=gnu++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CMAKE_CXX11_EXTENSION_COMPILE_OPTION}")

list(APPEND ALL_FILES
    ${SOURCE}
    ${SRC_COMMON}
    ${SRC_UTILS})

add_executable(satvistool_test ${ALL_FILES})
