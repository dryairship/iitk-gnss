set(AVAILABLE_ACQUISITION_ALGORITHMS "Algorithm1" "Algorithm2")
set(ACQUISITION_ALGO "Algorithm1" CACHE STRING "The algorithm to use for aquisition")
set_property(CACHE ACQUISITION_ALGO PROPERTY STRINGS ${AVAILABLE_ACQUISITION_ALGORITHMS})

if ("${ACQUISITION_ALGO}" STREQUAL "Algorithm1")
    add_library(acquisition acquisition_algo1.cpp)
elseif("${ACQUISITION_ALGO}" STREQUAL "Algorithm2")
    add_library(acquisition acquisition_algo2.cpp)
else()
    message(SEND_ERROR "Acquisition algorithm is invalid")
endif()

target_link_libraries(acquisition PUBLIC gnss-utils)

target_include_directories(acquisition PUBLIC
                           "${PROJECT_SOURCE_DIR}/modules/gnss-utils")
