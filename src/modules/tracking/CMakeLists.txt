add_library(tracking tracking_algo1.cpp)

target_link_libraries(tracking PUBLIC gnss-utils)

target_include_directories(tracking PUBLIC
                           "${PROJECT_SOURCE_DIR}/modules/gnss-utils")
