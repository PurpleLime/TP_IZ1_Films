cmake_minimum_required(VERSION 3.15)

set(PROJECT_NAME TP_IZ1_Films)
project(TP_IZ1_Films C)

set(CMAKE_C_STANDARD 11)
set(INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)

include_directories(${INCLUDE_DIR})
add_executable(${PROJECT_NAME} ${SOURCE_DIR}/main.c)