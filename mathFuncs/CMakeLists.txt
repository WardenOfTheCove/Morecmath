cmake_minimum_required(VERSION 3.15)
project(morecmath CXX)




add_library(morecmath src/funcs.cpp)
target_include_directories(morecmath PUBLIC include)



set_target_properties(morecmath PROPERTIES PUBLIC_HEADER "include/funcs.hpp")
install(TARGETS morecmath)
