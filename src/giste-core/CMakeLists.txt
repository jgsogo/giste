
cmake_minimum_required(VERSION 2.8.12)

set(LIBRARY_NAME core)
file(GLOB interface_SRC config.h)


## Common for every library
file(GLOB all_sources "*.h" "*.hpp" "*.cpp")

get_filename_component(LIBRARY_DIRNAME ${CMAKE_CURRENT_LIST_DIR} NAME)

add_library(${LIBRARY_NAME} ${all_sources})
target_link_libraries(${LIBRARY_NAME} utils 
                                      ${CONAN_LIBS_YAML-CPP} 
                                      ${CONAN_LIBS_BOOST.FILESYSTEM}
                                      ${CONAN_LIBS_BOOST.SYSTEM})
generate_export_header(${LIBRARY_NAME})
set_target_properties(${LIBRARY_NAME} PROPERTIES 
                      LINKER_LANGUAGE CXX
                      PUBLIC_HEADER "${interface_SRC}")
target_include_directories(${LIBRARY_NAME} PUBLIC ${CMAKE_CURRENT_BINARY_DIR})

install(TARGETS ${LIBRARY_NAME} COMPONENT libraries
        ARCHIVE DESTINATION lib
        LIBRARY  DESTINATION lib
        RUNTIME DESTINATION bin
        PUBLIC_HEADER DESTINATION include/${LIBRARY_DIRNAME})
install(FILES $<TARGET_PDB_FILE:${LIBRARY_NAME}> DESTINATION bin OPTIONAL)
