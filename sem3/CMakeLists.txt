cmake_minimum_required(VERSION 3.2)

project(sem3)

set(CMAKE_C_FLAGS "-std=gnu11")
set(CMAKE_CXX_FLAGS "-std=gnu14")

find_package(PythonLibs 3.6 REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})

set(SOURCES
	sample1.c
)

add_executable(program ${SOURCES})

target_link_libraries(program ${PYTHON_LIBRARIES})
