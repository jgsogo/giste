
project(protozoo)
cmake_minimum_required(VERSION 2.8.12)

# Project version info
set(VERSION_MAJOR 0)
set(VERSION_MINOR 0)
set(VERSION_MICRO 0)
set(VERSION_STAGE "alpha")
set(VERSION_STAGE_NUM 0)

# Require C++14 (at least)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14") # Needed for Travis CI
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
add_compile_options(-std=c++14) # CMake 2.8.12 or newer

# Conan required
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

include(cmake/protozoo.cmake)

# Install prefix
set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_LIST_DIR}/install" CACHE INTERNAL "Default path to install")
message(STATUS "Installation folder is '${CMAKE_INSTALL_PREFIX}'")
set(CMAKE_INSTALL_PLUGINS "${CMAKE_INSTALL_PREFIX}/plugins" CACHE INTERNAL "Default path to plugins")

# Files in subdirectories (Visual Studio IDE)
set_property(GLOBAL PROPERTY USE_FODERS ON)

# Global configuration
# add_definitions(-Wfatal-errors)

# Options
option(BUILD_SHARED_LIBS "Build the shared library" ON)
option(BUILD_CLI "Build command line interfaces" ON)
option(BUILD_TEST "Build tests for project" OFF)
OPTION(SPDLOG_DEBUG_ON "Enable debug logging" OFF) # Disabled by default
IF(SPDLOG_DEBUG_ON)
    ADD_DEFINITIONS(-DSPDLOG_DEBUG_ON)
ENDIF(SPDLOG_DEBUG_ON)

# All sources will be under this directory ('src')
include_directories("${CMAKE_CURRENT_LIST_DIR}/src")
add_subdirectory(src)

if(BUILD_TEST)
	enable_testing()
	if (UNIX)
		add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1
		                  ${CMAKE_CTEST_COMMAND} --verbose
		                  WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
	else()
		add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1
		                  ${CMAKE_CTEST_COMMAND} -C $<CONFIG> --verbose
		                  WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
	endif()

	add_subdirectory(tests)
endif()

