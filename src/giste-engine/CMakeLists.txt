
project(Giste)
cmake_minimum_required(VERSION 2.8.12)

file(GLOB interface_SRC engine.h) # TODO: enumerate interface files
file(GLOB headers_SRC "*.h" "*.hpp")
file(GLOB impl_SRC "*.cpp")

add_library(engine ${impl_SRC} ${headers_SRC})
generate_export_header(engine)
set_target_properties(engine PROPERTIES 
                      LINKER_LANGUAGE CXX
                      PUBLIC_HEADER "${interface_SRC}")
target_include_directories(engine PUBLIC ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(engine core)

install(TARGETS engine
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin
        PUBLIC_HEADER DESTINATION include/engine)

if(BUILD_CLI)
	add_subdirectory(cli)
endif()

