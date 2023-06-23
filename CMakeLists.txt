cmake_minimum_required(VERSION 3.10)

# set the project name
project(halstead_analyzer VERSION 1.0)

file(GLOB SRC_DIR "${PROJECT_SOURCE_DIR}/src/*.c")
include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(${PROJECT_NAME} main.c ${SRC_DIR})


set(PROJECT_VERSION 1.0)
message(STATUS "Build halstead analyzer: ${PROJECT_VERSION}")


# setting the src file of the project
add_subdirectory(lib/spdlog)
add_subdirectory(lib/argparser)


target_include_directories(${PROJECT_NAME}
	PUBLIC lib/argparser PUBLIC lib/spdlog/include PUBLIC lib/pcre/src PUBLIC lib/googletest/googletest/include
)

target_link_directories(${PROJECT_NAME}
	PRIVATE lib/argparser PRIVATE lib/spdlog/src PRIVATE lib/pcre/src PRIVATE lib/googletest/googletest/src
)


target_link_libraries(${PROJECT_NAME} spdlog argparse pcre gtest)

