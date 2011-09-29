
find_package(Boost REQUIRED)

link_directories(
    ${Boost_LIBRARY_DIRS}
    )

include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${Boost_INCLUDE_DIRS}
    )
set(SRCS
    component_mapper.cpp
    delayed_entity_processing_system.cpp 
    delayed_entity_system.cpp
    entity.cpp
    entity_manager.cpp 
    entity_processing_system.cpp
    entity_system.cpp
    group_manager.cpp 
    interval_entity_processing_system.cpp
    interval_entity_system.cpp
    system_bit_manager.cpp
    system_manager.cpp
    tag_manager.cpp
    world.cpp
    util/bag.cpp
    util/timer.cpp
)

add_library(artemis ${SRCS})
