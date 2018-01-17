
cmake_minimum_required(VERSION 2.8.12)

set(LIBRARY_NAME protozoo_pln)
file(GLOB interface_SRC)
add_definitions(-DPROTOZOO_PLUGIN)

## Common for every library
file(GLOB all_sources "*.h" "*.hpp" "*.cpp")

get_filename_component(LIBRARY_DIRNAME ${CMAKE_CURRENT_LIST_DIR} NAME)

add_library(${LIBRARY_NAME} ${all_sources})
target_link_libraries(${LIBRARY_NAME} core)
generate_export_header(${LIBRARY_NAME})
set_target_properties(${LIBRARY_NAME} PROPERTIES 
                      LINKER_LANGUAGE CXX
                      PUBLIC_HEADER "${interface_SRC}")
target_include_directories(${LIBRARY_NAME} PUBLIC ${CMAKE_CURRENT_BINARY_DIR})

install(TARGETS ${LIBRARY_NAME}
        RUNTIME DESTINATION ${CMAKE_INSTALL_PLUGINS}
        PUBLIC_HEADER DESTINATION include/${LIBRARY_DIRNAME})
install(FILES $<TARGET_PDB_FILE:${LIBRARY_NAME}> DESTINATION ${CMAKE_INSTALL_PLUGINS} OPTIONAL)
