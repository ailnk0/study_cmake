# study_cmake

## 1. Recommended Directories Structure

```
// Recommended 1
.
├── bin             // 컴파일된 실행 파일
├── data            // 데이터와 에셋
├── demo            // 데모
├── doc             // 문서
├── include         // 공개 헤더 파일
├── lib             // 외부 라이브러리
├── src             // 소스 코드
└── test            // 테스트
```

```
// Recommended 2
.
├── bin             // 컴파일된 실행 파일
│    ├── debug      // 디버그 빌드
│    └── release    // 릴리스 빌드
├── doc             // 문서
├── include         // 공개 헤더 파일
├── lib             // 외부 라이브러리
├── obj             // 컴파일 중에 생성된 중간 개체 파일
├── packages        // 종속성 관리를 위한 NuGet 패키지
├── resources       // 이미지나 데이터 파일과 같은 리소스
├── src             // 소스 코드
├── test            // 테스트
└── tools           // 프로젝트와 관련된 스크립트 또는 도구
```

## 2. 모던 CMake

### 2.1. 작성 순서

1. ABI 영향을 주는 전역설정하기
2. 타겟을 정의
3. 타겟에서 공개해야 할 것과 하지 않을 것을 나누기
4. 타겟의 프로퍼티 설정하기

### 2.2. 모던 CMake에서 피해야 하는 명령어

아래와 같은 명령어는 피하고 대신 `target_*` 명령어를 사용하자.
다만, 기존 프로젝트를 분석할 때는 이런 명령어를 알아야 한다.

### 2.2.1. add_compile_options

컴파일 옵션을 전역으로 추가한다.

```cmake
add_compile_options(-Wall -Wextra -Werror)
```

### 2.2.2. add_definitions

전처리기 정의를 전역으로 추가한다.

```cmake
add_definitions(-DFOO_VERSION=1.0.0)
```

### 2.2.3. include_directories

헤더 파일의 경로를 전역으로 추가한다.

```cmake
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
```

### 2.2.4. link_libraries

라이브러리를 전역으로 추가한다.

```cmake
link_libraries(bar)
```

### 2.3. 모던 CMake에서 사용하는 명령어

모던 CMake에서는 Target을 정의하고, Target에 필요한 설정을 추가하는 방식으로 사용한다.
현재 Target에서만 사용하면 `PRIVATE`으로 사용하고, 외부에서도 사용할 수 있어야 하면 `PUBLIC`을 사용한다.
의존성 문제를 깔끔하게 관리하기 위해 기본적으로 `PRIVATE`을 사용하자.

### 2.3.1. add_executable

실행 파일을 만들기 위해 타겟을 정의한다.

```cmake
add_executable(foo src/main.cpp)
```

### 2.3.2. add_library

정적 라이브러리 또는 공유 라이브러리를 만들기 위해 타겟을 정의한다.

```cmake
add_library(foo STATIC src/foo.cpp)
```

### 2.3.3. target_link_libraries

타겟에게 필요한 라이브러리를 연결한다.

```cmake
target_link_libraries(foo PRIVATE
  bar
)
```

### 2.3.4. set_target_properties

타겟의 속성을 설정한다. 운영체제에서 지원하지 않는 속성은 무시된다.

```cmake
set_target_properties(foo PROPERTIES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED YES
  CXX_EXTENSIONS NO
)
```

### 2.3.5. target_compile_definitions

전처리기 정의를 추가한다.

```cmake
target_compile_definitions(foo PRIVATE
  FOO_VERSION=1.0.0
)
```

### 2.3.6. target_compile_options

컴파일 옵션을 추가한다.

```cmake
target_compile_options(foo PRIVATE
  -Wall
  -Wextra
  -Werror
)
```

### 2.3.7. target_include_directories

타겟에게 필요한 헤더 파일의 경로를 추가한다.

```cmake
target_include_directories(foo PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)
```

### 2.3.8. target_sources

타겟에게 필요한 소스 파일을 추가한다.

