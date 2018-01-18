
cmake_minimum_required(VERSION 2.8.12)

set(LIBRARY_NAME protozoo_pln)
file(GLOB interface_SRC)
set(LINK_LIBRARIES_LIST core)

add_protozoo_plugin(${LIBRARY_NAME} "${interface_SRC}" "${LINK_LIBRARIES_LIST}")
