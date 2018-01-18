
cmake_minimum_required(VERSION 2.8.12)

set(LIBRARY_NAME engine)
file(GLOB interface_SRC config.h)
set(LINK_LIBRARIES_LIST core ${CONAN_LIBS_YAML-CPP} ${CONAN_LIBS_BOOST.FILESYSTEM} ${CONAN_LIBS_BOOST.SYSTEM})

add_protozoo_library(${LIBRARY_NAME} "${interface_SRC}" "${LINK_LIBRARIES_LIST}")

# CLI
add_subdirectory(cli)
