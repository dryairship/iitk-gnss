add_library(position position_algo1.cpp)

target_link_libraries(position PUBLIC gnss-utils)

target_include_directories(position PUBLIC
                           "${PROJECT_SOURCE_DIR}/modules/gnss-utils")
