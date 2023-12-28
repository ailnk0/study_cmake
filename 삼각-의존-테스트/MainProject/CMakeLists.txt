cmake_minimum_required (VERSION 3.8)

# set the project name
project(MainProject)

# Proejct ABI 정의
if (MSVC)
  add_compile_options(/W4 /WX)
else()
  add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

# 라이브러리 참조 경로 추가
# Linux에서 RPATH(Run Path)가 정의되어 있지 않으면 시스템 기본 설치 경로에서 라이브러리를 찾는다.
# 따라서 사용자 라이브러리 경로를 수동으로 설정해줘야 한다.
# GNU가 권장하는 기본 라이브러리 경로는 lib이지만, windows dll의 경우 실행파일과 동일한 경로에 있어야 한다.
# 간결함을 위해 플랫폼 관계 없이 라이브러리가 실행파일과 동일한 경로에 위치하도록 설정했다.
list(APPEND CMAKE_INSTALL_RPATH ".")

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
