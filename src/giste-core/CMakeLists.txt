
project(Giste)
cmake_minimum_required(VERSION 2.8.12)

file(GLOB interface_SRC config.h) # TODO: enumerate interface files
file(GLOB headers_SRC "*.h" "*.hpp")
file(GLOB impl_SRC "*.cpp")

add_library(core ${impl_SRC} ${headers_SRC})
generate_export_header(core)
set_target_properties(core PROPERTIES 
                      LINKER_LANGUAGE CXX
                      PUBLIC_HEADER "${interface_SRC}")
target_include_directories(core PUBLIC ${CMAKE_CURRENT_BINARY_DIR})

install(TARGETS core
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin
        PUBLIC_HEADER DESTINATION include/core)

