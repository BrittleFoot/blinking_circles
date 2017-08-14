cmake_minimum_required(VERSION 3.1)
project(circles)

set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake/modules/")
message(${CMAKE_MODULE_PATH})

set (CMAKE_CXX_STANDARD 11)
set (SOURCE_DIR source)

set (SOURCES
        ${SOURCE_DIR}/main.cpp    
)

set(SFML_ROOT ${PROJECT_SOURCE_DIR}/libs/SFML/)
find_package(SFML COMPONENTS system window graphics network audio main)

include_directories(${SFML_INCLUDE_DIR})


add_executable(circles ${SOURCES})
target_link_libraries(circles ${SFML_LIBRARIES})
