
project(GisteEngineCLI)
cmake_minimum_required(VERSION 2.8.12)

message(STATUS "Add giste-engine-cli")

# Dependencies
# find_package(Boost COMPONENTS program_options filesystem system REQUIRED)
# Not working with bincrafters, see issue: https://github.com/bincrafters/community/issues/26

file(GLOB headers_SRC "*.h" "*.hpp")
file(GLOB impl_SRC "*.cpp")

add_executable(${PROJECT_NAME} ${impl_SRC} ${headers_SRC})
set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(${PROJECT_NAME} PUBLIC ${Boost_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${CONAN_LIBS})

install(TARGETS ${PROJECT_NAME} DESTINATION "bin")