```cmake
target_sources(foo PRIVATE
  src/foo.cpp
)
```

## 2.4. 모던 CMake 기본 명령어

### 2.4.1. cmake_minimum_required

최소한으로 필요한 CMake 버전을 지정한다.

```cmake
cmake_minimum_required(VERSION 3.10)
```

### 2.4.2. project

프로젝트 이름을 지정한다.

```cmake
project(foo)
```

### 2.4.3. find_package

패키지를 찾는다.

```cmake
find_package(Boost REQUIRED)
```

### 2.4.4. message

메시지를 출력한다.

```cmake
message(STATUS "CMake version: ${CMAKE_VERSION}")
```

### 2.4.5. set/unset

변수를 설정하거나 해제한다.

```cmake
set(FOO_VERSION 1.0.0)
unset(FOO_VERSION)
```

### 2.4.6. option

옵션을 설정한다.

```cmake
option(FOO_BUILD_TESTS "Build tests" ON)
```

### 2.4.7. list

리스트를 자료구조로 사용한다.

```cmake
list(APPEND FOO_SOURCES src/foo.cpp)
list(REMOVE_ITEM FOO_SOURCES src/foo.cpp)
```

### 2.4.8. if, elseif, else, endif

조건문을 사용한다.

```cmake
if(FOO_BUILD_TESTS)
  add_subdirectory(test)
elseif(FOO_BUILD_DEMO)
  add_subdirectory(demo)
else()
  message(STATUS "No tests or demos")
endif()
```

### 2.4.9. foreach, endforeach

반복문을 사용한다.

```cmake
foreach(SOURCE ${FOO_SOURCES})
  message(STATUS "Source: ${SOURCE}")
endforeach()
```

# 3. 빌드, 설치, 배포

## 3.1. 빌드 (Build)

기본 빌드 방법

```sh
mkdir build
cd build

# 빌드를 위한 Makefile 생성
cmake ..

# 빌드
cmake --build .
```

### 3.1.1. CMake 옵션

```sh
-B <dir>  # 빌드 디렉토리 지정
-j <n>  # 병렬 빌드
-G <generator>  # 빌드 시스템 지정
-D <var>=<value>  # 변수 설정
--build <dir>  # 빌드 디렉토리 지정
--target <target>  # 특정 타겟만 빌드
--config <config>  # 빌드 타입 지정
--fresh # CMakeCache.txt를 새로 생성
--install-prefix <dir>  # 설치 경로 지정
--toolchain <file>  # 툴체인 파일 지정
```

## 3.2. 설치 (Install)

## 3.2.1. 설정

기본 설치 구성

```cmake
# GNUInstallDirs 모듈 로드
include(GNUInstallDirs)

# 메세지 출력
message(STATUS "BINDIR: ${CMAKE_INSTALL_BINDIR}")
message(STATUS "LIBDIR: ${CMAKE_INSTALL_LIBDIR}")
message(STATUS "INCLUDEDIR: ${CMAKE_INSTALL_INCLUDEDIR}")
message(STATUS "DATAROOTDIR: ${CMAKE_INSTALL_DATAROOTDIR}")

# 타겟들의 설치 규칙 설정
install(TARGETS foo EXPORT installing-config
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
```

아래는 추가적인 설치 규칙 설정

```cmake
# 파일들을 어디에 설치할지 설정
install(FILES include/foo.h
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# 파일들을 타입에 따라 설치
install(FILES include/foo.h TYPE INCLUDE)

# CMake에서 설치된 타겟을 사용하기 위한 파일을 생성하고 설치
install(EXPORT installing-config
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/installing
  NAMESPACE installing::
)
```

## 3.2.2. 빌드 및 설치하기

```sh
mkdir build
cd build

# 빌드를 위한 Makefile 생성 및 설치 경로 설정
cmake .. --install-prefix=${사용자_설치_경로}

# 빌드
cmake --build . --target install
```

## 3.3. 배포 (Packaging)

## 3.3.1. 설정

