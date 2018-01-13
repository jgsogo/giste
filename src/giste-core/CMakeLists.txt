
project(Giste)
cmake_minimum_required(VERSION 2.8.12)

file(GLOB interface_SRC) # TODO: enumerate interface files
file(GLOB headers_SRC "*.h" "*.hpp")
file(GLOB impl_SRC "*.cpp")

add_library(core ${impl_SRC} ${headers_SRC})
set_target_properties(core PROPERTIES LINKER_LANGUAGE CXX)



