

project(Giste)
cmake_minimum_required(VERSION 2.8.12)

# Require C++14 (at least)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14") # Needed for Travis CI
add_compile_options(-std=c++14) # CMake 2.8.12 or newer

# Conan required
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

# Files in subdirectories (Visual Studio IDE)
set_property(GLOBAL PROPERTY USE_FODERS ON)

# Global configuration
add_definitions(-Wfatal-errors)

# All sources will be under this directory ('src')
add_subdirectory(src)
include_directories("${CMAKE_CURRENT_LIST_DIR}/src")

option(BUILD_TEST "Build tests for Giste project" OFF)
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

