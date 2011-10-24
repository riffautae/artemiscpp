cmake_minimum_required(VERSION 2.0)
project(artemis)


find_package(Boost REQUIRED)

link_directories(
    ${Boost_LIBRARY_DIRS}
    )

include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${Boost_INCLUDE_DIRS}
    )

add_subdirectory(src)

set_property(TARGET artemis PROPERTY LIBRARY_OUTPUT_DIRECTORY lib)
