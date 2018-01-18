
cmake_minimum_required(VERSION 2.8.12)

set(LIBRARY_NAME utils)
file(GLOB interface_SRC enums_parser.h str_conversion.h)

add_protozoo_library(${LIBRARY_NAME} "${interface_SRC}" "")
