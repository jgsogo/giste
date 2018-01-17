
project(GisteEngineCLI)
cmake_minimum_required(VERSION 2.8.12)

set(APP_NAME ${CMAKE_PROJECT_NAME}-engine-cli)
message(STATUS "Generate App: ${APP_NAME}")

# Dependencies
# find_package(Boost COMPONENTS program_options filesystem system REQUIRED)
# Not working with bincrafters, see issue: https://github.com/bincrafters/community/issues/26

file(GLOB all_sources "*.h" "*.hpp" "*.cpp")

add_executable(${APP_NAME} ${all_sources})
set_target_properties(${APP_NAME} PROPERTIES LINKER_LANGUAGE CXX
                                             VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_INSTALL_PREFIX}/bin")
target_include_directories(${APP_NAME} PUBLIC ${Boost_INCLUDE_DIR})
target_link_libraries(${APP_NAME} core ${CONAN_LIBS})

install(TARGETS ${APP_NAME} COMPONENT executable
        DESTINATION bin)
install(FILES $<TARGET_PDB_FILE:${APP_NAME}> DESTINATION bin OPTIONAL)

