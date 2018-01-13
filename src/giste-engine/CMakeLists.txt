
project(Giste)
cmake_minimum_required(VERSION 2.8.12)

file(GLOB interface_SRC) # TODO: enumerate interface files
file(GLOB headers_SRC "*.h" "*.hpp")
file(GLOB impl_SRC "*.cpp")

add_library(engine ${impl_SRC} ${headers_SRC})
set_target_properties(engine PROPERTIES LINKER_LANGUAGE CXX)

if(BUILD_CLI)
	add_subdirectory(cli)
endif()



