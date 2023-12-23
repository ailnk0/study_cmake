cmake_minimum_required (VERSION 3.8)

project(SubProject)

add_library(SubProject STATIC
  src/SubProject.cpp
)

target_include_directories(SubProject
PUBLIC
  include
PRIVATE
  src
)

target_link_libraries(SubProject
PRIVATE
  BaseProject
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET SubProject PROPERTY CXX_STANDARD 20)
endif()
