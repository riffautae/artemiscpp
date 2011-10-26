set(SRCS
    component.cpp
    delayed_entity_processing_system.cpp 
    delayed_entity_system.cpp
    entity.cpp
    entity_manager.cpp 
    entity_processing_system.cpp
    entity_system.cpp
    group_manager.cpp 
    interval_entity_processing_system.cpp
    interval_entity_system.cpp
    manager.cpp
    system_manager.cpp
    tag_manager.cpp
    world.cpp
    util/timer.cpp
)

add_library(artemis ${SRCS})
