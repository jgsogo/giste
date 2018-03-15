

function(_add_protozoo_target LIBRARY_NAME TYPE PUBLIC_HEADERS LINK_LIBRARIES_LIST)
    ## Common for every library
    file(GLOB all_sources "*.h" "*.hpp" "*.cpp")

    if(BUILD_SHARED_LIBS)
        configure_file(${CMAKE_TEMPLATES_DIR}/dll_load.cpp.template dll_load.cpp)
        list(APPEND all_sources dll_load.cpp)
    endif()

    get_filename_component(LIBRARY_DIRNAME ${CMAKE_CURRENT_LIST_DIR} NAME)

    add_library(${LIBRARY_NAME} ${TYPE} ${all_sources})
    target_link_libraries(${LIBRARY_NAME} ${LINK_LIBRARIES_LIST})
    generate_export_header(${LIBRARY_NAME})
    set_target_properties(${LIBRARY_NAME} PROPERTIES 
                          LINKER_LANGUAGE CXX
                          PUBLIC_HEADER "${PUBLIC_HEADERS}")
    target_include_directories(${LIBRARY_NAME} PUBLIC ${CMAKE_CURRENT_BINARY_DIR})
endfunction(_add_protozoo_target)


function(add_protozoo_library LIBRARY_NAME PUBLIC_HEADERS LINK_LIBRARIES_LIST)
    message("Add protozoo library: '${LIBRARY_NAME}'")
    _add_protozoo_target(${LIBRARY_NAME} "" "${PUBLIC_HEADERS}" "${LINK_LIBRARIES_LIST}")
    
    install(TARGETS ${LIBRARY_NAME} COMPONENT libraries
            ARCHIVE DESTINATION lib
            LIBRARY  DESTINATION lib
            RUNTIME DESTINATION bin
            PUBLIC_HEADER DESTINATION include/${LIBRARY_DIRNAME})
    if(MSVC AND BUILD_SHARED_LIBS)
        install(FILES $<TARGET_PDB_FILE:${LIBRARY_NAME}> DESTINATION bin OPTIONAL)
    endif()
endfunction(add_protozoo_library)


function(add_protozoo_plugin PLUGIN_NAME PUBLIC_HEADERS LINK_LIBRARIES_LIST)
    message("Add protozoo plugin: '${PLUGIN_NAME}'")
    add_definitions(-DPROTOZOO_PLUGIN)
    _add_protozoo_target(${PLUGIN_NAME} MODULE "" "${LINK_LIBRARIES_LIST}")
    
    install(TARGETS ${LIBRARY_NAME}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_PLUGINS}/lib
        LIBRARY DESTINATION ${CMAKE_INSTALL_PLUGINS}
        RUNTIME DESTINATION ${CMAKE_INSTALL_PLUGINS}
        PUBLIC_HEADER DESTINATION include/${LIBRARY_DIRNAME})
    if(MSVC)
        install(FILES $<TARGET_PDB_FILE:${LIBRARY_NAME}> DESTINATION ${CMAKE_INSTALL_PLUGINS} OPTIONAL)
    endif()
endfunction(add_protozoo_plugin)
