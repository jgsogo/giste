
cmake_minimum_required(VERSION 2.8.12)

set(LIBRARY_NAME core)
file(GLOB interface_SRC config.h)
set(LINK_LIBRARIES_LIST utils ${CONAN_LIBS_YAML-CPP} ${CONAN_LIBS_BOOST.FILESYSTEM} ${CONAN_LIBS_BOOST.SYSTEM})

add_protozoo_library(${LIBRARY_NAME} "${interface_SRC}" "${LINK_LIBRARIES_LIST}")
