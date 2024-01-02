# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project(CMakeProject1)

# Include sub-projects.
add_subdirectory(MainProject)

# Install을 위한 GNUInstallDirs 모듈 로드
include(GNUInstallDirs)

# Packaging를 위해 install target 설정
install(TARGETS MainProject BaseProject
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Packaging을 위한 시스템 라이브러리 모듈 로드
include(InstallRequiredSystemLibraries)

# Packaging을 위한 CPack 변수 설정
set(CPACK_PACKAGE_VENDOR "study_cmake")
set(CPACK_PACKAGE_VERSION_MAJOR "0")
set(CPACK_PACKAGE_VERSION_MINOR "1")
set(CPACK_PACKAGE_VERSION_PATCH "0")
set(CPACK_GENERATOR "STGZ;ZIP")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")

# Packaging을 위한 CPack 모듈 로드
include(CPack)