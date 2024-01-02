cmake_minimum_required (VERSION 3.8)

project(BaseProject)

add_library(BaseProject SHARED
  src/BaseProject.cpp
)

target_include_directories(BaseProject
PUBLIC
  include
PRIVATE
  src
)

target_compile_definitions(BaseProject 
PRIVATE
  BASEPROJECT_EXPORTS
  PRIVATE_BASE_DEF
PUBLIC
  PUBLIC_BASE_DEF
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET BaseProject PROPERTY CXX_STANDARD 20)
endif()
