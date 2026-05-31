cmake_minimum_required(VERSION 3.32)
project(morecmath)
add_library(morecmath)
target_sources(morecmath
    PUBLIC_HEADER
        mathFuncs/morecmath/funcs.cpp
    PUBLIC_HEADER FILE_SET HEADER
    BASE_DIRS CMAKE_CURRENT_SOURCE_DIR 
    FILES mathFuncs/morecmath/funcs.hpp
)
install(TARGETS morecmath LOCATION lib FILE_SET)
# Make project, add library, define sources and how to interface, install