cmake_minimum_required(VERSION 3.10)

project(iitk-gnss VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(modules/gnss-utils)
add_subdirectory(modules/acquisition)
add_subdirectory(modules/tracking)
add_subdirectory(modules/position)

configure_file(iitk-gnss-config.h.in iitk-gnss-config.h)
add_executable(iitk-gnss main.cpp)

target_link_libraries(iitk-gnss PUBLIC acquisition)
target_link_libraries(iitk-gnss PUBLIC tracking)
target_link_libraries(iitk-gnss PUBLIC position)

target_include_directories(iitk-gnss PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           "${PROJECT_SOURCE_DIR}/modules/acquisition"
                           "${PROJECT_SOURCE_DIR}/modules/tracking"
                           "${PROJECT_SOURCE_DIR}/modules/position")
