cmake_minimum_required (VERSION 3.8)

# set the project name
project(MainProject)

# Proejct ABI 정의
if (MSVC)
  add_compile_options(/W4 /WX)
else()
  add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

# 빌드에 포함할 소스 경로 추가
add_subdirectory(lib)

# 타겟 프로그램 정의
add_executable(MainProject src/MainProject.cpp)

target_link_libraries(MainProject
PRIVATE
  BaseProject
  SubProject
)

set_target_properties(MainProject BaseProject SubProject
  PROPERTIES
  LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET MainProject PROPERTY CXX_STANDARD 20)
endif()