```cmake
# InstallRequiredSystemLibraries 모듈 로드
include(InstallRequiredSystemLibraries)

# 패키징 관련된 변수 설정
set(CPACK_PACKAGE_VENDOR "study_cmake")
set(CPACK_PACKAGE_VERSION_MAJOR "0")
set(CPACK_PACKAGE_VERSION_MINOR "1")
set(CPACK_PACKAGE_VERSION_PATCH "0")
set(CPACK_GENERATOR "STGZ;ZIP")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")

# CTest 모듈 로드
include(CPack)
```

## 3.3.2. 빌드 및 설치하기

```sh
mkdir build
cd build

# 빌드를 위한 Makefile 생성
# --fresh CMakeCache.txt를 새로 생성
# -DCMAKE_BUILD_TYPE 빌드 타입을 지정
cmake .. --fresh -DCMAKE_BUILD_TYPE=Release

# Release 빌드
# --config 빌드 타입을 지정
cmake --build . --config Release

# 패키징
cpack
```

# 4. 외부 라이브러리 관리

## 4.1. CMake와 vcpkg

기본적으로 vcpkg로 설치한 라이브러리는 CMake에서 자동으로 찾아주며, 설치시 사용 방법을 출력해준다.

```sh
# cmake 생성 시 vcpkg.cmake을 toolchain으로 지정
# 아래 2가지 중에서 한 가지 방법을 사용한다.
cmake . --toolchain=[vcpkg 설치 경로]/scripts/buildsystems/vcpkg.cmake
cmake . -DCMAKE_TOOLCHAIN_FILE=[vcpkg 설치 경로]/scripts/buildsystems/vcpkg.cmake
```

```cmake
# 예시
find_package(fmt CONFIG REQUIRED)
target_link_libraries(main PRIVATE fmt::fmt)
```

## 4.2. include

```cmake
# 모듈 로드
include(CheckIncludeFileCXX)

# C++ 파일이 있는지 검사
check_include_file_cxx("filesystem" CXX_FILESYSTEM_HAVE_HEADER)
```

## 4.3. FetchContent

```cmake
# FetchContent 모듈 로드
include(FetchContent)

# 컨텐츠를 Git에서 가져오기
FetchContent_Declare(spdlog
  GIT_REPOSITORY https://github.com/gabime/spdlog.git
  GIT_TAG 706ad7059125f32158dad4441938c08fa910f143)

# 컨텐츠를 URL 다운로드를 통해 가져오기
FetchContent_Declare(poco
  URL https://github.com/pocoproject/poco/archive/refs/tags/poco-1.12.4-release.tar.gz
  URL_HASH MD5=0ca5d1e2f2a5e8ba2f0a83c2e6df374a
  DOWNLOAD_EXTRACT_TIMESTAMP 20230316091300
)

# 선언된 컨텐츠들을 프로젝트에서 사용할 수 있도록 준비
FetchContent_MakeAvailable(spdlog poco)

# 타겟을 링킹할 때 필요한 타겟이나 라이브러리를 지정
target_link_libraries(foo
PRIVATE
  spdlog::spdlog
  Poco::Net
)
```

# 5. 참고

## 5.1. GLOB

편의 기능

```cmake
# 모든 cpp 파일 목록 생성
file(GLOB FILES *.cpp)

# 모든 cpp 파일을 foo라는 실행 파일로 빌드
add_executable(foo ${FILES})
```

하지만 GLOB의 치명적인 단점

CMake가 파일 목록이 변경되었는지 알 수 없다. 자동으로 파일 목록을 갱신하지 않기 때문에 CMakeCache.txt를 수동으로 삭제해야 한다. 만약 사용자가 CMakeCache.txt를 삭제하지 않으면 새로운 파일이 추가되었는데도 불구하고 빌드되지 않거나 빌드 되더라도 예상치 못한 오류가 발생할 수 있다.

실수가 자주 발생할 수 있기 때문에 GLOB을 사용하지 않는 것이 좋다.
