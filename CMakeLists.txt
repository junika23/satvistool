cmake_minimum_required(VERSION 3.2.2)

project(satvistool VERSION 1.0.0)

OPTION(SHOW_DURATION "Show duration" OFF)
OPTION(BUILD_CATCH "Build catch tests" ON)

if (SHOW_DURATION)
    add_definitions(-DSHOW_DURATION)
endif()

set(SOURCE main.cpp)
aux_source_directory(common SRC_COMMON)
aux_source_directory(utils SRC_UTILS)
if (BUILD_CATCH)
    add_subdirectory(test)
endif()

list(APPEND ALL_FILES
    ${SOURCE}
    ${SRC_COMMON}
    ${SRC_UTILS})

set(CMAKE_CXX11_EXTENSION_COMPILE_OPTION "-std=gnu++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CMAKE_CXX11_EXTENSION_COMPILE_OPTION}")

add_executable(satvistool ${ALL_FILES})
