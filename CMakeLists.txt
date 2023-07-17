cmake_minimum_required(VERSION 3.22)
project(s21_containers)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_DIRS
    tests/
)

set(TEST_SRC "")

find_package(GTest REQUIRED)

include_directories(src/tests)
include_directories(${GTEST_INCLUDE_DIRS})

foreach(dir ${SOURCE_DIRS})
    file(GLOB CPP_SOURCES "${dir}/*.cpp")
    file(GLOB HEADER_SOURCES "${dir}/*.h")
    list(APPEND TEST_SRC ${CPP_SOURCES} ${HEADER_SOURCES})
endforeach()

add_executable(s21_containers
        ${TEST_SRC}
)

target_link_libraries(s21_containers PRIVATE ${GTEST_LIBRARIES} pthread)
