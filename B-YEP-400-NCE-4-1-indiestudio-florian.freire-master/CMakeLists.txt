cmake_minimum_required(VERSION 3.17)
project(BomberMan)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib/)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/)
add_executable(bomberman)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")
find_package(raylib REQUIRED)
target_link_libraries(bomberman pthread)
target_link_libraries(bomberman raylib)
target_include_directories(bomberman PRIVATE
include
include/Game
include/Game/GameObjects
include/Scene)
add_subdirectory(src)
