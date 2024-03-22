cmake_minimum_required(VERSION 3.28)

project(hchat)

# ABI
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
enable_testing()

# Projects
add_subdirectory(third-party)
add_subdirectory(hchat)
add_subdirectory(hchat-cli)
add_subdirectory(hchat-test)

# install
install(TARGETS hchat-cli)

# install - 모델 복사, 오래 걸리므로 테스트에서는 예외처리
# install(FILES "models/llama-2-7b-chat.Q5_K_S.gguf"
#   DESTINATION ${CMAKE_INSTALL_BINDIR}
# )

# package
include(InstallRequiredSystemLibraries)
set(CPACK_PACKAGE_VENDOR "hchat-cli")
set(CPACK_PACKAGE_VERSION_MAJOR "0")
set(CPACK_PACKAGE_VERSION_MINOR "1")
set(CPACK_PACKAGE_VERSION_PATCH "0")
set(CPACK_GENERATOR "STGZ;ZIP")
include(CPack)
