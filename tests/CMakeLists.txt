
project(Giste)

set(THREADS_PREFER_PTHREAD_FLAG TRUE)
find_package(Threads REQUIRED)
find_package(Boost COMPONENTS system filesystem unit_test_framework REQUIRED)

include_directories(${TEST_SOURCE_DIR}/src
                    ${Boost_INCLUDE_DIRS})

if(BUILD_SHARED_LIBS)
	add_definitions(-DBOOST_TEST_DYN_LINK)
endif()

# Add subdirectories with tests

