cmake_minimum_required (VERSION 3.8)

project("CMakeProject")

# Add source to this project's executable.
add_executable (CMakeProject "CMakeProject.cpp" "CMakeProject.h")

add_subdirectory("CMakeRoot")

target_include_directories(CMakeProject PUBLIC "../CMakeRoot/include")

target_link_libraries(CMakeProject CMakeRoot)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CMakeProject PROPERTY CXX_STANDARD 20)
endif()
