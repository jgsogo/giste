
project(Giste)
cmake_minimum_required(VERSION 2.8.12)

message(STATUS "Add giste-engine-cli")

# Dependencies
find_package(Boost COMPONENTS program_options REQUIRED)

file(GLOB interface_SRC) # TODO: enumerate interface files
file(GLOB headers_SRC "*.h" "*.hpp")
file(GLOB impl_SRC "*.cpp")

message(STATUS ">>> ${Boost_LIBRARIES}")

add_executable(engine-cli ${impl_SRC} ${headers_SRC})
set_target_properties(engine-cli PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(engine-cli ${Boost_LIBRARIES})



