cmake_minimum_required(VERSION 3.10)

# set the project name
project(halstead_analyzer VERSION 1.0)

file(GLOB SRC_DIR "${PROJECT_SOURCE_DIR}/src/*.c")
file(GLOB TEST_SRC_DIR "${PROJECT_SOURCE_DIR}/test/*.c")
include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(${PROJECT_NAME} main.c ${SRC_DIR} ${TEST_SRC_DIR})


set(PROJECT_VERSION 1.0)
message(STATUS "Build halstead analyzer: ${PROJECT_VERSION}")


# setting the src file of the project
add_subdirectory(lib/spdlog)
add_subdirectory(lib/argparser)

# adding gtest to the source 
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/ec4fed93217bc2830959bb8e86798c1d86956949.zip
)
#   URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


enable_testing()

include(GoogleTest)
gtest_discover_tests(halstead_analyzer)
# gest including portion ended


target_include_directories(${PROJECT_NAME}
	PUBLIC lib/argparser PUBLIC lib/spdlog/include PUBLIC lib/pcre/src
)

target_link_directories(${PROJECT_NAME}
	PRIVATE lib/argparser PRIVATE lib/spdlog/src PRIVATE lib/pcre/src
)


target_link_libraries(${PROJECT_NAME} spdlog argparse pcre  GTest::gtest_main)

