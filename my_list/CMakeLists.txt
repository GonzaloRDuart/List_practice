cmake_minimum_required(VERSION 3.27)
project(my_list_project)

set(CMAKE_CXX_STANDARD 17)

add_library(my_list_library STATIC my_list.cpp)

add_executable(main main.cpp)

target_link_libraries(main PRIVATE my_list_library)